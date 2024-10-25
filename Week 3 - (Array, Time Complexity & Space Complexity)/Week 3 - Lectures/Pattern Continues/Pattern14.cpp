#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size for Alphabest Pyramid\n=> ";
    cin >> n;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col <= 2*row; col++)
        {
            if (col <= row)
            {
                cout << char(65+col);
            }
            else
            {
                cout << char(65+(2*row)-col);
            }  
        }
        cout << endl;
    }

    return 0;
}