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

class TwoSum {
  public:
    // ATTENTION: the array is not sorted
    // sorting will corrupt the index order

    // two passes
    vector<int> twoSumImpl1(vector<int>& nums, int target)
    {
        unordered_map<int, int> m;
        // for the same value, index will be overwritten
        for(int i = 0; i < nums.size(); ++i) {
            m[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if(m.count(diff) && m[diff] != i) {
                return {i, m[diff]};
            }
        }
        return {};
    }

    // one pass
    vector<int> twoSumImpl1(vector<int>& nums, int target)
    {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if(m.count(diff) && m[diff] != i) {
                return {m[diff], i};
                res.push_back(m[diff]);
                res.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }
        return res;

      private:
    };
