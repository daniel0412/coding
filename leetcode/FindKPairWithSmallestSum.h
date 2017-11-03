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

class FindKPairWithSmallestSum {
  public:
    vector<pair<int, int> > kSmallestPairs(vector<int>& nums1,
                                           vector<int>& nums2,
                                           int k)
    {
        vector<pair<int, int> > res;
        if(nums1.size() * nums2.size() <= k) {
            for(auto n1 : nums1) {
                for(auto n2 : nums2) {
                    res.emplace_back(n1, n2);
                }
            }
            return res;
        }

        auto comp = [&nums1, &nums2](const pair<int, int>& a,
                                     const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] >
                nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(comp)>
            q(comp);
        // std::min() has to convert vector.size() type from size_t
        for(int i = 0; i < min(k, (int) nums1.size()); ++i) {
            q.emplace(i, 0);
        }
        while(k--) {
            int id1 = q.top().first, id2 = q.top().second;
            q.pop();
            res.emplace_back(nums1[id1], nums2[id2]);
            if(id2 + 1 < nums2.size()) {
                q.emplace(id1, id2 + 1);
            }
        }
        return res;
    }

  private:
};
