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

class CreateMaxNum {
  public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
    {
        vector<int> res;
        int len1 = nums1.size(), len2 = nums2.size();
        // attention:
        // there is upper/lower limit of number of digits we can take from one array
        // it depends on how many number there are in both arrays
        for(int i = max(0, k - len2); i <= min(k, len1); ++i) {
            // here max function can be applied to vector
            res = max(
                res,
                merge(formulateMax(nums1, i), formulateMax(nums2, (k - i))));
        }
        return res;
    }

  private:
    // this is classical
    vector<int> formulateMax(const vector<int>& num, int k)
    {
        vector<int> res;
        int num2Del = num.size() - k;
        for(auto d : num) {
            while(num2Del > 0 && !res.empty() && res.back() < d) {
                res.pop_back();
                --num2Del;
            }
            /* this is wrong, in case larger number comes the last
            if(res.size() < k)
                res.push_back(d);
                */
            res.push_back(d);
        }
        // in case more than k digits are left
        res.resize(k);
        return res;
    }

    vector<int> findMax(const vector<int>& nums, int k)
    {
        if(k == 0)
            return {};
        if(k == nums.size())
            return nums;
        vector<int> res;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            // if found larger number, and still have enough digits left to form k digits number
            // then pop out smaller digit
            while(!res.empty() && res.back() < nums[i] &&
                  n - i - 1 + res.size() >= k) {
                res.pop_back();
            }
            // if size k not reached, keep pusing into res
            if(res.size() < k) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
    // when merge, push the current larger element,
    // if equals, we need to compare next elements in the array,
    // since next greater element should be put in th array first
    // e.g. [6,7] and [6,5,3] => 67653 but not 66753, so should choose 6 in
    // first
    // array
    vector<int> merge(vector<int> num1, vector<int> num2)
    {
        vector<int> res;
        while(num1.size() + num2.size()) {
            // *IMPORTANT* vector > :
            // first  compare element by element
            // if all equal, then check length
            vector<int>& tmp = num1 > num2 ? num1 : num2;
            res.push_back(tmp.front());
            tmp.erase(tmp.begin());
        }
        return res;
    }
};
