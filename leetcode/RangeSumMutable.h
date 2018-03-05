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

class NumArray {
  public:
    NumArray(vector<int> nums) : d_nums(nums)
    {
        // calculate
        int height = nums.empty() ? 0 : ceil(log(nums.size()) / log(2));
        int len = pow(2, height + 1) - 1;
        d_st.resize(len);
        updateSt(0, d_nums.size() - 1, 0);
    }

    void update(int i, int val)
    {
        if(i < 0 || i >= d_nums.size())
            return;
        int diff = val - d_nums[i];
        d_nums[i] = val;
        updateSt(0, d_nums.size() - 1, 0, i, diff);
    }

    int sumRange(int i, int j)
    {
        return querySum(0, d_nums.size() - 1, 0, i, j);
    }


    int initSt(int s, int e, int id)
    {
        if(s == e) {
            d_st[id] = d_nums[s];
        }
        else {
            int m = s + (e - s) / 2;
            d_st[id] = initSt(s, m, 2 * id + 1) + initSt(m + 1, e, 2 * id + 2);
        }
        return d_st[id];
    }

    void updateSt(int s, int e, int id, int i, int diff)
    {
        if(i >= s && i <= e) {
            d_st[id] += diff;
            if(s == e)
                return;
            int m = s + (e - s) / 2;
            updateSt(s, m, 2 * id + 1, i, diff);
            update(m + 1, e, 2 * id + 2, i, diff);
        }
    }

    int querySum(int s, int e, int id, int qs, int qe)
    {
        if(qs <= s && qe >= e) {
            return d_st[id];
        }

        if(qs > e || qe < s)
            return 0;
        int m = s + (e - s) / 2;
        return querySum(s, m, 2 * id + 1, qs, qe) +
            querySum(m + 1, e, 2 * id + 2, qs, qe);
    }

  private:
    vector<int> d_nums;
    vector<int> d_st;  // segment tree
};
