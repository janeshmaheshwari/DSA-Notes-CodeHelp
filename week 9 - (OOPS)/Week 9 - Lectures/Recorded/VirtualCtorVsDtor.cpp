#include <iostream>
using namespace std;

/*
=> Virtual in C++ <= (Way to achieve RunTime Polymorphism)


1. V Tables (Static Array Table OR Function Pointer Table)

-> The vtable is a mechanism that allows dynamic (runtime)
polymorphism, where the correct function implementation is
selected based on the actual type of the object at runtime
rather than the type known at compile-time.

    (1) Formed for Every class having at least one Virtual
        Function and for its derived classes
    (2) It is Static Arrays, hence one instance for a class
        A class only has a vtable if it contains at least
        one virtual function (including destructors).

        It is not for the non-Virtual classes.

        Inherited(derived) Classes and Virtual Functions 
        also have a vtable even if it doesn’t declare any 
        additional virtual functions. This ensures the
        derived class can override any virtual functions
        from the base class if needed.

        If a class is purely virtual (an abstract class) but
        doesn’t define any functions (including a virtual
        destructor), it theoretically doesn’t need a vtable
        because it lacks any functionality to dispatch.
        However, this can depend on the compiler's implementation.
        Some compilers may still create a minimal vtable
        entry to mark the class as abstract and prevent it
        from being instantiated, but this is an implementation
        detail and not standard behavior.

    (3) VPtr - Virtual Pointer (a hidden member pointer) is
        added by compiler to classes with virtual and its
        derived classes.  

    (4) Depending upon object type VPtr is bonded to VTable

2. VTables are created at compile time

3. When object of a particular type is created at runtime.
   There will be a VPtr which is intialized to point to a
   static VTable at time of construction. 


=> Can we make virtual ctor ?

1. NO.

2. Constructor cannot be virtual, because when constructor
   of a class is executed there is no virtual table in the
   memory, means no virtual pointer defined yet. So, the
   constructor should always be non-virtual.

3. A virtual call is a mechanism to get work done given
   partial information. In particular, "virtual" allows us
   to call a function knowing only any interfaces and not
   the exact type of the object. To create an object you
   need complete information. In particular, you need to
   know the exact type of what you want to create.
   Consequently, a "call to a constructor" cannot be virtual.


=> Can we make Virtual dtor ?

1. Yes

2. It is really important to handle proper destruction of
   Derived classes

3. For Example :-
*/

class Base
{
public:
    Base()
    {
        cout << "Base Ctor" << endl;
    }
    // ~Base()
    // {
    //     cout << "Base Dtor" << endl;
    // }
    virtual ~Base()
    {
        cout << "Base Dtor" << endl;
    }
};

/*
=> TIP :-
Whenever you make Relation between Base and Derived Class
(Inheritance) always make virtual Dtor of Base Class
*/

class Derived : public Base
{
    int *a;

public:
    Derived()
    {
        a = new int[1000];
        cout << "Derived  Ctor" << endl;
    }
    ~Derived()
    {
        delete[] a;
        cout << "Derived Dtor" << endl;
    }
};

int main()
{
    Base *b = new Derived();
    delete b;

    return 0;
}