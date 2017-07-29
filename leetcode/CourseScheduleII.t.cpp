#include "gtest/gtest.h"
#include "CourseScheduleII.h"

TEST(CourseScheduleII, CourseScheduleII)
{
    CourseScheduleII sol;
    int n = 4;
    vector<pair<int,int>> p({{1, 0}, {2,0}, {3,1}, {3,2}});
    vector<int> orders = sol.findOrder(n, p);
    for(auto o : orders) {
        cout << o << ","<<endl;
    }
}
