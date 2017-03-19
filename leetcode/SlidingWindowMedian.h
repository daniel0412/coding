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
        }else{
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

    void printSets() {
        cout << "========================" << endl;
        cout << "> lsize: " << d_leftSet.size() << ", rsize: " << d_rightSet.size() << endl;
        cout << "> leftset:  ";
        for(auto d : d_leftSet) cout << d << ",";
        cout << endl;
        cout << "> leftset:  ";
        for(auto d : d_rightSet) cout << d << ",";
        cout << endl;
        cout << "========================" << endl;
    }

    multiset<int, greater<int> > d_leftSet;
    multiset<int, less<int> > d_rightSet;
};
