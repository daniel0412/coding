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

class TicTacToe {
  public:
    TicTacToe(int n)
        : d_n(n), d_rows(n, 0), d_cols(n, 0), d_diag(0), d_antidiag(0){};

    int move(int row, int col, int player)
    {
        int cnt = player == 1 ? 1 : -1;
        d_rows[row] += cnt;
        d_cols[col] += cnt;
        if(row + col == d_n - 1) {
            d_antidiag += cnt;
        }
        if(row == col) {
            d_diag += cnt;
        }
        if(abs(d_rows[row]) == d_n || abs(d_cols[col]) == d_n ||
           abs(d_diag) == d_n || abs(d_antidiag) == n) {
            return player;
        }
        return 0;
    }

  private:
    vector<int> d_rows;
    vector<int> d_cols;
    int d_diag;
    int d_antidiag;
    int d_n;
};
