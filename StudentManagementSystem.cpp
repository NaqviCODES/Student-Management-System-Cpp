#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

// Structure to store student data
struct Student {
    int rollNo;
    string name;
    float marks;
    char grade;
    int attendance;
};

// Vector to store students
vector<Student> students;

// Function to calculate grade
char calculateGrade(float marks) {
    if (marks >= 85)
        return 'A';
    else if (marks >= 70)
        return 'B';
    else if (marks >= 50)
        return 'C';
    else
        return 'F';
}

// Function to add a student
void addStudent() {
    Student s;
    cout << "Enter Roll No: ";
    cin >> s.rollNo;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Marks: ";
    cin >> s.marks;
    cout << "Enter Attendance (%): ";
    cin >> s.attendance;

    s.grade = calculateGrade(s.marks);
    students.push_back(s);

    cout << "Student added successfully!\n";
}

// Function to view all students
void viewStudents() {
    if (students.empty()) {
        cout << "No records found!\n";
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        cout << "\nRoll No: " << students[i].rollNo;
        cout << "\nName: " << students[i].name;
        cout << "\nMarks: " << students[i].marks;
        cout << "\nGrade: " << students[i].grade;
        cout << "\nAttendance: " << students[i].attendance << "%\n";
    }
}

// Function to search student by roll number
int searchStudent(int roll) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].rollNo == roll)
            return i;
    }
    return -1;
}

// Function to update student (Call by Reference)
void updateStudent() {
    int roll;
    cout << "Enter Roll No to update: ";
    cin >> roll;

    int index = searchStudent(roll);
    if (index != -1) {
        cout << "Enter new Marks: ";
        cin >> students[index].marks;
        cout << "Enter new Attendance: ";
        cin >> students[index].attendance;

        students[index].grade = calculateGrade(students[index].marks);
        cout << "Student record updated successfully!\n";
    } else {
        cout << "Student not found!\n";
    }
}

// Function to delete student
void deleteStudent() {
    int roll;
    cout << "Enter Roll No to delete: ";
    cin >> roll;

    int index = searchStudent(roll);
    if (index != -1) {
        students.erase(students.begin() + index);
        cout << "Student deleted successfully!\n";
    } else {
        cout << "Student not found!\n";
    }
}

// Function to save data to file
void saveToFile() {
    ofstream fout("students.txt");

    for (int i = 0; i < students.size(); i++) {
        fout << students[i].rollNo << " "
             << students[i].name << " "
             << students[i].marks << " "
             << students[i].grade << " "
             << students[i].attendance << endl;
    }

    fout.close();
    cout << "Data saved to file successfully!\n";
}

// Function to load data from file
void loadFromFile() {
    ifstream fin("students.txt");
    Student s;
    students.clear();

    while (fin >> s.rollNo >> s.name >> s.marks >> s.grade >> s.attendance) {
        students.push_back(s);
    }

    fin.close();
    cout << "Data loaded from file successfully!\n";
}

// Function to sort students by marks
void sortByMarks() {
    sort(students.begin(), students.end(),
         [](Student a, Student b) {
             return a.marks > b.marks;
         });

    cout << "Students sorted by marks successfully!\n";
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Save to File\n";
        cout << "6. Load from File\n";
        cout << "7. Sort by Marks\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: updateStudent(); break;
            case 4: deleteStudent(); break;
            case 5: saveToFile(); break;
            case 6: loadFromFile(); break;
            case 7: sortByMarks(); break;
            case 0: cout << "Program exited.\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
