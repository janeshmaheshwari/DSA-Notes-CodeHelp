#include <iostream>
using namespace std;

int Factorial(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    
    int ans = n * Factorial(n - 1);
    return ans;
}

void PrintReverse(int n)
{
    if (n == 0)
    {
        return;
    }
    
    PrintReverse(n-1); //Head Recursion
    cout << n << " ";
}

void Print(int n)
{
    if (n == 0)
    {
        return;
    }
    
    cout << n << " ";
    Print(n-1); //Tail Recursion
}

int PowerOf2(int n)
{
    if (n == 0)
    {
        return 1;
    }

    int ans = 2 * PowerOf2(n-1);
    return ans;
}

int Fibbonacci(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
   
    //OR :-
    // if (n < 2)
    // {
    //     return n;
    // }
    
    int ans = Fibbonacci(n-1) + Fibbonacci(n-2);
    return ans;
}

int SumNto1(int n)
{
    if (n == 1)
    {
        return 1;
    }
    
    int ans = n + SumNto1(n-1);
    return ans;
}

int main()
{
    // cout << Factorial(5) << endl;

    // PrintReverse(10);
    // cout << endl;

    // Print(10);
    // cout << endl;

    // cout << PowerOf2(10) << endl;

    cout << Fibbonacci(7) << endl;

    // cout << SumNto1(10) << endl;

    return 0;
}