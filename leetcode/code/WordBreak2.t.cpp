#include "gtest/gtest.h"
#include "WordBreak2.h"

TEST(WordBreak2, WordBreak2)
{
    WordBreak2 sol;
    vector<string> wordDict={"cat", "cats", "and", "sand", "dog"};
    string s = "catsanddog";
    vector<string> res = sol.wordBreak(s, wordDict);
    EXPECT_EQ(2, res.size());
}
