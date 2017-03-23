/* 166. Fraction to Recurring Decimal
 *
 *
 * Given two integers representing the numerator and denominator of a fraction,
 *return the fraction in string format.
 *
 * If the fractional part is repeating, enclose the repeating part in
 *parentheses.
 *
 * For example,
 *
 * Given numerator = 1, denominator = 2, return "0.5".
 * Given numerator = 2, denominator = 1, return "2".
 * Given numerator = 2, denominator = 3, return "0.(6)".
 */

#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>

using namespace std;

class FractionToRecurringDecimal {
  public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if(denominator == 0)
            return "";
        if(numerator == 0)
            return "0";

        long numeratorL = static_cast<long>(numerator);
        long denominatorL = static_cast<long>(denominator);

        bool isNegative =
            ((numeratorL / abs(numeratorL)) * (denominatorL / abs(denominatorL)) ==
             -1);

        numeratorL = abs(numeratorL);
        denominatorL = abs(denominatorL);

        vector<long> res;
        unordered_map<long, size_t> mymap;
        while(numeratorL != 0 && mymap.find(numeratorL) == mymap.end()) {
            long a = numeratorL / denominatorL;
            long r = numeratorL % denominatorL;
            res.push_back(a);
            mymap[numeratorL] = res.size() - 1;
            numeratorL = r * 10;
        }
        bool isRecurring = numeratorL != 0;

        stringstream ss;
        if(isNegative)
            ss << "-";
        for(size_t i = 0; i < res.size(); ++i) {
            if(i == 1)
                ss << ".";
            if(isRecurring && i == mymap[numeratorL])
                ss << "(";
            ss << res[i];
        }
        if(isRecurring)
            ss << ")";
        return ss.str();
    }

  private:
};
