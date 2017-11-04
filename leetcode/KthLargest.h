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

class KthLargest {
  public:
    int findKthLargest(vector<int>& nums, int k)
    {
        if(nums.size() < k || k < 1 || nums.size() == 0)
            return -1;
         return recursiveImpl(nums, 0, nums.size() - 1, k);

    }

  private:
    int recursiveImpl(vector<int>& nums, int start, int end, int k)
    {

        int p = start;
        for(int i = start; i < end; ++i) {
            if(nums[i] < nums[end]) {
                if(i != p) {
                    swap(nums[i], nums[p]);
                }
                ++p;
            }
        }
        swap(nums[p], nums[end]);

        int numLeft = end - p + 1;
        if(numLeft == k)
            return nums[p];
        else if(numLeft > k) {
            return recursiveImpl(nums, p + 1, end, k);
        }
        else {
            return recursiveImpl(nums, start, p - 1, k - numLeft);
        }
    }

    int iterativeImpl(vector<int>& nums, int k)
    {
        int left = 0, right = nums.size() - 1;
        int p = 0;
        while(left <= right) {
            p = partition(nums, left, right);
            int numGreater = right - p + 1;
            if(numGreater == k)
                break;
            else if(numGreater < k) {
                right = p - 1;
                k = k - numGreater;
            }
            else {
                left = p + 1;
            }
        }
        return nums[p];
    }

    int partition(vector<int>& nums, int start, int end)
    {
        int p = end;
        int j = start;
        for(int i = start; i < end; ++i) {
            if(nums[i] < nums[p]) {
                if(nums[i] != nums[j]) {
                    swap(nums[j], nums[i]);
                }
                ++j;
            }
        }
        swap(nums[j], nums[end]);
        return j;
    }

    // quick sort implementation practice
    void quickSort(vector<int>& nums, int left, int right)
    {
        if(left < right) {
            int p = partition(nums, left, right);
            quickSort(nums, left, p - 1);
            quickSort(nums, p + 1, right);
        }
    }


};
