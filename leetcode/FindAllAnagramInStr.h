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

class FindAllAnagramInStr {
  public:
    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> m;
        for(auto c : p)
            ++m[c];
        vector<int> res;
        int left = 0, right = 0;
        int cnt = p.size();
        while(right < s.size()) {
            if(m[s[right++]]-- > 0)
                --cnt;
            if(cnt == 0)
                res.push_back(left);
            if(right - left == p.size() && m[s[left++]]++ >= 0)
                ++cnt;
        }
        return res;
    }

  private:
};
