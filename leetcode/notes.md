## Questions

#### Priority queue as a class data member using a cusomized comparator
```cpp
class Test {
    auto f = [](const int a, const int b) {return a < b};
    priority_queue<int, vector<int>, decltype(f)> d_maxHeap(f);
};

```
Issues:
- data member f cannot be initialized inside class
- if use a static variable above the class definition, still cannot pass compilation

#### `unordered_map` with customized key
- define `hash` function
    - hash each data member
    - combine into one hash value (good start is to use bit shift and XOR)
- define `comparator` (to differentiate collision of diff keys)
```cpp
// `hash` is a templated struct, ways to declare and use hash functions
hash<string> stringhash;
auto inthash = hash<int>();

// define hash function for the key
struct KeyHasher {
    size_t operator()(const Key& k) {
        return ((hash<string>()(k.first) ^ (hash<string>()(k.second) << 1) ) >> 1) ^ (hash<int>()(k.third) << 1);
    }
};

struct Key {
    string first;
    string second;
    int third;
    // define the comparator
    bool operator==(const Key& k1) {
        return first == k1.first && second == k1.second && third == k1.third;
    }
};

// now we can use unordered_map for customized key
unordered_map<Key, string, KeyHasher> m;
```



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
- comparator class (the only way that works of priority queue as a data member in a class)
```cpp
class Comp{
    public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }
};
// no need to pass any parameter
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

#### numeric_limits
- `numeric_limits<T>::min()` returns negative value for `T=int`, for positive value for `float` or `double`
- use `numeric_limits<double>::lowest()` if needed

#### level order travesal of binary tree
- use dfs and tracking parameter
- use bfs with queue
    - can use a `nullptr` separator each row in the queue
    - load one row, and then `for` loop, avoid separator logics

#### some useful functions might be used in coding
- string
```cpp
find_last_of('/')
find_last_not_of(' ')
```
- set
    - `set` can be used as a binary search tree `O(log(n))` insertion
    - `set` does not have `iter+1` operation, but can do `++iter` or `--iter`
    - `set` can use `set.lower_bound()` api
    - define with comparator
    ```cpp
    class Comp {
        public:
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
            return a.first < b.first;
        };
    };
    set<pair<int,int>, Comp> s;
    // or use the labmda function definition with decltype
    ```

- allgorithms
```cpp
bool isalnum(c);
transform(src.begin(), src.end(), dst.begin(), ::tolower);
```

#### good coding ways to format string
```cpp
// turn a vecotr into ',' separated string
ostringstream ss;
copy(vec.begin(), vec.end()-1, ostream_iterator<string>(ss, ","));
ss << *vec.rbegin();
return ss.str();
```

#### some algorithms
```cpp
reverse(nums.begin(), nums.end()); // return void, but chagne in place;
sort(nums.begin(), nums.end()); // return void, but chagne in place;
struct OP {
    string operator()(const string& s1, const string& s2) {
        ...
    }
};
string s = accumulate(string1, string2, initstring, OP());
```

#### initializer list
```cpp
vector<pair<int,int>> v{{1,2}, {2,3}};
v.emplace_back(4,5); // takes in a list of arguments, but not {4,5}
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

#### count number of 1s in an int
```cpp
int res = 0;
while(num) {
    ++res;
// this line will clear the right most 1
    num = num & (num-1);
}
```

### Interesting Problems
- Walls ang Gates

rather than thinking to do dfs for each `room` cell, we can use reverse engineer to start from `gate` to do dfs

## Templates
### Topological Sort
#### cycle detection/find orders
- dfs: store in adjacency matrix, and maintain `visited` vector to indicate if `visited in path` or `path found`
- bfs: store in-degree inforatmion, start from zero in-degree
- union find: can be applied to undirected graph, also can process streamed input
```cpp 
// dfs
```

```cpp 
// bfs
```

### Union Find
To count number of unions, cycle detection, can applied to undirected group only, but can process streaming input
```cpp
int numOfUnions(const vector<vector<int>>& M) {
    int n = M.size();
    int cnt = n; // initial counts
    vector<int> roots(n); // track initial root
    for(int i = 0; i < n; ++i) roots[i] = i;

    for(int i = 0; i < n; ++i) {
        for(int j = i+1; j < n; ++j) {
            if(M[i][j]) {
                int ri = getroot(roots, i);
                int rj = getroot(roots, j);
                // merge when roots not same
                if(ri != rj) {
                    // reduce count when merge
                    --cnt;
                    // ATTENTION: update root's root, ri/rj, not i/j
                    roots[ri] = roots[rj];
                }
            }
        }
        return cnt;
    }

int getroot(vector<int>& roots, int i) {
    while(roots[i] != i) {
        // assign grandparent root as its parent root
        roots[i] = roots[roots[i]];
        i = roots[i];
    }
    return i;
}
```

#### lower bound
- definition: given `val`, the first element `>= val`

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
```

#### upper bound
- definition: given `val`, the first element `> val`

```cpp
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
// note: in case all num are smaller than val, returned l would be nums.size()
```

### quick sort/select
For `quick sort` or `quick select`, the key is the embedded partition function

```cpp
int partition(vector<int>& nums, int left, int right)
{
    int p = left;
    // pick `right` as the pivot
    for(int i = left; i < right; ++i) {
        if(nums[i] < nums[right]) {
            if(nums[i] != nums[p]) {
                swap(nums[i], nums[p]);
            }
            ++p;
        }
    }
    swap(nums[p], nums[end]);
    // now `p` is the index of the pivot
    // it is possible that `p = right`, but sub sort/select will start within [left, p-1] or [p+1, right]
    // so it will no enter into an infinity loop
    return p;
}
```

### segment tree
- refer to `mutable range sum` for the array implementation

### binay indexed tree

