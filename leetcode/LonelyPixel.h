/* 531. Lonely Pixel I
 *
 * Given a picture consisting of black and white pixels, find the number of
 *black lonely pixels.
 *
 * The picture is represented by a 2D char array consisting of 'B' and 'W',
 *which means black and white pixels respectively.
 *
 * A black lonely pixel is character 'B' that located at a specific position
 *where the same row and same column don't have any other black pixels.
 *
 *
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
#include <queue>
#include <functional>
#include <utility>

using namespace std;

class LonelyPixel {
  public:
    int findLonelyPixle(vector<vector<char> >& pic)
    {
        int count = 0;
        if(pic.empty() || pic[0].empty())
            return count;
        int numRows = pic.size(), numCols = pic[0].size();
        vector<int> rowCounts(numRows, 0);
        vector<int> colCounts(numCols, 0);
        for(int i = 0; i < numRows; ++i) {
            for(int j = 0; j < numCols; ++j) {
                if(pic[i][j] == 'B') {
                    ++rowCounts[i];
                    ++colCounts[j];
                }
            }
        }

        for(int i = 0; i < numRows; ++i) {
            for(int j = 0; j < numCols; ++j) {
                if(pic[i][j] == 'B' && rowCounts[i] == 1 &&
                   colCounts[j] == 1) {
                    ++count;
                }
            }
        }
        return count;
    }

  private:
};
