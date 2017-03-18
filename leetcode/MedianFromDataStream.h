/* 295. Find Median from Data Stream
 *
 * Design a data structure that supports the following two operations:
 *  - void addNum(int num) - Add a integer number from the data stream to the
 *data structure.
 *  - double findMedian() - Return the median of all elements so far.
 */

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>

using namespace std;

static auto lessCmp = [](const int a, const int b) { return a < b; };
static auto greaterCmp = [](const int a, const int b) { return a > b; };

class MedianFromDataStream {
  public:
    MedianFromDataStream() {}

    void addNum(int num)
    {
        if(d_leftMaxHeap.size() <= d_rightMinHeap.size()) {
            if(d_leftMaxHeap.size() == 0 || num <= d_rightMinHeap.top()) {
                d_leftMaxHeap.push(num);
            }
            else {
                d_leftMaxHeap.push(d_rightMinHeap.top());
                d_rightMinHeap.pop();
                d_rightMinHeap.push(num);
            }
        }
        else {
            if(d_rightMinHeap.size() == 0 || num >= d_leftMaxHeap.top()) {
                d_rightMinHeap.push(num);
            }
            else {
                d_rightMinHeap.push(d_leftMaxHeap.top());
                d_leftMaxHeap.pop();
                d_leftMaxHeap.push(num);
            }
        }
    }

    double findMedian()
    {
        if(d_leftMaxHeap.size() > d_rightMinHeap.size())
            return d_leftMaxHeap.top();
        else{
            return (d_leftMaxHeap.top() + d_rightMinHeap.top()) * 0.5;
        }
    }

  private:
    priority_queue<int, vector<int>, decltype(lessCmp)> d_leftMaxHeap(lessCmp);
    priority_queue<int, vector<int>, decltype(greaterCmp)> d_rightMinHeap(greaterCmp);

     //priority_queue<int, vector<int>, less<int> > d_leftMaxHeap;
     //priority_queue<int, vector<int>, greater<int> > d_rightMinHeap;
};
