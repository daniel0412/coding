/* 4. Median of Two Sorted Arrays
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 */

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class MedianOfTwoSortedArray {
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int len1 = nums1.size(), len2 = nums2.size(), sum = len1 + len2;

        // mid: the mid-th smallest element of the combined array, not the
        // index
        int mid = sum / 2 + 1;

        // array size is odd, median is the middle one
        if(sum % 2)
            return findKth(nums1, 0, len1, nums2, 0, len2, mid);
        // array size is even, median is the average of the middle two numbers
        else
            return (findKth(nums1, 0, len1, nums2, 0, len2, mid) +
                    findKth(nums1, 0, len1, nums2, 0, len2, mid - 1)) /
                2;
    }

  private:
    double findKth(const vector<int>& nums1,
                   int start1,
                   int end1,
                   const vector<int>& nums2,
                   int start2,
                   int end2,
                   int k)
    {
        int len1 = end1 - start1, len2 = end2 - start2;
        if(len1 < len2)
            return findKth(nums2, start2, end2, nums1, start1, end1, k);
        if(len2 == 0)
            return nums1[start1 + k - 1];
        if(k == 1)
            return min(nums1[start1], nums2[start2]);

        // ATTENTION: each call only eliminate at most k/2 number
        // different from normal binary search
        int n1 = min(len1, k / 2), n2 = min(len2, k / 2);
        if(nums1[start1 + n1 - 1] < nums2[start2 + n2 - 1]) {
            return findKth(
                nums1, start1 + n1, end1, nums2, start2, end2, k - n1);
        }
        else {
            return findKth(
                nums1, start1, end1, nums2, start2 + n2, end2, k - n2);
        }
    }
};
