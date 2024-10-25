#include <iostream>
using namespace std;

int x = 5; //Global Variable

void fun()
{
    cout << "\n// change Global x in fun()\n::x = 1;\n";
    ::x = 1; //Global x
    cout << "// Printing Global x in fun()\n8) cout << ::x << endl ==> ";
    cout << ::x << endl;

    cout << "\n// Local x of fun()\nint x = 0;\n";
    int x = 0;
    cout << "// Printing Local x in fun()\n9) cout << x << endl ==> ";
    cout << x << endl;
}

int main()
{
    cout << "\nint x = 5;" << endl;
    cout << "// No local x before this statement\n// Printing Global x in main()\n1) cout << x << endl; ==> ";
    cout << x << endl;

    cout << "\n// change Global x\nx = 4;";
    x = 4;
    cout << "\n// OR syntax can be these\n::x = 4;\n";
    :: x = 4;
    cout << "// Printing Global x in main()\n2) cout << x << endl ==> ";
    cout << x << endl;

    cout << "\n// Local of Main Function\nint x = 3;\n";
    int x = 3;
    cout << "// Printing Local x in main()\n3) cout << x << endl ==> ";
    cout << x << endl;

    cout << "\n// Printing Global x in main()\n4) cout << ::x << endl; ==> ";
    cout << ::x << endl;

    {
        cout << "\n// Printing Global x in {} in main()\n5) cout << ::x << endl; ==> ";
        cout << ::x << endl;

        cout << "\n// Printing main() x in {} as it is most recent\n6) cout << x << endl; ==> ";
        cout << x << endl;

        cout << "\n// Most Local or most Recent x in {} in main()\nint x = 2;\n";
        int x = 2;
        cout << "// Printing Localest x in {} in main()\n7) cout << x << endl; ==> ";
        cout << x << endl;
    }
    fun();
    cout << "\n------------------------------return 0;------------------------------" << endl;

    return 0;
}
