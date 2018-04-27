/* 388. Longest Absolute File Path
 *
 * Suppose we abstract our file system by a string in the following manner:
 * The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
 *
 * dir
 *      subdir1
 *      subdir2
 *          file.ext
 *The directory dir contains an empty sub-directory subdir1 and a sub-directory
 *subdir2 containing a file file.ext.
 *
 *The string
 *"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
 *represents:
 *
 *dir
 *  subdir1
 *      file1.ext
 *      subsubdir1
 *  subdir2
 *      subsubdir2
 *          file2.ext
 * The directory dir contains two sub-directories subdir1 and subdir2.
 * subdir1 contains a file file1.ext and an empty second-level
 *sub-directorysubsubdir1.
 * subdir2 contains a second-level sub-directory subsubdir2 containing a file
 *file2.ext.
 *
 * We are interested in finding the longest (number of characters) absolute
 *path to a file within our file system.
 * For example, in the second example above, the longest absolute path is
 *"dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the
 *double quotes).
 *
 * Given a string representing the file system in the above format,
 * return the length of the longest absolute path to file in the abstracted
 *file system.
 * If there is no file in the system, return 0.
 *
 *Note:
 *  The name of a file contains at least a . and an extension.
 *  The name of a directory or sub-directory will not contain a ..
 *
 * Time complexity required: O(n) where n is the size of the input string.
 *
 * Notice that a/aa/aaa/file1.txt is not the longest file path, if there is
 *another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
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

class LongestAbsoluteFilePath {
  public:
    int lengthLongestPath(string input)
    {
        int curLen = 0, start = 0, end = 0, maxLen = 0, level = 0;
        bool isFile = false;
        while(end <= input.length()) {
            if(end == input.length()) {
                if(isFile && input[end - 1] != '.') {
                    curLen += ((end - start) + 1);
                    maxLen = maxLen > curLen ? maxLen : curLen;
                }
                break;
            }
            if(input[end++] != '\n') {
                if(input[end] == '.')
                    isFile = true;
                continue;
            }
            curLen += (end - start);

            if(isFile && end >= 1 && input[end - 2] != '.') {
                maxLen = maxLen > curLen ? maxLen : curLen;
            }
            d_stack.push(input.substr(start, end - start));
            isFile = false;
            level = 0;
            while(input[end] == '\t') {
                ++level;
                ++end;
            }
            start = end;
            while(d_stack.size() > level) {
                curLen -= d_stack.top().size();
                d_stack.pop();
            }
        }
        clearStack();
        return maxLen > 1 ? maxLen - 1 : maxLen;
    }

  private:
    void clearStack()
    {
        while(d_stack.size() > 0) {
            d_stack.pop();
        }
    }
    stack<string> d_stack;
};
