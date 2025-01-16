#ifndef MYSTRING_H
#define MYSTRINH_H

#include <iostream>

class MyString
{
private:
    char *data;
    int length;

public:
    MyString(); // Default Ctor

    MyString(const char *str); // Parameterised Ctor

    MyString(const MyString &other); // Copy Ctor

    ~MyString(); // Default Dtor

    int size() const;

    bool empty() const;

    const char* c_str() const;

    char operator[](int index);

    int find(const MyString &substr) const;

    // Overload Insertion Operator (<<) for easy output
    friend std::ostream &operator<<(std::ostream &os, const MyString &str);
};

#endif // MYSTRING_H