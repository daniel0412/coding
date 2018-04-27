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

class DecodeString {
  public:
    string decodeString(string s)
    {
        int i = 0, start = 0, len = s.size();
        string res;
        stack<string> ss;

        while(i < len) {
            if(isdigit(s[i])) {
                start = i;
                while(i < len && isdigit(s[i]))
                    ++i;
                ss.push(s.substr(start, i - start));
            }
            else if(s[i] == '[') {
                ++i;
            }
            else if(isalpha(s[i])) {
                start = i;
                while(i < len && isalpha(s[i]))
                    ++i;
                string t = s.substr(start, i - start);
                if(ss.empty() || isdigit(ss.top()[0]))
                    ss.push(t);
                else
                    ss.top() += t;
            }
            else if(s[i] == ']') {
                ++i;
                string res;
                string t = ss.top();
                ss.pop();
                int num = atoi(ss.top().c_str());
                ss.pop();
                for(int k = 0; k < num; ++k)
                    res += t;
                if(ss.empty() || isdigit(ss.top()[0]))
                    ss.push(res);
                else
                    ss.top() += res;
            }
        }
        if(ss.size() == 1)
            return ss.top();
        return "";
    }

    string dfs(const string& s, size_t& i)
    {
        string res;
        while(i < s.size()) {
            // when see ']', should return recursive call
            if(s[i] == ']') {
                ++i;
                return res;
            }

            // when see digit, indicating some recursive call needed
            if(isdigit(s[i])) {
                int start = i;
                while(i < s.size() && isdigit(s[i]))
                    ++i;
                int cnt = stoi(s.substr(start, i - start));
                ++i;
                string tmpstr = dfs(s, i);
                for(size_t k = 0; k < cnt; ++k) {
                    res += tmpstr;
                }
            }
            // if is alpha chars, just append
            else {
                res.push_back(s[i++]);
            }
        }
        return res;
    }

  private:
};
