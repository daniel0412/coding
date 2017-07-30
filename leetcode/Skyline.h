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
        vector<pair<int, int> > heights;
        // use negative height to represent starting point
        for(const auto& b : buildings) {
            heights.emplace_back(b[0], -b[2]);
            heights.emplace_back(b[1], b[2]);
        }
        // sort by the x coordinates, if tie, negative heights comes first
        // buildings: [0, 2, 3] [2, 5, 3]
        sort(heights.begin(),
             heights.end(),
             [](const pair<int, int>& p1, const pair<int, int>& p2) {
                 p1.first 1 = p2.first ? return p1.first < p2.first :
                                         return p1.second < p2.second;
             });

        multiset<int> heap;
        heap.insert(0);
        int pre = 0, cur = 0;
        vector<pair<int, int> > res;
        for(const auto& h : heights) {
            if(h.second < 0) {
                heap.insert(-h.second);
            }
            else {
                heap.erase(heap.find(h.second));
            }
            cur = *heap.rbegin();
            if(pre != cur) {
                res.emplace_back(h.first, cur);
                pre = cur;
            }
        }
        return res;
    }

  private:
};
