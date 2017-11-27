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
    string minWindow(string s, string t) { return impl1(s, t); }
    string impl0(string s, string t)
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
    string impl1(const string& s, const string& t)
    {
        int sLen = s.size(), tLen = t.size();
        if(sLen < tLen)
            return "";
        unordered_map<char, int> needs;
        for(auto c : t) {
            ++needs[c];
        }
        int numMiss = tLen;
        int begin = 0, end = 0, head = 0;
        int dist = INT_MAX;
        while(end < sLen) {
            if(needs.count(s[end])) {
                if(needs[s[end]]-- > 0) {
                    --numMiss;
                }
                if(numMiss == 0) {
                    //cout << "before window: " << begin << ", " << end << endl;
                    while(begin <= end) {
                        if(needs.count(s[begin])) {
                            if(needs[s[begin]] >= 0) {
                                if(numMiss == 0) {
                                    ++numMiss;
                                    ++needs[s[begin]];
                                    int tmpDist = end - begin;
                                    if(tmpDist < dist) {
                                        head = begin;
                                        dist = tmpDist;
                                    }
                                }
                                else {
                                    break;
                                }
                            }
                            else {
                                ++needs[s[begin]];
                            }
                        }
                        ++begin;
                    }
                    // cout << "after : " << begin << ":" << s[begin] << endl;
                    cout << "after window: " << begin << ", " << end << endl;
                }
            }
            ++end;
        }
        return dist == INT_MAX ? "" : s.substr(head, dist + 1);
    }

    string towPointerImpl(string s, string t)
    {
        if(s.size() < t.size())
            return "";
        unordered_map<char, int> m;
        for(auto c : t)
            ++m[c];
        int left = 0, right = 0;
        int cnt = t.size(), len = s.size();

        // locate the first char included in 't'
        while(left < len && m.count(s[left]) == 0) {
            ++left;
        }
        if(left == len)
            return "";

        right = left;
        string minStr(s.size() + t.size() + 1, ' ');
        while(right < s.size()) {
            // if current char is not needed, continue;
            if(m.count(s[right]) == 0) {
                ++right;
                continue;
            }
            else {
                if(m[s[right++]]-- > 0)
                    --cnt;
                if(cnt == 0) {
                    // move left to shorten str lenght to find a valid answer
                    while(m.count(s[left]) == 0 || m[s[left]] < 0) {
                        if(m.count(s[left]))
                            ++m[s[left]];
                        ++left;
                    }
                    minStr = minStr.size() < (right - left) ?
                        minStr :
                        s.substr(left, right - left);
                    // move left to start next valid string search
                    ++m[s[left++]];
                    ++cnt;
                }
            }
        }
        return minStr.size() <= s.size() ? minStr : "";
    }

    string slidingWindowImpl(string s, string t)
    {
        int sn = s.size(), tn = t.size();
        if(tn > sn)
            return "";
        unordered_map<char, int> m;
        for(auto c : t)
            ++m[c];
        int left = 0, right = 0, cnt = tn;
        int minLen = numeric_limits<int>::max();
        string minStr;
        while(right < sn) {
            if(m.find(s[right]) == m.end()) {
                ++right;
                continue;
            }
            else {
                if(m[s[right++]]-- > 0) {
                    --cnt;
                }
                if(cnt == 0) {
                    while(1) {
                        if(m.find(s[left]) == m.end()) {
                            ++left;
                        }
                        else if(m[s[left]] < 0) {
                            ++m[s[left++]];
                        }
                        else {
                            break;
                        }
                    }
                    if(right - left < minLen) {
                        minLen = min(minLen, right - left);
                        minStr = s.substr(left, right - left);
                    }
                    ++m[s[left++]];
                    ++cnt;
                }
            }
            return minStr;
        }
};
