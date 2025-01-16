#include <iostream>
using namespace std;

class Student
{
private:
    int a;
    int b;
    bool c;
    
/*
If nothing in class, than 1 byte is alloted for class.
The memory allocation is based on the nearest multiple
of the biggest Data Type.
*/

public:
    int age;
    int *v; //Pointer Initialization

    Student()
    {
        cout << "Student ctor called !!!" << endl;
    }
    // Student(){} --> Default Constructor created by Compiler.
/*
Only Function in class c++, that has no return type.
ctor --> It Construct an instance of class.
*/

// Class is Polymorphism

    // paremeterized ctor
    Student(int a, int age, bool _b, int _c)
    {
        // Ways to Put Values in Variables
        this->a = a;
        this->b = _b;
        c = _c;

        this->age = age;
        this->v = new int(10); //Memory allocation on heap

        cout << "Student paremeterized ctor called" << endl;
    }

    ~Student() // Default dtor called
    {
        cout << "Student dtor called" << endl;

        // Step to safe from memory overflow
        delete v;
    }
};

int main()
{
    // cout << sizeof(Student) << endl;
    Student s1;
    cout << s1.age << endl; // No value assign, print Garbage value

    Student s2(1, 12, 1, 1);
    cout << s2.age << endl;
    cout << s2.v << endl;

    int* a = new int(5); // Int on Heap
    // Class on Heap
    Student *s4 = new Student(3, 34, 1, 6);
    cout << s4->age << endl;
    cout << (*s4).age << endl;
    // cout << s4.age << endl;

    cout << s4 << endl;

    delete s4; // No Leak

    return 0;
}