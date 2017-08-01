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

class FindCelebrity {
  public:
    int findCelebrity(int n)
    {
        int candidate = 0;
        for(int i = 0; i < n; ++i) {
            if(knows(candidate, i)) {
                candidate = i;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(i != candidate && (!knows(i, candidate) || knows(candidate, i)))
                return -1;
        }
        return candidate;
    }

    int findCelebrityLessCall(int n)
    {
        int candidate = 0;
        for(int i = 0; i < n; ++i) {
            if(knows(candidate, i)) {
                candidate = i;
            }
        }
        for(int i = 0; i < res; ++i) {
            if(!knows(i, candidate) || knows(candidate, i))
                return -1;
        }
        for(int i = res + 1; i < n; ++i) {
            if(!know(i, candidate))
                return -1;
        }
        return candidate;
    }

  private:
};
