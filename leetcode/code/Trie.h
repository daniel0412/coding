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
class Trie {
  public:
    struct TrieNode {
        bool _isWord;
        vector<TrieNode*> _next;
        TrieNode() : _isWord(false), _next(26, nullptr) {}
    };

    /** Initialize your data structure here. */
    Trie() { _root = new TrieNode(); }
    ~Trie() { release(_root); }
    void release(TrieNode* curNode)
    {
        if(curNode == nullptr)
            return;
        for(auto p : curNode->_next) {
            release(p);
        }
        delete curNode;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode* curNode = _root;
        for(auto c : word) {
            size_t id = c - 'a';
            if(curNode->_next[id] == nullptr) {
                curNode->_next[id] = new TrieNode();
            }
            curNode = curNode->_next[id];
        }
        curNode->_isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode* curNode = _root;
        for(auto c : word) {
            size_t id = c - 'a';
            if(curNode->_next[id] == nullptr)
                return false;
            curNode = curNode->_next[id];
        }
        return curNode->_isWord;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix)
    {
        TrieNode* curNode = _root;
        for(auto c : prefix) {
            size_t id = c - 'a';
            if(curNode->_next[id] == nullptr)
                return false;
            curNode = curNode->_next[id];
        }
        return true;
    }

  private:
    TrieNode* _root;
};
