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

class MergeSort {
  public:
      void sort(vector<int>& v) {
          if(v.empty()) return;
          int s = 0, e = v.size()-1;
          mergeSort(v, s, e);
      }

      void mergeSort(vector<int>& v, int s, int e)
      {
          if(s < e) {
              int m = s + (e - s) / 2;
              mergeSort(v, s, m);
              mergeSort(v, m + 1, e);
              merge(v, s, m, e);
          }
      }

      void merge(vector<int>& v, int s, int m, int e) {
          int i = s, j = m+1, k = 0;
          vector<int> res(e-s+1, 0);
          while(i <= m && j <= e) {
              // here = indicates stable sorting
              if(v[i] <= v[j]) {
                  res[k] = v[i++];
              }else {
                  res[k] = v[j++];
              }
              ++k;
          }
          while(i <= m) {
              res[k++] = v[i++];
          }
          while(j <= e) {
              res[k++] = v[j++];
          }
          copy(res.begin(), res.end(), v.begin() + s);
      }
  private:
};
