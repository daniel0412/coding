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

class SentenceSimilarityII {
  public:
    bool areSentencesSimilar(vector<string>& words1,
                             vector<string>& words2,
                             vector<pair<string, string> > pairs)
    {
        if(words1.size() != words2.size())
            return false;

        unordered_map<string, string> roots;
        for(const auto& kv : pairs) {
            string r1 = getRoot(roots, kv.first);
            string r2 = getRoots(roots, kv.second);
            if(r1 != r2) {
                roots[r1] = r2;
            }
        }

        for(int i = 0; i < words1.size(); ++i) {
            if(getRoot(roots, words1[i]) != getRoot(roots, words2[i]))
                return false;
        }
        return true;
    }

    string getRoot(unordered_map<string, string>& roots, string s)
    {
        if(roots.count(s) == 0)
            roots[s] = s;
        while(roots[s] != s) {
            roots[s] = roots[roots[s]];
            s = roots[s];
        }
        return s;
    }

  private:
};
