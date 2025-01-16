#include <iostream>
using namespace std;

class abc
{
public:
    int x, y;

    void print() const
    {
        cout << x << " " << y << endl;
        cout << this->x << " " << this->y << endl;
    }
};

class xyz
{
public:
    //Not a single class instance, but it will share the same to all class instances
    static int a, b;
    int c, d;

    // xyz() : a(0), b(0) {} //Will Not Work
    xyz() : c(0), d(0) {}

    static void print ()
    {
        printf("I am in  Static %s\n", __FUNCTION__);
        cout << a << " " << b << endl;
    }

    // static void print () //Will not work
    // {
    //     cout << c << " " << d << endl;
    // }
};

int xyz :: a;
int xyz :: b;

int main()
{
    abc obj1 = {1, 2};
    abc obj2 = {3, 4};
    obj1.print();
    obj2.print();

    xyz obj;
    xyz::print();

    // xyz obj3 = {1, 2};/Will not work
    xyz obj3;
    obj3.a = 1;
    obj3.b = 2;
    obj3.print();
    xyz obj4;
    obj4.a = 10;
    obj4.b = 20;
    obj3.print();
    obj4.print();

    return 0;
}