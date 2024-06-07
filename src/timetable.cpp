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
    private:
        string courseName;
        string courseCode;
        string courseDay;
        string courseTime;
        Teacher teacher; 
        vector<Student> students; 
        Room room; 
    public:
        Course(string courseName, Teacher teacher, vector<Student> students, Room room) {
            this->courseName = courseName;
            this->teacher = teacher;
            this->students = students;
            this->room = room;
        }

        // setter and getter methods
        void setCourseName(string courseName) { this->courseName = courseName; }
        void setCourseCode(string courseCode) { this->courseCode = courseCode; }
        void setCourseDay(string courseDay) { this->courseDay = courseDay; }
        void setCourseTime(string courseTime) { this->courseTime = courseTime; }
        void setTeacher(Teacher teacher) { this->teacher = teacher; }
        void setStudents(vector<Student> students) { this->students = students; }
        void setRoom(Room room) { this->room = room; }
        string getCourseName() { return courseName; }
        string getCourseCode() { return courseCode; }
        string getCourseDay() { return courseDay; }
        string getCourseTime() { return courseTime; }
        Teacher getTeacher() { return teacher; }
        vector<Student> getStudents() { return students; }
        Room getRoom() { return room; }

        void addStudent(Student student) {
            this->students.push_back(student);
        }

        void modifyStudent(string studentName, Student student) {
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getName() == studentName) {
                    students[i] = student;
                    break;
                }
            }
        }

        void removeStudent(string studentName) {
            for (int i = 0; i < students.size(); i++) {
                if (students[i].getName() == studentName) {
                    students.erase(students.begin() + i);
                    break;
                }
            }
        }

        
};

class Person {
    protected: // access modifier
        string name;
        string email;
        string phone;
        vector<string> personList;
    public:
        Person(string name, string email, string phone) {
            this->name = name;
            this->email = email;
            this->phone = phone;
        }
        virtual void printDetails() = 0; // polymorphism

        // setter and getter methods
        void setName(string name) { this->name = name; }
        void setEmail(string email) { this->email = email; }
        void setPhone(string phone) { this->phone = phone; }
        string getName() { return name; }
        string getEmail() { return email; }
        string getPhone() { return phone; }

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
    private:
        string teacherID;
    public:
        Teacher(string name, string email, string phone, string teacherID) 
            : Person(name, email, phone), teacherID(teacherID) {}

        void printDetails() override { // overriding
            cout << "Teacher Name: " << name << "\n";
            cout << "Teacher ID: " << teacherID << "\n";
        }

        // setter and getter for teacherID
        void setTeacherID(string teacherID) { this->teacherID = teacherID; }
        string getTeacherID() { return teacherID; }
};

class Student : public Person { // inheritance
    private:
        string studentID;
    public:
        Student(string name, string email, string phone, string studentID) 
            : Person(name, email, phone), studentID(studentID) {}

        void printDetails() override { // overriding
            cout << "Student Name: " << name << "\n";
            cout << "Student ID: " << studentID << "\n";
        }

        // setter and getter for studentID
        void setStudentID(string studentID) { this->studentID = studentID; }
        string getStudentID() { return studentID; }
};

class Room { 
    private: // abstraction
        string roomNumber;
        int capacity;
        bool isAvailable;
        vector<string> roomList;
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

void displayTimetable(vector<Course> courseList, vector<Teacher> teacherList, vector<Student> studentList, vector<Room> roomList) {
    // TO DO
    cout << "Generating Available Timetable\n";
    cout << "-----------------------------\n";

    for (Course course : courseList) {
        cout << "Course Name: " << course.getCourseName() << "\n";
        cout << "Course Code: " << course.getCourseCode() << "\n";
        cout << "Day: " << course.getCourseDay() << "\n";
        cout << "Time: " << course.getCourseTime() << "\n";
        cout << "Teacher: " << course.getTeacher().getName() << "\n";
        cout << "Room: " << course.getRoom().getRoomNumber() << "\n";
        cout << "Students: \n";
        for (Student student : course.getStudents()) {
            cout << student.getName() << "\n";
        }
        cout << "-----------------------------\n";
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
            cout << "4. Display Course\n";

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
            cout << "4. Display Teacher\n";

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
            cout << "4. Display Student\n";

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
            cout << "4. Display Room\n";

            cout << "Enter your choice: ";
            cin >> roomChoice;
            switch (roomChoice) {
               // TO DO, USE SETTER AND GETTER
            }
            break;
        case 5:
            displayTimetable();
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