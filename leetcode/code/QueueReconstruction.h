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

class QueueReconstruction {
  public:
    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people)
    {
        sort(people.begin(),
             people.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first == b.first ? a.second < b.second :
                                             a.first > b.first;
             });
        for(int i = 0; i < people.size(); ++i) {
            auto p = people[i];
            if(i != people[i].second) {
                people.erase(people.begin() + i);
                people.insert(people.begin() + p.second, p);
            }
        }
        return people;
    }

  private:
};
