#include <iostream>
#include <cmath>
using namespace std;

int SumOf3 (int a = 0, int b = 0, int c = 0)
{
    int ans = a + b + c;
    return ans;
}

void MessagePrint ()
{
    cout << "Msg1" << endl;
    return;
    cout << "Msg2" << endl;
}

int MaxOf3 (int a, int b, int c)
{
    return max(max(a,b),c);
}

void PrintCounting(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << endl;
    }
    return;
}

void CheckEvenOdd(int x)
{
    if (x%2 == 0)
    {
        cout << "Even Number" << endl;
    }
    else
    {
        cout << "Odd Number" << endl;
    }
}

int SumUptoN(int n)
{
    return ((n*(n+1))/2);
}

int SumEvenUptoN(int n)
{
    int ans = 0;

    for (int i = 2; i <= n; i = i + 2)
    {
        ans = ans + i;
    }

    return ans;
}

bool CheckPrime(int x)
{
    if (x < 2)
    {
        return false;
    }
    else
    {
        for (int i = 2; i <= sqrt(x); i++)
        {
            if (x%i == 0)
            {
                return false;
            }
        }
        return true; 
    } 
}

int main()
{
    cout << SumOf3(5, 6, 7) << endl;

    MessagePrint();

    cout << MaxOf3(16, 17, 18) << endl;

//  Class Work Functions

    PrintCounting(10);

    CheckEvenOdd(5);

    cout << SumUptoN(10) << endl;

    cout << SumEvenUptoN(10) << endl;

    cout << CheckPrime(17);

    return 0;
}