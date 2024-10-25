//Left(<<) & Right(>>) Shift Operators
#include <iostream>
using namespace std;

int main()
{
/*
1) Left Shift Operator :- a<<n = a * (2^n)

Ex: 0000...0010 -> 2
    After Left Shift
    0000...0100 -> 4    
*/
    int a = 7;
    cout << (a<<2) << endl;

/*
2) Right Shift Operator :- a>>n = a / (2^n)

Ex: 0000...0101 -> 5
    After Left Shift
    0000...0010 -> 2
*/
    signed b = -10;
    cout << (b>>1) << endl; //Compiler took negative sign differently and at last converted the number from postive to negative all after calculation.
    
    unsigned int c = -100;
    cout << (c>>1) << endl; //Compiler didn't took negative sign differently and used is as the last bit(1) and continued the calculation.

    int d = 10;
    cout << (d << -1) << endl;
    cout << (d >> -1) << endl;
//This will Create a Warning and will print (ZERO) or a garbage value in output.

    return 0;
}