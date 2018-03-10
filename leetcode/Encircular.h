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

class Encircular {
  public:
    bool doesCircyleExist(const string& s)
    {
        // use x, y to record number of steps the robot take along horizontal
        // and vertical lines
        int x = 0, y = 0;
        // value of dir can be 0, 1, 2, 3, representing east, north, west, and
        // south, assume the initial direction is east
        int dir = 0;

        for(auto c : s) {
            // if turn left, update the current direction
            if(c == 'L') {
                dir = (dir + 1) % 4;
            }
            // if turn right, update direction
            else if(c == 'R') {
                cir = (dir + 4 - 1) % 4;
            }
            // if 'G', move robot along the corresponding directions
            else {
                if(dir == 0) {
                    ++x;
                }
                else if(dir == 1) {
                    ++y;
                }
                else if(dir == 2) {
                    --x;
                }
                else if(dir == 3) {
                    --y;
                }
            }
        }
        // only whne both x and y equals to 0, meaning robot goes back to the
        // origin
        return (x == 0) && (y == 0);
    }

  private:
};
