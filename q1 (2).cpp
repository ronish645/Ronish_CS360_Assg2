#include <iostream>
#include <string>
using namespace std;

class GradeBook {
public:
    explicit GradeBook(string courseName, string instructorName)
        : courseName(courseName), instructorName(instructorName) {}

    void setCourseName(string name) {
        courseName = name;
    }

    string getCourseName() const {
        return courseName;
    }

    void setInstructorName(string name) {
        instructorName = name;
    }

    string getInstructorName() const {
        return instructorName;
    }

    void displayMessage() const {
        cout << "Welcome to the grade book for\n" << getCourseName() << "!"
             << endl;
        cout << "This course is presented by: " << getInstructorName() << endl;
    }

private:
    string courseName;
    string instructorName;
}; // end class GradeBook

int main() {
    GradeBook myGradeBook("CS101 Introduction to C++ Programming", "Professor Smith");
    myGradeBook.displayMessage();

    // Demonstrating changing the instructor's name
    myGradeBook.setInstructorName("Professor Johnson");
    cout << "\nChanging course instructor.\n";
    myGradeBook.displayMessage();
    return 0;
}
