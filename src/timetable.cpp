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
        cout << "\033[1;34mNama Guru: \033[0m" << name << "\n";
        cout << "\033[1;34mID Guru: \033[0m" << teacherID << "\n";
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
        cout << "\033[1;34mNama Siswa: \033[0m" << name << "\n";
        cout << "\033[1;34mID Siswa: \033[0m" << studentID << "\n";
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
    cout << "\033[1;33mMasukkan Nama Kursus: \033[0m";
    cin >> courseName;
    cout << "\033[1;33mMasukkan Kode Kursus: \033[0m";
    cin >> courseCode;
    cout << "\033[1;33mMasukkan Hari Kursus: \033[0m";
    cin >> courseDay;
    cout << "\033[1;33mMasukkan Waktu Kursus: \033[0m";
    cin >> courseTime;

    string teacherID;
    cout << "\033[1;33mMasukkan ID Guru: \033[0m";
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
    cout << "\033[1;33mMasukkan ID Siswa (akhiri dengan 'end'): \033[0m";
    while (cin >> studentID && studentID != "end") {
        for (auto &s : studentList) {
            if (s->getStudentID() == studentID) {
                students.push_back(s);
                break;
            }
        }
    }

    string roomNumber;
    cout << "\033[1;33mMasukkan Nomor Ruangan: \033[0m";
    cin >> roomNumber;
    Room* room = nullptr;
    for (auto &r : roomList) {
        if (r->getRoomNumber() == roomNumber) {
            room = r;
            break;
        }
    }

    courseList.push_back(Course(courseName, courseCode, courseDay, courseTime, teacher, students, room));
    cout << "\033[1;32mKursus berhasil ditambahkan.\033[0m\n";
}

void modifyCourse() {
    string courseCode;
    cout << "\033[1;33mMasukkan Kode Kursus untuk Dimodifikasi: \033[0m";
    cin >> courseCode;
    for (auto &course : courseList) {
        if (course.getCourseCode() == courseCode) {
            string courseName, courseDay, courseTime;
            cout << "\033[1;33mMasukkan Nama Kursus Baru: \033[0m";
            cin >> courseName;
            cout << "\033[1;33mMasukkan Hari Kursus Baru: \033[0m";
            cin >> courseDay;
            cout << "\033[1;33mMasukkan Waktu Kursus Baru: \033[0m";
            cin >> courseTime;
            course.setCourseName(courseName);
            course.setCourseDay(courseDay);
            course.setCourseTime(courseTime);

            string teacherID;
            cout << "\033[1;33mMasukkan ID Guru Baru: \033[0m";
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
            cout << "\033[1;33mMasukkan ID Siswa Baru (akhiri dengan 'end'): \033[0m";
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
            cout << "\033[1;33mMasukkan Nomor Ruangan Baru: \033[0m";
            cin >> roomNumber;
            Room* room = nullptr;
            for (auto &r : roomList) {
                if (r->getRoomNumber() == roomNumber) {
                    room = r;
                    break;
                }
            }
            course.setRoom(room);

            cout << "\033[1;32mKursus berhasil dimodifikasi.\033[0m\n";
            return;
        }
    }
    cout << "\033[1;31mKursus tidak ditemukan.\033[0m\n";
}

void deleteCourse() {
    string courseCode;
    cout << "\033[1;33mMasukkan Kode Kursus untuk Dihapus: \033[0m";
    cin >> courseCode;
    for (auto it = courseList.begin(); it != courseList.end(); ++it) {
        if (it->getCourseCode() == courseCode) {
            courseList.erase(it);
            cout << "\033[1;32mKursus berhasil dihapus.\033[0m\n";
            return;
        }
    }
    cout << "\033[1;31mKursus tidak ditemukan.\033[0m\n";
}

void displayCourses() {
    cout << "\033[1;36mMenampilkan semua kursus:\033[0m\n";
    for (const auto &course : courseList) {
        cout << "Nama Kursus: " << course.getCourseName() << "\n";
        cout << "Kode Kursus: " << course.getCourseCode() << "\n";
        cout << "Hari Kursus: " << course.getCourseDay() << "\n";
        cout << "Waktu Kursus: " << course.getCourseTime() << "\n";
        if (course.getTeacher()) {
            cout << "Guru: " << course.getTeacher()->getName() << "\n";
        }
        cout << "Siswa: ";
        for (const auto &student : course.getStudents()) {
            cout << student->getName() << " ";
        }
        cout << "\n";
        if (course.getRoom()) {
            cout << "Ruangan: " << course.getRoom()->getRoomNumber() << "\n";
        }
        cout << "-------------------------\n";
    }
}

void displayMenu() {
    cout << "\033[1;33m===========================\n";
    cout << "Manajemen Kursus Universitas\n";
    cout << "===========================\033[0m\n";
    cout << "\033[1;32m1. Tambah Kursus\n";
    cout << "2. Modifikasi Kursus\n";
    cout << "3. Hapus Kursus\n";
    cout << "4. Tampilkan Kursus\n";
    cout << "5. Keluar\033[0m\n";
    cout << "Masukkan pilihan Anda: ";
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
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
                displayCourses();
                break;
            case 5:
                cout << "\033[1;32mKeluar...\033[0m\n";
                break;
            default:
                cout << "\033[1;31mPilihan tidak valid. Silakan coba lagi.\033[0m\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
