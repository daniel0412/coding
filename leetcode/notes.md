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

