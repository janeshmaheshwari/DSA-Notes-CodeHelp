#include <iostream>
#include <string>
#include "MyString.h"

using namespace std;

int main()
{
    MyString t = "CodeHelp";
    cout << t << endl;

    MyString s("Janesh Maheshwari");
    cout << s << endl;

    cout << s[0] << endl;

    cout << s.find("Mahesh") << endl;

    return 0;
}
/*
g++ -c MyString.cpp && g++ -c main.cpp && g++ -o main MyString.o main.o
*/