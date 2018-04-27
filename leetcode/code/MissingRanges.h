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

class MissingRanges {
  public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper)
    {
        vector<string> res;
        stringstream ss;
        int start = lower;

        for(int i = 0; i < nums.size();) {
            if(nums[i] == start) {
                while(i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                    ++i;
                }
                start = nums[i] + 1;
                ++i;
            }
            else {
                if(nums[i] - 1 == start) {
                    res.emplace_back(to_string(start));
                }
                else {
                    ss.clear();
                    ss.str("");
                    ss << start << "->" << nums[i] - 1;
                    res.emplace_back(ss.str());
                }
                start = nums[i];
            }
        }
        if(start < upper) {
            ss.clear();
            ss.str("");
            ss << start << "->" << upper;
            res.emplace_back(ss.str());
        }
        else if(start == upper) {
            res.emplace_back(to_string(start));
        }
        return res;
    }

  private:
};
