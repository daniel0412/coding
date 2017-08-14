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

class CourseScheduleIII {
  public:
    int scheduleCourse(vector<vector<int> >& courses)
    {
        sort(courses.begin(),
             courses.end(),
             [](const vector<int>& c1, const vector<int>& c2) {
                 return c1[1] < c2[1];
             });
        priority_queue<int, vector<int>, less<int> > q;
        int curTime = 0;
        for(const auto& c : courses) {
            if(curTime + c[0] > c[1]) {
                if(!q.empty() && c[0] < q.top()) {
                    curTime = curTime - q.top() + c[0];
                    q.pop();
                    q.push(c[0]);
                }
            }
            else {
                curTime += c[0];
                q.push(c[0]);
            }
        }
        return q.size();
    }

  private:
};
