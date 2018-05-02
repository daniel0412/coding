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

class MaxSwap {
  public:
    // case to consider
    // 1. increasing: 1234
    // 2. decreasing: 4321
    // 3. multiple large number: 1992
    // 4. decrease first few: 98658
    int maximumSwapEasier(int num)
    {
        string str = to_string(num);
        vector<int> vv;
        for(int i = 0; i < str.size(); ++i) {
            // only record the large digit
            while(!vv.empty() && str[vv.back()] < str[i]) {
                vv.pop_back();
            }
            vv.push_back(i);
        }
        // if decreasing, no digits kicked out
        if(vv.size() == str.size())
            return num;

        // locate the last largest digit that does not match its index
        for(int i = 0; i < vv.size(); ++i) {
            // found digits location not match
            if(i != vv[i]) {
                int j = i;
                // swap the last max digit that has the same value
                while(j + 1 < vv.size() && str[vv[j]] == str[vv[j + 1]])
                    ++j;
                swap(str[i], str[vv[j]]);
                break;
            }
        }
    }

    // this version is eaiser to understand, and should use this version
    int maximumSwap(int num)
    {
        string s = to_string(num);
        // find the first char that from which the monotonic decreasing order is lost
        int i = 0, n = s.size();
        while(i < n - 1) {
            if(s[i] < s[i + 1])
                break;
            ++i;
        }
        // if all decreasing order, just return
        if(i == n - 1)
            return num;
        // find the max char after order corruption
        int maxJ = i + 1, j = i + 2;
        while(j < n) {
            // here attention***** = sign is needed, since we only want to replace the last max char
            // e.g., 1991 -> 9911 (but not 9191)
            if(s[j] >= s[maxJ])
                maxJ = j;
            ++j;
        }
        // find the first char that is lower than maxJ char, and swap
        int maxI = 0;
        while(s[maxI] >= s[maxJ])
            ++maxI;
        swap(s[maxI], s[maxJ]);
        return stoi(s);
    }
  private:
};
