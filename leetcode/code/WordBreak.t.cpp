#include "gtest/gtest.h"
#include "WordBreak.h"

TEST(WordBreak, WordBreak)
{
    WordBreak sol;
    vector<string> wordDict = {"leet", "code"};
    string s("leetcode");
    EXPECT_TRUE(sol.wordBreak(s, wordDict));
}
