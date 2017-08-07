/* 252 Meeting Room
 *
 * Given an array of meeting time intervals consisting of start and end times
 *[[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all
 *meetings.
 *
 * For example,
 * Given [[0, 30],[5, 10],[15, 20]],
 * return false.
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

class MeetingRooms {
  public:
    //bool canAttendMeetings(vector<Interval>& intervals)
    //{
        //auto cmp = [](const Interval& a, const Interval& b) {
            //return a.start < b.start;
        //};
        //sort(intervals.begin(), intervals.end(), cmp);
        //for(int i = 1; i < intervals.size(); ++i) {
            //if(intervals[i].start < intervals[i - 1].end)
                //return false;
        //}
        //return true;
    //}

  //private:
    bool canAttendMeetings(vector<Interval>& intervals)
    {
        sort(intervals.begin(),
             intervals.end(),
             [](const Interval& a, const Interval& b) {
                 return a.start < b.start;
             });
        for(size_t i = 1; i < intervals.size(); ++i) {
            if(intervals[i - 1].end > intervals[i].start)
                return false;
        }
        return true;
    }
};
