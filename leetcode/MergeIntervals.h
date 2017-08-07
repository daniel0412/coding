/* 56. Merge Intervals
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 */

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class MergeIntervals {
  public:
    vector<Interval> merge(vector<Interval>& intervals)
    {
        if(intervals.size() <= 1)
            return intervals;

        sort(intervals.begin(),
             intervals.end(),
             [](const Interval& a, const Interval& b) {
                 return a.start < b.start;
             });

        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i].start <= res.back().end) {
                res.back().end = max(res.back().end, intervals[i].end);
            }
            else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }

  private:
};
