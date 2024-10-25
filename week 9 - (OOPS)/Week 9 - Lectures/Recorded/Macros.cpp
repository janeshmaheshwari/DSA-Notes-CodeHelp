#include <iostream>
using namespace std;

// text(code) -> Pre-Processing -> compile -> exe(machine code)
// pre-process = change the #define(MACROS) to its value

#define PI 3.14159465 // Not taking any space in memory
#define MAXX(x,y) (x>y ? x : y)

float circleArea(float r)
{
    return PI*r*r;
}

float circlePerimeter(float r)
{
    return 2*PI*r;
}

int main()
{
    cout << circleArea(5) << endl;
    cout << circlePerimeter(5) << endl;
    cout << MAXX(2, 3) << endl;

    return 0;
}