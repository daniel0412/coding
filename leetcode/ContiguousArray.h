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

class ContiguousArray {
  public:
    int findMaxLength(vector<int>& nums) { return presumImpl(nums); }
    int presumImpl(vector<int>& nums)
    {
        int res = 0;
        int curSum = 0;
        unordered_map<int, int> sumToId{{0, -1}};
        for(size_t i = 0; i < nums.size(); ++i) {
            curSum += (nums[i] == 1) ? 1 : -1;
            if(sumToId.count(curSum)) {
                res = max(res, (int) i - sumToId[curSum]);
            }
            else {
                sumToId.insert({curSum, i});
            }
        }
        return res;
    }
    int timeoutImpl(vector<int>& nums)
    {
        if(nums.size() <= 1)
            return 0;
        vector<pair<int, int> > total(nums.size(), {0, 0});
        if(nums[0] == 0) {
            total[0].first = 1;
        }
        else {
            total[0].second = 1;
        }
        int maxLen = 0;
        for(size_t i = 1; i < nums.size(); ++i) {
            if(nums[i] == 0) {
                total[i].first = total[i - 1].first + 1;
                total[i].second = total[i - 1].second;
            }
            else {
                total[i].first = total[i - 1].first;
                total[i].second = total[i - 1].second + 1;
            }
            if(total[i].first == total[i].second) {
                maxLen = i + 1;
                continue;
            }
            else {
                for(int j = 0; j < i; ++j) {
                    int curLen = i - j;
                    if(curLen <= maxLen)
                        break;
                    if(total[i].first - total[j].first ==
                       total[i].second - total[j].second) {
                        maxLen = curLen;
                        break;
                    }
                }
            }
        }
        return maxLen;
    }

  private:
};
