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

    string dfs(const string& s, int& i, int cnt)
    {
        string res("");
        int nextCnt = 1; // count for the next recursive []
        while(i < s.size()) {
            if(isdigit(s[i])) {
                int start = i;
                while(i < s.size() && isdigit(s[i]))
                    ++i;
                nextCnt = stoi(s.substr(start, i - start));
            }
            else if(s[i] == '[') {
                res += dfs(s, ++i, nextCnt);
            }
            else if(s[i] == ']') {
                ++i;
                string t = res;
                while(--cnt > 0)
                    res += t;
                return res;
            }
            else {
                res.push_back(s[i++]);
            }
        }
        return res;
    }

  private:
};
