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

class SplitArrayIntoConsecutiveSequences {
  public:
    bool isPossible(vector<int>& nums)
    {
        // freq: val->freq map
        // needed: number of val needed for the next element in consecutive sequence
        unordered_map<int, int> freq, needed;
        for(const auto n : nums)
            ++freq[n];
        for(const auto n : nums) {
            // if val is used up somewhere else, just contiue
            if(freq[n] == 0)
                continue;
            // if val can be used to extend the sequence, be greedy, use it
            // REASON: array is alredy sorted
            else if(needed[n]) {
                --needed[n];
                ++needed[n + 1];
            }
            // if val cannot be part of an existing consecutive sequence, 
            // start a new sequence with at least three elements
            else if(freq[n + 1] && freq[n + 2]) {
                --freq[n + 1];
                --freq[n + 2];
                ++needed[n + 3];
            }
            else {
                return false;
            }
            --freq[n];
        }
        return true;
    }

  private:
};
