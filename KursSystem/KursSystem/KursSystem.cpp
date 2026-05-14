#include <iostream>
#include <vector>
#include <string>
#include <cassert>

class Student {
public:
    std::string name;
    bool passed;

    Student(std::string nameIn) {
        name = nameIn;
        passed = false;
    }
};

class Course {
public:
    std::vector <Student> students;

    void addStudent(Student student) {

        students.push_back(student);

    };
    void passStudent(std::string name) {

        for (int i = 0; i < students.size(); i++) {
        
            if (students[i].name == name){
                
                    students[i].passed = true;
                
            };
        
        };
    };
    int countPassed() {

        int passedCount= 0;

        for (int i = 0; i < students.size(); i++) {

            if (students[i].passed == true) {

                passedCount++;

            };

        };

        return passedCount;
    };

};

void runTests() {
    // Fresh course has 0 passed
    Course c1;
    assert(c1.countPassed() == 0);

    // Adding students doesn't auto-pass them
    Course c2;
    c2.addStudent(Student("Hanna"));
    c2.addStudent(Student("Maria"));
    assert(c2.countPassed() == 0);

    // Passing one student counts correctly
    Course c3;
    c3.addStudent(Student("Hanna"));
    c3.addStudent(Student("Maria"));
    c3.passStudent("Maria");
    assert(c3.countPassed() == 1);

    // Passing all students counts correctly
    Course c4;
    c4.addStudent(Student("Hanna"));
    c4.addStudent(Student("Maria"));
    c4.passStudent("Hanna");
    c4.passStudent("Maria");
    assert(c4.countPassed() == 2);

    // Passing a student that doesn't exist does nothing
    Course c5;
    c5.addStudent(Student("Hanna"));
    c5.passStudent("Erik"); // not in course
    assert(c5.countPassed() == 0);

    // Passing same student twice doesn't double count
    Course c6;
    c6.addStudent(Student("Hanna"));
    c6.passStudent("Hanna");
    c6.passStudent("Hanna");
    assert(c6.countPassed() == 1);

    // Single student, not passed
    Course c7;
    c7.addStudent(Student("Hanna"));
    assert(c7.countPassed() == 0);

    // Single student, passed
    Course c8;
    c8.addStudent(Student("Hanna"));
    c8.passStudent("Hanna");
    assert(c8.countPassed() == 1);

    std::cout << "All tests passed!" << std::endl;
}


int main()
{
    runTests();
}