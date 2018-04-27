/* 533. Lonely Pixel II
 *
 * Given a picture consisting of black and white pixels, and a positive integer
 *N, find the number of black pixels located at some specific row R and column
 *C that align with all the following rules:
 *
 * Row R and column C both contain exactly N black pixels.
 * For all rows that have a black pixel at column C, they should be exactly the
 *same as row R
 * The picture is represented by a 2D char array consisting of 'B' and 'W',
 *which means black and white pixels respectively.
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

class LonelyPixel2 {
  public:
    int findBlackPixel(vector<vector<char> >& pic, int N)
    {
        if(pic.empty() || pic[0].empty())
            return 0;

        int count = 0;
        int numRows = pic.size(), numCols = pic[0].size();

        vector<vector<int> > bpColIndices(numRows, vector<int>());
        vector<vector<int> > bpRowIndices(numCols, vector<int>());

        vector<string> rowStrs;
        unordered_map<string, unordered_set<int> > rowToIndexMap;

        for(int i = 0; i < numRows; ++i) {
            string s;
            for(int j = 0; j < numCols; ++j) {
                s.push_back(pic[i][j]);
                if(pic[i][j] == 'B') {
                    bpColIndices[i].push_back(j);
                    bpRowIndices[j].push_back(i);
                }
            }
            rowStrs.push_back(s);
            rowToIndexMap[s].insert(i);
        }
        for(int i = 0; i < numRows; ++i) {
            for(int j = 0; j < numCols; ++j) {
                if(pic[i][j] == 'B' && bpColIndices[i].size() == N &&
                   bpRowIndices[j].size() == N) {
                    string s = rowStrs[bpRowIndices[j][0]];
                    bool isLonly = true;
                    for(auto id : bpRowIndices[j]) {
                        if(rowToIndexMap[s].count(id) == 0) {
                            isLonly = false;
                            break;
                        }
                    }
                    if(isLonly)
                        ++count;
                }
            }
        }
        return count;
    }

  private:
};
