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
        // state definition:
        // 0: dead -> dead
        // 1: live -> dead
        // 2: dead -> live
        // 3: live -> live
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int cnt = 0;
                for(int d = 0; d < dirs.size(); ++d) {
                    for(const auto& d : dirs) {
                        int x = i + d.first, y = j + d.second;
                        if(x >= 0 && y >= 0 && x < m && y < n &&
                           board[x][y] % 2)  // current live
                            ++cnt;
                    }
                    if(board[i][j]) {
                        if(cnt == 2 || cnt == 3)
                            board[i][j] = 3;
                    }
                    else {
                        if(cnt == 3)
                            board[i][j] = 2;
                    }
                }
            }
        }

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(board[i][j] == 1)
                    board[i][j] = 0;
                else if(board[i][j] == 2 || board[i][j] == 3)
                    board[i][j] = 1;
            }
        }
    }

  private:
};
