/*  425 Word Squares
 *
 * Given a set of words (without duplicates), find all word squares you can
 *build from them.
 *
 * A sequence of words forms a valid word square if the kth row and column read
 * the exact same string, where 0 ≤ k < max(numRows, numColumns).
 *
 * Note:
 *
 * There are at least 1 and at most 1000 words.
 * All words will have the exact same length.
 * Word length is at least 1 and at most 5.
 * Each word contains only lowercase English alphabet a-z.
 */

#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>

using namespace std;

struct TrieNode {
    bool isWord;
    vector<TrieNode*> next;
    TrieNode() : isWord(false), next(vector<TrieNode*>(26, nullptr)) {}
};


class Trie {
  public:
    Trie() { d_root = new TrieNode(); }

    void buildTrie(const vector<string>& data)
    {
        for(const auto& word : data) {
            TrieNode* curNode = d_root;
            for(const auto c : word) {
                size_t idx = c - 'a';
                if(curNode->next[idx] == nullptr) {
                    curNode->next[idx] = new TrieNode();
                }
                curNode = curNode->next[idx];
            }
            curNode->isWord = true;
        }
    }

    void findAllWordsWithPrefix(unordered_set<string>& words,
                                const vector<char>& prefix)
    {
        TrieNode* curNode = d_root;
        string path("");
        for(auto c : prefix) {
            size_t idx = c - 'a';
            if(curNode->next[idx] == nullptr)
                return;
            path.push_back(c);
            curNode = curNode->next[idx];
        }

        vector<string> subWords;
        string subPath("");
        getAllWordsWithGivenRoot(subWords, curNode, subPath);
        for(const auto& w : subWords) {
            words.insert(path + w);
        }
    }

    void getAllWordsInTrie(vector<string>& words)
    {
        string path("");
        getAllWordsWithGivenRoot(words, d_root, path);
    }

    void printWordsInTrie()
    {
        cout << "++++++++++ words in trie +++++++++" << endl;
        vector<string> allWords;
        getAllWordsInTrie(allWords);
        for(const auto& w : allWords) {
            cout << w << "|";
        }
        cout << endl;
        cout << "++++++++++++++++++++++++++++++++++" << endl;
    }

  private:
    void getAllWordsWithGivenRoot(vector<string>& words,
                                  TrieNode* root,
                                  string& path)
    {
        if(root == nullptr)
            return;
        if(root->isWord)
            words.push_back(path);
        for(int i = 0; i < root->next.size(); ++i) {
            if(root->next[i] != nullptr) {
                path.push_back(i + 'a');
                getAllWordsWithGivenRoot(words, root->next[i], path);
                path.pop_back();
            }
        }
    }
    TrieNode* d_root;
};

class WordSquares {
  public:
    vector<vector<string> > wordSquares(vector<string>& words)
    {
        vector<vector<string> > res;
        vector<string> path;
        d_trie.buildTrie(words);
        dfs(res, path, 0, unordered_set<string>(words.begin(), words.end()));
        return res;
    }

  private:
    void dfs(vector<vector<string> >& res,
             vector<string>& path,
             int id,
             unordered_set<string> candidates)
    {
        if(path.size() > 0) {
            if(id == path[0].size()) {
                res.push_back(path);
                return;
            }
            else if(candidates.empty()) {
                return;
            }
        }
        for(const auto& w : candidates) {
            vector<char> prefix;
            unordered_set<string> nextLevelCandidates;
            path.push_back(w);
            getNextLevelCandidates(path, nextLevelCandidates);
            dfs(res, path, id + 1, nextLevelCandidates);
            path.pop_back();
        }
    }

    void getNextLevelCandidates(const vector<string>& path,
                                unordered_set<string>& candidates)
    {
        int numChars = path.size();
        vector<char> prefix;
        for(const auto& w : path) {
            prefix.push_back(w[numChars]);
        }
        d_trie.findAllWordsWithPrefix(candidates, prefix);
        // following code disallow use the same word twice
        // for(const auto& w : path) {
        // if(candidates.count(w) > 0) candidates.erase(w);
        //}
    }

    Trie d_trie;
};
