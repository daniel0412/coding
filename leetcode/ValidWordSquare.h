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
    bool validWordSquare(vector<string>& words)
    {
        if(words.empty()) return true;
        if(words.size() != words[0].size())
            return false;
        // have to validate all matrix, not upper/lower triangle
        // since it might be triangle has more chars
        for(size_t i = 0; i < words.size(); ++i) {
            for(size_t j = 0; j < words[i].size(); ++j) {
                if(j >= words.size() || i >= words[j].size() ||
                   words[i][j] != words[j][i])
                    return false;
            }
        }
        return true;
    }

  private:
};

int main() {
    vector<string> words;
    words.emplace_back("abcde");
    words.emplace_back("bgeh");
    words.emplace_back("cei");
    words.emplace_back("dh");
    words.emplace_back("e");

    ValidWordSquare sol;
    cout << "valid: " << sol.validWordSquare(words) << endl;

    return 0;
}
