#include "gtest/gtest.h"
#include "RemoveDuplicateLetter.h"

TEST(RemoveDuplicateLetter, RemoveDuplicateLetter)
{
    RemoveDuplicateLetter sol;
    string given = "bbcaac";
    string target = "bac";
    EXPECT_EQ(target, sol.removeDuplicateLetters(given));
}
