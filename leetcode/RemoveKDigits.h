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

class RemoveKDigits {
  public:
    string removeKdigits(string num, int k)
    {
        if(k >= num.size() || num.empty())
            return "0";
        if(k <= 0)
            return num;
        string res;
        // need to cal here, since k is changing in the next loop
        int numLeft = num.size() - k;
        for(auto c : num) {
            while(k && res.size() && res.back() > c) {
                res.pop_back();
                --k;
            }
            res.push_back(c);
        }
        res.resize(numLeft);
        int i = 0;
        while(i < res.size() && res[i] == '0')
            ++i;
        if(i == res.size())
            return "0";
        return res.substr(i);

      private:
    };
