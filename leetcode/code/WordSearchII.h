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

class WordSearchII {
  public:
    using MapOfSet = unordered_map<string, unordered_set<string> >;
    vector<string> findWords(vector<vector<char> >& board,
                             vector<string>& words)
    {
        MapOfSet m;
        buildMap(words, m);
        string path;
        unordered_set<string> res;
        vector<pair<int, int> > dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for(int i = 0; i < (int) board.size(); ++i) {
            for(int j = 0; j < (int) board[0].size(); ++j) {
                dfs(board, m, i, j, path, res, dirs);
            }
        }
        return vector<string>{res.begin(), res.end()};
    }

    // use a prefix map instead of a prefix tree to check if word starting with
    // such prefix exist
    // prefix -> word
    void buildMap(const vector<string>& words, MapOfSet& m)
    {
        for(const auto& w : words) {
            for(size_t i = 0; i < w.size(); ++i) {
                m[w.substr(0, i + 1)].insert(w);
            }
        }
    }

    void dfs(vector<vector<char> >& board,
             const MapOfSet& m,
             int r,
             int c,
             string& path,
             unordered_set<string>& res,
             const vector<pair<int, int> >& dirs)
    {
        if(r < 0 || r >= (int) board.size() || c < 0 ||
           c >= (int) board[0].size() || board[r][c] == '0') {
            return;
        }
        path.push_back(board[r][c]);
        auto iter = m.find(path);
        if(iter != m.end()) {
            if(iter->second.find(path) != iter->second.end()) {
                res.insert(path);
            }
        }
        else {
            path.pop_back();
            return;
        }

        board[r][c] = '0';
        for(const auto& d : dirs) {
            dfs(board, m, r + d.first, c + d.second, path, res, dirs);
        }
        board[r][c] = path.back();
        path.pop_back();
    }


    // following is a trie based implementation

    // TrieNode declaration
    struct TrieNode {
        // ATTENTION, we can initilize vector data member like this
        TrieNode() : _isword(false), _next(26, nullptr) {}
        // indicate up to now, if a word is formed
        bool _isword;
        vector<TrieNode*> _next;
    };

    vector<string> findWords(vector<vector<char> >& board,
                             vector<string>& words)
    {
        TrieNode* root = new TrieNode();
        buildTrie(root, words);
        string path;
        unordered_set<string> res;
        vector<pair<int, int> > dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        for(int i = 0; i < (int) board.size(); ++i) {
            for(int j = 0; j < (int) board[0].size(); ++j) {
                dfs(board, root, i, j, path, res, dirs);
            }
        }
        return vector<string>{res.begin(), res.end()};
    }
    void insertWord(TrieNode* root, const string& w)
    {
        TrieNode* cur = root;
        for(const auto& c : w) {
            size_t id = c - 'a';
            if(cur->_next[id] == nullptr) {
                cur->_next[id] = new TrieNode();
            }
            cur = cur->_next[id];
        }
        cur->_isword = true;
    }

    void buildTrie(TrieNode* root, const vector<string>& words)
    {
        for(const auto& w : words) {
            insertWord(root, w);
        }
    }


    void dfs(vector<vector<char> >& board,
             TrieNode* cur,
             int r,
             int c,
             string& path,
             unordered_set<string>& res,
             const vector<pair<int, int> >& dirs)
    {
        if(r < 0 || r >= (int) board.size() || c < 0 ||
           c >= (int) board[0].size() || board[r][c] == '0') {
            return;
        }
        path.push_back(board[r][c]);
        size_t id = board[r][c] - 'a';
        if(cur->_next[id] == nullptr) {
            path.pop_back();
            return;
        }
        cur = cur->_next[id];
        if(cur->_isword) {
            res.emplace(path);
        }

        board[r][c] = '0';
        for(const auto& d : dirs) {
            dfs(board, cur, r + d.first, c + d.second, path, res, dirs);
        }
        board[r][c] = path.back();
        path.pop_back();
    }


  private:
};
