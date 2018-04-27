/* 316. Remove Duplicate Letters
 *
 * Given a string which contains only lowercase letters, remove duplicate
 *letters so that every letter appear once and only once. You must make sure
 *your result is the smallest in lexicographical order among all possible
 *results.
 *
 * Example:
 * Given "bcabc"
 * Return "abc"
 *
 * Given "cbacdcbc"
 * Return "acdb"
 */

#include <string>
#include <vector>
#include <list>
#include <stack>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <algorithm>
#include <utility>
#include "utils.h"

using namespace std;

class RemoveDuplicateLetter {
  public:
    string removeDuplicateLetters(string s)
    {
        int occurence[256] = {0};
        bool visited[256] = {false};
        for(const auto c : s)
            ++occurence[c];
        string res;
        res.push_back(0);
        for(const auto c : s) {
            --occurence[c];
            if(visited[c])
                continue;
            while(c < res.back() && occurence[res.back()] > 0) {
                visited[res.back()] = false;
                res.pop_back();
            }
            res.push_back(c);
            visited[c] = true;
        }
        return res.substr(1);
    }

  private:
};
