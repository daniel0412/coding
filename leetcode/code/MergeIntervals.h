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
        int start = intervals[0].start, end = intervals[0].end;
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i].start <= end) {
                // ATTENTION: here pick the largest 'end'
                end = max(end, intervals[i].end);
            }
            else {
                res.emplace_back(start, end);
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        // here to take care of the last interval
        res.emplace_back(start, end);
        return res;
    }

  private:
};
