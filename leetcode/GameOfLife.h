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

class GameOfLife {
  public:
    void gameOfLife(vector<vector<int> >& board)
    {
        if(board.empty() || board[0].empty())
            return;
        int m = board.size(), n = board[0].size();
        vector<pair<int, int> > dirs = {
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0, -1},
            {0, 1},
            {1, -1},
            {1, 0},
            {1, 1},
        };
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int cnt = 0;
                for(int d = 0; d < dirs.size(); ++d) {
                    int x = i + dirs[d].first;
                    int y = j + dirs[d].second;
                    // ATTENTION: value of board is changed, but state 2 is
                    // changed from live cell, state 3 is changed from dead
                    // cell
                    if(x >= 0 && x < m && y >= 0 && y < n &&
                       (board[x][y] == 1 || board[x][y] == 2))
                        ++cnt;
                }
                if(board[i][j] && (cnt < 2 || cnt > 3))
                    board[i][j] = 2;
                else if(!board[i][j] && cnt == 3)
                    board[i][j] = 3;
            }
        }

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                board[i][j] = board[i][j] % 2;
            }
        }
    }

  private:
};
