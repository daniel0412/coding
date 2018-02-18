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
            if(tmp == "#" && s.size() >= 2 && s.top() == "#") {
                s.pop();
                s.pop();
            }
            s.emplace(tmp);
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
            if(tmp == "#") {
                diff += 1;
            }
            else {
                diff -= 1;
            }
        }
        return diff == 0;
    }

  private:
};
