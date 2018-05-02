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

class Integer2English {
  public:
    string numberToWords(int num)
    {
        // corner case
        if(num == 0)
            return "Zero";
        // list all possible values
        unordered_map<int, string> dict = {
            {1, "One"},
            {2, "Two"},
            {3, "Three"},
            {4, "Four"},
            {5, "Five"},
            {6, "Six"},
            {7, "Seven"},
            {8, "Eight"},
            {9, "Nine"},
            {10, "Ten"},
            {11, "Eleven"},
            {12, "Twelve"},
            {13, "Thirteen"},
            {14, "Fourteen"},
            {15, "Fifteen"},
            {16, "Sixteen"},
            {17, "Seventeen"},
            {18, "Eighteen"},
            {19, "Nineteen"},
            {20, "Twenty"},
            {30, "Thirty"},
            {40, "Forty"},
            {50, "Fifty"},
            {60, "Sixty"},
            {70, "Seventy"},
            {80, "Eighty"},
            {90, "Ninety"},
        };
        // make sure we convert below thousands part first
        int divider = 1000;
        string res = convertHundred(dict, num % divider);
        num /= divider;
        // starting from lower bits to upper bits
        vector<string> base = {"Thousand", "Million", "Billion"};
        for(int i = 0; i < base.size(); ++i) {
            int a = num % divider;
            if(a > 0) {
                res = convertHundred(dict, a) + base[i] + " " + res;
            }
            num /= divider;
            if(num == 0)
                break;
        }
        res.pop_back();
        return res;
    }

    // this function is important
    string convertHundred(unordered_map<int, string>& dict, int n)
    {
        string res;
        int a = n / 100;
        int b = n % 100;
        int c = b % 10;
        if(a) {
            res = dict[a] + " Hundred ";
        }
        if(b == 0)
            return res;

        if(b < 20) {
            res += (dict[b] + " ");
        }
        else {
            // here we only get the number in the second bit (shi wei)
            res += dict[b / 10 * 10] + " ";
            if(c > 0)
                res += dict[c] + " ";
        }
        return res;
    }

  private:
};
