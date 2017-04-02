/* 284. Peeking Iterator
 *
 * Given an Iterator class interface with methods: next() and hasNext(), design
 *and implement a PeekingIterator that support the peek() operation -- it
 *essentially peek() at the element that will be returned by the next call to
 *next().
 *
 * Here is an example. Assume that the iterator is initialized to the beginning
 *of the list: [1, 2, 3].
 *
 * Call next() gets you 1, the first element in the list.
 *
 * Now you call peek() and it returns 2, the next element. Calling next() after
 *that still return 2.
 *
 * You call next() the final time and it returns 3, the last element. Calling
 *hasNext() after that should return false.
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
#include <queue>
#include <functional>
#include <utility>

using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
  public:
    Iterator(const vector<int>& nums) : d_vec(nums), d_id(0) {}
    Iterator(const Iterator& iter) : d_vec(iter.getData()), d_id(0) {}
    virtual ~Iterator(){};

    // Returns the next element in the iteration.
    int next() { return d_vec[d_id++]; }
    // Returns true if the iteration has more elements.
    bool hasNext() const { return d_id < d_vec.size(); }

  private:
    const vector<int>& getData() const { return d_vec; }
    vector<int> d_vec;
    int d_id;
};


class PeekingIterator : public Iterator {
  public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums)
    {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        d_peeked = false;
    }

    // Returns the next element in the iteration without advancing the
    // iterator.
    int peek()
    {
        if(d_peeked)
            return d_val;
        if(Iterator::hasNext()) {
            d_peeked = true;
            d_val = Iterator::next();
            return d_val;
        }
        throw runtime_error("No next element");
    }

    // hasNext() and next() should behave the same as in the Iterator
    // interface.
    // Override them if needed.
    int next()
    {
        if(d_peeked) {
            d_peeked = false;
            return d_val;
        }
        if(Iterator::hasNext()) {
            return Iterator::next();
        }
        throw runtime_error("No next element");
    }

    bool hasNext() const
    {
        if(d_peeked)
            return true;
        return Iterator::hasNext();
    }

  private:
    int d_val;
    bool d_peeked;
};
