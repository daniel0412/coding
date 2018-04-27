/* 480. Sliding Window Median
 *
 * Given an array nums, there is a sliding window of size k which is moving
 *from the very left of the array to the very right.
 * You can only see the k numbers in the window. Each time the sliding window
 *moves right by one position.
 * Your job is to output the median array for each window in the original
 *array.
 */

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <functional>

using namespace std;

class SlidingWindowMedian {
  public:
    // one multiset implementation
    vector<double> medianSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> res;
        multiset<int> ms(nums.begin(),
                         nums.begin() + k);  // with first k elements
        auto midIter = next(nums.begin(), k / 2);
        bool isodd = k % 2;
        int i = k;
        while(1) {
            if(isodd) {
                res.push_back(*midIter);
            }
            else {
                // incase overflow
                res.push_back((*midIer)/2.0+ *prev(midIter, 1) / 2.0);
            }
            if(i == nums.size())
                break;

            // insert next element, if equals to existing element, it will
            // insert right after the equivalent element
            ms.insert(nums[i]);
            // here, only <, no equal, due to reason mentioned above
            if(nums[i] < *midIter)
                --midIter;
            if(nums[i - k] <= *midIter)
                ++midIter;
            // pass an iterator, since erase will remove all same elements
            ms.erase(ms.lower_bound(nums[i - k]));
            ++i;
        }
        return res;
    }

    // following is two multiset implementation
    vector<double> medianSlidingWindow(vector<int>& nums, int k)
    {
        vector<double> res;
        for(int i = 0; i < k; ++i) {
            addNum(nums[i]);
        }
        res.push_back(getMedian());

        for(int i = k; i < nums.size(); ++i) {
            deleteNum(nums[i - k]);
            addNum(nums[i]);
            res.push_back(getMedian());
        }
        return res;
    }

  private:
    void addNum(int n)
    {
        if(d_leftSet.size() == 0) {
            d_leftSet.insert(n);
            return;
        }
        if(d_leftSet.size() <= d_rightSet.size()) {
            if(n <= *d_rightSet.begin()) {
                d_leftSet.insert(n);
            }
            else {
                d_leftSet.insert(*d_rightSet.begin());
                d_rightSet.erase(d_rightSet.begin());
                d_rightSet.insert(n);
            }
        }
        else {
            if(n >= *d_leftSet.begin()) {
                d_rightSet.insert(n);
            }
            else {
                d_rightSet.insert(*d_leftSet.begin());
                d_leftSet.erase(d_leftSet.begin());
                d_leftSet.insert(n);
            }
        }
    }

    void deleteNum(int n)
    {
        auto rightIter = d_rightSet.find(n);
        if(rightIter != d_rightSet.end()) {
            d_rightSet.erase(rightIter);
        }
        else {
            d_leftSet.erase(d_leftSet.find(n));
        }
    }

    double getMedian()
    {
        if(d_leftSet.size() == d_rightSet.size()) {
            return *d_leftSet.begin() * 0.5 + *d_rightSet.begin() * 0.5;
        }
        else {
            return *d_leftSet.begin();
        }
    }

    void printSets()
    {
        cout << "========================" << endl;
        cout << "> lsize: " << d_leftSet.size()
             << ", rsize: " << d_rightSet.size() << endl;
        cout << "> leftset:  ";
        for(auto d : d_leftSet)
            cout << d << ",";
        cout << endl;
        cout << "> leftset:  ";
        for(auto d : d_rightSet)
            cout << d << ",";
        cout << endl;
        cout << "========================" << endl;
    }

    multiset<int, greater<int> > d_leftSet;
    multiset<int, less<int> > d_rightSet;
};
