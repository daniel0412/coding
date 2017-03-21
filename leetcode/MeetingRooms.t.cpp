#include "gtest/gtest.h"
#include "MeetingRooms.h"

TEST(MeetingRooms, MeetingRooms)
{
    MeetingRooms sol;
    vector<Interval> input;
    input.emplace_back(Interval(0, 3));
    input.emplace_back(Interval(5, 10));
    input.emplace_back(Interval(11, 14));
    EXPECT_TRUE(sol.canAttendMeetings(input));

    input.emplace_back(Interval(12, 15));
    EXPECT_FALSE(sol.canAttendMeetings(input));
}
