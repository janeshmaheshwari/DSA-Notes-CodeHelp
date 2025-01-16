#include <iostream>
using namespace std;

class Student
{

public:

    //Attributes
    int id;
    int age;
    string name;
    int nos;
    float *gpa;

    //Constructor : Default Constructor
    Student()
    {
        cout << this->name << " Student Default Constructor called !!!" << endl;
    }

    //Constructor : Parameterised Constructor
    Student(int id, int age, string name, int nos, float gpa)
    {
        cout << "Student Parameterised Constructor called" << endl;
        this->id = id;
        this->age = age;
        this->name = name;
        this->nos = nos;
        this->gpa = new float(gpa);
    }

    //Copy Constructor
    Student(const Student &obj)
    {
        cout << "Student Copy Parameterised Constructor called" << endl;
        this->id = obj.id;
        this->age = obj.age;
        this->name = obj.name;
        this->nos = obj.nos;
    }

    // Behaviors / Methods / Functions
    void study()
    {
        cout << this->name << " Studing" << endl;
    }
    void sleep()
    {
        cout << this->name << " Sleeping" << endl;
    }
    void bunk()
    {
        cout << this->name << " Bunking" << endl;
    }

    //Distructor
    ~Student()
    {
        cout << this->name << " Student Default Distructor called !!!" << endl;
        delete this->gpa;
    }
};

int main()
{
    // Student A;
    // A.id = 21;
    // A.age = 18;
    // A.name = "Janesh";
    // A.nos = 5;

    // A.study();

    // Student B;
    // B.id = 22;
    // B.age = 20;
    // B.name = "Karan";
    // B.nos = 6;

    // B.bunk();

    // Student A(21, 18, "Janesh", 5); //STACK
    // Student B(22, 20, "Karan", 6);
    // A.study();
    // B.bunk();

    // Student C = A;
    // Student C(A);

    // cout << C.name <<  " " << A.name << endl;

    //Dynamic Allocation, or Student Pointer
    Student* D = new Student(21, 18, "Janesh", 21, 9.8); //HEAP
    cout << D->name << endl;
    cout << D->age << endl;
    D->study();
    delete D;

    return 0;
}