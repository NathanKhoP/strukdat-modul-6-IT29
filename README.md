# Repository Final Project - IT29

### Struktur Data dan Pemrograman Berbasis Objek / Data Structures and Object-Oriented Programming


## Anggota

| Nama                      | NRP        |
|---------------------------|------------|
|Nathan Kho Pancras         | 5027231002 |
|Daffa Rajendra Priatama    | 5027231009 |
|Nayyara Ashila             | 5027221083 |

# Timetable Management System

Sistem ini adalah implementasi sederhana dari sistem manajemen jadwal dengan menggunakan C++. Sistem ini memungkinkan pengguna untuk mengelola data terkait mata pelajaran, guru, murid, dan ruangan. Berikut adalah fitur-fitur utama yang disediakan:

## Fitur Utama

### Definisi Kelas

1. **Person**: 
    - Merepresentasikan seseorang dengan atribut:
        - Nama
        - Email
        - Telepon
    - Metode:
        - Mengatur atribut-atribut tersebut
        - Mencetak detail

2. **Teacher** (Turunan dari Person):
    - Atribut tambahan:
        - teacherID
    - Metode:
        - Mendapatkan teacherID
        - Mencetak detail guru

3. **Student** (Turunan dari Person):
    - Atribut tambahan:
        - studentID
    - Metode:
        - Mendapatkan studentID
        - Mencetak detail murid

4. **Room**: 
    - Merepresentasikan sebuah ruangan dengan atribut:
        - Nomor ruangan
        - Kapasitas
        - Status ketersediaan
    - Metode:
        - Mendapatkan dan mengatur atribut-atribut tersebut

5. **Course**: 
    - Merepresentasikan sebuah mata pelajaran dengan atribut:
        - Nama mata pelajaran
        - Kode mata pelajaran
        - Hari mata pelajaran
        - Waktu mata pelajaran
    - Mata pelajaran dapat memiliki:
        - Teacher yang ditugaskan
        - Daftar Student yang terdaftar
        - Room yang ditugaskan
    - Metode:
        - Mendapatkan dan mengatur atribut-atribut tersebut
        - Menambah atau menghapus murid

### Vektor Global

- `courseList`: Menyimpan semua mata pelajaran.
- `teacherList`: Menyimpan pointer ke semua guru.
- `studentList`: Menyimpan pointer ke semua murid.
- `roomList`: Menyimpan pointer ke semua ruangan.

### Definisi Fungsi

#### Manajemen Mata Pelajaran

- `addCourse()`: Meminta pengguna untuk detail mata pelajaran dan menambahkan mata pelajaran baru ke `courseList`.
- `modifyCourse()`: Meminta pengguna untuk kode mata pelajaran, kemudian memungkinkan modifikasi detail mata pelajaran yang sesuai.
- `removeCourse()`: Meminta pengguna untuk kode mata pelajaran dan menghapus mata pelajaran yang sesuai dari `courseList`.

#### Manajemen Guru

- `addTeacher()`: Meminta pengguna untuk detail guru dan menambahkan guru baru ke `teacherList`.
- `modifyTeacher()`: Meminta pengguna untuk ID guru, kemudian memungkinkan modifikasi detail guru yang sesuai.
- `removeTeacher()`: Meminta pengguna untuk ID guru dan menghapus guru yang sesuai dari `teacherList`.

#### Manajemen Murid

- `addStudent()`: Meminta pengguna untuk detail murid dan menambahkan murid baru ke `studentList`.
- `modifyStudent()`: Meminta pengguna untuk ID murid, kemudian memungkinkan modifikasi detail murid yang sesuai.
- `removeStudent()`: Meminta pengguna untuk ID murid dan menghapus murid yang sesuai dari `studentList`.

#### Manajemen Ruangan

- `addRoom()`: Meminta pengguna untuk detail ruangan dan menambahkan ruangan baru ke `roomList`.
- `modifyRoom()`: Meminta pengguna untuk nomor ruangan, kemudian memungkinkan modifikasi detail ruangan yang sesuai.
- `removeRoom()`: Meminta pengguna untuk nomor ruangan dan menghapus ruangan yang sesuai dari `roomList`.

#### Fungsi Pencetakan

- `printCourses()`: Mencetak detail semua mata pelajaran, termasuk guru dan ruangan yang ditugaskan, serta murid yang terdaftar.
- `printTeachers()`: Mencetak detail semua guru.
- `printStudents()`: Mencetak detail semua murid.
- `printRooms()`: Mencetak detail semua ruangan.

### Fungsi Utama

- Menampilkan menu dan meminta pengguna untuk memilih tindakan.
- Berdasarkan pilihan pengguna, fungsi yang sesuai dipanggil untuk mengelola mata pelajaran, guru, murid, atau ruangan, atau untuk mencetak detail entitas tersebut.
- Loop berlanjut sampai pengguna memilih untuk keluar.

