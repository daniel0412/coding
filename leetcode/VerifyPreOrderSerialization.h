/*
 *
 */

#include <string>
#include <vector>
#include <list>
#include <stack>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <functional>
#include <algorithm>
#include <utility>
#include "utils.h"

using namespace std;

class VerifyPreOrderSerialization {
  public:
    bool isValidSerialization(string preorder) {}

    bool stackimpl(string preorder)
    {
        stack<string> s;
        int id = 0;
        string tmp = getNext(preorder, id);
        while(!tmp.empty()) {
            s.emplace(tmp);
            if(tmp == "#") {
                // make sure the top three elements are subtree that can be
                // squashed
                while(s.size() >= 3) {
                    string a = s.top();
                    s.pop();
                    string b = s.top();
                    s.pop();
                    string c = s.top();
                    s.pop();
                    if(a == "#" && b == "#" && c != "#")
                        s.emplace(tmp);
                    else {
                        s.emplace(c);
                        s.emplace(b);
                        s.emplace(a);
                        break;
                    }
                }
            }
        }
        return s.size() == 1 && s.top() == "#";
    }

    string getNext(const string& str, int& id)
    {
        int start = id;
        while(id < str.size() && str[id++] != ',')
            ;
        return id == str.size() ? str.substr(start) :
                                  str.substr(start, id - start - 1);
    }


    bool degreeimpl(string preorder)
    {
        int diff = -1;
        int id = 0;
        string tmp = getNext(preorder, id);
        while(!tmp.empty()) {
            if(diff >= 0)
                return false;
            if(tmp == "#") {
                diff += 1;
            }
            else {
                diff -= 1;
            }
            tmp = getNext(preorder, id);
        }
        return diff == 0;
    }

  private:
};
