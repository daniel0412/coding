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

class NonOverlappingInterval {
  public:
    int eraseOverlapIntervals(vector<Interval>& intervals)
    {
        sort(intervals.begin(),
             intervals.end(),
             [](const Interval& a, const Interval& b) {
                 return a.start < b.start;
             });
        int res = 0, last = 0;
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i].start < intervals[last].end) {
                ++res;
                last = intervals[i].end > intervals[last].end ? last : i;
            }
            else {
                last = i;
            }
        }
        return res;
    }

  private:
};
