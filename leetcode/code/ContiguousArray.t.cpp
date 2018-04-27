#include "gtest/gtest.h"
#include "ContiguousArray.h"

TEST(ContiguousArray, ContiguousArray)
{
    ContiguousArray sol;
    vector<int> nums{0, 1, 0};
    ASSERT_EQ(2, sol.findMaxLength(nums));
}
