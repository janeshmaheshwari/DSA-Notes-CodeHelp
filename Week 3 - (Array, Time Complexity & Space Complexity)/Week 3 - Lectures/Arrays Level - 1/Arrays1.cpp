#include <iostream>
using namespace std;
/*
Arrays :-

1. List of Similar Items
2. Collection of Elements
3. Data Structure(Type)
4. Continuous Memory Block
*/
int main()
{
/*

//  Address of Integer and its Size
    int a =5;
    cout << "The address of a with address of operator : " << &a << endl;
    cout << "Size of a : " << sizeof(a) << endl;

//  Creation of Array and its Address and its Size
    int arr[10];
    cout << "Base address of array without address of operator : " << arr << endl;
    cout << "Base address of array with address of operator : " << &arr << endl;
    cout << "Size of array : " << sizeof(arr) << endl;

    int brr[] = {2, 3, 4, 5};
    int crr[5] = {1, 2, 3, 4, 5};
    int drr[5] = {2, 3};
//  int drr[2] = {6, 7, 8, 9, 10}; --> Error

    int err[5];
    cout << "Taking input in an Array :-" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the value for "<< i << " index\n=> ";
        cin >> err[i];
    }
    cout << "Printing the Array :-" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << err[i] << " ";
    }

Formula :-
arr[i] = Value at (Address)->[Base Address of Array + {(Index "i")*(Data type Size)}]

*/
    int frr[10];
    cout << "Taking input in frr Array :-" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter the value for "<< i << " index\n=> ";
        cin >> frr[i];
        frr[i] = 2*frr[i];
    }
    cout << "Printing the frr Array :-" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << frr[i] << " ";
    }

    int grr[5];
    int sum = 0;

    cout << "Taking input in grr Array :-" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the value for "<< i << " index\n=> ";
        cin >> grr[i];
        sum += grr[i];
    }
    cout << "Printing the grr Array :-" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << grr[i] << " + ";
    }

    cout << endl << "sum : " << sum << endl;    

//  => Linear Search in an Array <=

//  Formation of Array
    int hrr[5];
    cout << "Taking input in an Array :-" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the value for "<< i << " index\n=> ";
        cin >> hrr[i];
    }
    cout << "Printing the Array :-" << endl << "{ ";
    for (int i = 0; i < 5; i++)
    {
        cout << hrr[i] << " ";
    }
    cout << "}" << endl;

//  Linear Search
    int target;
    cout << "Enter the Target Value\n=> ";
    cin >> target;

    for (int i = 0; i < 5; i++)
    {
        if (target == hrr[i])
        {
            cout << target << " Found at " << i << " index !" << endl;
            break;
        }
        else
        {
            cout << "Target not Found !";
        }
    }

    return 0;
}