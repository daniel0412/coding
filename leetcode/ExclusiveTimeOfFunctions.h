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

class ExclusiveTimeOfFunctions {
  public:
      vector<int> exclusiveTime(int n, vector<string>& logs) {
          vector<int> res(n, 0);
          stack<int> s;
          int id, time;
          char type;
          int prevTime = 0;
          for(const auto& log : logs) {
              parse(log, id, type, time);
              if(type == 's') {
                  if(!s.empty()) {
                      res[s.top()] += (time - prevTime);
                  }
                  s.push(id);
              } else {
                  res[s.top()] += (++time - prevTime);
                  s.pop();
              }
              prevTime = time;
          }
          return res;
      }
  private:
    void parse(const string& log, int& id, char& type, int& time)
    {
        size_t i = log.find_first_of(":");
        id = stoi(log.substr(0, i));
        size_t j = log.find_last_of(":");
        type = log[i + 1];
        time = stoi(log.substr(j + 1));
    }
};
