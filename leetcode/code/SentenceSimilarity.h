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

class SentenceSimilarity {
  public:
    bool areSentencesSimilar(vector<string>& words1,
                             vector<string>& words2,
                             vector<pair<string, string> > pairs)
    {
        if(words1.size() != words2.size())
            return false;
        unordered_map<string, unordered_set<string> > m;
        for(const auto& kv : pairs) {
            m[kv.first].insert(kv.second);
        }
        for(int i = 0; i < words1.size(); ++i) {
            const auto& w1 = words1[i];
            const auto& w2 = words2[i];
            if(w1 == w2)
                continue;
            if(!m[w1].count(w2) && !m[w2].count(w1))
                return false;
        }
        return true;
    }

  private:
};
