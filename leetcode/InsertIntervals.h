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
    //vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
    //{
        //vector<Interval> res;
        //int s, e;
        //bool started = false;
        //bool inserted = false;
        //for(int i = 0; i < intervals.size();) {
            //if(inserted || newInterval.start > intervals[i].end) {
                //res.push_back(intervals[i++]);
            //}
            //else {
                //if(newInterval.end < intervals[i].start) {
                    //res.push_back(newInterval);
                    //inserted = true;
                    //continue;
                //}
                //else {
                    //if(newInterval.start < intervals[i].start) {
                        //s = newInterval.start;
                    //}
                    //else if(newInterval.start >= intervals[i].start &&
                            //newInterval.start <= intervals[i].end) {
                        //s = intervals[i].start;
                    //}
                    //while(newInterval.end >= intervals[i].end) {
                        //if(i < intervals.size() - 1 &&
                           //newInterval.end >= intervals[i + 1].start) {
                            //++i;
                        //}
                        //else {
                            //break;
                        //}
                    //}
                    //e = intervals[i].end > newInterval.end ? intervals[i].end :
                                                             //newInterval.end;
                    //++i;
                    //res.push_back(Interval(s, e));
                    //inserted = true;
                //}
            //}
        //}
        //if(!inserted)
            //res.push_back(newInterval);
        //return res;
    //}

  //private:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        auto iter = intervals.begin();
        while(iter!=intervals.end()) {
            if(iter->end < newInterval.start) {
                res.emplace_back(*iter);
                ++iter;
            }else{
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
