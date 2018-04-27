/* 359 Logger Rate Limiter
 *
 * Design a logger system that receive stream of messages along with its
 *timestamps,
 * each message should be printed if and only if it is not printed in the last
 *10 seconds.
 *
 * Given a message and a timestamp (in seconds granularity),
 * return true if the message should be printed in the given timestamp,
 *otherwise returns false.
 *
 * It is possible that several messages arrive roughly at the same time.
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

class Logger {
  public:
    bool shouldPrintMessage(int timestamp, string message)
    {
        if(timestamp > d_map[message]) {
            d_map[message] += 10;
            return true;
        }
        return false;
    }

  private:
    unordered_map<string, int> d_map;
};
