#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
//  arr = arr + 1; --> Will throw Error

    // int brr[4] = {10, 20, 30, 40};
    // cout << sizeof(brr) << endl;

    // int *p = brr;
    // cout << sizeof(p) << endl;

    char ch[7] = "Janesh";
    char *cptr = ch; 

    // cout << ch << endl;
    // cout << cptr << endl << endl;

    // cout << &cptr << endl;
    // cout << &ch << endl << endl;

    // cout << *ch << endl;
    // cout << *(ch + 0) << endl;
    // cout << ch[0] << endl;
    // cout << 0[ch] << endl << endl;

    // cout << *cptr << endl;
    // cout << *(cptr + 0) << endl;
    // cout << cptr[0] << endl;
    // cout << 0[cptr] << endl << endl;

    char CH[30] = "Statement";
    char* CPTR = &CH[0];

    // cout << CH << endl;
    // cout << &CH << endl;
    // cout << *(CH + 3) << endl << endl;

    // cout << CPTR << endl;
    // cout << &CPTR << endl;
    // cout << *(CPTR + 3) << endl << endl;

    // cout << CPTR + 2 << endl;
    // cout << *CPTR << endl;
    // cout << CPTR + 8 << endl << endl;

    // char abcd1 = 'a';
    // char *abcd2 = &abcd1;
    // cout << abcd2 << endl;

    // int x = 10;
    // int *ptr = &x;
    // cout << ptr << endl;
    // cout << * ptr + 2**ptr - 3**ptr << endl;

    char crr[20];
    int i;
    for (i = 0; i < 10; i++)
    {
        *(crr + i) = 65 + i;
    }
    *(crr + i) = '\0';

    cout << crr << endl;

    return 0;
}