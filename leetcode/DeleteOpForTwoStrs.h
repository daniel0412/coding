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

class DeleteOpForTwoStrs {
  public:
    int minDistance(string word1, string word2)
    {
        int m1 = word1.size(), m2 = word2.size();
        vector<vector<int> > dp(m1 + 1, vector<int>(m2 + 1, 0));
        for(int i = 0; i < m1; ++i) {
            for(int j = 0; j < m2; ++j) {
                if(word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }
                else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return m1 + m2 - 2 * dp.back().back();
    }

  private:
};
