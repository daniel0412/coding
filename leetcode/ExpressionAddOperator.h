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
    vector<string> addOperators(string num, int target)
    {
        vector<string> res;
	// attention to overflow
        long cv;
        string path;
        // find the first operator value, the following can use recursion
        // (operator, val)
        for(int i = 0; i < num.size(); ++i) {
            path = num.substr(0, i + 1);
            cv = stol(path);
            dfs(num, i + 1, target, res, path, cv, cv, '+');
            if(num[0] == '0')
                break;
        }
        return res;
    }

  private:
    void dfs(const string& num,
             int pos,
             const int target,
             vector<string>& res,
             string path,
             long cv,
             const long preVal,
             const char op)
    {
        if(pos == num.size()) {
            if(target == cv)
                res.push_back(path);
            return;
        }
        for(int i = pos; i < num.size(); ++i) {
            if(num[pos] == '0' and i > pos)
                return;
            string cur = num.substr(pos, i - pos + 1);
            long curVal = stol(cur);
            dfs(num,
                i + 1,
                target,
                res,
                path + "+" + cur,
                cv + curVal,
                curVal,
                '+');
            dfs(num,
                i + 1,
                target,
                res,
                path + "-" + cur,
                cv - curVal,
                -curVal,
                '-');
            dfs(num,
                i + 1,
                target,
                res,
                path + "*" + cur,
                cv - preVal + preVal * curVal,
                preVal * curVal,
                op);  // this op is always the latest non-'*' operator
        }
    }
};
