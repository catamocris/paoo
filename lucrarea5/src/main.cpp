#include <iostream>
#include "student.hpp"

int main() {

    Student student1("Ana", 21, 7);
    Student student2("Maria", 22, 8);
    Student student3("Ioana", 23, 10);


    std::cout << "\n----- Item 10: Assignment operators -----\n";

    student1 = student2 = student3;

    std::cout << "\nStudent 1:\n";
    student1.display();

    std::cout << "\nStudent 2:\n";
    student2.display();

    std::cout << "\nStudent 3:\n";
    student3.display();


    std::cout << "\n----- Item 11: Assignment to self -----\n";

    student1 = student1;

    std::cout << "\nStudent 1 after self-assignment:\n";
    student1.display();


    std::cout << "\n----- Item 12: Copying functions -----\n";

    std::cout << "\n----- Copy constructor\n";

    Student student4(student3);

    std::cout << "\nOriginal student:\n";
    student3.display();

    std::cout << "\nCopied student:\n";
    student4.display();

    std::cout << "\n----- Copy assignment operator\n";

    Student student5("Alex", 20, 5);

    student5 = student3;

    std::cout << "\nStudent 5 after assignment:\n";
    student5.display();

    return 0;
}