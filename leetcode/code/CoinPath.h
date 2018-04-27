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

class CoinPath {
  public:
    vector<int> cheapestJump(vector<int>& A, int B)
    {
        if(A.back() == -1)
            return {}
        vector<int> res;
        int n = A.size();
        vector<int> dp(n + 1, numeric_limit::max()), pos(n + 1, -1);
        dp[1] = A.front();
        pos[1] = 1;
        for(int i = 2; i <= n; ++i) {
            if(A[i - 1] == -1)
                continue;
            for(int j = max(1, i - B); j < i; ++j) {
                if(pos[j] == -1)
                    continue;
                if(dp[i] > dp[j] + A[i - 1]) {
                    dp[i] = dp[j] + A[i - 1];
                    pos[i] = j;
                }
            }
        }
        int parent = pos.back();
        if(parent == -1)
            return res;
        while(parent != 1) {
            res.push_back(parent);
            parent = pos[parent];
        }
        return {res.rbegin(), res.rend()};
    }


    // from back to start
    vector<int> backtostart(vector<int>& A, int B)
    {
        if(A.empty() || A.back() == -1)
            return {};
        vector<int> pos(A.size(), -1),
            dp(A.size(), numeric_limits<int>::max());
        dp.back() = A.back();
        for(int i = A.size() - 2; i >= 0; --i) {
            if(A[i] == -1)
                continue;
            for(int j = i + 1; j < min(A.size() - 1, i + B); ++j) {
                if(dp[j] == numeric_limits<int>::max()) continue;
                int cost = A[i] + dp[j];
                if(dp[i] > cost) {
                    dp[i] = cost;
                    pos[i] = j;
                }
            }
        }
        if(dp.front() == numeric_limits<int>::max()) {
            return {};
        }
        vector<int> res;
        res.push_back(1);
        int i = 0;
        while(pos[i] != -1) {
            res.push_back(pos[i] + 1);
            i = pos[i];
        }
        return res;
    }

  private:
};
