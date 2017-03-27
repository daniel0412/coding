/* 460. LFU Cache
 *
 * Design and implement a data structure for Least Frequently Used (LFU) cache.
 *It should support the following operations: get and put.
 *
 * get(key) - Get the value (will always be positive) of the key if the key
 *exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 *When the cache reaches its capacity, it should invalidate the least
 *frequently used item before inserting a new item. For the purpose of this
 *problem, when there is a tie (i.e., two or more keys that have the same
 *frequency), the least recently used key would be evicted.
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
#include <utility>

using namespace std;

class LFUCache {
  public:
    LFUCache(int capacity) : d_capacity(capacity), d_minFreq(0) {}

    int get(int key)
    {
        KVMAP::iterator iter = d_kvMap.find(key);
        if(iter == d_kvMap.end())
            return -1;
        d_freqMap[iter->second.freq].erase(iter->second.loc);
        if(d_minFreq == iter->second.freq &&
           d_freqMap[iter->second.freq].size() == 0)
            ++d_minFreq;
        d_freqMap[++iter->second.freq].push_front(key);
        iter->second.loc = d_freqMap[iter->second.freq].begin();
        return iter->second.value;
    }

    void put(int key, int value)
    {
        if(d_kvMap.count(key) != 0) {
            KVMAP::iterator iter = d_kvMap.find(key);
            iter->second.value = value;
            d_freqMap[iter->second.freq].erase(iter->second.loc);
            if(d_minFreq == iter->second.freq &&
               d_freqMap[iter->second.freq].size() == 0)
                ++d_minFreq;

            d_freqMap[++iter->second.freq].push_front(key);
            iter->second.loc = d_freqMap[iter->second.freq].begin();
            return;
        }
        if(d_capacity <= d_kvMap.size()) {
            d_kvMap.erase(d_freqMap[d_minFreq].back());
            d_freqMap[d_minFreq].pop_back();
        }

        d_freqMap[1].push_front(key);
        d_kvMap[key].value = value;
        d_kvMap[key].freq = 1;
        d_kvMap[key].loc = d_freqMap[1].begin();
        d_minFreq = 1;
    }

  private:
    int d_capacity;
    int d_minFreq;
    struct ValueNode {
        int value;
        int freq;
        list<int>::iterator loc;
    };
    typedef unordered_map<int, ValueNode> KVMAP;
    KVMAP d_kvMap;
    unordered_map<int, list<int> > d_freqMap;
};
