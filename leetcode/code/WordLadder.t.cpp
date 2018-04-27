#include "gtest/gtest.h"
#include "WordLadder.h"

TEST(WordLadder, WordLadder)
{
    WordLadder sol;
    string beginword = "hit";
    string endword = "cog";
    vector<string> wordlist({"hot", "dot", "dog", "lot", "log"});
    EXPECT_EQ(0, sol.ladderLength(beginword, endword, wordlist));
}
