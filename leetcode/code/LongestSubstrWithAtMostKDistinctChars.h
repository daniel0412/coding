/*  340 Longest Substring with At Most K Distinct Characters
 *
 * Given a string, find the length of the longest substring T that contains at
 *most k distinct characters.
 *
 * For example, Given s = “eceba” and k = 2,
 *
 * T is "ece" which its length is 3.
 *
 */

#include <string>
#include <vector>
#include <stack>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>

using namespace std;

class LongestSubstrWithAtMostKDistinctChars {
  public:

    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        int slen = s.size();
        if(slen <= k)
            return slen;
        int maxLen = 0;
        int start = 0, end = 0;
        // store char->max index up to now map
        unordered_map<char, int> m;
        while(end < s.size()) {
            m[s[end]] = end;
            // make sure the map size is no greater than k
            while(m.size() > k) {
                // find the first char from start that we can remove from the
                // map
                if(m[s[start]] == start)
                    m.erase(s[start]);
                ++start;
            }
            ++end;
            maxLen = max(maxLen, end - start);
        }
        return maxLen;
    }

  private:
};
