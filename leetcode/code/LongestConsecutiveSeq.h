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

class LongestConsecutiveSeq {
  public:
      int longestConsecutive(vector<int>& nums) {
          unordered_set<int> s(nums.begin(), nums.end());
          int maxCnt;
          while(!s.empty()){
              int up = *s.begin();
              int down = up;
              int cnt = 1;
              s.erase(up);
              while(s.count(++up)) {
                  s.erase(up);
                  ++cnt;
              }
              while(s.count(--down)) {
                  s.erase(down);
                  ++cnt;
              }
              maxCnt = max(maxCnt, cnt);
          }
          return maxCnt;
      }
  private:
};
