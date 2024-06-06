#include <bits/stdc++.h>
using namespace std;

// Progress:
// [x] Class & Objects
// [x] Attribute, Property & Methods, Behaviors
// [x] Constructor
// [x] Setter & Getter
// [x] Encapsulation
// [ ] Inheritance (um)
// [ ] Overriding
// [ ] Access Modifiers, Visibility
// [ ] Abstraction
// [ ] Polymorphism

class Course {
    private:
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

        void modifyCourse() {

        }

        void deleteCourse() {

        }
};

class Teacher {
    private:
        string teacherName;
        string teacherCode;
        string teacherEmail;
        string teacherPhone;
    public:
        // methods to add, remove, update teacher list
        Teacher(string teacherName, string teacherCode, string teacherEmail, string teacherPhone) { // constructor
            this->teacherName = teacherName;
            this->teacherCode = teacherCode;
            this->teacherEmail = teacherEmail;
            this->teacherPhone = teacherPhone;
        }

        void setTeacherName(string teacherName) { this->teacherName = teacherName; }
        void setTeacherCode(string teacherCode) { this->teacherCode = teacherCode; }
        void setTeacherEmail(string teacherEmail) { this->teacherEmail = teacherEmail; }
        void setTeacherPhone(string teacherPhone) { this->teacherPhone = teacherPhone; }
        string getTeacherName() { return teacherName; }
        string getTeacherCode() { return teacherCode; }
        string getTeacherEmail() { return teacherEmail; }
        string getTeacherPhone() { return teacherPhone; }

        void modifyTeacher() {

        }

        void deleteTeacher() {

        }
};

class Student {
    private:
        string studentName;
        string studentCode;
        string studentEmail;
        string studentPhone;
    public:
        // methods to add, remove, update student list
        Student(string studentName, string studentCode, string studentEmail, string studentPhone) { // constructor
            this->studentName = studentName;
            this->studentCode = studentCode;
            this->studentEmail = studentEmail;
            this->studentPhone = studentPhone;
        }

        void setStudentName(string studentName) { this->studentName = studentName; }
        void setStudentCode(string studentCode) { this->studentCode = studentCode; }
        void setStudentEmail(string studentEmail) { this->studentEmail = studentEmail; }
        void setStudentPhone(string studentPhone) { this->studentPhone = studentPhone; }
        string getStudentName() { return studentName; }
        string getStudentCode() { return studentCode; }
        string getStudentEmail() { return studentEmail; }
        string getStudentPhone() { return studentPhone; }

        void modifyStudent() {

        }

        void deleteStudent() {

        }
};

class Room {
    private:
        string roomNumber;
        int capacity;
        bool isAvailable;
    public:
        // methods add, remove, update room list
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

        void modifyRoom() {

        }

        void deleteRoom() {

        }
};

int main(int argc, char *argv[]) {
    // display menu

    return 0;
}