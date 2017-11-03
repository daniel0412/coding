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

class FindKClosestElements {
  public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        if(k >= arr.size())
            return arr;

        auto iter = upper_bound(arr.begin(), arr.end(), x);
        if(iter == arr.end()) {
            return vector<int>(arr.end() - k, arr.end());
        }
        else if(iter == arr.begin()) {
            return vector<int>(arr.begin(), arr.begin() + k);
        }
        else {
            auto startIter = iter;
            auto endIter = iter;
            int cnt = 0;
            while(cnt < k) {
                ++cnt;
                if(startIter == arr.begin()) {
                    ++endIter;
                }
                else if(endIter == arr.end()) {
                    --startIter;
                }
                else {
                    if(x - *(startIter - 1) <= *endIter - x) {
                        --startIter;
                    }
                    else {
                        ++endIter;
                    }
                }
            }
            return vector<int>(startIter, endIter);
        }

      private:
    };
