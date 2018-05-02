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
        int i = 0, len = path.size();
        stack<string> s;
        while(i < len) {
            string tmp = getNext(path, i);
            if(tmp.empty() || tmp == ".")
                continue;
            if(tmp == "..") {
                // corner case "/../"
                if(!s.empty())
                    s.pop();
            }
            else {
                s.push(tmp);
            }
        }
        if(s.empty())
            return "/";
        string res;
        while(!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }
        // empty case
        return res.empty() ? "/" : res;
    }

    string getNext(const string& path, int& i)
    {
        int len = path.size();
        if(i >= len)
            return "";
        if(i < len && path[i] == '/')
            ++i;
        int start = i, end = start;
        while(end < len && path[end] != '/') {
            ++end;
        }
        i = end;
        return path.substr(start, end - start);
    }

  private:
};
