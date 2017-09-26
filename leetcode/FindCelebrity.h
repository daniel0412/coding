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
        // first find candidate
        // if a knows b, a is not candidate, but b is
        // if a does not know b, b is not candidate, but a is
        for(int i = 0; i < n; ++i) {
            if(knows(candidate, i)) {
                candidate = i;
            }
        }
        // before candidate, need to check both directions
        for(int i = 0; i < candidate; ++i) {
            if(!knows(i, candidate) || knows(candidate, i))
                return -1;
        }
        // after candidate, we already candidate does know them
        for(int i = candidate + 1; i < n; ++i) {
            if(!know(i, candidate))
                return -1;
        }
        return candidate;
    }

  private:
};
