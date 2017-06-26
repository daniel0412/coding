#include "gtest/gtest.h"
#include "WordSearch.h"

TEST(WordSearch, WordSearch)
{
    WordSearch sol;
    vector<vector<char> > board;
    board.push_back(vector<char>({'A', 'B', 'C', 'E'}));
    board.push_back(vector<char>({'S', 'F', 'C', 'S'}));
    board.push_back(vector<char>({'A', 'D', 'E', 'E'}));
    EXPECT_TRUE(sol.exist(board, "ABCCED"));
    EXPECT_TRUE(sol.exist(board, "SEE"));
    EXPECT_FALSE(sol.exist(board, "ABCB"));
}
