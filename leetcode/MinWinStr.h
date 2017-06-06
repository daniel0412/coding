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

class MinWinStr {
  public:
    string minWindow(string s, string t)
    {
        if(s.size() < t.size() || t.empty())
            return "";

        // construct c->count map
        unordered_map<char, int> tCount;
        for(auto c : t) {
            ++tCount[c];
        }

        // track num of chars in t, but not in the candidate substr
        int numLeft = t.size();

        string minStr;
        int minLen = INT_MAX;
        int start = 0;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(tCount.count(c) > 0) {
                --tCount[c];
                if(tCount[c] >= 0) {
                    --numLeft;
                    if(numLeft == 0) {
                        // moving start pos forward
                        while(start <= i) {
                            char currentC = s[start];
                            if(tCount.count(currentC) == 0) {
                                ++start;
                            }
                            else if(tCount[currentC] < 0) {
                                ++tCount[currentC];
                                ++start;
                            }
                            else {
                                int len = i - start + 1;
                                if(len < minLen) {
                                    minStr = s.substr(start, len);
                                    minLen = minStr.size();
                                    if(len == t.size())
                                        return minStr;
                                }
                                ++tCount[currentC];
                                ++numLeft;
                                ++start;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return minStr;
    }

  private:
};
