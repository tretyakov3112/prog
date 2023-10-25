#pragma once
#include<iostream>

struct Foo {
    void say() const { std::cout << "Foo says: " << msg << "\n"; }
protected:
    Foo(const std::string& msg) : msg(msg) { }
private:
    const std::string& msg;
};

struct Fo : Foo
{
    Fo(const std::string& msg) : Foo(msg) {}

};

const Foo get_foo(const std::string& msg) 
{
    const Fo fo(msg);
    return fo;
}

void foo_says(const Foo& foo) { foo.say(); }



int main() 
{
    foo_says(get_foo("Hi"));
}
