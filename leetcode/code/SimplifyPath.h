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

class SimplifyPath {
  public:
    string simplifyPath(string path)
    {
        stack<string> mystack;
        int start = 0, pathLen = path.size();
        for(int i = 0; i < pathLen; ++i) {
            if(path[i] == '/' || i == pathLen-1) {
                int len = i-start-1;
                if(i == pathLen-1 && path[i] != '/') ++len;
                if(len > 0) {
                    string tmp = path.substr(start + 1, len);
                    if(tmp == ".") {
                        //continue;
                    }
                    else if(tmp == "..") {
                        if(!mystack.empty()) {
                            mystack.pop();
                        }
                    }
                    else {
                        mystack.push(tmp);
                    }
                }
                start = i;
            }
        }

        string res;
        while(!mystack.empty()) {
            res = "/" + mystack.top() + res;
            mystack.pop();
        }
        return res.empty() ? "/" : res;
    }

  private:
};
