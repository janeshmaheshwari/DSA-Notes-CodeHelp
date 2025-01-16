#include <iostream>
using namespace std;

/*
Virtual is a way :-
1) To left the Decisions for RunTime,
2) To acieve RunTime Polymorphism,
3) To do Late Binding.
*/

class Animal
{
public:
    Animal()
    {
        cout << "Animal Ctor Called !!!" << endl;
    }

    virtual void sound() // Function is now Virtual
    {                    // Decision taken at RunTime
        cout << "Animal making Sound" << endl;
    }

    virtual ~Animal()
    {
        cout << "~Animal Dtor Called !!!" << endl;
    }
};

class Dog : public Animal
{
public:
    void sound() override // Doesn't make difference
    {                     // Just Increase Redability
        cout << "Dog Barking" << endl;
    }
};

class Cat : public Animal
{
public:
    void sound() override // Doesn't make difference
    {                     // Just Increase Redability
        cout << "Cat Mewing" << endl;
    }
};

class Parrot : public Animal
{
public:
    Parrot()
    {
        cout << "Parrot Ctor Called !!!\n" << endl;
    }

    void sound()
    {
        cout << "Parrot is Talking" << endl;
    }

    ~Parrot()
    {
        cout << "~Parrot Dtor Called !!!" << endl;
    }
};

void sound(Animal *animal)
{
    animal->sound(); // This line is Polymorphic
/*
It is calling the Sound of respective HEAP Object
rather than Sound of Animal Object So [animal->sound()]
is behaving as per required object allocated at RunTime
*/
    cout << endl;
}

int main()
{
/*
2) Run Time Polymorphism (Dynamic Polymorphism)

    (a) Function OverRidding
*/
    
    // cout << "Animal Pointer and Animal Object" << endl;
    // Animal *animal = new Animal();
    // animal->sound();
    // sound(animal);

    // cout << "Dog Pointer and Dog Object" << endl;
    // Dog *dog = new Dog();
    // dog->sound();
    // sound(dog);

    // cout << "Cat Pointer and Cat Object" << endl;
    // Cat *cat = new Cat();
    // cat->sound();
    // sound(cat);

    // cout << "Animal Pointer and Dog Object" << endl;
    // Animal *animalD = new Dog();
    // animalD->sound();
    // sound(animalD);

    // cout << "Animal Pointer and Cat Object" << endl;
    // Animal *animalC = new Cat();
    // animalC->sound();
    // sound(animalC);


/*
This line is relevant only when it executes on
RunTime (as it's memory need to be allocated on HEAP)

But this decision is been taken at compile time, it is
also called Static Binding(or Early Binding) and animal's
sound is been executed because of animal's pointer

Therefore, we need a way so that this decision is
taken by compile on runtime rather than compile time

This is known as Dynamic Polymorphism.

This can be done by making the Animal's Sound Virtual

Now during Runtime a HEAP Memory is allocated to Dog,
containing Dog Sound and it's pointer is made on stack
name animal of Animal class.

So now the animal is pointing to the Dog's Sound,
this is known as Late Binding
*/

    cout << "Animal Pointer and Parrot Object" << endl;
    Animal *animalP = new Parrot(); //1) UpCasting (From Child to parent)
    sound(animalP);

    delete animalP;

/*
    Parent* a = new Parent();
    Parent* a = new Child();
    Child* a = new Child();
    Child* a = new Parent();

Without Virtual Keyword in Prent Class, jo Left mein
likha hai (Container) uska Function (Dtor) call hoga

with Virtual Keyword (always in Parent class Function)
jo Right mein likha hai (Actual Object on HEAP) uska
Function (Dtor) call hoga
*/

    return 0;
} 