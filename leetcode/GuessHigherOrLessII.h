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

class GuessHigherOrLessII {
  public:
    int getMoneyAmount(int n) { return minmax(n); }

    // most intuitive recursive implementation
    int recursiveImpl(int n) { return guessCost(1, n); }

    // given a range, get min-max cost of the guess
    int guessCost(int left, int right)
    {
        // stop when less than 2 numbers
        if(left >= right)
            return 0;
        int minCost = numeric_limits<int>::max();
        // for each guess
        for(int x = left; x <= right; ++x) {
            // for each guess x
            // given number can fall in left or right part
            // so need to take the max, to take both case into consideration
            // then plus cost x
            cost = max(guessCost(left, x - 1), guessCost(x + 1, right)) + x;

            // but among all tries of x, we should take the minimum cost
            minCost = min(minCost, cost);
        }
        return minCost;
    }

    // the above solution timeout
    // obviously, exponential cost, and lots of duplicated computation
    // so we can do recursion + memorization
    int recursiveWithMemorization(int n)
    {
        // all cost initialized to 0
        // since we need to store from 1-n, we choose size n+1
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
        return guessCost(1, n, dp);
    }

    int guessCost(int left, int right, vector<vector<int> >& dp)
    {
        if(left >= right)
            return 0;
        // use cache if found already computed
        if(dp[left][right])
            return dp[left][right];
        int minCost = numeric_limits<int>::max();
        for(int x = left; x <= right; ++x) {
            minCost = min(
                minCost,
                max(guessCost(left, x - 1, dp), guessCost(x + 1, right, dp)) +
                    x);
        }
        // store into cache the intermediate results
        dp[left][right] = minCost;
        return minCost;
    }


    // the above recursion with memorization can be abstracted to find the
    // state transfer formula
    // thus we can use dp without recursion
    int dpImpl(int n)
    {
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
        // cause r > l and dp[l][r] depends on x and x >= l and x <= r
        // we need to start from reverse order
        for(int l = n - 1; l > 0; --l) {
            for(int r = l + 1; r <= n; ++r) {
                dp[l][r] = numeric_limits<int>::max();
                // to void dp[x+1][r] overflow, we can stop at x < r
                // since even if x==r, and x+1 does not overflow
                // that value will be 0, no affects
                for(int x = l; x < r; ++x) {
                    dp[l][r] =
                        min(dp[l][r], max(dp[l][x - 1], dp[x + 1][r]) + x);
                }
            }
        }
        return dp[1][n];
    }

  private:
};
