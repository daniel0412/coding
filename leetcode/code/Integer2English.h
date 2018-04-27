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
    string numberToWords(int num){
        if(num == 0) return "Zero";
        const int BILLION = 1000000000;
        const int THOUSAND = 1000;
        vector<string> bases = {"Billion ", "Million ", "Thousand ", " "};
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
        string res;
        int divider = BILLION;
        for(size_t i = 0; i < bases.size(); ++i) {
            int a = num / divider;
            if(a > 0) {
                res += convertHundred(a, dict) + bases[i];
                num %= divider;
            }
            divider /= THOUSAND;
        }
        int id = res.find_last_not_of(' ');
        return res.substr(0, id+1);

    }
    string convertHundred(int num, unordered_map<int, string>& dict)
    {
        string res;
        int a = num / 100;
        if(a) {
            res = dict[a] + " Hundred ";
        }
        num %= 100;
        if(num == 0) {
            return res;

        }
        if(num <= 20 || num % 10 == 0) {
            res = res + dict[num] + " ";
        }else{
            res = res + dict[(num/10) * 10] + " " + dict[num % 10] + " ";
        }
        return res;
    }
    string convertHundred2(int num, unordered_map<int, string>& dict)
    {
        string res;
        int a = num / 100, b = num % 100, c = num % 10;
        res += (a == 0 ? "" : dict[a] + " Hundred ");
        if(b <= 20) {
            res += (b == 0 ? "" : dict[b]);
        }
        else {
            res += (dict[b / 10 * 10] + (c == 0 ? "" : dict[c]) + " ");
        }
        return res;
    }

  private:
};
