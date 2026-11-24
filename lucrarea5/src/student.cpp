#include "student.hpp"
#include <iostream>

// constructor
Student::Student(std::string name, int age, int grade)
    : Person(name, age), grade(new int(grade)) {
}

// copy constructor
Student::Student(const Student& other)
    : Person(other), grade(new int(*other.grade)) {
}

// copy assignment operator
Student& Student::operator=(const Student& other) {

    // copiem inainte de a elibera memoria veche
    int* oldGrade = grade;
    grade = new int(*other.grade);
    delete oldGrade;

    // copiem atributele mostenite
    Person::operator=(other);

    // returnam referinta la obiectul curent
    return *this;
}

// destructor
Student::~Student() {
    delete grade;
}

// afisare
void Student::display() {
    Person::display();
    std::cout << "Grade: " << *grade << "\n";
    std::cout << "Grade address: " << grade << "\n";
}