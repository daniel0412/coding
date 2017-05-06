/* 408 valid word abbrevation
 * Given a non-empty string s and an abbreviation abbr, return whether the
 *string matches with the given abbreviation.
 *
 * A string such as "word" contains only the following valid abbreviations:
 *
 * ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d",
 *"1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 * Notice that only the above abbreviations are valid abbreviations of the
 *string "word". Any other string is not a valid abbreviation of "word".
 *
 * Note:
 * Assume s contains only lowercase letters and abbr contains only lowercase
 *letters and digits.
 *
 * Example 1:
 *
 * Given s = "internationalization", abbr = "i12iz4n":
 *
 * Return true.
 *
 *
 *  Example 2:
 *
 *  Given s = "apple", abbr = "a2e":
 *
 *  Return false.
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

class ValidWordAbbr {
  public:
    bool validWordAbbreviation(string word, string abbr)
    {
        if(word.empty())
            return abbr.empty();
        int wLen = word.size(), aLen = abbr.size();
        int wi = 0, ai = 0;
        while(ai < aLen && wi < wLen) {
            int cnt = 0;
            while(abbr[ai] >= '0' && abbr[ai] <= '9') {
                if(cnt == 0 && abbr[ai] == '0')
                    return false;
                cnt = cnt * 10 + (abbr[ai] - '0');
                ++ai;
            }
            if(cnt == 0) {
                if(word[wi] != abbr[ai])
                    return false;
                else {
                    ++ai;
                    ++wi;
                }
            }
            else {
                wi += cnt;
            }
        }
        return ai == aLen && wi == wLen;
    }

  private:
};
