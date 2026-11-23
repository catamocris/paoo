#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <list>
#include "course.hpp"

class Student {
private:
    std::string name;
    int age;
    const std::string id;
    int grade;
    std::list<Course> courses;

public:
    Student(std::string name, int age, std::string id);

    Student(const Student&) = delete;
    
    void add_course(Course& course);

    void display();
    
    void display_courses();
};

#endif