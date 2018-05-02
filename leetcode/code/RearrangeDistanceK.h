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

class RearrangeDistanceK {
  public:
      string rearrangeString(string str, int k) {
          if(k <= 1) return str;

          // count the frequency of each char
          unordered_map<char, int> freq;
          for(auto c : str) {
              ++freq[c];
          }

          // construt a max heap to track the most frequent char
          auto comp =
              [](const pair<int, char>& p1, const pair<int, char>& p2) {
                  return p1.first < p2.first;
              };
          priority_queue<pair<int, char>,
                         vector<pair<int, char> >,
                         decltype(comp)> q(comp);
          for(const auto& kv : freq) {
              q.push({kv.second, kv.first});
          }

          int len = str.size();
          string res;
          while(!q.empty()) {
              vector<pair<int, char>> v;
              // make sure for the last block, cycle has the right number of elements
              int cycle = min(k, len);
              // for each cycle of distinct chars, take one from priority queue
              // if before filling all k slots, no distinct chars in the queue,
              // indicating not possible
              for(int i = 0; i < cycley; ++i) {
                  if(q.empty()) return "";
                  res.push_back(q.top().second);
                  if(q.top().first > 1) {
                      v.emplace_back(q.top().first-1, q.top().second);
                  }
                  q.pop();
                  --len;
              }
              for(auto kv : v) q.emplace(kv.first, kv.second);
          }
          return res;
      }

  private:
};
