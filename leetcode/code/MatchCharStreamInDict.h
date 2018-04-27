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

class MatchCharStreamInDict {
  public:
    vector<bool> match(vector<string>& words, string& charStream)
    {
        // 1) suffix trie for suffix check
        // 2) maxLen to prune
        Trie trie;
        size_t maxLen = 0;
        for(const auto& w : words) {
            maxLen = max(maxLen, w.size());
            trie.insert(w);
        }

        string buffer;
        vector<bool> res;
        for(auto c : charStream) {
            buffer.push_back(c);
            if(buffer.size() > maxLen)
                buffer = buffer.substr(1);
            res.emplace_back(trie.suffixExists(buffer))
        }
    }

  private:
};
