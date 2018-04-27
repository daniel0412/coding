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

class MedianFromDataStream {
  public:
    MedianFromDataStream() {}

    // always make sure that size(leftMaxHeap) is equal to or 1 greater than size(rightMinHeap)
    void addNum(int num)
    {
        // should always push to leftmax if size is no greater than rightmin
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
        // leftmax size is already greater than rightmin, find correct val to push to rightmin
        else {
            if(num >= d_leftMaxHeap.top()) {
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
        else {
            return (d_leftMaxHeap.top() + d_rightMinHeap.top()) * 0.5;
        }
    }

  private:
    // ways to use std less/greater function
    priority_queue<int, vector<int>, less<int> > d_leftMaxHeap;
    priority_queue<int, vector<int>, greater<int> > d_rightMinHeap;
};


// multiset + iterator solution
class MedianFinder {
  public:
    /** initialize your data structure here. */
    MedianFinder() { d_iter = d_set.begin(); }

    void addNum(int num)
    {
        d_set.insert(num);
        if(d_set.size() == 1) {
            d_iter = d_set.begin();
        }
        else {
            // number inserted greater or equal to current pointer val
            // then inserted after it
            if(num >= *d_iter) {
                // odd numbers
                if(d_set.size() % 2) {
                    d_iter = next(d_iter);
                }
            }
            else {
                if(d_set.size() % 2 == 0) {
                    d_iter = prev(d_iter);
                }
            }
        }
    }

    double findMedian()
    {
        if(d_set.size() % 2) {
            return *d_iter;
        }
        else {
            return 0.5 * (*d_iter) + 0.5 * (*next(d_iter));
        }
    }
    multiset<int> d_set;
    multiset<int>::iterator d_iter;
};
