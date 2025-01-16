#include <iostream>
#include "bird.h"

using namespace std;

/*
=> Abstraction in C++ <=

1. Delivering only essential information to the outer world
   while masking the background details.
2. It is a design and programming method that separates the
   interface from the implementation.
3. Real life e.g., various functionalities of AirPods but
   don't know the actual implementation/ working
    
    (1) To drive a car, one only needs to know the driving
        process and not the mechanics of the car engine

=> Abstraction in Header files

1. Function's implementation is hidden in header files.
2. We could use the same program without knowing its inside
   working.
3. E.g., Sort(), for example, is used to sort an array, list,
   or a collection of items, and we know that if we give a
   container to sort, it will sort it, but we don't know
   which sorting algorithm it uses to sort that container.

=> Abstraction using Classes

1. Grouping data members and member functions into classes
   using access specifiers.
2. A class can choose which data members are visible to the
   outside world and which are hidden.

=> What is Abstract Class?
1. Class that contains at least one pure virtual function,
   and these classes cannot be instantiated.
2. It has come from the idea of Abstraction.
3. These Classes work as Interface

=> Design Strategy
1. Abstraction divides code into two categories: interface
   and implementation. So, when creating your component,
   keep the interface separate from the implementation so
   that if the underlying implementation changes, the
   interface stays the same.
2. In this instance, any program that uses these interfaces
   would remain unaffected and would require recompilation
   with the most recent implementation.
*/

// Bird is acting as Interface
void BirdDoesSomething(Bird *&bird)
{
   bird->eat();
   bird->eat();
   bird->eat();
   bird->eat();
   bird->eat();

   bird->fly();
   bird->fly();
   bird->fly();
   bird->fly();
   bird->fly();
}

int main()
{
   Bird*bird1 = new Sparrow();
   BirdDoesSomething(bird1);

// Sigle Line of Code Changes the Whole Code
   Bird*bird2 = new Eagle();
   BirdDoesSomething(bird2);

// We need to go through Inteface to access this functions
   Sparrow*sp = new Sparrow();
   // sp->eat();
   // sp->fly();

// we can't make object of Abstract class or c++ interface
   // Bird*bird3 = new Bird();

    return 0;
}