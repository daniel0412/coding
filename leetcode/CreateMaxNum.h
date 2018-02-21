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
        for(int i = max(0, k - len2); i <= min(k, len1); ++i) {
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

    vector<int> merge(vector<int> num1, vector<int> num2)
    {
        vector<int> res;
        while(num1.size() + num2.size()) {
            // *IMPORTANT* vector > : first use vector that have larger
            // following number  or longer
            vector<int>& tmp = num1 > num2 ? num1 : num2;
            res.push_back(tmp.front());
            tmp.erase(tmp.begin());
        }
        return res;
    }
};
