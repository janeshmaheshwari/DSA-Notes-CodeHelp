#include <iostream>
using namespace std;

class abc
{
    int x;
    int *y;
    const int z;

public:
    // Initialization List
    abc(int _x, int _y, int _z = 0) : x(_x), y(new int(_y)), z(_z) {}

    // abc(int x, int _y, int z = 0)
    // {
    //     this->x = x;

    //     // *this->y = _y;
    //     y = new int(_y);

    //     this->z = z; // Not working for constant z
    // }

    int getX() const
    {
        // x = 5; // Can't be reinitialize
        return x;
    }
    void setX(int x) const
    {
        // this->x = x;
    }
    
    int getY() const
    {
        return *y;
    }
    void setY(int y)
    {
        *this->y = y;
    }
    
    int getZ() const
    {return z;}
};

void printABC(const abc &a)
{
    a.setX(10);

    cout << a.getX() << ", ";
    cout << a.getY() << ", ";
    cout << a.getZ() << endl;
}

int main()
{
    abc a(1, 2, 3);
    printABC(a);
}

int main2()
{
    const int x = 5; // x is Constant

    // int *p = &x;
    // *p = 10;
    // cout << x << endl;


    //1. Const with Pointers

    // int const *a = new int(2); //Same as below
    const int *a = new int(2); // Const Data, Non Const Pointer 
    // *a = 20; // Data Can't be reinitialize

    cout << *a << endl; // a is pointing to 2
    delete a; // Delete that Address

    int b = 5;
    a = &b; // Point the a on Address of b
    cout << *a << endl; // a is pointing on 5


    //2. Const Pointer, Non Const Data
    int *const c = new int(2);
    cout << *c << endl;
    *c = 20;
    cout << *c << endl;

    int d = 50;
    // c = &d; // Pointer Can't be reinitialize


    //3. Const Pointer, Const Data
    const int *const e = new int (2);
    // *e = 20;
    int f = 5;
    // e = &f;

    return 0;
}