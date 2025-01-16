#include <iostream>
using namespace std;

class Student
{

private:
    string g;

public:
    int id;
    int age;
    bool present;
    string name;
    int nos;
    int *v;

// Getter/Setter (Can be also used for private members)
    string GetName()
    {
        return this->g;
    }
    void SetName(string g)
    {
        this->g = g;
    }


    Student()
    {
        cout << "Student ctor called !!!" << endl;
    }

    Student(int id, int age, bool present, string name, int nos, string g)
    {
        this->id = id;
        this->age = age;
        this->present = present;
        this->name = name;
        this->nos = nos;
        this->g = g;

        this->v = new int (10);

        cout << "Student paremeterized ctor called" << endl;
    }

    Student(int id, int age, bool present, string name, int nos)
    {
        this->id = id;
        this->age = age;
        this->present = present;
        this->name = name;
        this->nos = nos;

        cout << "Student paremeterized ctor called" << endl;
    }


// Copy ctor can be made else it is automatically made by compiler
// Learn this in shallow and deep copy

/*
=> It's necessary to put (student scrobj) by reference,
because if we are making a copy ctor, which means compiler
copy it by it's self, so we can't take it by value, as it
copies the data, we can only take it by reference.

=> It's necessary to puct it with const keyword, because
as it is called by refernce, data can be easily modified
in it,so make the srcobj constant
*/

    // Student(const Student &srcobj)
    // {
    //     // srcobj.g = "hello"; //Not possible in const
    //     this->id = srcobj.id;
    //     this->age = srcobj.age;
    //     this->present = srcobj.present;
    //     this->name = srcobj.name;
    //     this->nos = srcobj.nos;
    //     this->g = srcobj.g;

    //     cout << "Student Copy ctor called" << endl;
    // }


// Step to safe from memory overflow
    ~Student()
    {
        cout << "Student dtor called" << endl;
        delete v; //No leak
    }
};



// Inheritance
class Bird
{

public:

    int age, weight, nol;
    string color;

    void eat()
    {
        cout << "Bird is Eating" << endl;
    }

    void fly()
    {
        cout << "Bird is Flying" << endl;
    }
};

class Sparrow : public Bird
{
public:

    Sparrow(int age, int weight, int nol, string color)
    {
        this->age = age;
        this->weight = weight;
        this->nol = nol;
        this->color = color;
    }

    void grassing()
    {
        cout << "Sparrow is grassing" << endl;
    }
};

class Piegon : public Bird
{
public:

    void guttering()
    {
        cout << "Piegon is guttering" << endl;
    }
};

class Parrot : public Bird
{
public:

    void speaking()
    {
        cout << "Parrot is speaking" << endl;
    }
};



class Person
{
public:

    void walk()
    {
        cout << "Walking..." << endl;
    }
};

class Teacher : virtual public Person
{
public:

    void teach()
    {
        cout << "Teaching..." << endl;
    }
};

class Researcher : virtual public Person
{
public:

    void Research()
    {
        cout << "Researching..." << endl;
    }
};

class Professor : public Teacher, public Researcher
{
public:

    void Bore()
    {
        cout << "Boring..." << endl;
    }
};



class Vector
{
    int x, y;

public:
    // Vector(int x, int y)
    // {
    //     this->x = x;
    //     this->y = y;
    // }

    // init list
    Vector(int x, int y) : x(x), y(y) {}

// Operator Overloading
    void operator+(const Vector &srcobj)
    {
        // this->x += srcobj.x; //this->x = this->x + srcobj.x;
        // this->y += srcobj.y; //this->y = this->y + srcobj.y;

        x += srcobj.x;
        y += srcobj.y;
    }

    void operator-(const Vector &srcobj)
    {
        x -= srcobj.x;
        y -= srcobj.y;
    }

    void operator++()
    {
        x++;
        y++;
    }


    void display()
    {
        cout << "x : " << x << ", y : " << y << endl;
    }
};

//ctor, dtor and copy ctor are functions that doesn't have any return type
int main()
{
    // Copy ctor
    Student s1(1, 12, 1, "Chota Bheem", 1, "Chutki");
    Student s2 = s1;

    cout << s1.name << endl;
    cout << s2.name << endl << endl;

    Student s3;
    cout << s3.name;
    // Ctor called, copy ctor is not called
    s3 = s1;
    cout << s3.name << endl << endl;

    // Copy ctor called (it is called only at time of construction)
    // Student s4(s1); //OR
    Student s4 = s1;
    cout << s3.name << endl << endl;

    Student s5(1, 12, 1, "Chota Bheem", 1, "Chutki");
    cout << s5.GetName() << endl;
    s5.SetName("Indumati");
    cout << s5.GetName() << endl << endl;


/*
Encapsulation is often a mean to achieve abstraction,
(how ?) By hiding the internal details and exposing
only what is necessary.
*/

    Sparrow sp1(1, 10, 2, "Black");
    cout << sp1.weight << endl << endl;

// Protected data can be Derived,
// but private data can't be inherit.


// Types of Inheritance

//  1) Single -> One Derived class From one class
//  2) Multi-Level -> Chain of Inheritance, Many Single Inheritances
//  3) Hierarchical -> Many Derived Classes from 1 Class only
//  4) Multiple -> Derived Class Inherit from more than 1 class


// Diamond Problem

// Solution 1 : Scope Resolution
    Professor p1;
    p1.Teacher :: walk();
    p1.Researcher :: walk();

// Solution 2 : Virtual
    Professor p2;
    p2.walk();



// Virtual is been classified at time of Compile
// Compile Time is faster than Run time

/*
=> Types of Polymorphism

1) Compile Time Polymorphism (Static Polymorphism)

    (a) Funstion Overloading :-
        (i) Prameterized Ctor
        (ii) Function

    (b) Operator Overloading

2) Run Time Polymorphism (in OOPS3.cpp)
*/
    Vector v1(1, 2);
    Vector v2(3, 4);

    v1.display();
    v2.display();

    v1 + v2;
    v1.display();

    v1 - v2;
    v1.display();

    ++v1;
    v1.display();    

    return 0;
}