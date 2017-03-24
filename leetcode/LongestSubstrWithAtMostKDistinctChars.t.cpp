#include "gtest/gtest.h"
#include "LongestSubstrWithAtMostKDistinctChars.h"

TEST(LongestSubstrWithAtMostKDistinctChars,
     LongestSubstrWithAtMostKDistinctChars)
{
    LongestSubstrWithAtMostKDistinctChars sol;
    EXPECT_EQ(3, sol.lengthOfLongestSubstringKDistinct("eceba", 2));
}
