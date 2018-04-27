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

class RotateArray {
  public:
      void rotate(vector<int>& nums, int k) {
      }
  private:
    // store the last k elements, and move
    void impl1(vector<int>& nums, int k)
    {
        int n = nums.size();
        k = k % n;
        vector<int> tmp(k, 0);
        for(int i = 1; i <= k; ++i) {
            tmp[k - i] = nums[n - i];
        }
        for(int i = n - k - 1; i >= 0; --i) {
            nums[i + k] = nums[i];
        }
        for(int i = 0; i < k; ++i) {
            nums[i] = tmp[i];
        }
    }

    // double reverse, in place
    void impl2(vector<int>& nums, int k)
    {
        int n = nums.size();
        k %= n;
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }

    // rotate 1 a time, and keep doing this for k times
    // timeout
    void impl3(vector<int>& nums, int k)
    {
        int n = nums.size();
        k %= n;
        int i = 0;
        while(i++ < k) {
            int t = nums.back();
            for(int i = n - 1; i > 0; --i) {
                nums[i] = nums[i - 1];
            }
            nums[0] = t;
        }
    }
};
