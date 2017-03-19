#include "gtest/gtest.h"
#include "MergeIntervals.h"

TEST(MergeIntervals, MergeIntervals) {
    MergeIntervals sol;
    vector<Interval> givenIntervals;
    givenIntervals.emplace_back(Interval(1,3));
    givenIntervals.emplace_back(Interval(8,10));
    givenIntervals.emplace_back(Interval(2,6));
    givenIntervals.emplace_back(Interval(15,18));
    vector<Interval> targetIntervals;
    targetIntervals.emplace_back(Interval(1,6));
    targetIntervals.emplace_back(Interval(8,10));
    targetIntervals.emplace_back(Interval(15,18));

    vector<Interval> resultIntervals = sol.merge(givenIntervals);
    ASSERT_EQ(resultIntervals.size(), targetIntervals.size());
    for(int i = 0; i < resultIntervals.size(); ++i) {
        EXPECT_EQ(resultIntervals[i].start, targetIntervals[i].start);
        EXPECT_EQ(resultIntervals[i].end, targetIntervals[i].end);
    }
}
