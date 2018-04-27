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

class LongestValidParenthesis {
  public:
      int longestValidParentheses(string s) {
	  int cnt = 0, maxCnt = 0;
	  for(int left = 0, right = 0; right < s.size(); ++right) {
	      if(s[right] == ')') {
              if(cnt == 0) {
                  maxCnt = max(maxCnt, right - left);
                  left = right + 1;
              }
          }else {

	  }

	  }
      }
  private:
};
