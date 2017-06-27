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
    int doubleBfs(
            const string& beginword,
            const string& endword,
            vector<string>& wordlist
            )
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
            }else{
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
                    s[i]=curC;
                }
            }
            ++length;
            swap(temp, *pB);
        }
        return 0;
    }

    int bfs(const string& beginword,
             const string& endword,
             const vector<string>& wordlist)
    {
        unordered_set<string> dict(wordlist.begin(), wordlist.end());
        if(beginword.size() != endword.size() || dict.count(endword) == 0)
            return 0;
        if(beginword == endword)
            return 0;

        // reuse dict rather than 'visited' can avoid timeout
        //unordered_set<string> visited;
        queue<string> q;
        q.push(beginword);
        q.push("*");
        //visited.insert(beginword);
        dict.erase(beginword);
        int length = 1;
        while(!q.empty()) {
            string tmp = q.front();
            q.pop();
            // ***** make sure only when q is not empyt, we push '*', otherwise, never ends
            if(tmp == "*" && !q.empty()) {
                ++length;
                // ******* important where to push '*'
                q.push("*");
                continue;
            }
            else if(tmp == endword) {
                return length;
            }
            else {
                for(int i = 0; i < tmp.size(); ++i) {
                    char curC = tmp[i];
                    for(char c = 'a'; c <= 'z'; ++c) {
                        tmp[i] = c;
                        //if(visited.count(tmp) == 0 && dict.count(tmp) > 0) {
                        if( dict.count(tmp) > 0) {
                            //visited.insert(tmp);
                            dict.erase(tmp);
                            q.push(tmp);
                            cout << tmp << " ";
                        }
                    }
                    tmp[i] = curC;
                }
            }
        }
        return 0;
    }
};
