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

class MaxVacationDays {
  public:
    int maxVacationDays(vector<vector<int> >& flights,
                        vector<vector<int> >& days)
    {
        int ncities = flights.size(), nweeks = days[0].size();
        vecto<vector<int> > dp(ncities, vector<int>(nweeks, -1));
        int res = -1;
        for(int i = 0; i < ncities; ++i) {
            if(flights[0][i] || i == 0)
                dp[i][0] = days[i][0];
        }
        for(int w = 1; w < nweeks; ++w) {
            for(int c = 0; c < ncities; ++c) {
                for(int p = 0; p < ncities; ++p) {
                    if(dp[p][w - 1] == -1)
                        continue;
                    if(p == c || flights[p][c]) {
                        dp[c][w] = max(dp[c][w], dp[p][w - 1] + days[c][w]);
                    }
                }
                if(w == nweeks - 1) {
                    res = max(res, dp[c][w]);
                }
            }
        }
        return res;
    }

  private:
};
