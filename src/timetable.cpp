```cpp
#include <bits/stdc++.h>
using namespace std;

class Teacher;  
class Student;
class Room;    

class Person {
protected:
    string name;
    string email;
    string phone;
public:
    Person(string name, string email, string phone)
        : name(name), email(email), phone(phone) {}
    virtual void printDetails() const = 0;

    // setter and getter methods
    void setName(string name) { this->name = name; }
    void setEmail(string email) { this->email = email; }
    void setPhone(string phone) { this->phone = phone; }
    const string& getName() const { return name; }
    const string& getEmail() const { return email; }
    const string& getPhone() const { return phone; }
};

class Teacher : public Person {
private:
    string teacherID;
public:
    Teacher(string name, string email, string phone, string teacherID)
        : Person(name, email, phone), teacherID(teacherID) {}

    void printDetails() const override {
        cout << "Teacher Name: " << name << "\n";
        cout << "Teacher ID: " << teacherID << "\n";
    }

    void setTeacherID(string teacherID) { this->teacherID = teacherID; }
    const string& getTeacherID() const { return teacherID; }
};

class Student : public Person {
private:
    string studentID;
public:
    Student(string name, string email, string phone, string studentID) 
        : Person(name, email, phone), studentID(studentID) {}

    void printDetails() const override {
        cout << "Student Name: " << name << "\n";
        cout << "Student ID: " << studentID << "\n";
    }

    void setStudentID(string studentID) { this->studentID = studentID; }
    string getStudentID() const { return studentID; }
};

class Room {
private:
    string roomNumber;
    int capacity;
    bool isAvailable;
public:
    Room(string roomNumber, int capacity, bool isAvailable) {
        this->roomNumber = roomNumber;
        this->capacity = capacity;
        this->isAvailable = isAvailable;
    }

    void setRoomNumber(string roomNumber) { this->roomNumber = roomNumber; }
    void setCapacity(int capacity) { this->capacity = capacity; }
    void setIsAvailable(bool isAvailable) { this->isAvailable = isAvailable; }
    string getRoomNumber() const { return roomNumber; }
    int getCapacity() const { return capacity; }
    bool getIsAvailable() const { return isAvailable; }
};

class Course {
private:
    string courseName;
    string courseCode;
    string courseDay;
    string courseTime;
    Teacher* teacher;
    vector<Student*> students;
    Room* room;
public:
    Course(string courseName, string courseCode, string courseDay, string courseTime, Teacher* teacher, vector<Student*> students, Room* room)
        : courseName(courseName), courseCode(courseCode), courseDay(courseDay), courseTime(courseTime), teacher(teacher), students(students), room(room) {}

    // setter and getter methods
    void setCourseName(string courseName) { this->courseName = courseName; }
    void setCourseCode(string courseCode) { this->courseCode = courseCode; }
    void setCourseDay(string courseDay) { this->courseDay = courseDay; }
    void setCourseTime(string courseTime) { this->courseTime = courseTime; }
    void setTeacher(Teacher* teacher) { this->teacher = teacher; }
    void setStudents(vector<Student*> students) { this->students = students; }
    void setRoom(Room* room) { this->room = room; }

    const string& getCourseName() const { return courseName; }
    const string& getCourseCode() const { return courseCode; }
    const string& getCourseDay() const { return courseDay; }
    const string& getCourseTime() const { return courseTime; }
    const Teacher* getTeacher() const { return teacher; }
    const vector<Student*>& getStudents() const { return students; }
    const Room* getRoom() const { return room; }

    void addStudent(Student* student) {
        this->students.push_back(student);
    }

    void modifyStudent(string studentName, Student* student) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i]->getName() == studentName) {
                students[i] = student;
                break;
            }
        }
    }

    void removeStudent(string studentName) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i]->getName() == studentName) {
                students.erase(students.begin() + i);
                break;
            }
        }
    }
};

vector<Course> courseList;
vector<Teacher*> teacherList;
vector<Student*> studentList;
vector<Room*> roomList;

void addCourse() {
    string courseName, courseCode, courseDay, courseTime;
    cout << "Enter Course Name: ";
    cin >> courseName;
    cout << "Enter Course Code: ";
    cin >> courseCode;
    cout << "Enter Course Day: ";
    cin >> courseDay;
    cout << "Enter Course Time: ";
    cin >> courseTime;

    string teacherID;
    cout << "Enter Teacher ID: ";
    cin >> teacherID;
    Teacher* teacher = nullptr;
    for (auto &t : teacherList) {
        if (t->getTeacherID() == teacherID) {
            teacher = t;
            break;
        }
    }

    vector<Student*> students;
    string studentID;
    cout << "Enter Student IDs (end with 'end'): ";
    while (cin >> studentID && studentID != "end") {
        for (auto &s : studentList) {
            if (s->getStudentID() == studentID) {
                students.push_back(s);
                break;
            }
        }
    }

    string roomNumber;
    cout << "Enter Room Number: ";
    cin >> roomNumber;
    Room* room = nullptr;
    for (auto &r : roomList) {
        if (r->getRoomNumber() == roomNumber) {
            room = r;
            break;
        }
    }

    courseList.push_back(Course(courseName, courseCode, courseDay, courseTime, teacher, students, room));
    cout << "Course added successfully.\n";
}

void modifyCourse() {
    string courseCode;
    cout << "Enter Course Code to Modify: ";
    cin >> courseCode;
    for (auto &course : courseList) {
        if (course.getCourseCode() == courseCode) {
            string courseName, courseDay, courseTime;
            cout << "Enter new Course Name: ";
            cin >> courseName;
            cout << "Enter new Course Day: ";
            cin >> courseDay;
            cout << "Enter new Course Time: ";
            cin >> courseTime;
            course.setCourseName(courseName);
            course.setCourseDay(courseDay);
            course.setCourseTime(courseTime);

            string teacherID;
            cout << "Enter new Teacher ID: ";
            cin >> teacherID;
            Teacher* teacher = nullptr;
            for (auto &t : teacherList) {
                if (t->getTeacherID() == teacherID) {
                    teacher = t;
                    break;
                }
            }
            course.setTeacher(teacher);

            vector<Student*> students;
            string studentID;
            cout << "Enter new Student IDs (end with 'end'): ";
            while (cin >> studentID && studentID != "end") {
                for (auto &s : studentList) {
                    if (s->getStudentID() == studentID) {
                        students.push_back(s);
                        break;
                    }
                }
            }
            course.setStudents(students);

            string roomNumber;
            cout << "Enter new Room Number: ";
            cin >> roomNumber;
            Room* room = nullptr;
            for (auto &r : roomList) {
                if (r->getRoomNumber() == roomNumber) {
                    room = r;
                    break;
                }
            }
            course.setRoom(room);

            cout << "Course modified successfully.\n";
            return;
        }
    }
    cout << "Course not found.\n";
}

void deleteCourse() {
    string courseCode;
    cout << "Enter Course Code to Delete: ";
    cin >> courseCode;
    auto it = std::remove_if(courseList.begin(), courseList.end(),
        [&courseCode](const Course &course) { return course.getCourseCode() == courseCode; });

    if (it != courseList.end()) {
        courseList.erase(it, courseList.end());
        cout << "Course deleted successfully.\n";
    } else {
        cout << "Course not found.\n";
    }
}

void displayCourse() {
    cout << "-----------------------------\n";
    for (const auto &course : courseList) {
        cout << "Course Name: " << course.getCourseName() << "\n";
        cout << "Course Code: " << course.getCourseCode() << "\n";
        cout << "Day: " << course.getCourseDay() << "\n";
        cout << "Time: " << course.getCourseTime() << "\n";
        cout << "Teacher: " << (course.getTeacher() ? course.getTeacher()->getName() : "N/A") << "\n";
        cout << "Room: " << (course.getRoom() ? course.getRoom()->getRoomNumber() : "N/A") << "\n";
        cout << "Students: ";
        for (const auto &student : course.getStudents()) {
            cout << student->getName() << " ";
        }
        cout << "\n-----------------------------\n";
    }
}

void addTeacher() {
    string name, email, phone, teacherID;
    cout << "Enter Teacher Name: ";
    cin >> name;
    cout << "Enter Teacher Email: ";
    cin >> email;
    cout << "Enter Teacher Phone: ";
    cin >> phone;
    cout << "Enter Teacher ID: ";
    cin >> teacherID;
    teacherList.push_back(new Teacher(name, email, phone, teacherID));
    cout << "Teacher added successfully.\n";
}

void modifyTeacher() {
    string teacherID;
    cout << "Enter Teacher ID to Modify: ";
    cin >> teacherID;
    for (auto &teacher : teacherList) {
        if (teacher->getTeacherID() == teacherID) {
            string name, email, phone;
            cout << "Enter new Teacher Name: ";
            cin >> name;
            cout << "Enter new Teacher Email: ";
            cin >> email;
            cout << "Enter new Teacher Phone: ";
            cin >> phone;
            teacher->setName(name);
            teacher->setEmail(email);
            teacher->setPhone(phone);
            cout << "Teacher modified successfully.\n";
            return;
        }
    }
    cout << "Teacher not found.\n";
}

void deleteTeacher() {
    string teacherID;
    cout << "Enter Teacher ID to Delete: ";
    cin >> teacherID;
    auto it = std::remove_if(teacherList.begin(), teacherList.end(),
        [&teacherID](Teacher* teacher) { return teacher->getTeacherID() == teacherID; });

    if (it != teacherList.end()) {
        teacherList.erase(it, teacherList.end());
        cout << "Teacher deleted successfully.\n";
    } else {
        cout << "Teacher not found.\n";
    }
}

void displayTeacher() {
    cout << "-----------------------------\n";
    for (const auto &teacher : teacherList) {
        teacher->printDetails();
        cout << "-----------------------------\n";
    }
}

void addStudent() {
    string name, email, phone, studentID;
    cout << "Enter Student Name: ";
    cin >> name;
    cout << "Enter Student Email: ";
    cin >> email;
    cout << "Enter Student Phone: ";
    cin >> phone;
    cout << "Enter Student ID: ";
    cin >> studentID;
    studentList.push_back(new Student(name, email, phone, studentID));
    cout << "Student added successfully.\n";
}

void modifyStudent() {
    string studentID;
    cout << "Enter Student ID to Modify: ";
    cin >> studentID;
    for (auto &student : studentList) {
        if (student->getStudentID() == studentID) {
            string name, email, phone;
            cout << "Enter new Student Name: ";
            cin >> name;
            cout << "Enter new Student Email: ";
            cin >> email;
            cout << "Enter new Student Phone: ";
            cin >> phone;
            student->setName(name);
            student->setEmail(email);
            student->setPhone(phone);
            cout << "Student modified successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void deleteStudent() {
    string studentID;
    cout << "Enter Student ID to Delete: ";
    cin >> studentID;
    auto it = std::remove_if(studentList.begin(), studentList.end(),
        [&studentID](Student* student) { return student->getStudentID() == studentID; });

    if (it != studentList.end()) {
        studentList.erase(it, studentList.end());
        cout << "Student deleted successfully.\n";
    } else {
        cout << "Student not found.\n";
    }
}

void displayStudent() {
    cout << "-----------------------------\n";
    for (const auto &student : studentList) {
        student->printDetails();
        cout << "-----------------------------\n";
    }
}

void addRoom() {
    string roomNumber;
    int capacity;
    bool isAvailable;
    cout << "Enter Room Number: ";
    cin >> roomNumber;
    cout << "Enter Room Capacity: ";
    cin >> capacity;
    cout << "Is Room Available (1 for Yes, 0 for No): ";
    cin >> isAvailable;
    roomList.push_back(new Room(roomNumber, capacity, isAvailable));
    cout << "Room added successfully.\n";
}

void modifyRoom() {
    string roomNumber;
    cout << "Enter Room Number to Modify: ";
    cin >> roomNumber;
    for (auto &room : roomList) {
        if (room->getRoomNumber() == roomNumber) {
            int capacity;
            bool isAvailable;
            cout << "Enter new Room Capacity: ";
            cin >> capacity;
            cout << "Is Room Available (1 for Yes, 0 for No): ";
            cin >> isAvailable;
            room->setCapacity(capacity);
            room->setIsAvailable(isAvailable);
            cout << "Room modified successfully.\n";
            return;
        }
    }
    cout << "Room not found.\n";
}

void deleteRoom() {
    string roomNumber;
    cout << "Enter Room Number to Delete: ";
    cin >> roomNumber;
    auto it = std::remove_if(roomList.begin(), roomList.end(),
        [&roomNumber](Room* room) { return room->getRoomNumber() == roomNumber; });

    if (it != roomList.end()) {
        roomList.erase(it, roomList.end());
        cout << "Room deleted successfully.\n";
    } else {
        cout << "Room not found.\n";
    }
}

void displayRoom() {
    for (const auto &room : roomList) {
        cout << "-----------------------------\n";
        cout << "Room Number: " << room->getRoomNumber() << "\n";
        cout << "Capacity: " << room->getCapacity() << "\n";
        cout << "Availability: " << (room->getIsAvailable() ? "Available" : "Not Available") << "\n";
        cout << "-----------------------------\n";
    }
}

void displayTimetable() {
    displayCourse();
}

void printMenu() {
    int choice;
    cout << "1. Course Menu\n";
    cout << "2. Teacher Menu\n";
    cout << "3. Student Menu\n";
    cout << "4. Room Menu\n";
    cout << "5. Generate Timetable\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    int subChoice;
    switch (choice) {
        case 1:
            cout << "1. Add Course\n";
            cout << "2. Modify Course\n";
            cout << "3. Delete Course\n";
            cout << "4. Display Course\n";
            cout << "Enter your choice: ";
            cin >> subChoice;
            switch (subChoice) {
                case 1:
                    addCourse();
                    break;
                case 2:
                    modifyCourse();
                    break;
                case 3:
                    deleteCourse();
                    break;
                case 4:
                    displayCourse();
                    break;
                default:
                    cout << "Invalid Choice\n";
            }
            break;

        case 2:
            cout << "1. Add Teacher\n";
            cout << "2. Modify Teacher\n";
            cout << "3. Delete Teacher\n";
            cout << "4. Display Teacher\n";
            cout << "Enter your choice: ";
            cin >> subChoice;
            switch (subChoice) {
                case 1:
                    addTeacher();
                    break;
                case 2:
                    modifyTeacher();
                    break;
                case 3:
                    deleteTeacher();
                    break;
                case 4:
                    displayTeacher();
                    break;
                default:
                    cout << "Invalid Choice\n";
            }
            break;

        case 3:
            cout << "1. Add Student\n";
            cout << "2. Modify Student\n";
            cout << "3. Delete Student\n";
            cout << "4. Display Student\n";
            cout << "Enter your choice: ";
            cin >> subChoice;
            switch (subChoice) {
                case 1:
                    addStudent();
                    break;
                case 2:
                    modifyStudent();
                    break;
                case 3:
                    deleteStudent();
                    break;
                case 4:
                    displayStudent();
                    break;
                default:
                    cout << "Invalid Choice\n";
            }
            break;

        case 4:
            cout << "1. Add Room\n";
            cout << "2. Modify Room\n";
            cout << "3. Delete Room\n";
            cout << "4. Display Room\n";
            cout << "Enter your choice: ";
            cin >> subChoice;
            switch (subChoice) {
                case 1:
                    addRoom();
                    break;
                case 2:
                    modifyRoom();
                    break;
                case 3:
                    deleteRoom();
                    break;
                case 4:
                    displayRoom();
                    break;
                default:
                    cout << "Invalid Choice\n";
            }
            break;

        case 5:
            displayTimetable();
            break;

        case 0:
            exit(0);
            break;

        default:
            cout << "Invalid Choice\n";
    }
}

int main() {
    while (true) {
        printMenu();
        cout << "\n";
    }
    return 0;
}
