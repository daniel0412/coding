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
// vector solution
// O(n) add
// O(1) get
class SummaryRanges {
  public:
    /** Initialize your data structure here. */
    SummaryRanges() {}


    void addNum(int val)
    {
        auto comp = [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        };
        auto iter =
            lower_bound(d_vec.begin(), d_vec.end(), Interval(val, val), comp);
        if(iter != d_vec.begin() && (iter - 1)->end + 1 >= val)
            --iter;
        int start = val, end = val;
        while(iter != d_vec.end() && iter->start - 1 <= val &&
              iter->end + 1 >= val) {
            start = min(start, iter->start);
            end = max(end, iter->end);
            iter = d_vec.erase(iter);
        }
        d_vec.insert(iter, Interval(start, end));
    }

    vector<Interval> getIntervals() { return d_vec; }

  private:
    vector<Interval> d_vec;
};


// binary search tree solution using set
// O(log(n)) add
// O(n) get
class SummaryRanges {
  public:
    /** Initialize your data structure here. */
    SummaryRanges() {}

    void addNum(int val)
    {
        auto iter = d_set.lower_bound(Interval(val, val));
        if(iter != d_set.begin() && (--iter)->end + 1 < val)
            ++iter;
        int start = val, end = val;
        while(iter != d_set.end() && iter->start - 1 <= val &&
              iter->end + 1 >= val) {
            start = min(start, iter->start);
            end = max(end, iter->end);
            iter = d_set.erase(iter);
        }
        d_set.insert(iter, Interval(start, end));
    }

    vector<Interval> getIntervals()
    {
        vector<Interval> res;
        for(const auto& i : d_set) {
            res.emplace_back(i.start, i.end);
        }
        return res;
    }

  private:
    struct Comp {
        bool operator()(const Interval& a, const Interval& b)
        {
            return a.start < b.start;
        };
    };
    set<Interval, Comp> d_set;
};
