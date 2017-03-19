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

        vector<Interval> res;
        auto cmp = [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        };
        sort(intervals.begin(), intervals.end(), cmp);
        Interval tmp(intervals[0].start, intervals[0].end);
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i].start <= tmp.end) {
                tmp.end = max(tmp.end, intervals[i].end);
            }
            else {
                res.push_back(tmp);
                tmp.start = intervals[i].start;
                tmp.end = intervals[i].end;
            }
        }
        res.push_back(tmp);
        return res;
    }

  private:
};
