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



