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

class MineSweeper {
  public:
    using vv = vector<vector<char> >;
    using vp = vector<pair<int, int> >;
    vector<vector<char> > updateBoard(vector<vector<char> >& board,
                                      vector<int>& click)
    {
        if(board.empty() || board[0].empty())
            return board;
        vp dirs = {{0, 1},
                   {1, 0},
                   {-1, 0},
                   {0, -1},
                   {1, 1},
                   {-1, -1},
                   {-1, 1},
                   {1, -1}};
        int i = click[0], j = click[1];
        if(board[i][j] == 'M') {
            board[i][j] = 'X';
        }
        else {
            dfs(board, i, j, dirs);
        }
        return board;
    }

    void dfs(vv& board, int i, int j, const vp& dirs)
    {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
           board[i][j] != 'E')
            return;
        int numMines = numAdjMines(board, i, j, dirs);
        if(numMines == 0) {
            board[i][j] = 'B';
            for(const auto& d : dirs) {
                dfs(board, i + d.first, j + d.second, dirs);
            }
        }
        else {
            string numStr = to_string(numMines);
            board[i][j] = numStr[0];
        }
    }

    int numAdjMines(const vv& board, int i, int j, const vp& dirs)
    {
        int cnt = 0;
        for(const auto& d : dirs) {
            int x = i + d.first;
            int y = j + d.second;
            if(x >= 0 && y >= 0 && x < board.size() && y < board[0].size() &&
               board[x][y] == 'M')
                ++cnt;
        }
        return cnt;
    }

  private:
};
