## Software Design Pattern
- general reusable solutions to problems which occur over and over again in object-oriented design enviroment
- not a finished design that can be transformed into source code directly
- but templates how to solve the problem
 structure (how classes and objects are composed to form larger structures) and behavioral patterns (the assignment of responsibilities between objects).

### Creational Design Pattern (abstract the instantiation process)
- [Singleton Pattern](#singleton-pattern)
- [Factory Pattern](#factory-pattern)
- Abstract Factory Pattern
- [Builder Pattern](#builder-pattern)
- Prototype Pattern
- Object Pool Pattern

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
    - when the resource stateless object is costly to create, and is limited, but multiple clients need to access the resource, thus use object pool pattern to reuse the resource
    - How?
        - create the reusable object
            - main a pool of resusable object, which manages allocate reusable object to client, mark as available when client finishes using it
                - client request object from the pool as if creating a new object, and inform the pool after using it
                - Examples?
                    - database connections

#### Dependency Injection Pattern (a.k.a. Inversion of Control)
- When?
    - when declaring a member object inside a class, rather than using new to create a member object, it is better passed by reference, and the reference would be better a interface, thus can be extended without changing the client code
    - How?
        - constructor injection
            - setter injection
                - interface injection

### Structural Design Pattern
- Adapter Pattern
- Composite Pattern
- Proxy Pattern
- Flyweight Pattern
- Facade Pattern
- Bridge Pattern
- Decorator Pattern

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

### Behavioral Design Pattern
- Template Method Pattern
- Mediator Pattern
- Chain of Responsibility Pattern
- Observer Pattern
- Strategy Pattern
- Command Pattern
- State Pattern
- Visitor Pattern
- Interpreter Pattern
- Iterator Pattern
- Memento Pattern
