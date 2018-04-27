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

class QuickSort {
  public:
    void sort(vector<int>& v)
    {
        if(v.empty())
            return;
        quickSort(v, 0, v.size() - 1);
    }

    // return the index of the pivot
    // after this, [s, p-1] is less than pivoe, and [p+1, e] is greater than or
    // equal to pivot
    int partition(vector<int>& v, int s, int e)
    {
        // randomized pivot
        int n = e - s + 1;
        int p = rand() % n + s;
        swap(v[s], v[p]);
        p = s;
        int i = s + 1, j = e;
        while(i <= j) {
            // compare with pivot to make sure all value on the left of pivot
            // is smaller than pivot value
            if(v[i] < v[p]) {
                ++i;
            }
            else {
                swap(v[i], v[j--]);
            }
        }
        // put pivot value in the pivot position
        swap(v[p], v[i - 1]);
        return i - 1;
    }

    // standard quicksort with two recursive calls
    void quickSort(vector<int>& v, int s, int e)
    {
        if(s < e) {
            int p = partition(v, s, e);
            quickSort(v, s, p - 1);
            quickSort(v, p + 1, e);
        }
    }

    // tail optimization to reduce worst case O(n) stack space to O(log(n))
    void qs(vector<int>& v, int s, int e)
    {
        while(s < e) {
            int p = partition(v, s, e);
            if(p - s < e - p) {
                qs(v, s, p - 1);
                s = p + 1;
            }
            else {
                qs(v, p + 1, e);
                e = p - 1;
            }
        }
    }

  private:
};
