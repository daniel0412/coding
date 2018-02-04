/* 422 Valid Word Square
 *
 * Given a sequence of words, check whether it forms a valid word square.
 *
 * A sequence of words forms a valid word square if the kth row and column read
 *the exact same string, where 0 ≤k < max(numRows, numColumns).
 *
 * Note:
 *
 * The number of words given is at least 1 and does not exceed 500.
 * Word length will be at least 1 and does not exceed 500.
 * Each word contains only lowercase English alphabet a-z.
 */

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>

using namespace std;

class ValidWordSquare {
  public:
    //bool validWordSquare(vector<string>& words)
    //{
        //for(int i = 0; i < words.size(); ++i) {
            //for(int j = 0; j < words[i].size(); ++j) {
                //if(j >= words.size() || i >= words[j].size() ||
                   //words[i][j] != words[j][i]) {
                    //return false;
                //}
            //}
        //}
        //return true;
    //}

    bool validWordSquare(vector<string>& words)
    {
        if(words.size() != words[0].size())
            return false;
        for(int i = 0; i < words.size(); ++i) {
            for(int j = i + 1; j < words[i].size(); ++j) {
                if(j >= words.size() || i >= words[j].size() ||
                   words[i][j] != words[j][i])
                    return false;
            }
        }
        return true;
    }

  private:
};
