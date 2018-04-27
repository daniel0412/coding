#include "gtest/gtest.h"
#include "MeetingRooms2.h"

TEST(MeetingRooms2, MeetingRooms2)
{
    MeetingRooms2 sol;
    vector<Interval> input;
    input.emplace_back(Interval(0, 3));
    input.emplace_back(Interval(11, 14));
    input.emplace_back(Interval(5, 10));
    EXPECT_EQ(1, sol.minMeetingRooms(input));

    input.emplace_back(Interval(12, 15));
    EXPECT_EQ(2, sol.minMeetingRooms(input));
}
