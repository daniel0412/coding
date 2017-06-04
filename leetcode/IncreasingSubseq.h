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

class IncreasingSubseq {
  public:
    vector<vector<int> > findSubsequences(vector<int>& nums)
    {
        vector<int> path;
        set<vector<int> > results;
        recursiveImpl(nums, 0, path, results);
        return vector<vector<int> >(results.begin(), results.end());
    }

  private:
    void recursiveImpl(const vector<int>& nums,
                       const int start,
                       vector<int>& path,
                       set<vector<int> >& results)
    {
        //if(start >= nums.size()) return;
        if(path.size() >= 2) {
            results.insert(path);
        }
        for(int i = start; i < nums.size(); ++i) {
            if(!path.empty() && path.back() > nums[i])
                continue;
            path.push_back(nums[i]);
            recursiveImpl(nums, i + 1, path, results);
            path.pop_back();
        }
    }
};
