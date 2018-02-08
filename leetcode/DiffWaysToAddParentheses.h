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

class DiffWaysToAddParentheses {
  public:
    vector<int> diffWaysToCompute(string input)
    {
        vector<int> res;
        for(int i = 0; i < input.size(); ++i) {
            char c = input[i];
            if(c == '+' || c == '-' || c == '*') {
                vector<int> leftres = diffWaysToCompute(input.substr(0, i));
                vector<int> rightres = diffWaysToCompute(input.substr(i + 1));
                for(auto l : leftres) {
                    for(auto r : rightres) {
                        switch(c) {
                            case '+':
                                res.push_back(l + r);
                                break;
                            case '-':
                                res.push_back(l - r);
                                break;
                            case '*':
                                res.push_back(l * r);
                                break;
                        }
                    }
                }
            }
        }
        if(res.empty()) {
            res.push_back(atoi(input.c_str()));
        }
        return res;
    }

  private:
};
