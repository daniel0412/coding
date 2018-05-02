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

class 24Game
{
  public:
    bool judgePoint24(vector<int> & nums)
    {
        vector<double> data(nums.begin(), nums.end());
        vector<char> ops = {'+', '-', '*', '/'};
        double epsilon = 0.0001;
        return dfs(data, ops, epsilon);
    }

    bool dfs(
        vector<double> & data, const vector<char>& ops, const double& epsilon)
    {
        // keep reducing the size of data, when only 1 left, compare it with 24
        if(data.size() == 1) {
            return abs(data.front() - 24) < epsilon;
        }

        // pick any combination of two number
        for(size_t i = 0; i < data.size(); ++i) {
            for(size_t j = 0; j < data.size(); ++j) {
                if(i == j)
                    continue;
                // construct the next data array
                vector<double> t;
                // get all numbers that are not i/j-th
                for(size_t k = 0; k < data.size(); ++k) {
                    if(k != i && k != j)
                        t.push_back(data[k]);
                }
                // apply all possible ops on these two picked number
                for(const auto& op : ops) {
                    // for +/*, exchange two number does not matter, so ignore one side
                    if((op == '+' || op == '*') && i > j)
                        continue;
                    // for /, need to check zero
                    if(op == '/' && data[j] < epsilon)
                        continue;
                    switch(op) {
                        case '+':
                            t.push_back(data[i] + data[j]);
                            break;
                        case '-':
                            t.push_back(data[i] - data[j]);
                            break;
                        case '*':
                            t.push_back(data[i] * data[j]);
                            break;
                        case '/':
                            t.push_back(data[i] / data[j]);
                            break;
                    }
                    if(dfs(t, ops, epsilon))
                        return true;
                    // pop back for the next op loop
                    t.pop_back();
                }
            }
        }
        return false;
    }
private:
}
;
