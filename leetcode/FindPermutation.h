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

class FindPermutation {
  public:
    vector<int> findPermutation(string s)
    {
        if(s.empty())
            return {};
        int n = s.size();
        vector<int> res(n + 1, 0);
        for(int i = 1; i <= n + 1; ++i) {
            res[i - 1] = i;
        }
        int start = -1, k = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == 'D') {
                start = i;
                while(s[i++] == 'D')
                    ++k;
                reverse(res.begin() + start, res.begin() + start + k);
            }
        }
        return res;
    }

  private:
};
