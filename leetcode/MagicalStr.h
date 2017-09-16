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

class MagicalStr {
  public:
    int magicalString(int n)
    {
        if(n == 0)
            return 0;
        // start from the third 2 in '122'
        queue<int> q;
        q.push(2);
        int len = 3;
        int res = 1;
        bool isOne = true;
        while(!q.empty() && len < n) {
            int j = 0;
            int cnt = q.front();
            q.pop();
            if(isOne) {
                while(j++ < cnt)
                    q.push(1);
                res += cnt;
                len += cnt;
                if(len > n)
                    --res;
                isOne = false;
            }
            else {
                while(j++ < cnt)
                    q.push(2);
                len += cnt;
                isOne = true;
            }
        }
        return res;
    }

  private:
};
