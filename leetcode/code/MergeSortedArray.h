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

class MergeSortedArray {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = m + n - 1, i1 = m - 1, i2 = n - 1;
        while(i1 >= 0 && i2 >= 0) {
            if(nums1[i1] >= nums2[i2]) {
                nums1[i--] = nums1[i1--];
            }
            else {
                nums1[i--] = nums2[i2--];
            }
        }
        while(i1 >= 0) {
            nums1[i--] = nums1[i1--];
        }
        while(i2 >= 0) {
            nums1[i--] = nums2[i2--];
        }
    }

  private:
};
