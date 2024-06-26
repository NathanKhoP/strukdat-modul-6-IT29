#include <bits/stdc++.h>
using namespace std;

const string RESET_COLOR = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";

class Teacher;  
class Student;
class Room;    

void logToFile(const string& message) {
    time_t currentTime = time(nullptr);
    struct tm* localTime = localtime(&currentTime);
    ofstream logFile("logs.log", ios::app);

    logFile << "[" << put_time(localTime, "%Y-%m-%d %H:%M:%S") << "] " << message << endl;
    logFile.close();
}

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
        cout << "Teacher Email: " << email << "\n";
        cout << "Teacher Phone: " << phone << "\n";
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
        cout << "Student Email: " << email << "\n";
        cout << "Student Phone: " << phone << "\n";
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
    int numStudents = 0;
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

    int getNumStudents() const { return numStudents; }
    void setNumStudents(int numStudents) { this->numStudents = numStudents; }
};

vector<Course> courseList;
vector<Teacher*> teacherList;
vector<Student*> studentList;
vector<Room*> roomList;

void addCourse() {
    string courseName, courseCode, courseDay, courseTime;
    cout << CYAN << "Enter Course Name: " << RESET_COLOR;
    getline(cin >> ws, courseName);
    cout << CYAN << "Enter Course Code: " << RESET_COLOR;
    cin >> courseCode;
    cout << CYAN << "Enter Course Day: " << RESET_COLOR;
    cin >> courseDay;
    cout << CYAN << "Enter Course Time: " << RESET_COLOR;
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
            if (!room->getIsAvailable()) {
                cout << RED << "Room is not available." << RESET_COLOR << endl;
                return;
            }
            break;
        }
    }

    courseList.push_back(Course(courseName, courseCode, courseDay, courseTime, teacher, students, room));
    courseList.back().setNumStudents(students.size());
    cout << GREEN << "Course added successfully." << RESET_COLOR << endl;
    logToFile("Course added: " + courseCode);

}

void modifyCourse() {
    string courseCode;
    cout << CYAN << "Enter Course Code to Modify: " << RESET_COLOR;
    cin >> courseCode;

    for (auto &course : courseList) {
        if (course.getCourseCode() == courseCode) {
            string courseName, courseDay, courseTime;
            cout << "Enter new Course Name: ";
            getline(cin >> ws, courseName);
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
            course.setNumStudents(students.size());

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

            if (course.getRoom() != room) {
                room->setIsAvailable(true);
            }
            room->setIsAvailable(false);

            cout << GREEN << "Course modified successfully." << RESET_COLOR << endl;
            logToFile("Course modified: " + courseCode);
            return;
        }
    }
    cout << RED << "Course not found." << RESET_COLOR << endl;
    logToFile("Course modification failed: " + courseCode);
}

void deleteCourse() {
    string courseCode;
    cout << CYAN << "Enter Course Code to Delete: " << RESET_COLOR;
    cin >> courseCode;
    auto it = std::remove_if(courseList.begin(), courseList.end(),
        [&courseCode](const Course &course) { return course.getCourseCode() == courseCode; });

    if (it != courseList.end()) {
        courseList.erase(it, courseList.end());
        cout << GREEN << "Course deleted successfully." << RESET_COLOR << endl;
        logToFile("Course deleted: " + courseCode);
    } else {
        cout << RED << "Course not found." << RESET_COLOR << endl;
        logToFile("Course deletion failed: " + courseCode);
    }
}

void displayCourse() {
    cout << YELLOW << "-----------------------------" << RESET_COLOR << endl;
    for (const auto &course : courseList) {
        cout << BLUE << "Course Name: " << RESET_COLOR << course.getCourseName() << endl;
        cout << BLUE << "Course Code: " << RESET_COLOR << course.getCourseCode() << endl;
        cout << BLUE << "Day: " << RESET_COLOR << course.getCourseDay() << endl;
        cout << BLUE << "Time: " << RESET_COLOR << course.getCourseTime() << endl;
        cout << YELLOW << "-----------------------------" << RESET_COLOR << endl;
    }
}

void addTeacher() {
    string name, email, phone, teacherID;
    cout << CYAN << "Enter Teacher Name: " << RESET_COLOR;
    getline(cin >> ws, name);
    cout << CYAN << "Enter Teacher Email: " << RESET_COLOR;
    cin >> email;
    cout << CYAN << "Enter Teacher Phone: " << RESET_COLOR;
    cin >> phone;
    cout << CYAN << "Enter Teacher ID: " << RESET_COLOR;
    cin >> teacherID;
    teacherList.push_back(new Teacher(name, email, phone, teacherID));
    cout << GREEN << "Teacher added successfully." << RESET_COLOR << endl;
    logToFile("Teacher added: " + teacherID);
}

void modifyTeacher() {
    string teacherID;
    cout << CYAN << "Enter Teacher ID to Modify: " << RESET_COLOR;
    cin >> teacherID;
    for (auto &teacher : teacherList) {
        if (teacher->getTeacherID() == teacherID) {
            string name, email, phone;
            cout << CYAN << "Enter new Teacher Name: " << RESET_COLOR;
            getline(cin >> ws, name);
            cout << CYAN << "Enter new Teacher Email: " << RESET_COLOR;
            cin >> email;
            cout << CYAN << "Enter new Teacher Phone: " << RESET_COLOR;
            cin >> phone;
            teacher->setName(name);
            teacher->setEmail(email);
            teacher->setPhone(phone);
            cout << GREEN << "Teacher modified successfully." << RESET_COLOR << endl;
            logToFile("Teacher modified: " + teacherID);
            return;
        }
    }
    cout << RED << "Teacher not found." << RESET_COLOR << endl;
    logToFile("Teacher modification failed: " + teacherID);
}

void deleteTeacher() {
    string teacherID;
    cout << CYAN << "Enter Teacher ID to Delete: " << RESET_COLOR;
    cin >> teacherID;
    auto it = std::remove_if(teacherList.begin(), teacherList.end(),
        [&teacherID](Teacher* teacher) { return teacher->getTeacherID() == teacherID; });
    if (it != teacherList.end()) {
        teacherList.erase(it, teacherList.end());
        cout << GREEN << "Teacher deleted successfully." << RESET_COLOR << endl;
        logToFile("Teacher deleted: " + teacherID);
    } else {
        cout << RED << "Teacher not found." << RESET_COLOR << endl;
        logToFile("Teacher deletion failed: " + teacherID);
    }
}

void displayTeacher() {
    cout << YELLOW << "-----------------------------" << RESET_COLOR << endl;
    for (const auto &teacher : teacherList) {
        cout << BLUE << "Teacher Details:" << RESET_COLOR << endl;
        teacher->printDetails();
        cout << YELLOW << "-----------------------------" << RESET_COLOR << endl;
    }
}

void addStudent() {
    string name, email, phone, studentID;
    cout << CYAN << "Enter Student Name: " << RESET_COLOR;
    getline(cin >> ws, name);
    cout << CYAN << "Enter Student Email: " << RESET_COLOR;
    cin >> email;
    cout << CYAN << "Enter Student Phone: " << RESET_COLOR;
    cin >> phone;
    cout << CYAN << "Enter Student ID: " << RESET_COLOR;
    cin >> studentID;
    studentList.push_back(new Student(name, email, phone, studentID));
    cout << GREEN << "Student added successfully." << RESET_COLOR << endl;
    logToFile("Student added: " + studentID);
}

void modifyStudent() {
    string studentID;
    cout << CYAN << "Enter Student ID to Modify: " << RESET_COLOR;
    cin >> studentID;
    for (auto &student : studentList) {
        if (student->getStudentID() == studentID) {
            string name, email, phone;
            cout << CYAN << "Enter new Student Name: " << RESET_COLOR;
            getline(cin >> ws, name);
            cout << CYAN << "Enter new Student Email: " << RESET_COLOR;
            cin >> email;
            cout << CYAN << "Enter new Student Phone: " << RESET_COLOR;
            cin >> phone;
            student->setName(name);
            student->setEmail(email);
            student->setPhone(phone);
            cout << GREEN << "Student modified successfully." << RESET_COLOR << endl;
            logToFile("Student modified: " + studentID);
            return;
        }
    }
    cout << RED << "Student not found." << RESET_COLOR << endl;
    logToFile("Student modification failed: " + studentID);
}

void deleteStudent() {
    string studentID;
    cout << CYAN << "Enter Student ID to Delete: " << RESET_COLOR;
    cin >> studentID;
    auto it = std::remove_if(studentList.begin(), studentList.end(),
        [&studentID](Student* student) { return student->getStudentID() == studentID; });
    if (it != studentList.end()) {
        studentList.erase(it, studentList.end());
        cout << GREEN << "Student deleted successfully." << RESET_COLOR << endl;
        logToFile("Student deleted: " + studentID);
    } else {
        cout << RED << "Student not found." << RESET_COLOR << endl;
        logToFile("Student deletion failed: " + studentID);
    }
}

void displayStudent() {
    cout << YELLOW << "-----------------------------" << RESET_COLOR << endl;
    for (const auto &student : studentList) {
        cout << BLUE << "Student Details:" << RESET_COLOR << endl;
        student->printDetails();
        cout << YELLOW << "-----------------------------" << RESET_COLOR << endl;
    }
}


void addRoom() {
    string roomNumber;
    int capacity;
    bool isAvailable;
    cout << CYAN << "Enter Room Number: " << RESET_COLOR;
    cin >> roomNumber;
    cout << CYAN << "Enter Room Capacity: " << RESET_COLOR;
    cin >> capacity;
    cout << CYAN << "Is Room Available (1 for Yes, 0 for No): " << RESET_COLOR;
    cin >> isAvailable;
    roomList.push_back(new Room(roomNumber, capacity, isAvailable));
    cout << GREEN << "Room added successfully." << RESET_COLOR << endl;
    logToFile("Room added: " + roomNumber);
}

void modifyRoom() {
    string roomNumber;
    cout << CYAN << "Enter Room Number to Modify: " << RESET_COLOR;
    cin >> roomNumber;
    for (auto &room : roomList) {
        if (room->getRoomNumber() == roomNumber) {
            int capacity;
            bool isAvailable;
            cout << CYAN << "Enter new Room Capacity: " << RESET_COLOR;
            cin >> capacity;
            cout << CYAN << "Is Room Available (1 for Yes, 0 for No): " << RESET_COLOR;
            cin >> isAvailable;
            room->setCapacity(capacity);
            room->setIsAvailable(isAvailable);
            cout << GREEN << "Room modified successfully." << RESET_COLOR << endl;
            logToFile("Room modified: " + roomNumber);
            return;
        }
    }
    cout << RED << "Room not found." << RESET_COLOR << endl;
    logToFile("Room modification failed: " + roomNumber);
}

void deleteRoom() {
    string roomNumber;
    cout << CYAN << "Enter Room Number to Delete: " << RESET_COLOR;
    cin >> roomNumber;
    auto it = std::remove_if(roomList.begin(), roomList.end(),
        [&roomNumber](Room* room) { return room->getRoomNumber() == roomNumber; });
    if (it != roomList.end()) {
        roomList.erase(it, roomList.end());
        cout << GREEN << "Room deleted successfully." << RESET_COLOR << endl;
        logToFile("Room deleted: " + roomNumber);
    } else {
        cout << RED << "Room not found." << RESET_COLOR << endl;
        logToFile("Room deletion failed: " + roomNumber);
    }
}

void displayRoom() {
    cout << YELLOW << "-----------------------------" << RESET_COLOR << endl;
    for (const auto &room : roomList) {
        cout << BLUE << "Room Number: " << RESET_COLOR << room->getRoomNumber() << endl;
        cout << BLUE << "Capacity: " << RESET_COLOR << room->getCapacity() << endl;
        cout << BLUE << "Availability: " << RESET_COLOR << (room->getIsAvailable() ? "Available" : "Not Available") << endl;
        cout << YELLOW << "-----------------------------" << RESET_COLOR << endl;
    }
}

void displayTimetable() {
    cout << YELLOW << "-----------------------------" << RESET_COLOR << endl;
    for (const auto &course : courseList) {
        cout << BLUE << "Course Name: " << RESET_COLOR << course.getCourseName() << endl;
        cout << BLUE << "Course Code: " << RESET_COLOR << course.getCourseCode() << endl;
        cout << BLUE << "Day: " << RESET_COLOR << course.getCourseDay() << endl;
        cout << BLUE << "Time: " << RESET_COLOR << course.getCourseTime() << endl;
        cout << BLUE << "Teacher: " << RESET_COLOR << (course.getTeacher() ? course.getTeacher()->getName() : "N/A") << endl;
        cout << BLUE << "Room: " << RESET_COLOR << (course.getRoom() ? course.getRoom()->getRoomNumber() : "N/A") << endl;
        cout << BLUE << "Students Enrolled: " << RESET_COLOR << course.getNumStudents() << endl;
        cout << BLUE << "Students: " << RESET_COLOR;
        for (const auto &student : course.getStudents()) {
            cout << student->getName() << " ";
        }
        cout << endl << YELLOW << "-----------------------------" << RESET_COLOR << endl;
    }
}

void exportCoursesToCSV(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << RED << "Failed to open file: " << filename << RESET_COLOR << endl;
        return;
    }

    file << "Course Name,Course Code,Course Day,Course Time,Teacher ID,Student IDs,Room Number\n";
    for (const auto& course : courseList) {
        file << course.getCourseName() << ","
             << course.getCourseCode() << ","
             << course.getCourseDay() << ","
             << course.getCourseTime() << ","
             << (course.getTeacher() ? course.getTeacher()->getTeacherID() : "N/A") << ",";

        bool isFirst = true;
        for (const auto& student : course.getStudents()) {
            if (!isFirst) {
                file << "|";
            }
            file << student->getStudentID();
            isFirst = false;
        }

        file << "," << (course.getRoom() ? course.getRoom()->getRoomNumber() : "N/A") << "\n";
    }

    file.close();
    cout << GREEN << "Courses exported successfully to " << filename << RESET_COLOR << endl;
    logToFile("Courses exported to " + filename);
}

void importCoursesFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << RED << "Failed to open file: " << filename << RESET_COLOR << endl;
        return;
    }

    string line;
    getline(file, line); 

    while (getline(file, line)) {
        stringstream ss(line);
        string courseName, courseCode, courseDay, courseTime, teacherID, studentIDs, roomNumber;

        getline(ss, courseName, ',');
        getline(ss, courseCode, ',');
        getline(ss, courseDay, ',');
        getline(ss, courseTime, ',');
        getline(ss, teacherID, ',');
        getline(ss, studentIDs, ',');
        getline(ss, roomNumber, ',');

        Teacher* teacher = nullptr;
        for (const auto& t : teacherList) {
            if (t->getTeacherID() == teacherID) {
                teacher = t;
                break;
            }
        }

        vector<Student*> students;
        stringstream studentIDsStream(studentIDs);
        string studentID;
        while (getline(studentIDsStream, studentID, '|')) {
            for (const auto& s : studentList) {
                if (s->getStudentID() == studentID) {
                    students.push_back(s);
                    break;
                }
            }
        }

        Room* room = nullptr;
        for (const auto& r : roomList) {
            if (r->getRoomNumber() == roomNumber) {
                room = r;
                break;
            }
        }

        courseList.push_back(Course(courseName, courseCode, courseDay, courseTime, teacher, students, room));
        courseList.back().setNumStudents(students.size());
    }

    file.close();
    cout << GREEN << "Courses imported successfully from " << filename << RESET_COLOR << endl;
    logToFile("Courses imported from " + filename);
}

void exportStudentsToCSV(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << RED << "Failed to open file: " << filename << RESET_COLOR << endl;
        return;
    }

    file << "Student Name,Student Email,Student Phone,Student ID\n";
    for (const auto& student : studentList) {
        file << student->getName() << ","
             << student->getEmail() << ","
             << student->getPhone() << ","
             << student->getStudentID() << "\n";
    }

    file.close();
    cout << GREEN << "Students exported successfully to " << filename << RESET_COLOR << endl;
    logToFile("Students exported to " + filename);
}

void importStudentsFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << RED << "Failed to open file: " << filename << RESET_COLOR << endl;
        return;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string name, email, phone, studentID;

        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, phone, ',');
        getline(ss, studentID, ',');

        studentList.push_back(new Student(name, email, phone, studentID));
    }

    file.close();
    cout << GREEN << "Students imported successfully from " << filename << RESET_COLOR << endl;
    logToFile("Students imported from " + filename);
}

void exportTeachersToCSV(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << RED << "Failed to open file: " << filename << RESET_COLOR << endl;
        return;
    }

    file << "Teacher Name,Teacher Email,Teacher Phone,Teacher ID\n";
    for (const auto& teacher : teacherList) {
        file << teacher->getName() << ","
             << teacher->getEmail() << ","
             << teacher->getPhone() << ","
             << teacher->getTeacherID() << "\n";
    }

    file.close();
    cout << GREEN << "Teachers exported successfully to " << filename << RESET_COLOR << endl;
    logToFile("Teachers exported to " + filename);
}

void importTeachersFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << RED << "Failed to open file: " << filename << RESET_COLOR << endl;
        return;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string name, email, phone, teacherID;

        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, phone, ',');
        getline(ss, teacherID, ',');

        teacherList.push_back(new Teacher(name, email, phone, teacherID));
    }

    file.close();
    cout << GREEN << "Teachers imported successfully from " << filename << RESET_COLOR << endl;
    logToFile("Teachers imported from " + filename);
}

void exportRoomsToCSV(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << RED << "Failed to open file: " << filename << RESET_COLOR << endl;
        return;
    }

    file << "Room Number,Room Capacity,Room Availability\n";
    for (const auto& room : roomList) {
        file << room->getRoomNumber() << ","
             << room->getCapacity() << ","
             << (room->getIsAvailable() ? "Available" : "Not Available") << "\n";
    }

    file.close();
    cout << GREEN << "Rooms exported successfully to " << filename << RESET_COLOR << endl;
    logToFile("Rooms exported to " + filename);
}

void importRoomsFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << RED << "Failed to open file: " << filename << RESET_COLOR << endl;
        return;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string roomNumber;
        int capacity;
        string availability;

        getline(ss, roomNumber, ',');
        getline(ss, availability, ',');
        ss >> capacity;

        bool isAvailable = (availability == "Available");

        roomList.push_back(new Room(roomNumber, capacity, isAvailable));
    }

    file.close();
    cout << GREEN << "Rooms imported successfully from " << filename << RESET_COLOR << endl;
    logToFile("Rooms imported from " + filename);
}

void printMenu() {
    int choice;
    string exportFilename, importFilename;
    cout << "\033[1;33m===========================\n";
    cout << "Timetable Management System\n";
    cout << "===========================\033[0m\n";
    cout << MAGENTA << "1. Course Menu\n2. Teacher Menu\n3. Student Menu\n4. Room Menu\n5. Generate Timetable\n6. Export File...\n7. Import File...\n0. Exit\n" << RESET_COLOR;
    cout << CYAN << "Enter your choice: " << RESET_COLOR;
    cin >> choice;

    int subChoice;
    switch (choice) {
        case 1:
            cout << BLUE << "1. Add Course\n2. Modify Course\n3. Delete Course\n4. Display Course\n" << RESET_COLOR;
            cout << CYAN << "Enter your choice: " << RESET_COLOR;
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
                    cout << RED << "Invalid Choice\n" << RESET_COLOR;
            }
            break;

        case 2:
            cout << BLUE << "1. Add Teacher\n2. Modify Teacher\n3. Delete Teacher\n4. Display Teacher\n" << RESET_COLOR;
            cout << CYAN << "Enter your choice: " << RESET_COLOR;
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
                    cout << RED << "Invalid Choice\n" << RESET_COLOR;
            }
            break;

        case 3:
            cout << BLUE << "1. Add Student\n2. Modify Student\n3. Delete Student\n4. Display Student\n" << RESET_COLOR;
            cout << CYAN << "Enter your choice: " << RESET_COLOR;
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
                    cout << RED << "Invalid Choice\n" << RESET_COLOR;
            }
            break;

        case 4:
            cout << BLUE << "1. Add Room\n2. Modify Room\n3. Delete Room\n4. Display Room\n" << RESET_COLOR;
            cout << CYAN << "Enter your choice: " << RESET_COLOR;
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
                    cout << RED << "Invalid Choice\n" << RESET_COLOR;
            }
            break;

        case 5:
            displayTimetable();
            break;

        case 6:
            cout << BLUE << "1. Export Courses\n2. Export Students\n3. Export Teachers\n4. Export Rooms\n" << RESET_COLOR;
            cout << CYAN << "Enter your choice: " << RESET_COLOR;
            cin >> subChoice;
            cout << CYAN << "Enter filename: " << RESET_COLOR;
            cin >> exportFilename;
            switch (subChoice) {
                case 1:
                    exportCoursesToCSV(exportFilename);
                    break;
                case 2:
                    exportStudentsToCSV(exportFilename);
                    break;
                case 3:
                    exportTeachersToCSV(exportFilename);
                    break;
                case 4:
                    exportRoomsToCSV(exportFilename);
                    break;
                default:
                    cout << RED << "Invalid Choice\n" << RESET_COLOR;
            }
            break;

        case 7:
            cout << BLUE << "1. Import Courses\n2. Import Students\n3. Import Teachers\n4. Import Rooms\n" << RESET_COLOR;
            cout << RED << "Disclaimer: Due to how this program works, please input courses last when importing files.\n" << RESET_COLOR;
            cout << CYAN << "Enter your choice: " << RESET_COLOR;
            cin >> subChoice;
            cout << CYAN << "Enter filename: " << RESET_COLOR;
            cin >> importFilename;
            switch (subChoice) {
                case 1:
                    importCoursesFromCSV(importFilename);
                    break;
                case 2:
                    importStudentsFromCSV(importFilename);
                    break;
                case 3:
                    importTeachersFromCSV(importFilename);
                    break;
                case 4:
                    importRoomsFromCSV(importFilename);
                    break;
                default:
                    cout << RED << "Invalid Choice\n" << RESET_COLOR;
            }
            break;

        case 0:
            exit(0);
            break;

        default:
            cout << RED << "Invalid Choice\n" << RESET_COLOR;
    }
}

int main() {
    while (true) {
        printMenu();
        cout << "\n";
    }
    return 0;
}