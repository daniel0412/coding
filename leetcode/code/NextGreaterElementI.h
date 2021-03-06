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

class NextGreaterElementI {
  public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums)
    {
        unordered_map<int, int> m;
        stack<int> s;
        vector<int> res;
        // loop over nums to find all next greater element
        for(auto d : nums) {
            // pop out all elements that are smaller than d
            // since their next greater element is already found
            while(!s.empty() && d > s.top()) {
                m[s.top()] = d;
                s.pop();
            }
            // needs to push current d anyway, since its next greater element has to come after this
            s.push(d);
        }
        for(auto d : findNums) {
            if(m.find(d) != m.end()) {
                res.push_back(m[d]);
            }
            else {
                res.push_back(-1);
            }
        }
        return res;
    }

  private:
};
