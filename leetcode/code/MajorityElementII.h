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

class MajorityElementII {
  public:
    vector<int> majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> m;
        int len = nums.size(), thresh = len / 3;
        for(auto n : nums) {
            ++m[n];
            if(m.size() > 2) {
                auto iter = m.begin();
                while(iter != m.end()) {
                    if(--iter->second == 0) {
                        // attention: map erase and increase iterator
                        m.erase(iter++);
                    }
                    else {
                        ++iter;
                    }
                }
            }
        }

        for(auto& kv : m) {
            kv.second = 0;
        }

        for(auto n : nums) {
            if(m.count(n)) {
                ++m[n];
            }
        }
        vector<int> res;
        for(auto& kv : m) {
            if(kv.second > thresh) {
                res.push_back(kv.first);
            }
        }
        return res;
    }

  private:
};
