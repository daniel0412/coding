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

class PermutationInString {
  public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_map<char, int> m;
        for(auto c : s1)
            ++m[c];
        int left = 0, right = 0;
        int cnt = s1.size();
        while(right < s2.size()) {
            if(m[s2[right++]]-- > 0)
                --cnt;
            if(cnt == 0)
                return true;
            if(right - left == s1.size() && m[s2[left++]]++ >= 0)
                ++cnt;
        }
        return false;
    }

  private:
};
