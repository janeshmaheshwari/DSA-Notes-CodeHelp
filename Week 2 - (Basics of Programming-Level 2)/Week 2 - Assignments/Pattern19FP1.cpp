#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size for Stars Number Stars\n=> ";
    cin >> n;

    for (int row = 0; row < n; row++)
    {
        int start_index = 8 - row;
        int count_num = row + 1;

        for (int col = 0; col < 17; col++)
        {
            if (col == start_index && count_num>0)
            {
                cout << row + 1;
                start_index+=2;
                count_num--;
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}