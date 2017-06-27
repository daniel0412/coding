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
        return impl(beginWord, endWord, wordList);
    }

  private:
    int impl(const string& beginword,
             const string& endword,
             const vector<string>& wordlist)
    {
        if(beginword.size() != endword.size())
            return 0;
        if(beginword == endword)
            return 0;
        unordered_set<string> dict(wordlist.begin(), wordlist.end());

        unordered_set<string> visited;
        queue<string> q;
        q.push(beginword);
        q.push("*");
        visited.insert(beginword);
        int length = 1;
        while(!q.empty()) {
            string tmp = q.front();
            q.pop();
            if(tmp == "*") {
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
                        if(visited.count(tmp) == 0 && dict.count(tmp) > 0) {
                            visited.insert(tmp);
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
