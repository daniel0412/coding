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

class InsertDeleteGetrandom {
  public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already
     * contain the specified element. */
    bool insert(int val)
    {
        if(d_m.count(val))
            return false;
        d_vec.push_back(val);
        d_m[val] = d_vec.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the
     * specified element. */
    bool remove(int val)
    {
        if(d_m.find(val) == d_m.end())
            return false;
        size_t id = d_m[val];
        d_m[d_vec.back()] = id;
        swap(d_vec.back(), d_vec[id]);
        d_m.erase(val);
        d_vec.pop_back();
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() { return d_vec[rand() % d_vec.size()]; }

    vector<int> d_vec;
    unordered_map<int, size_t> d_m;
};
