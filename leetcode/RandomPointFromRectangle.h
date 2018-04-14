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

class RandomPointFromRectangle {
  public:
    struct Rectangle {
        int width;
        int height;
        pair<int, int> leftDown;
    };

    // random point from single rectangle
    // x/y are orthogonal, so generate separate x/y
    pair<int, int> getRandom(const Rectangle& rec) {
        int x = rec.leftDown.first + rand() % width;
        int y = rec.leftDown.second + rand() % height;
        return {x, y};
    }

    // random point from list of rectangles
    pair<int, int> getRandom2(const vector<Rectangle>& recs) {
        vector<int> presum(recs.size()+1, 0);
        for(int i = 1; i <= recs.size(); ++i) {
            presum[i] = presum[i-1] + getArea(res);
        }
        int randomNum = rand() % presum.back();
        auto iter = presum.upper_bound(randomNum);
        int selectedId = iter-presum.begin() - 1;
        return getRandom(recs[selectedId]);
    }

    // random point from list of overlapped rectangles
    // case1) points in rectangle are discrete (get list of points)
    // case2) points in rectangle are continuous

  private:
};
