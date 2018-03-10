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

class FindCloseColor {
  public:
    // define Color structure, and interfeace to calculate euclidean distance
    // between two colors
    struct Color {
        Color(int red, int green, int blue)
            : d_red(red), d_green(green), d_blue(blue)
        {
        }
        int dist(const Color& c)
        {
            return pow(d_red - c.d_reid, 2) + pow(d_green - c.d_green, 2) +
                pow(d_blue - c.d_blue, 2);
        }
        int d_red;
        int d_green;
        int d_blue;
    };
    vector<string> findclosecolor(const vector<string>& colors)
    {
        // construct map from color name to color
        unordered_map<string, Color> pureColors;
        pureColors["black"] = {0, 0, 0};
        pureColors["white"] = {255, 255, 255};
        pureColors["red"] = {255, 0, 0};
        pureColors["green"] = {0, 255, 0};
        pureColors["blue"] = {0, 0, 255};

        vector<string> res(colors.size());

        // loop over all given color bit strings, to find the closest color
        for(int i = 0; i < colors.size(); ++i) {
            const Color& c = colors[i];
            int cnt = 0, minDist = numeric_limit<int>::max();
            // compute the distance from all pure colors, and find and track
            // the closest one
            for(const auto& p : pureColors) {
                int dist = c.dist(p.second);
                if(minDist > dist) {
                    cnt = 1;
                    minDist = dist;
                    res[i] = p.first;
                }
                else if(minDist == dist) {
                    ++cnt;
                }
            }
            if(cnt > 1) {
                res[i] = "ambiguous";
            }
        }
        return res;
    }

  private:
};
