#include <iostream>
#include <cmath>
using namespace std;
/*
Home Work Functions

-> 0. Phibonacci Series (Incomplete)
1. Function To Find Area Of a Circle
2.Check Even Odd using Bitwise Operator (Normal and Bitwise Method)
3. Function to Find Factorial of a Number
4. Check Prime && 5.Print All Prime Number from 1 to N
6.Reverse Integer
7. Set the Kth Bit
8. Convert the Temperature (Farhanit to Celcius)
9. Count all Set Bits
10. Create Number using Digits
11. Print All digit of an Integer
12. KM to Miles
*/

double Area(int r)
{
    double pi = M_PI;
    cout << "Totral Area of Circle with Radius " << r << " is ";
    return (pi*r*r);
}

bool EvenOdd(int n)
{
    cout << "Odd = 0 And Even = 1\n=> ";
    if (n & 1)
    {
        return false; //Odd Number
    }
    return true;
}

long long int Factorial(int x)
{
    if (x == 0)
    {
        return 1;
    }
    else
    {
        return (x * Factorial(x-1));
    }
}

void Prime(int x)
{
    if (x >= 2)
    {
        cout << "2" << endl;
    }

    for (int i = 3; i <= x; i++)
    {
        bool flag = true;

        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i%j == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << i << endl;
        }
    } 
}

int ReverseInt(int x)
{
    int ReverseInteger = 0;
    bool isNeg = false;

    if (x <= INT32_MIN)
    {
        return 0;
    }
    if (x < 0)
    {
       isNeg = true;
       x = -x;
    }
    while (x > 0)
    {
        if (ReverseInteger > (INT32_MAX)/10)
        {
            return 0;
        }
        int LastDigit = 0;
        LastDigit = x%10;
        ReverseInteger = (ReverseInteger*10) + LastDigit;
        x = x/10;
    }
    
    cout << "Reverse Integer is ";
    return isNeg ? -ReverseInteger : ReverseInteger;
}

int SetKthBit(int N, int K)
{
    return (N | (1<< K));
}

void TempConerter(float C)
{
    cout << "Celcius to Kelvin\n=> " << (C+273.15) << "\nCelcius to Ferhanite\n=> " << ((C*1.80) + 32.00) << endl;
}

int CountSetBit(int x)
{
    int Count = 0;

    // while (x >= 1)
    // {
    //     if (x%2 == 1)
    //     {
    //         Count ++;
    //         x = x/2;
    //     }
    // }

    while (x)
    {
        if (x & 1)
            Count++ ;
            x = (x >> 1);
    }
    cout << "Total Number of Set Bits ";
    return Count;
}

int DigtoNum()
{
    int TotalDigits;
    cout << "Enter the number of Digits for the output Number\n=> ";
    cin >> TotalDigits;
    int num = 0;

    for (int i = 0; i < TotalDigits; i++)
    {
        int LastDigit;
        cout << "Enter Digit Number " << i+1 << "\n=> ";
        cin >> LastDigit;
        num = (num*10) + LastDigit;
        cout << "Number Create so far " << num << endl;
    }
    cout << "Number Created ";
    return num;
}

void NumtoDig (int x)
{
    int count = 0;
    int copy = x;

    while (copy > 0)
    {
        copy = copy/10;
        count++;
    }
    
    for (int i = count; i > 0; i--)
    {
        int FirstDigit = 0;

        FirstDigit = x / pow(10,i-1);
        cout << FirstDigit << endl;
        x = x - FirstDigit*pow(10,i-1);
    }   
}

float DisConverter(float Km)
{
    cout << Km << " KM in Miles is  ";
    return (Km*0.621371);
}

int main()
{
    cout << Area(8) << endl;
    cout << EvenOdd(5) << endl;
    cout << Factorial(10) << endl;
    Prime(30);
    cout << ReverseInt(-168) << endl;
    cout << SetKthBit(10,2) << endl;
    TempConerter(36.50);
    cout << CountSetBit(10) << endl;
    cout << DigtoNum() << endl;
    NumtoDig(837);
    cout << DisConverter(10);

    return 0;
}