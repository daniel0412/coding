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

class BinaryIndexedTree {
  public:
    BinaryIndexedTree(vector<int> nums)
        : d_nums(nums.size(), 0), d_tree(nums.size() + 1, 0)
    {
        // initialize d_nums, and d_tree
        for(int i = 0; i < nums.size(); ++i) {
            d_nums[i] = nums[i];
            d_tree[i+1] = nums[i];
        }
        // for each element in d_tree, if its value gets accumulated in any parent, should add it into parent bucket
        for(int i = 1; i < d_tree.size(); ++i) {
            // get lowbit of i
            int lowbit = i & ( i ^ (i-1));
            // find parent id
            int parentId = i + lowbit;
            // accumulate if within size
            if( parentId < d_tree.size()) {
                d_tree[parentId] += d_tree[i];
            }
        }
    }

    int getRangeSum(int i, int j) {
        if(i > j) return getRangeSum(j, i);
        // ATTENTION: here should be i-1
        return getSum(j) - getSum(i-1);
    }

    void update(int i, int val) {
        // get the change diff
        int diff = val - d_nums[i];
        d_nums[i] = val;
        // offset handling
        ++i;
        // update all the way up to all the parents
        while(i < d_tree.size()) {
            d_tree[i] += diff;
            // calculate lowbit
            lowbit = i & (i ^ (i-1));
            // get the parent, whoes value include the updated value
            i = i + lowbit;
        }
    }

    int getSum(int i) {
        int sum = 0, lowbit = 0;
        // offset handling
        ++i;
        // accumulate all the children subranges
        while(i > 0) {
            sum += d_tree[i];
            // get lowbit
            lowbit = i & (i ^ (i-1));
            // get previous range sum index
            i = i - lowbit;
        }
        return sum;

    }

  private:
      vector<int> d_nums;
      vector<int> d_tree;
};
