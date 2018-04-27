/* 482. License Key Formatting
 * Now you are given a string S, which represents a software license key which
 *we would like to format. The string S is composed of alphanumerical
 *characters and dashes. The dashes split the alphanumerical characters within
 *the string into groups. (i.e. if there are M dashes, the string is split into
 *M+1 groups). The dashes in the given string are possibly misplaced.
 *
 * We want each group of characters to be of length K (except for possibly the
 *first group, which could be shorter, but still must contain at least one
 *character). To satisfy this requirement, we will reinsert dashes.
 *Additionally, all the lower case letters in the string must be converted to
 *upper case.
 *
 * So, you are given a non-empty string S, representing a license key to
 *format, and an integer K. And you need to return the license key formatted
 *according to the description above.
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
#include <utility>

using namespace std;

class LicenseKeyFormatting {
  public:
    string licenseKeyFormatting(string s, int K)
    {
        if(s.empty())
            return s;
        int strLen = 0;
        for(auto c : s) {
            if(c == '-')
                continue;
            if(c >= 'a' && c <= 'z')
                c = 'A' - 'a' + c;
            s[strLen++] = c;
        }
        if(strLen <= 0) return string("");

        int residual = strLen % K;
        int numFullGroups = strLen / K;
        int strLenAfterFormat = strLen + numFullGroups;
        if(residual == 0)
            --strLenAfterFormat;
        s.resize(strLenAfterFormat);
        for(int i = 1; i <= strLen; ++i) {
            s[strLenAfterFormat - i - ((i - 1) / K)] = s[strLen - i];
            if(i % K == 0) {
                int dashLoc = strLenAfterFormat - i - (i / K);
                if(dashLoc > 0)
                    s[dashLoc] = '-';
            }
        }
        return s;
    }

  private:
};
