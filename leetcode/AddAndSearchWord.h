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

class WordDictionary {
  public:
    struct TrieNode {
        bool _isWord;
        vector<TrieNode*> _next;
        TrieNode() : _isWord(false), _next(26, nullptr) {}
    };
    /** Initialize your data structure here. */
    WordDictionary() { _root = new TrieNode(); }

    /** Adds a word into the data structure. */
    void addWord(string word)
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

    bool search(string word) { return searchImpl(word, 0, _root); }

    /** Returns if the word is in the data structure. A word could contain the
        * dot character '.' to represent any one letter. */
    bool searchImpl(const string& word, size_t i, TrieNode* curNode)
    {
        if(i == word.size())
            return curNode && curNode->_isWord;
        if(word[i] == '.') {
            for(auto p : curNode->_next) {
                if(p && searchImpl(word, i + 1, p)) {
                    return true;
                }
            }
            return false;
        }
        else {
            size_t id = word[i] - 'a';
            if(curNode->_next[id] == nullptr)
                return false;
            return searchImpl(word, i + 1, curNode->_next[id]);
        }
    }
    /** Returns if the word is in the data structure. A word could contain the
        * dot character '*' to represent any string, including empty string. */
    bool searchImpl2(const string& word, size_t i, TrieNode* curNode)
    {
        if(i == word.size())
            return curNode && curNode->_isWord;
        if(word[i] == '*') {
            // if this is the last '*' in the pattern
            if(i + 1 == word.size())
                return true;

            // check next character with up-to-now prefix
            for(auto p : curNode->_next) {
                // current '*' matches nothing, need to check next char in
                // pattern matches to move on
                if(p && (word[i + 1] == '.' || word[i + 1] == '*' ||
                         p->_next[word[i + 1] - 'a']) &&
                   searchImpl2(word, i + 1, p)) {
                    return true;
                }

                // current '*' match more than more char
                if(p && searchImpl2(word, i + 1, p))
                    return true;
            }
            return false;
        }
        else if(word[i] == '.') {
            for(auto p : curNode->_next) {
                if(p && searchImpl2(word, i + 1, p)) {
                    return true;
                }
                return false;
            }
        }
        else {
            size_t id = word[i] - 'a';
            if(curNode->_next[id] == nullptr) {
                return false;
            }
            return searchImpl2(word, i + 1, curNode->_next[id]);
        }
    }
    TrieNode* _root;
};
