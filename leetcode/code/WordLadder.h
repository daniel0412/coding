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

class WordLadder {
  public:
    int ladderLength(string beginWord,
                     string endWord,
                     vector<string>& wordList)
    {
        return doubleBfs(beginWord, endWord, wordList);
    }

  private:
    int doubleBfs(const string& beginword,
                  const string& endword,
                  vector<string>& wordlist)
    {
        unordered_set<string> dict(wordlist.begin(), wordlist.end());
        if(beginword.size() != endword.size() || dict.count(endword) == 0)
            return 0;
        if(beginword == endword)
            return 1;

        unordered_set<string> begins, ends;
        unordered_set<string>* pB = nullptr;
        unordered_set<string>* pE = nullptr;
        begins.insert(beginword);
        ends.insert(endword);
        dict.erase(beginword);
        dict.erase(endword);
        int length = 2;
        while(!begins.empty() && !ends.empty()) {
            if(begins.size() <= ends.size()) {
                pB = &begins;
                pE = &ends;
            }
            else {
                pB = &ends;
                pE = &begins;
            }
            unordered_set<string> temp;
            for(auto s : *pB) {
                for(int i = 0; i < s.size(); ++i) {
                    char curC = s[i];
                    for(char c = 'a'; c <= 'z'; ++c) {
                        if(s[i] != c) {
                            s[i] = c;
                            if(pE->find(s) != pE->end()) {
                                return length;
                            }
                            if(dict.count(s) > 0) {
                                temp.insert(s);
                                dict.erase(s);
                            }
                        }
                    }
                    s[i] = curC;
                }
            }
            ++length;
            swap(temp, *pB);
        }
        return 0;
    }

    // bfs
    int ladderLength(string beginWord,
                     string endWord,
                     vector<string>& wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_set<string> v;
        queue<string> q;
        q.push(beginWord);
        v.insert(beginWord);
        int steps = 1;
        while(!q.empty()) {
            ++steps;
            int len = q.size();
            for(size_t i = 0; i < len; ++i) {
                auto s = q.front();
                q.pop();
                for(size_t j = 0; j < s.size(); ++j) {
                    auto tmp = s;
                    for(char c = 'a'; c <= 'z'; ++c) {
                        if(s[j] == c)
                            continue;
                        tmp[j] = c;
                        if(dict.count(tmp) && !v.count(tmp)) {
                            if(tmp == endWord)
                                return steps;
                            v.insert(tmp);
                            q.push(tmp);
                        }
                        tmp[j] = s[j];
                    }
                }
            }
        }
        return 0;
    }
};
