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

class InsertDeleteGetrandomII {
  public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}

    /** Inserts a value to the collection. Returns true if the collection did
     * not already contain the specified element. */
    bool insert(int val)
    {
        d_v.push_back(val);
        d_m[val].insert(d_v.size() - 1);
        return d_m[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection
     * contained the specified element. */
    bool remove(int val)
    {
        if(d_m[val].empty())
            return false;

        int id = *d_m[val].begin();
        d_m[val].erase(id);
        if(d_v.size() - 1 != id) {
            int tmp = d_v.back();
            swap(d_v[id], d_v.back());
            d_m[tmp].erase(d_v.size() - 1);
            d_m[tmp].insert(id);
        }
        d_v.pop_back();
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom()
    {
        if(d_v.empty())
            return -1;
        return d_v[rand() % d_v.size()];
    }

    unordered_map<int, unordered_set<size_t> > d_m;
    vector<int> d_v;

  private:
};
