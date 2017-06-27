#include "gtest/gtest.h"
#include "WordLadder.h"

TEST(WordLadder, WordLadder)
{
    WordLadder sol;
    string beginword = "hit";
    string endword = "cog";
    vector<string> wordlist({"hot", "dot", "dog", "lot", "log", "cog"});
    EXPECT_EQ(5, sol.ladderLength(beginword, endword, wordlist));
}
