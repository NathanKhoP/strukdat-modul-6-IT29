#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    string email;
    string phone;

public:
    Person(const string &name, const string &email, const string &phone)
        : name(name), email(email), phone(phone) {}

    void setName(const string &name) { this->name = name; }
    void setEmail(const string &email) { this->email = email; }
    void setPhone(const string &phone) { this->phone = phone; }

    virtual void printDetails() const {
        cout << "\033[34mName:\033[0m " << name << "\n\033[34mEmail:\033[0m " << email << "\n\033[34mPhone:\033[0m " << phone << endl;
    }
};

class Teacher : public Person {
private:
    string teacherID;

public:
    Teacher(const string &name, const string &email, const string &phone, const string &teacherID)
        : Person(name, email, phone), teacherID(teacherID) {}

    string getTeacherID() const { return teacherID; }

    void printDetails() const override {
        Person::printDetails();
        cout << "\033[34mTeacher ID:\033[0m " << teacherID << endl;
    }
};

class Student : public Person {
private:
    string studentID;

public:
    Student(const string &name, const string &email, const string &phone, const string &studentID)
        : Person(name, email, phone), studentID(studentID) {}

    string getStudentID() const { return studentID; }

    void printDetails() const override {
        Person::printDetails();
        cout << "\033[34mStudent ID:\033[0m " << studentID << endl;
    }
};

class Room {
private:
    string roomNumber;
    int capacity;
    bool isAvailable;

public:
    Room(const string &roomNumber, int capacity, bool isAvailable)
        : roomNumber(roomNumber), capacity(capacity), isAvailable(isAvailable) {}

    string getRoomNumber() const { return roomNumber; }
    int getCapacity() const { return capacity; }
    bool getIsAvailable() const { return isAvailable; }

    void setRoomNumber(const string &roomNumber) { this->roomNumber = roomNumber; }
    void setCapacity(int capacity) { this->capacity = capacity; }
    void setIsAvailable(bool isAvailable) { this->isAvailable = isAvailable; }
};

class Course {
private:
    string courseName;
    string courseCode;
    string courseDay;
    string courseTime;
    Teacher *teacher;
    vector<Student *> students;
    Room *room;

public:
    Course(const string &courseName, const string &courseCode, const string &courseDay, const string &courseTime)
        : courseName(courseName), courseCode(courseCode), courseDay(courseDay), courseTime(courseTime), teacher(nullptr), room(nullptr) {}

    string getCourseName() const { return courseName; }
    string getCourseCode() const { return courseCode; }
    string getCourseDay() const { return courseDay; }
    string getCourseTime() const { return courseTime; }

    void setCourseName(const string &courseName) { this->courseName = courseName; }
    void setCourseCode(const string &courseCode) { this->courseCode = courseCode; }
    void setCourseDay(const string &courseDay) { this->courseDay = courseDay; }
    void setCourseTime(const string &courseTime) { this->courseTime = courseTime; }
    void setTeacher(Teacher *teacher) { this->teacher = teacher; }
    void setRoom(Room *room) { this->room = room; }

    Teacher *getTeacher() const { return teacher; }
    Room *getRoom() const { return room; }
    vector<Student *> getStudents() const { return students; }

    void addStudent(Student *student) { students.push_back(student); }
    void removeStudent(const string &studentID) {
        for (int i = 0; i < students.size(); ++i) {
            if (students[i]->getStudentID() == studentID) {
                students.erase(students.begin() + i);
                break;
            }
        }
    }
};

vector<Course> courseList;
vector<Teacher *> teacherList;
vector<Student *> studentList;
vector<Room *> roomList;

void addCourse() {
    string courseName, courseCode, courseDay, courseTime;
    cout << "\033[36mEnter Course Name:\033[0m ";
    cin >> courseName;
    cout << "\033[36mEnter Course Code:\033[0m ";
    cin >> courseCode;
    cout << "\033[36mEnter Course Day:\033[0m ";
    cin >> courseDay;
    cout << "\033[36mEnter Course Time:\033[0m ";
    cin >> courseTime;

    courseList.push_back(Course(courseName, courseCode, courseDay, courseTime));
    cout << "\033[32mCourse added successfully.\033[0m\n";
}

void modifyCourse() {
    string courseCode;
    cout << "\033[36mEnter Course Code to Modify:\033[0m ";
    cin >> courseCode;
    for (auto &course : courseList) {
        if (course.getCourseCode() == courseCode) {
            string courseName, courseDay, courseTime;
            cout << "\033[36mEnter new Course Name:\033[0m ";
            cin >> courseName;
            cout << "\033[36mEnter new Course Day:\033[0m ";
            cin >> courseDay;
            cout << "\033[36mEnter new Course Time:\033[0m ";
            cin >> courseTime;
            course.setCourseName(courseName);
            course.setCourseDay(courseDay);
            course.setCourseTime(courseTime);
            cout << "\033[32mCourse modified successfully.\033[0m\n";
            return;
        }
    }
    cout << "\033[31mCourse not found.\033[0m\n";
}

void removeCourse() {
    string courseCode;
    cout << "\033[36mEnter Course Code to Remove:\033[0m ";
    cin >> courseCode;
    for (int i = 0; i < courseList.size(); ++i) {
        if (courseList[i].getCourseCode() == courseCode) {
            courseList.erase(courseList.begin() + i);
            cout << "\033[32mCourse removed successfully.\033[0m\n";
            return;
        }
    }
    cout << "\033[31mCourse not found.\033[0m\n";
}

void addTeacher() {
    string name, email, phone, teacherID;
    cout << "\033[36mEnter Teacher Name:\033[0m ";
    cin >> name;
    cout << "\033[36mEnter Teacher Email:\033[0m ";
    cin >> email;
    cout << "\033[36mEnter Teacher Phone:\033[0m ";
    cin >> phone;
    cout << "\033[36mEnter Teacher ID:\033[0m ";
    cin >> teacherID;

    teacherList.push_back(new Teacher(name, email, phone, teacherID));
    cout << "\033[32mTeacher added successfully.\033[0m\n";
}

void modifyTeacher() {
    string teacherID;
    cout << "\033[36mEnter Teacher ID to Modify:\033[0m ";
    cin >> teacherID;
    for (auto &teacher : teacherList) {
        if (teacher->getTeacherID() == teacherID) {
            string name, email, phone;
            cout << "\033[36mEnter new Teacher Name:\033[0m ";
            cin >> name;
            cout << "\033[36mEnter new Teacher Email:\033[0m ";
            cin >> email;
            cout << "\033[36mEnter new Teacher Phone:\033[0m ";
            cin >> phone;
            teacher->setName(name);
            teacher->setEmail(email);
            teacher->setPhone(phone);
            cout << "\033[32mTeacher modified successfully.\033[0m\n";
            return;
        }
    }
    cout << "\033[31mTeacher not found.\033[0m\n";
}

void removeTeacher() {
    string teacherID;
    cout << "\033[36mEnter Teacher ID to Remove:\033[0m ";
    cin >> teacherID;
    for (int i = 0; i < teacherList.size(); ++i) {
        if (teacherList[i]->getTeacherID() == teacherID) {
            teacherList.erase(teacherList.begin() + i);
            cout << "\033[32mTeacher removed successfully.\033[0m\n";
            return;
        }
    }
    cout << "\033[31mTeacher not found.\033[0m\n";
}

void addStudent() {
    string name, email, phone, studentID;
    cout << "\033[36mEnter Student Name:\033[0m ";
    cin >> name;
    cout << "\033[36mEnter Student Email:\033[0m ";
    cin >> email;
    cout << "\033[36mEnter Student Phone:\033[0m ";
    cin >> phone;
    cout << "\033[36mEnter Student ID:\033[0m ";
    cin >> studentID;

    studentList.push_back(new Student(name, email, phone, studentID));
    cout << "\033[32mStudent added successfully.\033[0m\n";
}

void modifyStudent() {
    string studentID;
    cout << "\033[36mEnter Student ID to Modify:\033[0m ";
    cin >> studentID;
    for (auto &student : studentList) {
        if (student->getStudentID() == studentID) {
            string name, email, phone;
            cout << "\033[36mEnter new Student Name:\033[0m ";
            cin >> name;
            cout << "\033[36mEnter new Student Email:\033[0m ";
            cin >> email;
            cout << "\033[36mEnter new Student Phone:\033[0m ";
            cin >> phone;
            student->setName(name);
            student->setEmail(email);
            student->setPhone(phone);
            cout << "\033[32mStudent modified successfully.\033[0m\n";
            return;
        }
    }
    cout << "\033[31mStudent not found.\033[0m\n";
}

void removeStudent() {
    string studentID;
    cout << "\033[36mEnter Student ID to Remove:\033[0m ";
    cin >> studentID;
    for (int i = 0; i < studentList.size(); ++i) {
        if (studentList[i]->getStudentID() == studentID) {
            studentList.erase(studentList.begin() + i);
            cout << "\033[32mStudent removed successfully.\033[0m\n";
            return;
        }
    }
    cout << "\033[31mStudent not found.\033[0m\n";
}

void addRoom() {
    string roomNumber;
    int capacity;
    bool isAvailable;
    cout << "\033[36mEnter Room Number:\033[0m ";
    cin >> roomNumber;
    cout << "\033[36mEnter Room Capacity:\033[0m ";
    cin >> capacity;
    cout << "\033[36mIs Room Available (1 for Yes, 0 for No):\033[0m ";
    cin >> isAvailable;

    roomList.push_back(new Room(roomNumber, capacity, isAvailable));
    cout << "\033[32mRoom added successfully.\033[0m\n";
}

void modifyRoom() {
    string roomNumber;
    cout << "\033[36mEnter Room Number to Modify:\033[0m ";
    cin >> roomNumber;
    for (auto &room : roomList) {
        if (room->getRoomNumber() == roomNumber) {
            int capacity;
            bool isAvailable;
            cout << "\033[36mEnter new Room Capacity:\033[0m ";
            cin >> capacity;
            cout << "\033[36mIs Room Available (1 for Yes, 0 for No):\033[0m ";
            cin >> isAvailable;
            room->setCapacity(capacity);
            room->setIsAvailable(isAvailable);
            cout << "\033[32mRoom modified successfully.\033[0m\n";
            return;
        }
    }
    cout << "\033[31mRoom not found.\033[0m\n";
}

void removeRoom() {
    string roomNumber;
    cout << "\033[36mEnter Room Number to Remove:\033[0m ";
    cin >> roomNumber;
    for (int i = 0; i < roomList.size(); ++i) {
        if (roomList[i]->getRoomNumber() == roomNumber) {
            roomList.erase(roomList.begin() + i);
            cout << "\033[32mRoom removed successfully.\033[0m\n";
            return;
        }
    }
    cout << "\033[31mRoom not found.\033[0m\n";
}

void printCourses() {
    for (const auto &course : courseList) {
        cout << "\033[35mCourse Name:\033[0m " << course.getCourseName()
             << "\n\033[35mCourse Code:\033[0m " << course.getCourseCode()
             << "\n\033[35mCourse Day:\033[0m " << course.getCourseDay()
             << "\n\033[35mCourse Time:\033[0m " << course.getCourseTime() << endl;
        if (course.getTeacher() != nullptr) {
            cout << "\033[35mTeacher:\033[0m " << course.getTeacher()->getTeacherID() << endl;
        }
        if (course.getRoom() != nullptr) {
            cout << "\033[35mRoom:\033[0m " << course.getRoom()->getRoomNumber() << endl;
        }
        cout << "\033[35mStudents:\033[0m ";
        for (const auto &student : course.getStudents()) {
            cout << student->getStudentID() << " ";
        }
        cout << "\n---\n";
    }
}

void printTeachers() {
    for (const auto &teacher : teacherList) {
        teacher->printDetails();
        cout << "\n---\n";
    }
}

void printStudents() {
    for (const auto &student : studentList) {
        student->printDetails();
        cout << "\n---\n";
    }
}

void printRooms() {
    for (const auto &room : roomList) {
        cout << "\033[35mRoom Number:\033[0m " << room->getRoomNumber()
             << "\n\033[35mCapacity:\033[0m " << room->getCapacity()
             << "\n\033[35mIs Available:\033[0m " << room->getIsAvailable() << "\n---\n";
    }
}

void displayMenu() {
    // COURSE separation
    cout << "\033[33m1. Add Course\n";
    cout << "2. Modify Course\n";
    cout << "3. Remove Course\n";

    // TEACHER separation
    cout << "4. Add Teacher\n";
    cout << "5. Modify Teacher\n";
    cout << "6. Remove Teacher\n";

    // STUDENT separation
    cout << "7. Add Student\n";
    cout << "8. Modify Student\n";
    cout << "9. Remove Student\n";

    // ROOM separation
    cout << "10. Add Room\n";
    cout << "11. Modify Room\n";
    cout << "12. Remove Room\n";

    // PRINT separation
    cout << "13. Print All Courses\n";
    cout << "14. Print All Teachers\n";
    cout << "15. Print All Students\n";
    cout << "16. Print All Rooms\n";
    cout << "17. Exit\033[0m\n";
}

int main() {
    while (true) {
        displayMenu();
        int choice;
        cout << "\033[36mEnter your choice: \033[0m";
        cin >> choice;

        switch (choice) {
            case 1:
                addCourse();
                break;
            case 2:
                modifyCourse();
                break;
            case 3:
                removeCourse();
                break;
            case 4:
                addTeacher();
                break;
            case 5:
                modifyTeacher();
                break;
            case 6:
                removeTeacher();
                break;
            case 7:
                addStudent();
                break;
            case 8:
                modifyStudent();
                break;
            case 9:
                removeStudent();
                break;
            case 10:
                addRoom();
                break;
            case 11:
                modifyRoom();
                break;
            case 12:
                removeRoom();
                break;
            case 13:
                printCourses();
                break;
            case 14:
                printTeachers();
                break;
            case 15:
                printStudents();
                break;
            case 16:
                printRooms();
                break;
            case 17:
                return 0;
            default:
                cout << "\033[31mInvalid choice. Please try again.\033[0m\n";
        }
    }
    return 0;
}