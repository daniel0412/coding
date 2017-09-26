/* 57. Insert Interval
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 *intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their
 *start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as
 *[1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */

#include <string>
#include <vector>
#include <list>
#include <stack>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <algorithm>
#include <utility>
#include "utils.h"

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class InsertIntervals {
  public:

      // easy to understand
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
    {
        if(intervals.emtpy() || intervals.back().end < newInterval.start) {
            intervals.emplace_back(newInterval);
            return intervals;
        }
        if(intervals.front().start < newInterval.end) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        vector<Interval> res;
        bool inserted = false;
        for(auto& i : intervals) {
            if(!inserted) {
                if(newInterval.start <= intervals[i].start) {
                    if(!res.empty() && res.back().end >= newInterval.start) {
                        res.back().end = max(res.back().end, newInterval.end);
                    }
                    else {
                        res.emplace_back(newInterval);
                    }
                    inserted = true;
                }
            }
            if(!res.empty() && res.back().end >= intervals[i].start) {
                res.back().end = max(res.back().end, intervals[i].end);
            }
            else {
                res.emplace_back(intervals[i]);
            }
        }
        // deal with case that newInterval is not merged yet
        if(!inserted) {
            if(res.back().end >= newInterval.start) {
                res.back().end = max(res.back().end, newInterval.end);
            }
            else {
                res.emplace_back(newInterval);
            }
        }
        return res;
    }
    // private:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
    {
        vector<Interval> res;
        auto iter = intervals.begin();
        while(iter != intervals.end()) {
            if(iter->end < newInterval.start) {
                res.emplace_back(*iter);
                ++iter;
            }
            else {
                break;
            }
        }
        if(iter == intervals.end()) {
            res.emplace_back(newInterval);
            return res;
        }
        if(newInterval.end < iter->start) {
            res.emplace_back(newInterval);
            res.insert(res.end(), iter, intervals.end());
        }
        else {
            res.emplace_back(min(iter->start, newInterval.start),
                             max(iter->end, newInterval.end));
            while(++iter != intervals.end()) {
                if(iter->start <= res.back().end) {
                    res.back().end = max(res.back().end, iter->end);
                }
                else {
                    res.emplace_back(*iter);
                }
            }
        }
        return res;
    }

};
