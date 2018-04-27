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

class BurstBaloons {
  public:
    int maxCoins(vector<int>& nums) { return dp(nums); }

    int recursiveImpl(vector<int> v)
    {
        // stopping criteria
        if(v.size() == 1)
            return v.front();
        if(v.size() == 2)
            return v[0] * v[1] + max(v[1], v[0]);
        int maxS = 0;
        // loop to enumerate all possible choice of the first ballon to burst
        for(int i = 0; i < v.size(); ++i) {
            // prod of bursting the ith ballon
            int tmpS = v[i];
            if(i > 0)
                tmpS *= v[i - 1];
            if(i < v.size() - 1)
                tmpS *= v[i + 1];
            // construct the vector after bursting the ith baloon
            vector<int> nextV;
            nextV.insert(nextV.end(), v.begin(), v.begin() + i);
            nextV.insert(nextV.end(), v.begin() + i + 1, v.end());
            // keep track of the max, by recursively call the same function on
            // modified vector
            maxS = max(maxS, tmpS + recursiveImpl(nextV));
        }
        return maxS;
    }

    // trick dp
    // dp[i][j]: solution for baloon range [i, j]
    // formula: dp[i][j] = max(dp[i][j], dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1]) for all k in [i, j]
    // tricky point (which I missed): above k: the last ballon to burst in the range
    // i alwasy though k should be the first to burst
    int dp(vector<int>& v)
    {
        int n = v.size();
        v.insert(v.begin(), 1);
        v.push_back(1);
        vector<vector<int> > dp(n + 2, vector<int>(n + 2, 0));
        for(int l = n; l >= 1; --l) {
            for(int r = l; r <= n; ++r) {
                for(int k = l; k <= r; ++k) {
                    dp[l][r] = max(dp[l][r],
                                   dp[l][k - 1] + dp[k + 1][r] +
                                       v[l - 1] * v[r + 1] * v[k]);
                }
            }
        }
        return dp[1][n];
    }

  private:
};
