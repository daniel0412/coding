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
#include <numeric>
#include "utils.h"

using namespace std;

class MultiplyString {
  public:
    string multiply(string num1, string num2) {
        return multiplyFaster(num1, num2);
    }

    string multiplyFaster(string& num1, string& num2) {
        if(num1.empty() || num2.empty()) {
            return num1.empty() ? num2 : num1;
        }

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> res (num1.size() + num2.size(), 0);
        for(size_t i1 = 0; i1 < num1.size(); ++i1) {
            for(size_t i2 = 0; i2 < num2.size(); ++i2) {
                res[i1+i2] += (num1[i1]-'0') * (num2[i2]-'0');
            }
        }
        for(int i = 0; i < res.size(); ++i) {
            if(res[i]>=10) {
                res[i+1] += res[i]/10;
                res[i] %= 10;
            }
            cout << res[i] << endl;
        }
        int l = res.size() - 1;
        while(l >= 0 && res[l] == 0) {
            --l;
        }
        string prod;
        while(l >= 0) {
            prod.push_back(res[l--]+'0');
        }
        return prod.empty() ? "0" : prod;
    }

    string multiplySlower(string& num1, string& num2)
    {
        string longer = (num1.size() >= num2.size()) ? num1 : num2;
        string shorter = (num1.size() >= num2.size()) ? num2 : num1;
        if(shorter.empty())
            return longer;

        vector<string> res(shorter.size(), "");
        for(size_t i = 0; i < shorter.size(); ++i) {
            stringCharMultiply(longer, *(shorter.rbegin() + i), res[i]);
            if(!res[i].empty()) {
                res[i].insert(res[i].begin(), i, '0');
            }
        }
        string prod = accumulate(res.begin(), res.end(), string(""), Multiplication());
        reverse(prod.begin(), prod.end());
        return prod.empty() ? "0" : prod;
    }

  private:
    void stringCharMultiply(const string& s, const char c, string& res)
    {
        if(c == '0')
            return;
        int digit = c - '0';
        int carry = 0;
        for(auto iter = s.rbegin(); iter != s.rend(); ++iter) {
            int prod = (*iter - '0') * digit + carry;
            res.push_back(prod % 10 + '0');
            carry = prod / 10;
        }
        if(carry > 0) {
            res.push_back(carry + '0');
        }
    }
    struct Multiplication {
        string operator()(const string& s1, const string& s2)
        {
            if(s1.empty() || s2.empty()) {
                return s1.empty() ? s2 : s1;
            }
            string tmp;
            int carry = 0;
            auto iter1 = s1.begin(), iter2 = s2.begin();
            while(iter1 != s1.end() && iter2 != s2.end()) {
                int sum = *iter1 - '0' + *iter2 - '0' + carry;
                tmp.push_back(sum % 10 + '0');
                carry = sum / 10;
                ++iter1;
                ++iter2;
            }
            while(iter1 != s1.end()) {
                int sum = *iter1 - '0' + carry;
                tmp.push_back(sum % 10 + '0');
                carry = sum / 10;
                ++iter1;
            }
            while(iter2 != s2.end()) {
                int sum = *iter2 - '0' + carry;
                tmp.push_back(sum % 10 + '0');
                carry = sum / 10;
                ++iter2;
            }
            if(carry > 0)
                tmp.push_back(carry + '0');
            return tmp;
        }
    };
};
