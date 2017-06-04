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

          // fill the res string from the max heap
          const char DEFAULT_CHAR = '0';
          int len = str.size();
          string res(len, DEFAULT_CHAR);

          while(!q.empty()) {
              pair<int, char> p = q.top();
              // find first '0'
              int startId = res.find_first_of(DEFAULT_CHAR);
              for(int i = 0; i < p.first; ++i) {
                  int nextId = startId + i * k;
                  if(nextId >= len) return "";
                  res[nextId] = p.second;
              }
              q.pop();
          }
          return res;
      }

  private:
};
