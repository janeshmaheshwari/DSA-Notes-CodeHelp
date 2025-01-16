#include <iostream>
using namespace std;

class abc
{
public:
    int x, *y; // *y allocated on HEAP

    abc(int x, int y) : x (x), y(new int (y)) {} //init list

    // Default Dumb Copy Constructor : It does SHALLOW COPY
    // abc(const abc& obj)
    // {
    //     x = obj.x;
    //     y = obj.y;
    // }

    // Our Smart DEEP COPY
    // abc(const abc& obj)
    // {
    //     x = obj.x;
    //     y = new int(*obj.y);
    // }

    void print() const
    {
        printf("X : %d\nPTR Y : %p\nContent of Y (*y) : %d\n\n", x, y, *y);
    }

    ~abc()
    {
        delete y;
    }
};

int main()
{
    // abc a(1, 2);
    // cout << "Printing a\n";
    // a.print();

    // // abc b(a);
    // abc b = a;
    // cout << "Printing b\n";
    // b.print();

    // *b.y = 20;
    // cout << "Printing b\n";
    // b.print();

    // cout << "Printing a\n";
    // a.print();



    // Problems with SHALLOW COPY

    abc *c = new abc(1, 2);
    abc d = *c;
    d.print();

    delete c;
    d.print(); // Garbage Value or 0

    return 0;
}