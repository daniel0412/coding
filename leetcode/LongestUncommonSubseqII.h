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

class LongestUncommonSubseqII {
  public:
    int findLUSlength(vector<string>& strs)
    {
        unordered_map<string, int> m;
        for(const auto& s : strs) {
            ++m[s];
        }
        if(m.size() == 1)
            return -1;

        // sort by string length and occurance
        vector<pair<string, int> > vv;
        for(auto kv : m) {
            vv.emplace_back(pair<string, int>{kv.first, kv.second});
        }
        sort(vv.begin(),
             vv.end(),
             [](const pair<string, int>& a, const pair<string, int>& b) {
                 return a.first.size() > b.first.size() ||
                     (a.first.size() == b.first.size() && a.second < b.second);
             });

        if(vv[0].second == 1)
            return v[0].first.size();

        for(int i = 0; i < vv.size(); ++i) {
            if(vv[i].second > 1)
                continue;
            int j = 0;
            for(; j < i; ++j) {
                if(issub(vv[j].first, vv[i].first))
                    break;
            }
            // not a subseq of any longer string
            if(j == i)
                return vv[i].first.size();
        }
        return -1;
    }

    bool issub(const string& s, const string& p)
    {
        int i = 0;
        for(auto c : s) {
            if(p[i] == c)
                ++i;
            if(i == p.size())
                return true;
        }
        return false;
    }

  private:
};
