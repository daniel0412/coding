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

class LongestWordInDictAfterDel {
  public:
    string findLongestWord(string s, vector<string>& d)
    {
        sort(d.begin(),
             d.end(),
             [](const string& s1, const string& s2) {
                 if(s1.size() != s2.size())
                     return s1.size() > s2.size();
                 return s1 < s2;
             });
        for(const auto& t : d) {
            if(valid(s, t))
                return t;
        }
        return "";
    }

  private:
    bool valid(const string& s, const string& t)
    {
        int slen = s.size(), tlen = t.size();
        int si = 0, ti = 0;
        while(si < slen && ti < tlen) {
            if(s[si] == t[ti]) {
                ++ti;
            }
            ++si;
        }
        return ti == tlen;
    }
};
