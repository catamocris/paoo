#include "person.hpp"
#include <iostream>

Person::Person(std::string name, int age)
    : name(name), age(age) {
}

void Person::display() const {
    std::cout << "Name: " << name << "\n";
    std::cout << "Age: " << age << "\n";
}