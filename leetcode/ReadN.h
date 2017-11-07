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

namespace {
const int N_PER_READ = 4;
int read4(char *buf);
}

class ReadN {
  public:
    int read(char* buf, int n)
    {
        char buf4[4];
        int offset = 0;
        while(offset < n) {
            int num = read(buf4);
            for(int i = 0; i < num && offset < n; ++i) {
                buf[offset++] = buf4[i];
            }
            if(num < 4)
                break;
        }
        return min(res, n);
    }

  private:
};
