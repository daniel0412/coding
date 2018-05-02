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

class ExpressionAddOperator {
  public:
    // since only +/-/* is considered, only * needs special attention
    // keep track of previous element, such that if current op is *, minus prev
    // number, and perform multiplication
    vector<string> addOperators(string num, int target)
    {
        string path;
        vector<string> res;
        dfs(num, target, 0, 0, 0, path, res);
        return res;
    }
    // from different start, take different number of digits to form the next
    // number
    // long long to handle overflow
    void dfs(const string& num,
             int target,
             long long curRes,
             long long prev,
             size_t start,
             string path,
             vector<string>& res)
    {
        if(start == num.size()) {
            if(curRes == target) {
                res.emplace_back(path);
            }
            return;
        }
        for(int i = start; i < (int) num.size(); ++i) {
            auto tmp = num.substr(start, i - start + 1);
            long long val = stoll(tmp);
            // if this is the first number, special logic
            if(start == 0) {
                dfs(num, target, val, val, i + 1, tmp, res);
            }
            else {
                dfs(num,
                    target,
                    curRes + val,
                    val,
                    i + 1,
                    path + "+" + tmp,
                    res);
                dfs(num,
                    target,
                    curRes - val,
                    -val,
                    i + 1,
                    path + "-" + tmp,
                    res);
                dfs(num,
                    target,
                    (curRes - prev) + prev * val,
                    prev * val,
                    i + 1,
                    path + "*" + tmp,
                    res);
            }
            // if current value is 0, should not continue '012' case
            if(val == 0)
                break;
        }
    }
};
