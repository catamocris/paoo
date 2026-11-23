#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(std::string name, int age);

    void display() const;
};

#endif