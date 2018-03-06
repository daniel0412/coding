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

class LongestWordChain {
  public:
    int longestchain(const vector<string>& words)
    {
        // put all words into an unordered_set for quick word  exitence check
        unordered_set<string> s;
        for(auto& w : words) {
            s.insert(w);
        }

        // this keeps track of the maximal length of the word chain
        int maxlen = 0;
        // use an unordered map to memorize the longest chain starting from the
        // given word
        // to avoid duplicate calculation when performing dfs
        unordered_map<string, int> m;

        // loop over each word to find out the chain length starting from that
        // word
        for(const auto& w : words) {
            // only if the word length is greater than the current maxlen, we
            // check its length
            if(w.size() > maxlen) {
                // always keep updating the maximal length
                maxlen = max(maxlen, dfs(w, s, m));
            }
        }
        return maxlen;
    }

    int dfs(string startWord,
            const unordered_set<string>& s,
            unordered_map<string, int>& m)
    {
        // keep track of the max length of the chain satring from the
        // 'startWord'
        int maxcnt = 0;
        for(int i = 0; i < startWord.size(); ++i) {
            // remove the ith char, and find the next word to try
            string nextWord = startWord.substr(0, i) + startWord.substr(i + 1);
            // if the next word does not exist in the dict, just continue to
            // check the next one
            if(s.count(nextWord) == 0)
                continue;

            // if the next word is already visited, we read the chain length
            // from the map
            if(m.count(nextWord) > 0)
                maxcnt = max(maxcnt, m[nextWord]);
            else {
                // if not found, we recursively call the dfs function to
                // calculate the length
                maxcnt = max(maxcnt, dfs(nextWord, s, m));
            }
        }
        // put the result into the map to void duplicate calculation
        m[startWord] = maxcnt + 1;
        return m[startWord];
    }

  private:
};
