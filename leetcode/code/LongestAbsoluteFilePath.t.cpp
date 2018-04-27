#include "gtest/gtest.h"
#include "LongestAbsoluteFilePath.h"

TEST(LongestAbsoluteFilePath, LongestAbsoluteFilePath)
{
    LongestAbsoluteFilePath sol;
    EXPECT_EQ(10, sol.lengthLongestPath("a\n\taa\n\t\ta.ext\n\taaaaaaa."));
    EXPECT_EQ(13, sol.lengthLongestPath("a\n\taa\n\t\ta.ext\n\taaaaaaa.ext"));
    EXPECT_EQ(0, sol.lengthLongestPath("a\n\taa\n\t\ta.\n\taaaaaaa."));
}
