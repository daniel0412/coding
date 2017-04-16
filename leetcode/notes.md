## Questions

#### How to define a priority queue as a class data member using a cusomized comparator
```cpp
class Test {
    auto f = [](const int a, const int b) {return a < b};
    priority_queue<int, vector<int>, decltype(f)> d_maxHeap(f);
};

```
Issues:
- data member f cannot be initialized inside class
- if use a static variable above the class definition, still cannot pass compilation



## Some issues need more attention when coding

### STL Usages
#### multiset
- `erase(par)`
    - if `par` is the value type, it will erase all elements of the same value
    - if `par` is the iterator type, it will only erase one element of the same value
#### make_pair
- belongs to <utility> header file
- when use this, do not need to put type arguments in c++11, would be deduced from the context, just use `make_pair(a,b)'

#### stringstream
- `ss.clear()` only set the error state flag
- `ss.str("")` is used to reset the string inside`ss` stringstream

#### exception
c++ exception base class definition
```cpp
class exception {
    public:
      exception () noexcept;
      exception (const exception&) noexcept;
      exception& operator= (const exception&) noexcept;
      virtual ~exception();
      virtual const char* what() const noexcept;
}
```
in coding interview, if we want to throw some exception, we can do this
```cpp
throw runtime_error("exception msg")

catch (exception e) {
    cout << e.what() << endl;
}
```

#### priority_queue declaration with customized comparator
- comparator class
```cpp
class Comp{
    public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> heap;
```
- comparator function
```cpp
bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}
priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(const pair<int, int>&, const pair<int, int>&)> heap(comp);

```
- lambda function comparator
```cpp
auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp))> heap(comp);
```




### Common Coding Skills
#### overflow issue
```cpp
int a = 1, b = 3;
int midIndex = (a+b) * 0.5;
double median = (a+b) * 0.5;
```
above overflow issue should be avided using code below
```cpp
int a = 1, b = 3;
int midIndex = a + (b-a) * 0.5; // =2
double median = a * 0.5 + b * 0.5;
```
Note: due to `double` -> `int` cast, while computing `midIndex`, cannot use the same way for computing `median`.


#### `size_t` problems
```cpp
vector<int> vec{1,2,3};
for(int i = 0; i < vec.size()-1; ++i)
```
any `size()` function returns type `size_t`, which is `unsigned int`, in the case that `size()` return `0`, `size()-1` will overflow, and the 
condition does not hold any more



### Interesting Problems
- Walls ang Gates

rather than thinking to do dfs for each `room` cell, we can use reverse engineer to start from `gate` to do dfs


### lower/upper bound coding
```cpp
int lowerBound(const vector<int>& nums, int target)
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

int upperBound(const vector<int>& nums, int target)
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
```


