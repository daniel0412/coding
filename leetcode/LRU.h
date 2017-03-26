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
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>

using namespace std;

class LRUCache {
  public:
    LRUCache(int capacity) : d_capacity(capacity) {}

    int get(int key)
    {
        MAPTYPE::iterator iter = d_map.find(key);
        if(iter == d_map.end())
            return -1;
        d_list.push_front(*(iter->second));
        d_list.erase(iter->second);
        d_map[key] = d_list.begin();
        return d_map[key]->second;
    }

    void put(int key, int value)
    {
        if(d_map.size() >= d_capacity) {
            d_map.erase(d_list.rbegin()->first);
            d_list.pop_back();
        }
        d_list.push_front(make_pair(key, value));
        d_map[key] = d_list.begin();
    }


  private:
    typedef pair<int, int> NODE;
    typedef unordered_map<int, list<NODE>::iterator> MAPTYPE;
    MAPTYPE d_map;
    list<pair<int, int> > d_list;
    int d_capacity;
};
