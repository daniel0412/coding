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
        int res = 0;
        for(int i = 0; i <= n / N_PER_READ; ++i) {
            int c = read4(buf + res);
            if(c == 0)
                break;
            res += c;
        }
        return min(n, res);
    }

  private:
};
