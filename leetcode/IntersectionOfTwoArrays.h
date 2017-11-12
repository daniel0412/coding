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

class IntersectionOfTwoArrays {
  public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        if(nums1.size() > nums2.size())
            return intersection(nums2, nums1);
        vector<int> res;
        if(nums1.empty() || nums2.empty())
            return res;
        unordered_set<int> s;
        for(auto n : nums1)
            s.insert(n);
        for(auto n : nums2) {
            if(s.count(n)) {
                res.push_back(n);
                s.erase(n);
            }
        }
        return res;
    }

  private:
};
