/*
 *
 */

#include <string>
#include <vector>
#include <list>
#include <stack>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <functional>
#include <algorithm>
#include <utility>
#include "utils.h"

using namespace std;

class SurroundedRegion {
  public:
    void solve(vector<vector<char> >& board)
    {
        // mark O cell that can reach edge
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(i == 0 || j == 0 || i == board.size() - 1 ||
                   j == board[0].size() - 1) {
                    dfs(board, i, j);
                }
            }
        }

        // cell stays as O is non reachable from edge, should be marked as X
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'Y')
                    board[i][j] = 'O';
            }
        }
    }

  private:
    void dfs(vector<vector<char> >& board, int i, int j)
    {
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
           board[i][j] != 'O')
            return;
        board[i][j] = 'Y';
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }
};
