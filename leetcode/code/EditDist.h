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

class EditDist {
  public:
      // time complexity: O(m*n)
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for(int i = 0; i <= n1; ++i) {
            dp[i][0] = i;
        }
        for(int i = 0; i <= n2; ++i) {
            dp[0][i] = i;
        }
        for(int i = 1; i <= n1; ++i) {
            for(int j = 1; j<=n2; ++j) {
                if(word1[i-1]==word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        return dp[n1][n2];
    }

    // return recursiveImpl(word1, word2, 0, 0);
    int recursiveImpl(const string& w1, const string& w2, int i1, int i2)
    {
        if(i1 == w1.size())
            return w2.size() - i2;
        if(i2 == w2.size())
            return w1.size() - i1;
        if(w1[i1] == w2[i2])
            return recursiveImpl(w1, w2, i1 + 1, i2 + 1);
        return min(min(recursiveImpl(w1, w2, i1 + 1, i2),
                       recursiveImpl(w1, w2, i1, i2 + 1)),
                   recursiveImpl(w1, w2, i1 + 1, i2 + 1)) +
            1;
    }
}

private:
}
;
