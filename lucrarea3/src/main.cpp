#include <iostream>
#include <string>
#include <utility>

class Person {
    std::string name_;
    int *age_;

public:
    // constructor
    Person(std::string name, int age) 
        : name_(name), age_(new int(age)) {
            std::cout << "Constructor called \n";
    }
    
    // destructor
    ~Person() {
        std::cout << "Destructor called \n";
        delete age_;
    }

    // copy constructor
    Person(const Person& other)
        : name_(other.name_),
          age_(other.age_ ? new int(*other.age_) : nullptr) {
            std::cout << "Copy constructor called \n";
    }

    // move constructor
    Person(Person&& other) noexcept
        : name_(std::move(other.name_)), age_(other.age_) {
            other.age_ = nullptr;
            std::cout << "Move constructor called \n";
    }

    void display() {
        std::cout << "Name: " << name_ << "\n";
        std::cout << "Age: " << (age_ ? std::to_string(*age_) : "nullptr") << "\n";
        std::cout << "Age address: " << age_ << "\n";
        std::cout << "\n";
    }
};



int main() {

    std::cout << "\n ----- Constructor ----- \n";

    // crearea unui obiect si initializarea membrilor
    Person person1("Catalina", 22);
    person1.display();


    std::cout << "\n ----- Copy Constructor ----- \n";
    // crearea unui obiect nou, cu memorie alocata separat (deep copy)
    // fara copy constructor, aveam aceeasi adresa de memorie pt age (shallow copy), ceea ce ar duce la double delete la distrugerea obiectelor 
    Person person2 = person1;
    std::cout << "person1: \n";
    person1.display();
    std::cout << "person2 (copy): \n";
    person2.display();


    std::cout << "\n ----- Move Constructor ----- \n";
    // transferul memoriei de la person1 la person3
    // fara move constructor, se realizeaza o copie a datelor in loc sa se transfere memoria
    Person person3 = std::move(person1);
    std::cout << "person1 (after move): \n";
    person1.display();
    std::cout << "person3 (person1 moved): \n";
    person3.display();


    return 0;
}   // la iesirea din main se apeleaza destructorii
    // fara destructorul definit, memoria alocata dinamic pt age nu ar fi eliberata (memory leak)