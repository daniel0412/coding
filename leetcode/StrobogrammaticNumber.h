/*  246 Strobogrammatic Number
 * A strobogrammatic number is a number that looks the same when rotated 180
 *degrees (looked at upside down).
 *
 * Write a function to determine if a number is strobogrammatic. The number is
 *represented as a string.
 *
 * For example, the numbers "69", "88", and "818" are all strobogrammatic.
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

class StrobogrammaticNumber {
  public:
    bool isStrobogrammatic(string num)
    {
        unordered_map<char, char> lookupMap{
            {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        int i = 0, j = num.size() - 1;
        while(i <= j) {
            if(lookupMap[num[i++]] != num[j--])
                return false;
        }
        return true;
    }

  private:
};
