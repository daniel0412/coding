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

class FindAllAnagramInStr {
  public:
    vector<int> findAnagrams(string s, string p)
    {
        if(s.size() < p.size())
            return {};
        unordered_map<char, int> m;
        for(auto c : p)
            ++m[c];
        vector<int> res;
        int left = 0, right = 0;
        int cnt = p.size();
        while(right < s.size()) {
            if(m[s[right++]]-- > 0)
                --cnt;
            if(cnt == 0)
                res.push_back(left);
            if(right - left == p.size() && m[s[left++]]++ >= 0)
                ++cnt;
        }
        return res;
    }

  private:
    vector<int> twoCacheImpl(string s, string p)
    {
        if(s.size() < p.size())
            return false;
        unordered_map<char, int> sm, pm;
        for(auto c : p) {
            ++pm[c];
        }
        vector<int> res;
        int left = 0, right = 0;
        while(right < s.size()) {
            if(pm.find(s[right]) == pm.end()) {
                ++right;
                left = right;
                sm.clear();
                continue;
            }
            ++sm[s[right++]];
            if(right - left == p.size()) {
                if(compMap(pm, sm)) {
                    res.push_back(left);
                }
                --sm[s[left++]];
            }
        }
        return res;
    }

    bool compMap(unordered_map<char, int>& bench,
                 unordered_map<char, int>& test)
    {
        for(auto& kv : bench) {
            if(test[kv.first] != kv.second)
                return false;
        }
        return true;
    }
};
