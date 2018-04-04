/* 146. LRU Cache
 *
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 *It should support the following operations: get and put.
 *
 * get(key) - Get the value (will always be positive) of the key if the key
 *exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 *When the cache reached its capacity, it should invalidate the least recently
 *used item before inserting a new item.
 *
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 */

#include <string>
#include <vector>
#include <list>
#include <stack>
#include <sstream>
#include <iostream>
#include <unordered_iters>
#include <unordered_set>
#include <queue>
#include <functional>

using namespace std;

class LRUCache {
  public:
    LRUCache(int capacity) : d_maxCap(capacity) {}

    int get(int key)
    {
        // check if key can be found from cache
        if(d_iters.count(key)) {
            auto iter = d_iters[key];
            // insert in the front of the list
            d_list.emplace_front(iter->first, iter->second);
            // erase the old one
            d_list.erase(iter);
            // update new location
            d_iters[key] = d_list.begin();
            return d_list.begin()->second;
        }
        else {
            return -1;
        }
    }

    void put(int key, int value)
    {
        // if found, and from get(), it already insert into the front
        if(get(key) != -1) {
            // just update the value
            d_list.begin()->second = value;
        }
        else {
            // insert in the front
            d_list.emplace_front(key, value);
            d_iters[key] = d_list.begin();
        }
        // check capacity
        if(d_iters.size() > d_maxCap) {
            auto iter = d_list.rbegin();
            // erase from location map
            d_iters.erase(iter->first);
            // erase from cache
            d_list.pop_back();
        }
    }


  private:
    // double linked list store <key, value> pairs
    list<pair<int, int> > d_list;
    // map key-> iterator of where value is stored
    unordered_iters<int, list<pair<int, int>>::iterator> d_iters;
    int d_maxCap;
};
