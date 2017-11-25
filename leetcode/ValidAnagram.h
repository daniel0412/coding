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

class ValidAnagram {
  public:
    bool isAnagram(string s, string t)
    {
        if(s.size() != t.size())
            return false;
        return impl1(s, t);
    }

  private:
    // sorting implementation
    bool impl1(string& s, string& t)
    {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != t[i])
                return false;
        }
        return true;
    }


    // map implementation
    bool impl1(string& s, string& t)
    {
        unordered_map<char, int> m;
        for(auto c : s) {
            ++m[c];
        }
        for(auto c : t) {
            if(--m[c] < 0)
                return false;
        }
        return true;
    }
};
