## Questions

#### How to define a priority queue as a class data member using a cusomized comparator
```cpp
class Test{
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


### Common Coding Skills
#### overflow issue
```cpp
int a, b;
int mid = (a+b) * 0.5;
double median = (a+b) * 0.5;
```
above overflow issue should be avided using code below
```cpp
int a, b;
int mid = a * 0.5 + b * 0.5;
double median = a * 0.5 + b * 0.5;
```



