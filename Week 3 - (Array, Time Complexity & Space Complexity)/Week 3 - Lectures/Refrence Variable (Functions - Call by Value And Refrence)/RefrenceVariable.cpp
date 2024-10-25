#include <iostream>
using namespace std;

int SimpleIncrement(int n)
{
    n = n + 1;
}

void RefrenceIncrement(int &k)
{
    k = k + 1;
}

int main()
{
    int n;
    cout << "Enter the value for n\n=> ";
    cin >> n;
    SimpleIncrement(n);
    cout << "Value of n after Simple Increment : " << n << endl;

    RefrenceIncrement(n);
    cout << "Value of n after Refrence Increment : " << n << endl;

    return 0;
}