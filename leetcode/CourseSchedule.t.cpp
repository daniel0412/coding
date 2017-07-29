#include "gtest/gtest.h"
#include "CourseSchedule.h"

TEST(CourseSchedule, CourseSchedule)
{
    CourseSchedule sol;
    vector<pair<int,int>> p;
    p.push_back({3,0});
    p.push_back({0,1});
    int numCourses = 4;
    ASSERT_TRUE(sol.canFinish(numCourses, p));
}
