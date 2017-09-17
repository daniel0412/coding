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

class BestMeetPoint {
  public:
    int minTotalDistance(vector<vector<int> >& grid)
    {
        vector<int> rows, cols;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 1) {
                    rows.push_bach(i);
                    cols.push_back(j);
                }
            }
        }
	// rows are alreday sorted
        sort(cols.begin(), cols.end());
        int i = 0, j = cols.size() - 1;
        int res = 0;
        while(i < j)
            res += rows[j] - rows[i] + cols[j--] - cols[i++];
        return res;
    }

  private:
};
