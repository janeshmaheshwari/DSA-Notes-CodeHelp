#include <iostream>
using namespace std;

inline void NumberShow(int num)
{
    cout << num << endl;
}

int main()
{
// For Every Function Call it creates entery & exit in STACK
    NumberShow(10);

// In Inline it Puts the code of Function at Function Call
    cout << 10 << endl;

    NumberShow(10);
    NumberShow(10);
    NumberShow(10);
    NumberShow(10);
    NumberShow(10);
    NumberShow(10);

    return 0;
}