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
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> res;
        if(nums.size() < 2)
            return res;

        unordered_map<int, vector<int>> valToIndexListMap;
        for(int i = 0; i < nums.size(); ++i) {
            valToIndexListMap[nums[i]].push_back(i);
        }

        for(int firstId = 0; firstId < nums.size(); ++firstId) {
            unordered_map<int, vector<int> >::iterator iter =
                valToIndexListMap.find(target - nums[firstId]);
            if(iter != valToIndexListMap.end()) {
                for(auto secondId : iter->second) {
                    if(secondId == firstId) {
                        continue;
                    }
                    else {
                        res.push_back(firstId);
                        res.push_back(secondId);
                        return res;
                    }
                }
            }
        }
        return res;
    }

  private:
};
