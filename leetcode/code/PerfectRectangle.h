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

class PerfectRectangle {
  public:
    // criteria:
    // 1) overall area is the same
    // 2) edge points occurs only once, but inner points # of occurence is even
    bool isRectangleCover(vector<vector<int> >& rectangles)
    {
        if(rectangles.empty())
            return false;
        int sumArea = 0;
        int minX = numeric_limits<int>::max();
        int minY = numeric_limits<int>::max();
        int maxX = 0, maxY = 0;
        unordered_set<string> corners;
        for(const auto& r : rectangles) {
            minX = min(minX, r[0]);
            minY = min(minY, r[1]);
            maxX = max(maxX, r[2]);
            maxY = max(maxY, r[3]);
            sumArea += ((r[2] - r[0]) * (r[3] - r[1]));
            string leftdown = to_string(r[0]) + "," + to_string(r[1]);
            string leftup = to_string(r[0]) + "," + to_string(r[3]);
            string rightdown = to_string(r[2]) + "," + to_string(r[1]);
            string rightup = to_string(r[2]) + "," + to_string(r[3]);
            if(corners.count(leftdown))
                corners.erase(leftdown);
            else
                corners.insert(leftdown);
            if(corners.count(leftup))
                corners.erase(leftup);
            else
                corners.insert(leftup);
            if(corners.count(rightdown))
                corners.erase(rightdown);
            else
                corners.insert(rightdown);
            if(corners.count(rightup))
                corners.erase(rightup);
            else
                corners.insert(rightup);
        }
        if((sumArea != ((maxX - minX) * (maxY - minY))) ||
           corners.size() != 4 ||
           !corners.count(to_string(minX) + "," + to_string(minY)) ||
           !corners.count(to_string(minX) + "," + to_string(maxY)) ||
           !corners.count(to_string(maxX) + "," + to_string(minY)) ||
           !corners.count(to_string(maxX) + "," + to_string(maxY)))
            return false;
        return true;
    }

  private:
};
