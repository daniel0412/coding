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
        if(nums.size() == 0) return res;

        int start = 0;
        stringstream ss;

        for(int i = 0; i < nums.size() - 1;) {
            while(nums[i] + 1 == nums[i + 1]) {
                ++i;
            }
            ss << nums[start];
            if(i > start) {
                ss << "->";
                ss << nums[i];
            }
            res.push_back(ss.str());
            ss.clear();
            ss.str("");
            ++i;
            start = i;
        }
        if(start == nums.size() - 1) {
            ss << nums[start];
            res.push_back(ss.str());
        }
        return res;
    }

  private:
};
