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

class Skyline {
  public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings)
    {
        vector<pair<int, int> > pts;
        for(const auto& b : buildings) {
            pts.emplace_back(b[0], b[2]);
            pts.emplace_back(b[1], -b[2]);
        }

        // sort by the x coordinates, if tie, positive heights comes first
        // buildings: [0, 2, 3] [2, 5, 3], to make sure insertion happens
        // before remove
        sort(pts.begin(),
             pts.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first == b.first ? a.second > b.second :
                                             a.first < b.first;
             });
        multiset<int> s;
        // insert 0 to make sure after the last end point removal, we insert 0
        s.insert(0);
        vector<pair<int, int> > res;
        for(const auto& p : pts) {
            if(p.second < 0) {
                s.erase(s.find(-p.second));
            }
            else {
                s.insert(p.second);
            }
            int h = *s.rbegin();
            if(res.empty() || res.back().second != h) {
                res.emplace_back(p.first, h);
            }
        }
        return res;
    }

  private:
};
