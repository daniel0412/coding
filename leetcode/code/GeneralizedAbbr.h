/*
 * Write a function to generate the generalized abbreviations of a word.
 *
 * Example:
 *
 * Given word = "word", return the following list (order does not matter):
 *
 * ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d",
 *"1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
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
#include <algorithm>
#include <utility>
#include "utils.h"

using namespace std;

class GeneralizedAbbr {
  public:
    vector<string> generateAbbreviations(string word)
    {
        vector<string> res;
        dfsImpl(res, word, 0);
        return res;
    }

  private:
    void dfsImpl(vector<string>& res, string w, int id)
    {
        // format the abbreviated word
        if(id == w.size()) {
            string s;
            int cnt = 0;
            for(const auto c : w) {
                if(c == '1')
                    ++cnt;
                else {
                    if(cnt > 0) {
                        s = s + to_string(cnt);
                        cnt = 0;
                    }
                    s.push_back(c);
                }
            }
            if(cnt > 0)
                s = s + to_string(cnt);
            res.push_back(s);
            return;
        }
        dfsImpl(res, w, id + 1);
        w[id] = '1';
        dfsImpl(res, w, id + 1);
    }

    void impl(vector<string>& res, string w, int id)
    {
        // loop over all starting index
        for(int i = id; i < (int) w.size(); ++i) {
            // loop over all possible length for abbreviation
            for(int j = 1; i + j <= (int) w.size(); ++j) {
                string t = w.substr(0, i);
                string cnt = to_string(j);
                t = t + cnt + w.substr(i + j);
                res.emplace_back(t);
                // do the same thing for the abbreviated word
                // but need to make sure there is at least 1 in between two numbers
                impl(res, t, i + cnt.size() + 1);
            }
        }
    }
};
