#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "person.hpp"

class Student : Person {
private:
    int* grade;

public:
    Student(std::string name, int age, int grade);
    
    Student(const Student& other);

    Student& operator=(const Student& other);

    ~Student();

    void display();
};

#endif