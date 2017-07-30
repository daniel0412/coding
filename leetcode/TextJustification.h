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

class TextJustification {
  public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        vector<string> res;
        if(words.empty())
            return res;
        int startId = 0, endId = 0;
        int len = 0;
        for(int i = 0; i < words.size(); ++i) {
            // cout << "processing " << i << ": " << words[i] << endl;
            endId = i;
            if(len + words[i].size() + (endId - startId) <= maxWidth) {
                len += words[i].size();
            }
            else {
                res.emplace_back(
                    format(words, maxWidth, len, startId, endId - 1));
                startId = i;
                len = words[i].size();
            }
        }
        len = words[startId].size();
        string tmp = words[startId++];
        for(; startId < words.size(); ++startId) {
            len += 1;
            len += words[startId].size();
            tmp.append(1, ' ');
            tmp.append(words[startId]);
        }
        tmp.append(maxWidth - len, ' ');
        res.emplace_back(tmp);
        return res;
    }

  private:
    string format(vector<string>& words,
                  const int maxWidth,
                  const int len,
                  int startId,
                  int endId)
    {
        // cout << "formatting " << words[startId] << "->" << words[endId] <<
        // endl;
        string res;
        if(endId == startId) {
            res = words[startId];
            res.append(maxWidth - len, ' ');
        }
        else {
            int diff = maxWidth - len;
            int nIntervals = endId - startId;
            int numSpace = diff / nIntervals;
            int extraSpace = diff % nIntervals;
            res = words[startId];
            for(int i = startId + 1; i <= endId; ++i) {
                if(i > startId <= extraSpace) {
                    res.append(1, ' ');
                }
                res.append(numSpace, ' ');
                res.append(words[i]);
            }
        }
        return res;
    }
};
