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

class AddBoldTagInStr {
  public:
    string addBoldTag(string s, vector<string>& dict)
    {
        vector<bool> flags(s.size(), false);
        int end = -1;
        for(int i = 0; i < s.size(); ++i) {
            for(const auto& w : dict) {
                int len = w.size();
                if(i + len < s.size() && s.substr(i, len) == w) {
                    // greedy to identify the longest matched str
                    end = max(end, i + len);
                }
            }
            flags[i] = end > i;
        }
        int i = 0;
        string res;
        while(i < s.size()) {
            if(flags[i]) {
                int len = 0;
                while(flags[i]) {
                    ++len;
                    ++i;
                }
                res = res + ("<b>" + s.substr(i, len) + "</b>");
            }
            else {
                res.push_back(s[i]);
            }
        }
        return res;
    }

  private:
};
