#include "course.hpp"
#include <iostream>

Course::Course(std::string name, int credits)
    : name(name), credits(credits) {
}

void Course::display() {
    std::cout << "Course: " << name << ";\t";
    std::cout << "Credits: " << credits << "\n";
}