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

class FallingSquares {
  public:
    vector<int> fallingSquares(vector<pair<int, int> >& positions)
    {
        // stores starting index, and max height start from this starting index
        map<int, int> m = {{0, 0}, {numeric_limits<int>::max(), 0}};
        int maxH = 0;
        vector<int> res;
        for(const auto& p : positions) {
            // locate range [s, e)
            int s = p.first, e = p.first + p.second;
            // in case s is not in the map, find upper bound, and can start from prev iter to find curMax
            auto iteri = m.upper_bound(s);
            // since e is not included, can use lower bound
            auto iterj = m.lower_bound(e);

            // new right bound heigh
            int tmp = iterj->first == e ? iterj->second : prev(iterj)->second;
            int curMax = 0;
            //
            auto iter = prev(iteri);
            while(iter != iterj) {
                curMax = max(curMax, iter->second);
                ++iter;
            }
            // erase all values between (s, e), since s will be overwritten
            m.erase(iteri, iterj);
            curMax += p.second;
            // new height for left
            m[s] = curMax;
            // new heigh for right
            m[e] = tmp;
            maxH = max(maxH, curMax);
            res.push_back(maxH);
        }
        return res;
    }

  private:
};
