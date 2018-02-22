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

class RussianDollEnvelopes {
  public:
    using pii = pair<int, int>;
    int maxEnvelopes(vector<pair<int, int> >& envelopes)
    {
        // sort by first dim inc, if equal sort by second dim des
        sort(envelopes.begin(),
             envelopes.end(),
             [](const pii& a, const pii& b) {
                 return a.first < b.first ||
                     (a.first == b.first && a.second > b.second);
             });

        vector<int> res;
        for(int i = 0; i < envelopes.size(); ++i) {
            pii& e = envelopes[i];
            auto iter = lower_bound(res.begin(), res.end(), e.second);
            if(iter == res.end()) {
                res.push_back(e.second);
            }
            else {
                *iter = e.second;
            }
        }
        return res.size();
    }

  private:
};
