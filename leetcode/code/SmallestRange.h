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

class SmallestRange {
  public:
    vector<int> smallestRange(vector<vector<int> >& nums)
    {

        // merge all lists and form a sorted numbers with original list number
        vector<pair<int, int> > v;
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); ++i) {
            for(auto d : nums[i]) {
                v.emplace_back(i, d);
            }
            m[i] = 1;
        }

        sort(v.begin(),
             v.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        // similar logic as minimum window string
        int start = 0, end = 0;
        int range = numeric_limits<int>::max();
        int needs = m.size();
        vector<int> res({0, 0});
        while(end < v.size()) {
            if(m[v[end].first]-- > 0) {
                --needs;
            }
            if(needs == 0) {
                while(m[v[start].first] < 0) {
                    ++m[v[start].first];
                    ++start;
                }
                if(range > v[end].second - v[start].second) {
                    res[0] = v[start].second;
                    res[1] = v[end].second;
                    range = v[end].second - v[start].second;
                }
                ++m[v[start].first];
                ++start;
                ++needs;
            }
            ++end;
        }
        return res;
    }

  private:
};
