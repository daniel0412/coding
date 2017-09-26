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

class ShortestUnsortedContinuousSubarray {
  public:
      int findUnsortedSubarray(vector<int>& nums) {
	  int start = -1, end = -1;
	  int maxId = 0, i = 1;
	  while(i < nums.size()) {
	      if(nums[i-1] <= nums[i]) {
		  ++i;
	      }else if(start = -1) {

	      }

	  }
	  for(int i = 1; i < nums.size(); ++i) {
	      if(nums[i] >= nums[maxId]) {
		  maxId = i;
	      }else{

	      }

	  }
      }
  private:
      int upper(const vector<int>& nums, const int target, int s, int e) {
	  while(s < e) {
	      int m = s + (e-s)/2;
	      if(nums[m] <= target) {
		  s = m + 1;
	      }else{
		  e = m;
	      }
	  }
	  return e;
      }
};
