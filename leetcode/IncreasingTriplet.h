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

class IncreasingTriplet {
  public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        for(auto x : nums){
            if(x <= a) {
                a = x;
            }else if (x <= b) {
                b = x;
            }else{
                return true;
            }
        }
        return false;
    }
    // think about the following cases
    // [1,2,3]
    // [4,5,3,6]

  private:
};
