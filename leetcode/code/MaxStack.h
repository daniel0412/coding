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

class MaxStack {
  public:
    void push(int v)
    {
        _list.push_front(v);
        _map[v].push_back(_list.begin());
    }
    void pop()
    {
        int v = *_list.begin();
        _list.pop_front();
        _map[v].pop_back();
        if(_map[v].empty())
            _map.erase(v);
    }
    int top() { return *_list.begin(); }
    int peekMax() { return m.rbegin()->first; }
    int popMax()
    {
        int x = _map.rbegin()->first;
        _list.erase(_map[x].back());
        _map[x].pop_back();
        if(_map[x].empty())
            _map.erase(x);
        return x;
    }

  private:
    list<int> _list;
    map<int, vector<list<int>::iterator> > _map;
};
