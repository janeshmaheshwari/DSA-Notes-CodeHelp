#include <iostream>
using namespace std;

class Box
{
    int width;

    // Ctor
    Box(int width) : width(width) {};

public:
    int getWidth() const
    {
        return width;
    }

    void setWidth(int _val)
    {
        width = _val;
    }

    friend class BoxFactory;
};

class BoxFactory
{
    int count;

public:
    Box getABox(int _w)
    {
        ++count;
        return Box(_w);
    }
};

int main()
{
    // Box b(5);
    // cout << b.getWidth() << endl;

/*
    => yes Ctor can be made Privately
    => Advantage :- So that nobody can directly use ctor of
    box class (or directly can't make objects in box class)
    => Singleton Class
*/

    BoxFactory bFact;
    Box b = bFact.getABox(5);
    cout << b.getWidth();

    return 0;
}