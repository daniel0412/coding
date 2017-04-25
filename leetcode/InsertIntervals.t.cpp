#include "gtest/gtest.h"
#include "InsertIntervals.h"

TEST(InsertIntervals, InsertIntervals)
{
    InsertIntervals sol;
    vector<Interval> given;
    given.push_back(Interval(1, 2));
    given.push_back(Interval(3, 5));
    given.push_back(Interval(6, 7));
    given.push_back(Interval(8, 10));
    given.push_back(Interval(12, 16));
    vector<Interval> res = sol.insert(given, Interval(4, 9));
    EXPECT_EQ(3, res.size());
}

TEST(InsertIntervals, InsertIntervals1)
{
    InsertIntervals sol;
    vector<Interval> given;
    vector<Interval> res = sol.insert(given, Interval(4, 9));
    EXPECT_EQ(1, res.size());
    EXPECT_EQ(res[0].start ,4);
    EXPECT_EQ(res[0].end ,9);
}
