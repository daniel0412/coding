#include "gtest/gtest.h"
#include "SmallNumberAfterSelf.h"

TEST(SmallNumberAfterSelf, SmallNumberAfterSelf)
{
    SmallNumberAfterSelf sol;
    vector<int> given{26, 78, 27, 100, 33, 67, 90, 23, 66, 5,  38,  7,  35, 23,
                      52, 22, 83, 51,  98, 69, 81, 32, 78, 28, 94,  13, 2,  97,
                      3,  76, 99, 51,  9,  21, 84, 66, 65, 36, 100, 41};
    vector<int> expected{10, 27, 10, 35, 12, 22, 28, 8, 19, 2, 12, 2, 9, 6,
                         12, 5,  17, 9,  19, 12, 14, 6, 12, 5, 12, 3, 0, 10,
                         0,  7,  8,  4,  0,  0,  4,  3, 2,  0, 1,  0};

    vector<int> target = sol.countSmall(given);
    ASSERT_EQ(target.size(), expected.size());
    for(int i = 0; i < target.size(); ++i) {
        EXPECT_EQ(target[i], expected[i]);
    }
}
