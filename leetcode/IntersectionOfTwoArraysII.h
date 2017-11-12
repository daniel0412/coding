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

class IntersectionOfTwoArraysII {
  public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        if(nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        vector<int> res;
        if(nums1.empty() || nums2.empty())
            return res;
        unordered_map<int, int> m;
        for(auto n : nums1)
            ++m[n];
        for(auto n : nums2) {
            if(m[n] > 0) {
                res.push_back(n);
                --m[n];
            }
        }
        return res;
    }

  private:
};

// Follow up questions
// 1. what if two array are sorted -> two pointer solution
// 2. what if one array is very large -> binary search + two pointer
// 3. what if one array is too large that it can only be stored on disk
