#include "gtest/gtest.h"
#include "IncreasingSubseq.h"

TEST(IncreasingSubseq, IncreasingSubseq)
{
    IncreasingSubseq sol;
    vector<int> nums{4,6,7,7};
    vector<vector<int>> res = sol.findSubsequences(nums);
    //for(auto& v : res) {
        //for(auto d : v)
            //cout << d << ",";
        //cout << endl;
    //}
    EXPECT_EQ(8u, res.size());
}
