#include "student.hpp"
#include <iostream>

Student::Student(std::string name, int age, std::string id)
    : name(name), age(age), id(id), grade(0), courses() {
}

void Student::add_course(Course& course) {
    courses.push_back(course);      // se apeleaza copy constructor pt course
}

void Student::display() {
    std::cout << "Student: " << name << "\n";
    std::cout << "Age: " << age << "\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "Grade: " << grade << "\n";
    display_courses();
    std::cout<<"\n";
}

void Student::display_courses() {
    std::cout << "Courses:\n";

    for (Course& course : courses) {
        std::cout << "\t";
        course.display();
    }
}