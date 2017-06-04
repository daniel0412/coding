#include "gtest/gtest.h"
#include "IncreasingSubseq.h"

TEST(IncreasingSubseq, IncreasingSubseq)
{
    IncreasingSubseq sol;
    vector<int> nums{4,6,7,7};
    vector<vector<int>> res = sol.findSubsequences(nums);
    EXPECT_EQ(8u, res.size());
}
