#include <iostream>
using namespace std;

class A
{
private:
    int x;

public:
    A(int x) : x(x) {};

    int getX() const
    {
        return x;
    }
    void setX(int _val)
    {
        x = _val;
    }
    void print() const
    {
        cout << x << endl;
    }

    // friend class B; //Now B is A's Friend
    // friend void print(const A &);
};

class B
{
public:
    void print(const A &a)
    {
        // cout << a.getX() << endl; //It can be Access
        // cout << a.x << endl; //Only way to access it by making it A's friend

        a.print(); //Method to print private data members without using friend
    }
};

// void print (const A &a)
// {
//     cout << a.x << endl;
// }

int main()
{
    A a(5);
    B b;
    b.print(a);

    // print(a);

    return 0;
}