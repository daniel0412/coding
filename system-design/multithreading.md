# Multi-threading
- [Basics](#basics)
- [Synchronization](#synchronization)


## Basics
### thread creation in c++
Thread can be created 
- via function pointer
- via function object
- via lambda function
- via lambda closure
- via class member function

Notes:
- thread constructor is a `variadic` template
- any number of arguments can be passed into thread, but pass by value
- if pass by reference is needed, use `std::ref()`


```cpp
#include <thread>
using namespace std;

void fnPtr(int a, string& s) {
    cout << "function pointer thread creation" << endl;
}

class FnObj {
public:
    void operator()() {
	// within each thread, can use `this_thread::get_id()` to identify current thread
	cout << "thread id: " << std::this_thread::get_id() << endl;
    }
};

class A {
public:
    void memFn() {
	cout << "member function" << endl;
    }
};

int main() {
    // 1) thread creation with function pointer
    // each thread has its own stack, so is pass-by-value
    // can use `std::ref()` to do pass-by-reference
    string s = "pass by ref";
    thread fnPtrThread(fnPtr, 5, std::ref(s));

    // 2) thread creation with function object
    auto fnObj = FnObj();
    thread fnObjThread(fnObj);

    // 3) thread creation with lambda function
    thread labmdaThread([](){
	cout << "thread creation by labmda function" << endl;
    });

    // 4) thread creation with lambda closure
    auto lambdaClosure = ()[]{cout << "lambda closure" << endl;};
    thread labmdaClosureThread(lambda);
    // another api to get current thread id
    lambdaClosureThread.get_id();

    // 5) thread creation via member function
    A a;
    thread classThrad(A::memFn, &a);
    return 0;
}
```

### thread local storage
```cpp
// this indicate `gVal` will be created as a separate copy in each thread
thread_local int gVal = 1;

void assign(int v) {
    gVal = v;
    cout << "thread: " << this_thread::get_id() << ", gVal: " << gVal;
}

int main() {
    // will print out 10
    thread t1(assign, 10);
    // will print out 20
    thread t2(assign, 20);
    t1.join();
    t2.join();
    // will print out 1
    cout << "thread: " << this_thread::get_id() << ", gVal: " << gVal << endl;
    return 0;
}
```

### concepts
- `join()`
- 'detach()`

## Synchronization
### Mutex
### Condition Variable
### Sepheremo
