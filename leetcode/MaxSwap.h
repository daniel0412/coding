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
