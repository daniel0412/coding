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

class TwoSumSorted {
  public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> res;
        if(numbers.size() < 2)
            return res;
        int firstId = 0, secondId = numbers.size() - 1;
        while(firstId < secondId) {
            int sum = numbers[firstId] + numbers[secondId];
            if(sum == target) {
                res.push_back(firstId + 1);
                res.push_back(secondId + 1);
                return res;
            }
            else if(sum > target) {
                --secondId;
            }
            else {
                ++firstId;
            }
        }
        return res;
    }

  private:
};
