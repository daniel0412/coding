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

class WordSearch {
  public:
    bool exist(vector<vector<char> >& board, string word)
    {
        bool found = false;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                recursiveImpl(board, i, j, word, 0, found);
                if(found) {
                    return true;
                }
            }
        }
        return false;
    }

  private:
    void recursiveImpl(vector<vector<char> >& board,
                       int r,
                       int c,
                       const string& word,
                       int pos,
                       bool& found)
    {
        if(found || r < 0 || c < 0 || r >= board.size() ||
           c >= board[0].size() || board[r][c] == '0') {
            return;
        }

        if(board[r][c] != word[pos]) {
            return;
        }
        else {
            if(pos + 1 == word.size()) {
                found = true;
                return;
            }
            else {
                char tmp = board[r][c];
                board[r][c] = '0';
                recursiveImpl(board, r - 1, c, word, pos + 1, found);
                recursiveImpl(board, r + 1, c, word, pos + 1, found);
                recursiveImpl(board, r, c - 1, word, pos + 1, found);
                recursiveImpl(board, r, c + 1, word, pos + 1, found);
                board[r][c] = tmp;
            }
        }
    }
};
