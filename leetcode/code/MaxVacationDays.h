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
        int ncities = days.size(), nweeks = days[0].size();
        // dp[i][j]: in jth week, if stay at city i, the max  vacation days
        // then for (j+1)th week, check all possibilities
        // -1 means citi is not reachable on jth week
        vector<vector<int> > dp(ncities, vector<int>(nweeks, -1));
        int res = 0;
        for(int i = 0; i < ncities; ++i) {
            if(flights[0][i] || i == 0) {
                dp[i][0] = days[i][0];
            }
        }

        for(int w = 1; w < nweeks; ++w) {
            for(int c = 0; c < ncities; ++c) {
                for(int prevc = 0; prevc < ncities; ++prevc) {
                    // prev city is not reachable
                    if(dp[prevc][w - 1] == -1)
                        continue;
                    else if(flights[prevc][c] || prevc == c) {
                        dp[c][w] =
                            max(dp[c][w], dp[prevc][w - 1] + days[c][w]);
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
    int maxVacationDaysWithStates(vector<vector<int> >& flights,
                                  vector<vector<int> >& days)
    {
        int ncities = days.size(), nweeks = days[0].size();
        vector<vector<int> > dp(ncities, vector<int>(nweeks, -1));
        vector<vector<int> > states(ncities, vector<int>(nweeks, 0));
        int res = -1;
        int endcity = 0;
        for(int i = 0; i < ncities; ++i) {
            if(flights[0][i] || i == 0) {
                dp[i][0] = days[i][0];
            }
        }

        for(int w = 1; w < nweeks; ++w) {
            for(int c = 0; c < ncities; ++c) {
                for(int prevc = 0; prevc < ncities; ++prevc) {
                    if(dp[prevc][w - 1] == -1)
                        continue;
                    else if(flights[prevc][c] || prevc == c) {
                        int curDays = dp[prevc][w - 1] + days[c][w];
                        if(curDays > dp[c][w]) {
                            dp[c][w] = curDays;
                            states[c][w] = prevc;
                        }
                    }
                }
                if(w == nweeks - 1) {
                    if(res < dp[c][w]) {
                        res = dp[c][w];
                        endcity = c;
                    }
                }
            }
        }
        return res;
    }

    void printItenary(vector<vector<int> >& states, int endcity)
    {
        int nweeks = states[0].size();
        vector<int> res;
        res.push_back(endcity);
        for(int w = nweeks - 1; w >= 0; --w) {
            res.push_back(states[res.back()][w]);
        }
        for(auto iter = res.rbegin(); iter != res.rend(); ++iter) {
            cout << *iter << " ";
        }
        cout << endl;
    }
};
