#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
private:
    std::string name;
    int credits;

public:
    Course(std::string name, int credits);

    void display();
};

#endif