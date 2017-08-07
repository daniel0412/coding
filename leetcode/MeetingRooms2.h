/* 253 Meeting Rooms II
 *
 * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
 *
 * For example,
 * Given [[0, 30],[5, 10],[15, 20]],
 * return 2.
 *
 */

#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval(int s, int e) : start(s), end(e) {}
};


class MeetingRooms2 {
  public:
    //int minMeetingRooms(vector<Interval>& intervals)
    //{
        //sort(intervals.begin(),
             //intervals.end(),
             //[](const Interval& a, const Interval& b) {
                 //return a.start < b.start;
             //});
        //priority_queue<int, vector<int>, greater<int>> q;
        //for(const auto& i : intervals) {
            //if(!q.empty() && q.top() <= i.start) q.pop();
            //q.push(i.end);
        //}
        //return q.size();
      //}
  //private:
    int minMeetingRooms(vector<Interval>& intervals)
    {
        sort(intervals.begin(),
             intervals.end(),
             [](const Interval& a, const Interval& b) {
                 return a.start < b.start;
             });
        priority_queue<int, vector<int>, greater<int>> q;
        for(const auto& i : intervals) {
            if(!q.empty() && q.top() <= i.start) q.pop();
            q.push(i.end);
        }
        return q.size();
    }
};
