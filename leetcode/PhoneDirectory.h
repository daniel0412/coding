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

class PhoneDirectory {
  public:
    PhoneDirectory(const int maxNum)
        : d_maxNum(maxNum), d_used(vector<bool>(maxNum, false))
    {
    }

    int get()
    {
        if(!d_recycled.empty()) {
            int num = d_recycled.front();
            d_recycled.pop();
            d_used[num] = true;
            return num;
        }
        if(d_nextNum < d_maxNum) {
            int num = d_nextNum;
            d_used[num] = true;
            ++d_nextNum;
            return num;
        }
        return -1;
    }
    void recycle(const int num)
    {
        d_recycled.push(num);
        d_used[num] = false;
    }
    bool check(const int num)
    {
        if(num < 0 || num >= maxNUm)
            return false;
        return d_used[num];
    }

  private:
    int d_maxNum;
    int d_nextNum;
    queue<int> d_recycled;
    vector<int> d_used;
};
