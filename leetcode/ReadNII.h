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

class ReadNII {
  public:
      ReadNII() : d_readPos(0), d_writePos(0) {}
    int read(char* buf, int n)
    {
        for(int i = 0; i < n; ++i) {
            if(d_readPos == d_writePos) {
                d_readPos = 0;
                d_writePos = read4(d_buffer);
                if(d_writePos == 0) return i;
            }
            buf[i] = d_buffer[d_readPos++];
        }
        return n;
    }

  private:
    int d_readPos;
    int d_writePos;
    char d_buffer[4];
};
