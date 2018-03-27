## Software Design Pattern
- general reusable solutions to problems which occur over and over again in object-oriented design enviroment
- not a finished design that can be transformed into source code directly
- but templates how to solve the problem

### Creational Design Pattern (abstract the instantiation process)
- [Singleton Pattern](#singleton-pattern)
- [Factory Method](#factory-method)
- [Abstract Factory Pattern](#abstract-factory-pattern)
- [Builder Pattern](#builder-pattern)
- Prototype Pattern
- [Object Pool Pattern](#object-pool-pattern)

### Structural Design Pattern (classes and objects composed to form larger structures)
- Adapter Pattern
- Composite Pattern
- [Proxy Pattern](#proxy-pattern)
- [Flyweight Pattern](#flyweight-patter)
- Facade Pattern
- Bridge Pattern
- Decorator Pattern

### Behavioral Design Pattern (assignment of responsibilities between objects)
- Template Method Pattern
- Mediator Pattern
- Chain of Responsibility Pattern
- [Observer Pattern](#observer-pattern)
- Strategy Pattern
- Command Pattern
- State Pattern
- Visitor Pattern
- Interpreter Pattern
- Iterator Pattern
- Memento Pattern

#### Singleton Pattern
- When?
    - only one instantiation of the class is allowed in the JVM, like logging/driver/caches/thread pool, and etc
- How?
    - mark constructor as private to disable constructors
    - declare private static instance variable of the same class
    - declare public static getInstance() method to return the instance
- different implementations
    - eager initialization: initialize the static instance variable when declaration (cannot handle creation exception, object created before used, might never used)
    - static block initialization: add a static block of codes after instance declaration, in the block, add exception handling, but still object created too early, might never used
    - lazy initialization: only when getInstance() method is called, create instance if null, otherwise return the instance
    - thread-safe initialization:
    - mark getInstance() method synchronized -> too much overhead if the instance is already created
    - use synchronized block with double 'instance == null' check, if first check is null, put another check in synchronized block; if not, directly return

```cpp
class Singleton {
  public:
    // static interface to get the unique instance
    static Singleton* getInstance()
    {
        if(d_instance == nullptr) {
            d_instance = new Singleton();
        }
        return d_instance;
    }

    void tell()
    {
        std::cout << "This is Singleton." << std::endl;
    }

  private:
    // disalbe constructor
    Singleton() {}
    // unique static instance variable
    static Singleton* d_instance;
};

// initialize it at global level
Singleton* Singleton::d_instance = nullptr;
```

#### Factory Method
An interface for creating an object, but let subclasses decide which class to instantiate.
Factory Method lets a class defer instantiation to subclasses.
In contrast to Abstract Factory, Factory Method contain method to produce only one type of product.

- When to use
    - a class cant anticipate the class of objects it must create
    - a class wants its subclasses to specify the objects it creates
    - classes delegate responsibility to one of several helper subclasses, and you want to localize the knowledge of which helper subclass is the delegate

```cpp
class Product {
    virtual string name() = 0;
};

class ProductA : Product {
    string name() { return "prod-a"; }
};

class ProductB : Product {
    string name() { return "prod-b"; }
};

// interface for all factory methods
class Factory {
    virtual Product* createA() = 0;
    virtual Product* createB() = 0;
};

// concrete factory includs implementations for all factory methods
class FactoryImpl : Factory {
    Product* createA() {
        return new ProductA();
    }
    Product* createB() {
        return new ProductB();
    }
};
```

#### Abstract Factory Pattern
Provide an interface to create families of related or dependent objects without specifying their concrete classes.
Pattern applies to object and deal with object relationships, which are more dynamic.
In contrast to Factory Method, Abstract Factory pattern produces family of types that are related, ie. it has more than one method of types it produces.

- When to use
    - a system should be independent of how its products are created, composed, and represented
    - a system should be configured with one of multiple families of products
    - a family of related product objects is designed to be used together you want to provide a class library of products, and you want to reveal just their interfaces, not their implementations

```cpp
class Product {
    virtual string name() = 0;
};

class ProductAX : Product {
    string name() { return "prod-ax"; }
};

class ProductAY : Product {
    string name() { return "prod-ay"; }
};

class ProductBX : Product {
    string name() { return "prod-bx"; }
};

class ProductBY : Product {
    string name() { return "prod-by"; }
};

// abstract class with interfaces
class AbstractFactry {
    virtual Product* createProdA() = 0;
    virtual Product* createProdB() = 0;
};

// concreate impls for all X related products
class FactoryX : AbstractFactry {
    Product* createProdA() { return new ProductAX(); }
    Product* createProdB() { return new ProductBX(); }
};

// concreate impls for all Y related products
class FactoryY : AbstractFactry {
    Product* createProdA() { return new ProductAY(); }
    Product* createProdB() { return new ProductBY(); }
};
```

#### Builder Pattern
- when?
    - where there are lots of attribute (required and optional)
- why?
    - error prone to pass all the arguments in the right order
    - factory method will force to pass all the arguments, even if it is optional, have to pass 'null'
    - if the object creation is complex, all the complexity will go up to factory method
- how?
    - for class X, create a 'nested static class' called XBuilder, with all the data members from class X
    - XBuilder class should provide constructor with required data members as parameters
    - XBuilder class should provide setter methods for all optional data members, and the setter should return 'this' referencing to XBuilder, thus can chaining all setter to construct the object
    - XBuilder class should provide build() method to return new X(XBuilder), for this class X itself needs to provide private constructor taking XBuilder as a parameter

#### Object Pool Pattern
- When?
    - the resource stateless object is costly to create, and is limited
    - multiple clients need to access the resource, thus use object pool pattern to reuse the resource
- How?
    - create the reusable object
    - main a pool of resusable object, which manages allocate reusable object to client, mark as available when client finishes using it
    - client request object from the pool as if creating a new object, and inform the pool after using it
    - Examples?
        - database connections

#### Static Factory Method
- How?
    - disable all constructors, thus cannot create object using constructor
    - declare static create() function to create object, thus can be called before object is created
- Why?
    - this concept is widly use in different design patterns
    - create() can add extra layer to manager the creation of the objects
    - depending on different parameters, create subclasses
    - limit the number of object instances created (singleton/pool of objects)
    - create() function signatures/parameters can be renamed, to improve readability

#### Dependency Injection Pattern (a.k.a. Inversion of Control)
- When?
    - when declaring a member object inside a class, rather than using new to create a member object, it is better passed by reference, and the reference would be better a interface, thus can be extended without changing the client code
- How?
    - constructor injection
    - setter injection
    - interface injection

#### Flyweight Pattern
- When?
    - when need to create tons of object and memory is limited, thus use this pattern to share the objects
    - object same object's properties can be divided into `intrinsic` and `extrinsice`
    - `intrinsic` properties are those that come with the object, and won't change
    - `extrinsic` properties are those that come from the client
- How?
    - `flyweight interface`: defines the interface that manipulate the shared object by the `extrinsic` properties
    - `concrete flyweight`: stores the `intrinsic` properties and implements the flyweight interface
    - `flyweight factory`: maintain and manage the flyweight object. if the flyweight object is not created, create it;
    if created, return reference to the flyweight object
    - `client`: maintains reference to the shared object, and computes and manages the `extrinsic` properties of the shared object
    - Examples?
        - Java string pool
        - In the game where tons of soilder need to be drawn, flyweight interface defints how to move soilders, and concreate flyweight object defines all intrinsic properties needed to draw the soilder; client controls how to move the soilder around

#### Proxy Pattern
- When?
    - when we need to control the access of the object, we can consider Proxy Pattern
    - examples:
        - `protection proxy`: only give access to admins / make the object immutable by only providing getter and disable setter (fails fast)
        - `virtual proxy`: delaying the creation and initialization of expensive objects
        - `remote pvoxy`: provide local representation object which might call real object in remote address space
- How?
    - `subject interface`: the interface open to the client, and implemented by `read subject` and `proxy`
    - `real subject`: the underlying object implenting the interface
    - `proxy`: proxy of `real subject`, passed to the client
    - maintains a reference to the `real subject`
    - implement the interface, maybe calling the method of `real subject`
    - control the access to `real subject`

#### Observer Pattern
- defines many-to-one dependency: when the state for one subject is updated, all dependent observers will be notified, and observers states changed automatically
- when to use?
    - when an abstraction has two aspects, one dependent on the other
    - when a change to one object requires changing others, and you don't know how many objects need to be changed
    - when an object should be able to notify other objects without making assumptions about who these objects are
- example: auction/bidders

```cpp
// forward declaration of subject class to be observed
class Subject;

// observers that update based on subjects' state change
class Observer {
    public:
        virtual int getState() = 0;
        virtual void update(Subject* sub) = 0;
};

class DerivedObserver : Observer {
    public:
        DerivedObserver(int states) : d_observerState(states) {}

        int getState() { return d_observerStates; }
        void update(Subject* sub) {
            d_observerState = sub->getState();
        }

    private:
        int d_observerStates;
};

class Subject {
    public:
        // interface to add observer
        void attach(Observer* ob) {
            d_obs.emplace_back(ob);
        }
        // interface to delete observer
        void detach(int id) {
            d_obs.erase(d_obs.begin() + id);
        }

        // when subject is changed, notify all the observers
        void notify() {
            for(auto& ptr : d_obs) {
                ptr->update(this);
            }
        }
        // get/set states specific to concrete subjects
        virtual int getState() = 0;
        virtual void setState() = 0;
    private:
        // store all observers
        vector<Observer*> d_obs;
};

class DerivedSubject : Subject {
    void setState(int state) { d_subState = state; }
    int getState() { return d_subState; }
}

int main() {
    DerivedObserver ob1(1), ob2(2);
    cout << "ob1 state: " << ob1.getState() << endl;
    cout << "ob2 state: " << ob2.getState() << endl;

    DerivedSubject sub;
    sub.attach(ob1);
    sub.attach(ob2);
    sub.setState(666);
    sub.notify();

    // states will all changed to be 666
    cout << "ob1 state: " << ob1.getState() << endl;
    cout << "ob2 state: " << ob2.getState() << endl;
}
```
