#if !defined(BIRD_H)
#define BIRD_H
#include <iostream>


//=> Bird Use as INTERFACE <=

// By forming Abstract Class we can create a Interface
class Bird
{
public:
    virtual void eat() = 0;
    virtual void fly() = 0;
/*
Classes that inherit this class has to implement pure
virtual Functions
*/
};


// => Sparrow & Eagle Use as IMPLEMENTATION <=

class Sparrow : public Bird
{
// public:
private:
    void eat()
    {
        std::cout << "Sparrow is eating\n";
    }
    void fly()
    {
        std::cout << "Sparrow is flying\n";
    }
};

class Eagle : public Bird
{
// public:
private:
    void eat()
    {
        std::cout << "Eagle is eating\n";
    }
    void fly()
    {
        std::cout << "Eagle is flying\n";
    }
};

#endif // BIRD_H
