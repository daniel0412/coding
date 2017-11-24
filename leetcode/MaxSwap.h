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
                // swap the last digit that has the same value
                while(j + 1 < vv.size() && str[vv[j]] == str[vv[j + 1]])
                    ++j;
                swap(str[i], str[vv[j]]);
                break;
            }
        }
    }
    int maximumSwap(int num)
    {
        string nstr = to_string(num);
        char minc = nstr[0];
        int id = -1;
        for(int i = 1; i < nstr.size(); ++i) {
            minc = min(nstr[i], minc);
            if(nstr[i] <= minc) {
                minc = nstr[i];
            }
            else {
                if(id == -1) {
                    id = i;
                }
                else {
                    // here = sign is important, since we want to swap with the
                    // lower bit of that equal number
                    if(nstr[i] >= nstr[id])
                        id = i;
                }
            }
        }
        if(id >= 0) {
            for(int i = 0; i < nstr.size(); ++i) {
                if(nstr[i] < nstr[id]) {
                    swap(nstr[i], nstr[id]);
                    break;
                }
            }
        }
        return stoi(nstr);
    }

  private:
};
