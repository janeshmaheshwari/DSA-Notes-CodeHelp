#include <iostream>
#include <string.h>
using namespace std;

int FindLength(char ch[], int size)
{
    int length = 0;
    for (int i = 0; i < size; i++)
    {
        if (ch[i] == '\0')
        {
            break;
        }
        length++ ;
    }
    return length;
}

void ReverseString(char ch[], int n)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        swap(ch[i], ch[j]);
        i++ ;
        j-- ;
    }
}

void UpperCase(char ch[])
{
    // for (int i = 0; i < strlen(ch); i++)
    // {
    //     int x = ch[i];
    //     if (x >= 97 && x <= 122)
    //     {
    //         ch[i] = x - 32;
    //     }
    // }

    int index = 0;
    while (ch[index] != '\0')
    {
        if (ch[index] >= 'a' && ch[index] <= 'z')
        {
            ch[index] = ch[index] - 'a' + 'A';
        }
        index++ ;
    }  
}

void LowerCase(char ch[])
{
    int index = 0;
    while (ch[index] != '\0')
    {
        if (ch[index] >= 'A' && ch[index] <= 'Z')
        {
            ch[index] = ch[index] - 'A' + 'a';
        }
        index++ ;
    }  
}

void ReplacetoSpace(char ch[])
{
    int index = 0;
    while (ch[index] != '\0')
    {
        if (ch[index] == '@')
        {
            ch[index] = ' ';
        }
        index++ ;
    }
}

bool CheckPalindrome(char ch[], int n)
{
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        if (ch[i] != ch[j])
        {
            return false;
        }
        i++ ;
        j-- ;
    }
    return true;
}

int main()
{
//No (Space " ", Tab "\t", Enter "\n")
//Will Assume all of them as Null Character "\0"(Terminate)
//"\0" -> ASCII = 0 From 256 Character(1 Byte or 8 Bits)
    // char ch1[5];
    // cout << "Ch1\n=> ";
    // cin >> ch1;
    // cout << ch1 << endl;

//No (Enter "\n"); Only (Space " ", Tab "\t")
//Will Assume "\n" as Null Character "\0"(Terminate)
    // char ch2[10];
    // cout << "Ch2\n=> ";
    // cin.getline(ch2, 100);
    // cout << ch2 << endl;

    // char ch3[100];
    // cin >> ch3;
    // cout << FindLength(ch3,100) << endl;

    // char ch4[100];
    // cin.getline(ch4, 100);
    // cout << "FindLength Function : " << FindLength(ch4, 100) << endl;
    // cout << "strlen In Built Function : " << strlen(ch4) << endl;

    // char ch5[100];
    // cin.getline(ch5, 100);
    // ReverseString(ch5, strlen(ch5));
    // cout << "After Reverse :\n" << ch5 << endl;

    // char ch6[100];
    // cin.getline(ch6, 100);
    // UpperCase(ch6);
    // cout << "After Upper Cassing :\n" << ch6 << endl;
    // LowerCase(ch6);
    // cout << "After Lower Cassing :\n" << ch6 << endl;

    // char ch7[100];
    // cin.getline(ch7, 100);
    // ReplacetoSpace(ch7);
    // cout << "After Replacing @ with [SPACE] : " << ch7 << endl;

    // char ch8[100];
    // cin.getline(ch8, 100);
    // cout << CheckPalindrome(ch8, strlen(ch8)) << endl;

    // string str1;
    // cin >> str1;
    // cout << str1;

    // string str2;
    // getline(cin, str2);
    // cout << str2 << endl;

    // string str1 = "Love";
    // string str2 = "Babbar";
    // str1.append(str2);
    // cout << str1 << endl;
    // cout << str2 << endl;

    // string str3 = "This is a Car";
    // str3.erase(4, 3); //4th Index and 3 Characters
    // cout << str3;

    // string str4 = "Janesh Mahshwari";
    // string str5 = "Ghanshamdas ";
    // str4.insert(7, str5);
    // cout << str4 << endl;
    // cout << str5 << endl;

    // string str5 = "J";
    // cout << str5 << endl;
    // str5.push_back('M');
    // cout << str5 << endl;
    // str5.pop_back();
    // cout << str5 << endl;

    // string str6 ("There are two needles");
    // string str7 ("two");
    // if (str6.find(str7) == string::npos)
    // {
    //     cout << "Not Found" << endl;
    // }
    // else
    // {
    //     cout << "Found at " << str6.find(str7) << " index" << endl;
    // }

    // string str8 ("Janesh");
    // string str9 ("JaneshM");
    // if (str8.compare(str9) == 0)
    // {
    //     cout << "Matching" << endl;
    // }
    // else
    // {
    //     cout << "Not Matching" << endl;
    // }

    // string str10 ("This is a car, big daddy of all SUV's");
    // cout << str10.substr(19, 5) << endl;

    return 0;
}