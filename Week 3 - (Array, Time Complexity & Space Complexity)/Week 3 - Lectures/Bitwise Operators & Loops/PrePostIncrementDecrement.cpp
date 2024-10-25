/*Pre and Post Increment and Decrement

1) Pre-Increment --> ++a
2) Post-Increment --> a++
3) Pre-Decrement --> --a
4) Post-Decrement --> a--
*/
#include <iostream>
using namespace std;

int main()
{
    int a = 10;

    cout <<  (++a)*(a++)  << endl;

    return 0;
}