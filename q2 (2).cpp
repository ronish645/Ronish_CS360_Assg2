#include <iostream>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    // Constructor with parameter validation for month
    Date(int m, int d, int y) : day(d), year(y) {
        if(m >= 1 && m <= 12) {
            month = m;
        } else {
            month = 1; // Set month to 1 if out of range
        }
    }

    // Set functions
    void setMonth(int m) {
        month = (m >= 1 && m <= 12) ? m : 1; // Validate month
    }

    void setDay(int d) {
        day = d;
    }

    void setYear(int y) {
        year = y;
    }

    // Get functions
    int getMonth() const {
        return month;
    }

    int getDay() const {
        return day;
    }

    int getYear() const {
        return year;
    }

    // displayDate function
    void displayDate() const {
        cout << month << "/" << day << "/" << year << endl;
    }
};

int main() {
    // Create a Date object
    Date today(13, 25, 2024); // This will set the month to 1 because 13 is out of range

    // Display the date
    cout << "Today's date is: ";
    today.displayDate();

    // Modify the date using set functions
    today.setMonth(12);
    today.setDay(24);
    today.setYear(2024);

    // Display the modified date
    cout << "Modified date is: ";
    today.displayDate();

    return 0;
}
