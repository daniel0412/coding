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
        int sLen = s.length();
        if(sLen <= k)
            return sLen;
        unordered_map<char, int> mymap;
        int start = 0, end = 0, maxLen = 0;
        for(int i = 0; i < sLen;) {
            if(mymap.size() < k || mymap.find(s[i]) != mymap.end()) {
                ++mymap[s[i]];
                end = i;
                ++i;
            }
            else {
                auto iter = mymap.find(s[start]);
                ++start;
                if(--(iter->second) == 0) {
                    mymap.erase(iter);
                    end = i;
                    ++i;
                }
            }
            int curLen = end - start + 1;
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }

  private:
};
