#include<iostream>
using namespace std;

class Animal
{
public:
    string myName() const {m_name;}
    unsigned myAge() const;
private:
    string m_name;
    unsigned m_age;
};

// class Cat : public Animal
// {
//     void jump() {...}
// }

// class Zoo
// {

//     vector<Animal*> m_animals;
// };

class Base
{
public:
    void foo() { cout << "Foo" << endl;}
private:
    int x;
};

class PublicDerived : public Base
{
    double y;
};

int main()
{
    PublicDerived publicDerived;
    publicDerived.foo();
}
