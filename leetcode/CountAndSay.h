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

class CountAndSay {
  public:
    string countAndSay(int n)
    {
        if(n <= 0)
            return "";
        string res("1");
        for(int i = 1; i < n; ++i) {
            res = getNext(res);
        }
        return res;
    }

  private:
    string getNext(const string& s)
    {
        string res;
        char prev = s[0];
        int count = 1;

        for(size_t i = 1; i < s.size(); ++i) {
            if(s[i] == s[i - 1]) {
                ++count;
            }
            else {
                res += to_string(count);
                res.push_back(prev);
                prev = s[i];
                count = 1;
            }
        }
        res += to_string(count);
        res.push_back(prev);
        return res;
    }
};
