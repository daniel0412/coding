#include "gtest/gtest.h"
#include "LongestConsecutiveSeq.h"

TEST(LongestConsecutiveSeq, LongestConsecutiveSeq)
{
    LongestConsecutiveSeq sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    ASSERT_EQ(4, sol.longestConsecutive(nums));
}
