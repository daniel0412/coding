/* 228. Summary Ranges
 *
 * Given a sorted integer array without duplicates, return the summary of its
 *ranges.
 *
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 */

#include <string>
#include <vector>
#include <list>
#include <stack>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

class SummaryRanges {
  public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> res;
        if(nums.size() == 0)
            return res;

        int l = nums.front(), r = nums.front();
        for(int i = 1; i < nums.size(); ++i) {
            if(r + 1 != nums[i]) {
                res.emplace_back(formstr(l, r));
                l = nums[i];
            }
            r = nums[i];
        }
        // deal with the last one
        res.emplace_back(formstr(l, r));
        return res;
    }

    string formstr(int l, int r)
    {
        return l == r ? to_string(l) : to_string(l) + "->" + to_string(r);
    }

  private:
};
