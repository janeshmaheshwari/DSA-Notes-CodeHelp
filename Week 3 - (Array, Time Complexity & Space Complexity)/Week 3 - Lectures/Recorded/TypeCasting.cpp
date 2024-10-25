#include <iostream>
using namespace std;

int main()
{
//  Implicit Type Conversion

    int num1 = 10; //int works like float
    float num2 = 5.5;
    float result = num2 - num1;
    cout << result << endl;

    int new_result = result;
    cout << new_result << endl;

    char ch = 'A';

    int a = ch + 1;
    cout << a << endl;

    char b = 'B';
    int c = b;
    cout << c << endl;

    char d = ch  + 1;
    cout << d << endl;

//  Explicit Type Conversion

    double pi = 3.14159265;
    int intpi = int(pi);
    cout << intpi << endl;

    float floatingNumber = 65.35;
    char charValue = (char)floatingNumber;
    cout << charValue << endl;

    int x = 10;
    int y = 3.0;
    int z = ((float)x) / y;
    cout << z << endl;

    return 0;
}