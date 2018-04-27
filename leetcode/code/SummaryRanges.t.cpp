#include "gtest/gtest.h"
#include "SummaryRanges.h"

TEST(SummaryRanges, SummaryRanges)
{
    SummaryRanges sol;
    vector<int> vec{0, 1, 2, 4, 5, 7};
    vector<string> res = sol.summaryRanges(vec);
    vector<string> target{"0->2", "4->5", "7"};
    ASSERT_EQ(res.size(), target.size());
    for(int i = 0; i < res.size(); ++i) {
        EXPECT_EQ(res[i], target[i]);
    }

    vector<int> vec1{0, 1, 2, 4, 5, 7, 8};
    vector<string> res1 = sol.summaryRanges(vec1);
    vector<string> target1{"0->2", "4->5", "7->8"};
    ASSERT_EQ(res1.size(), target1.size());
    for(int i = 0; i < res1.size(); ++i) {
        EXPECT_EQ(res1[i], target1[i]);
    }
}
