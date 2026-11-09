#include <iostream>
#include <student.hpp>
#include <course.hpp>

int main() {

    Course course1("PAOO", 5);
    Course course3("OOP", 4);

    Student student1("Catalina", 22, "ABC123");
    student1.add_course(course1);
    student1.add_course(course3);
    student1.display();

    Student student2("Ana", 21, "DEF456");
    student2.add_course(course1);
    student2.display();

    // Student student3(student1);  // eroare: copy constructor sters

    // Student student3;            // eroare: nu se genereaza default constructor

    // Student student3 = student1; // eroare: copy constructor sters

    // student2 = student1;         // eroare: copy assignment operator sters


    std::cout << "Course 1:\n";
    course1.display();

    Course course2(course1);        // copy constructor generat automat
    std::cout << "\nCourse 2: (with copy constructor)\n";
    course2.display();

    course2 = course3;              // copy assignment operator generat automat
    std::cout << "\nCourse 2: (with copy assignment)\n";
    course2.display();

    return 0;

    // destructori generati automat
}