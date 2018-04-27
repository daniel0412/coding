/* 248 Strobogrammatic Number III
 *
 * A strobogrammatic number is a number that looks the same when rotated 180
 *degrees (looked at upside down).
 *
 * Write a function to count the total strobogrammatic numbers that exist in
 *the range of low <= num <= high.
 *
 * For example,
 * Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three
 *strobogrammatic numbers.
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

class StrobogrammaticNumber3 {
  public:
    int strobogrammaticInRange(string low, string high)
    {
        int lowLen = low.size(), highLen = high.size();
        long long totalCount = 0, lowCount = 0, highCount = 0;
        for(int i = lowLen + 1; i < highLen; ++i) {
            totalCount += count(i);
        }

        countGreaterThan(low, 0, lowCount);
        countLessThan(high, 0, highCount);

        totalCount += (lowCount + highCount);
        return static_cast<int>(totalCount);
    }
    long long count(int len)
    {
        if(len <= 0)
            return 0;
        if(len == 1)
            return 3;
        long long num = pow(5, len / 2) - pow(5, len / 2 - 1);
        if(len % 2 == 0) {
            return num;
        }
        else {
            return num * 3;
        }
    }

    void countGreaterThan(const string& number, int id, long long& totalCount)
    {
        size_t len = number.size();
        bool isOdd = len % 2 != 0;

        if(id == len / 2) {
            if(isOdd) {
                totalCount += numMiddleDigitsGreaterThan(number[id]);
            }
            return;
        }

        long long tmpNum = numDigitsGreaterThan(number[id]);
        int fullPossibleDigits = len / 2 - id - 1;
        if(isOdd) {
            totalCount += (pow(5, fullPossibleDigits) * 3 * tmpNum);
        }
        else {
            totalCount += (pow(5, fullPossibleDigits) * tmpNum);
        }
        if(isValidDigits(number[id])) {
            countGreaterThan(number, id + 1, totalCount);
        }
    }

    void countLessThan(const string& number, int id, long long& totalCount)
    {
        size_t len = number.size();
        bool isOdd = len % 2 != 0;
        if(id == len / 2) {
            if(isOdd) {
                totalCount += numMiddleDigitsLessThan(number[id]);
            }
            return;
        }
        long long tmpNum = numDigitsLessThan(number[id]);
        if(id == 0)
            --tmpNum;
        int fullPossibleDigits = len / 2 - id - 1;
        if(isOdd) {
            totalCount += (pow(5, fullPossibleDigits) * 3 * tmpNum);
        }
        else {
            totalCount += (pow(5, fullPossibleDigits) * tmpNum);
        }
        if(isValidDigits(number[id])) {
            countLessThan(number, id + 1, totalCount);
        }
    }

  private:
    long long numMiddleDigitsGreaterThan(char c)
    {
        if(c < '1')
            return 2;
        if(c < '8')
            return 1;
        return 0;
    }

    long long numMiddleDigitsLessThan(char c)
    {
        if(c > '8')
            return 3;
        if(c > '1')
            return 2;
        if(c > '0')
            return 1;
        return 0;
    }

    long long numDigitsGreaterThan(char c)
    {
        if(c < '1')
            return 4;
        if(c < '6')
            return 3;
        if(c < '8')
            return 2;
        if(c < '9')
            return 1;
        return 0;
    }

    long long numDigitsLessThan(char c)
    {
        if(c > '8')
            return 4;
        if(c > '6')
            return 3;
        if(c > '1')
            return 2;
        if(c > '0')
            return 1;
        return 0;
    }


    bool isValidDigits(char c)
    {
        if(c == '0' || c == '1' || c == '6' || c == '8' || c == '9')
            return true;
        return false;
    }
};
