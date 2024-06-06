#include <bits/stdc++.h>
using namespace std;

// Progress:
// [x] Class & Objects
// [x] Attribute, Property & Methods, Behaviors
// [x] Constructor
// [x] Setter & Getter
// [x] Encapsulation
// [x] Inheritance
// [x] Overriding
// [x] Access Modifiers, Visibility
// [x] Abstraction
// [x] Polymorphism

class Course {
    private: // abstraction
        string courseName;
        string courseCode;
        string courseTime;
        string courseDay;
    public:
        // methods to add, remove, update course list
        Course(string courseName, string courseCode, string courseTime, string courseDay) { // constructor
            this->courseName = courseName;
            this->courseCode = courseCode;
            this->courseTime = courseTime;
            this->courseDay = courseDay;
        }

        // setter and getter methods
        void setCourseName(string courseName) { this->courseName = courseName; }
        void setCourseCode(string courseCode) { this->courseCode = courseCode; }
        void setCourseTime(string courseTime) { this->courseTime = courseTime; }
        void setCourseDay(string courseDay) { this->courseDay = courseDay; }
        string getCourseName() { return courseName; }
        string getCourseCode() { return courseCode; }
        string getCourseTime() { return courseTime; }
        string getCourseDay() { return courseDay; }

        void addCourse() {
            // TO DO
        }

        void modifyCourse() {
            // TO DO
        }

        void deleteCourse() {
            // TO DO
        }
};

class Person {
    protected: // access modifier
        string name;
        string code;
        string email;
        string phone;
    public:
        Person(string name, string code, string email, string phone) {
            this->name = name;
            this->code = code;
            this->email = email;
            this->phone = phone;
        }
        virtual void printDetails() = 0; // polymorphism

        void addPerson() {
            // TO DO
        }

        void modifyPerson() {
            // TO DO
        }

        void deletePerson() {
            // TO DO
        }
};

class Teacher : public Person { // inheritance
    public:
        Teacher(string name, string code, string email, string phone) : Person(name, code, email, phone) {}
        void printDetails() override { // overriding
            cout << "Teacher Name: " << name << "\n";
            cout << "Teacher Code: " << code << "\n";
            cout << "Teacher Email: " << email << "\n";
            cout << "Teacher Phone: " << phone << "\n";
        }
};

class Student : public Person { // inheritance
    public:
        Student(string name, string code, string email, string phone) : Person(name, code, email, phone) {}
        void printDetails() override { // overriding
            cout << "Student Name: " << name << "\n";
            cout << "Student Code: " << code << "\n";
            cout << "Student Email: " << email << "\n";
            cout << "Student Phone: " << phone << "\n";
        }
};

class Room { 
    private: // abstraction
        string roomNumber;
        int capacity;
        bool isAvailable;
    public:
        // methods to add, remove, update room list
        Room(string roomNumber, int capacity, bool isAvailable) { // constructor
            this->roomNumber = roomNumber;
            this->capacity = capacity;
            this->isAvailable = isAvailable;
        }

        void setRoomNumber(string roomNumber) { this->roomNumber = roomNumber; }
        void setCapacity(int capacity) { this->capacity = capacity; }
        void setIsAvailable(bool isAvailable) { this->isAvailable = isAvailable; }
        string getRoomNumber() { return roomNumber; }
        int getCapacity() { return capacity; }
        bool getIsAvailable() { return isAvailable; }

        void addRoom() {
            // TO DO
        }

        void modifyRoom() {
            // TO DO
        }

        void deleteRoom() {
            // TO DO
        }
};

void displayTimetable(string course, string teacher, string student, string room) {
    // TO DO
}

void printMenu() {
    cout << "1. Course Menu\n";
    cout << "2. Teacher Menu\n";
    cout << "3. Student Menu\n";
    cout << "4. Room Menu\n";
    cout << "5. Generate Timetable\n";
    cout << "0. Exit\n";

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    int courseChoice, teacherChoice, studentChoice, roomChoice;
    string course, teacher, student, room;

    switch (choice) { 
        case 1:
            cout << "1. Add Course\n";
            cout << "2. Modify Course\n";
            cout << "3. Delete Course\n";

            cout << "Enter your choice: ";
            cin >> courseChoice;
            switch (courseChoice) {
                // TO DO, USE SETTER AND GETTER
            }
            break;

        case 2:
            cout << "1. Add Teacher\n";
            cout << "2. Modify Teacher\n";
            cout << "3. Delete Teacher\n";

            cout << "Enter your choice: ";
            cin >> teacherChoice;
            switch (teacherChoice) {
                // TO DO, USE SETTER AND GETTER
            }
            break;

        case 3:
            cout << "1. Add Student\n";
            cout << "2. Modify Student\n";
            cout << "3. Delete Student\n";

            cout << "Enter your choice: ";
            cin >> studentChoice;
            switch (studentChoice) {
                // TO DO, USE SETTER AND GETTER
            }
            break;

        case 4:
            cout << "1. Add Room\n";
            cout << "2. Modify Room\n";
            cout << "3. Delete Room\n";

            cout << "Enter your choice: ";
            cin >> roomChoice;
            switch (roomChoice) {
               // TO DO, USE SETTER AND GETTER
            }
            break;
        case 5:
            cout << "Input Course, Teacher, Student, Room\n";
            cin >> course >> teacher >> student >> room;
            displayTimetable(course, teacher, student, room);
            break;

        case 0:
            return;

        default:
            cout << "Invalid Choice\n";
            printMenu();
            break;
    }
    printMenu();
}

int main(int argc, char const *argv[]) {
    printMenu();
    return 0;
}