/* 346  Moving Average from Data Stream
 *
 * Given a stream of integers and a window size,
 * calculate the moving average of all integers in the sliding window.
 *
 * For example,
 * MovingAverage m = new MovingAverage(3);
 * m.next(1) = 1
 * m.next(10) = (1 + 10) / 2
 * m.next(3) = (1 + 10 + 3) / 3
 * m.next(5) = (10 + 3 + 5) / 3
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

class MovingAvgFromDS {
  public:
    MovingAvgFromDS(int windowSize) : d_size(windowSize), d_sum(0) {}
    double next(int val)
    {
        d_sum += val;
        d_queue.push(val);
        if(d_queue.size() > d_size) {
            d_sum -= d_queue.front();
            d_queue.pop();
        }

        return d_sum * 1.0 / d_queue.size();
    }

  private:
    int d_size;
    long long d_sum;
    queue<int> d_queue;
};
