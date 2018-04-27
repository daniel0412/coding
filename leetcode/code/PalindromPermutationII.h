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

class PalindromPermutationII {
  public:
    vector<string> generatePalindromes(string s)
    {
        unordered_map<char, int> m;
        for(auto c : s)
            ++m[c];
        string t, m;
        for(const auto& kv : m) {
            if(kv.second % 2) {
                m.push_back(kv.first);
            }
            t += string(kv.second / 2, kv.first);
            if(m.size() > 1)
                return {};
        }
        vector<string> res;
    }

    void permutate(string& s, int start, const string& m, vector<string>& res)
    {
        if(start >= s.size()) {
            res.emplace_back(s + m + reverse(s.begin(), s.end()));
            return;
        }
        // fix the start element, and permutate the rest
        for(int i = start; i < s.size(); ++i) {
            // dedupliation step to make sure the start-th element is the same
            // for once
            if(i > start && s[i] == s[start])
                continue;
            swap(s[i], s[start]);
            permutate(s, start + 1, m, res);
            swap(s[i], s[start]);
        }
    }

  private:
};
