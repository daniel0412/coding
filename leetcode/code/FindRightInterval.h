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

class FindRightInterval {
  public:
    vector<int> findRightInterval(vector<Interval>& intervals)
    {
        vector<pair<int, int> > startIndexVec;
        for(int i = 0; i < intervals.size(); ++i) {
            startIndexVec.emplace_back(pair<int,int>({intervals[i].start, i}));
        }
        sort(startIndexVec.begin(),
             startIndexVec.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first < b.first;
             });
        vector<int> res(intervals.size(), -1);
        for(int i = 0; i < intervals.size(); ++i) {
            res[i] = lowerbound(startIndexVec, intervals[i].end);
        }
        return res;
    }

  private:
    int lowerbound(const vector<pair<int, int> >& startIndexVec, const int x)
    {
        int start = 0, end = startIndexVec.size() - 1;
        if(x > startIndexVec[end].first)
            return -1;
        if(x == startIndexVec.back().first)
            return startIndexVec.back().second;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(startIndexVec[mid].first < x) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return startIndexVec[start].second;
    }
};
