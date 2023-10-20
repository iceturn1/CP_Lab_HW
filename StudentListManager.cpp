#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Student {
    string name;
    int ID;
    double grade;
};

void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter student name: ";
    cin >> newStudent.name;
    cout << "Enter student ID: ";
    cin >> newStudent.ID;
    cout << "Enter student grade: ";
    cin >> newStudent.grade;
    students.push_back(newStudent);
}

void updateStudent(vector<Student>& students, int targetID) {
    for (Student& student : students) {
        if (student.ID == targetID) {
            cout << "Enter updated grade: ";
            cin >> student.grade;
            return;
        }
    }
    cout << "Student not found." << endl;
}

void deleteStudent(vector<Student>& students, int targetID) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->ID == targetID) {
            students.erase(it);
            return;
        }
    }
    cout << "Student not found." << endl;
}

void displayStudents(const vector<Student>& students) {
    for (const Student& student : students) {
        cout << "Name: " << student.name << ", ID: " << student.ID << ", Grade: " << student.grade << endl;
    }
}

void displayAverageGrade(const vector<Student>& students) {
    double sum = 0;
    for (const Student& student : students) {
        sum += student.grade;
    }
    if (!students.empty()) {
        double average = sum / students.size();
        cout << "Average Grade: " << average << endl;
    } else {
        cout << "No students in the database." << endl;
    }
}

// Make sure to create the "student_records.txt" file in the same directory where the program is running to save and load data.
void saveToFile(const vector<Student>& students) {
    ofstream outFile("student_records.txt");
    if (outFile.is_open()) {
        for (const Student& student : students) {
            outFile << student.name << " " << student.ID << " " << student.grade << "\n";
        }
        outFile.close();
        cout << "Student records saved to file." << endl;
    } else {
        cerr << "Error: Could not open the file for writing." << endl;
    }
}

// Make sure to create the "student_records.txt" file in the same directory where the program is running to save and load data.
void loadFromFile(vector<Student>& students) {
    ifstream inFile("student_records.txt");
    if (inFile.is_open()) {
        students.clear(); // Clear existing data
        Student student;
        while (inFile >> student.name >> student.ID >> student.grade) {
            students.push_back(student);
        }
        inFile.close();
        cout << "Student records loaded from file." << endl;
    } else {
        cerr << "Error: Could not open the file for reading." << endl;
    }
}

int main() {
    vector<Student> students;
    char choice;

    do {
        cout << "Student Record System" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Update Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Display Students" << endl;
        cout << "5. Calculate Average Grade" << endl;
        cout << "6. Save to File" << endl;
        cout << "7. Load from File" << endl;
        cout << "9. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addStudent(students);
                break;
            case '2':
                int updateID;
                cout << "Enter student ID to update: ";
                cin >> updateID;
                updateStudent(students, updateID);
                break;
            case '3':
                int deleteID;
                cout << "Enter student ID to delete: ";
                cin >> deleteID;
                deleteStudent(students, deleteID);
                break;
            case '4':
                displayStudents(students);
                break;
            case '5':
                displayAverageGrade(students);
                break;
            case '6':
                saveToFile(students);
                break;
            case '7':
                loadFromFile(students);
                break;
            case '9':
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '9');

    return 0;
}
