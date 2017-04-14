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

template <typename T>
T lowerBound(const vector<T>& nums, T target)
{
    int l = 0, r = nums.size() - 1, m;
    while(l <= r) {
        m = (r - l) / 2 + l;
        if(nums[m] < target) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return l;
}

template <typename T>
T upperBound(const vector<T>& nums, T target)
{
    int l = 0, r = nums.size() - 1, m;
    while(l <= r) {
        m = (r - l) / 2 + l;
        if(nums[m] <= target) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return l;
}
