#include <iostream>
#include <string>
using namespace std;
class HeartRates {
private:
    string firstName;
    string lastName;
    int birthMonth;
    int birthDay;
    int birthYear;

public:
    // Constructor
    HeartRates(string firstName, string lastName, int month, int day, int year)
        : firstName(firstName), lastName(lastName), birthMonth(month), birthDay(day), birthYear(year) {}

    // Set and Get functions
    void setFirstName(string fName) {
        firstName = fName;
    }

    string getFirstName() const {
        return firstName;
    }

    void setLastName(string lName) {
        lastName = lName;
    }

    string getLastName() const {
        return lastName;
    }

    void setBirthMonth(int month) {
        birthMonth = month;
    }

    int getBirthMonth() const {
        return birthMonth;
    }

    void setBirthDay(int day) {
        birthDay = day;
    }

    int getBirthDay() const {
        return birthDay;
    }

    void setBirthYear(int year) {
        birthYear = year;
    }

    int getBirthYear() const {
        return birthYear;
    }

    // Calculate age
    int getAge() const {
        int currentYear, currentMonth, currentDay;
        cout << "Enter the current year: ";
        cin >> currentYear;
        cout << "Enter the current month: ";
        cin >> currentMonth;
        cout << "Enter the current day: ";
        cin >> currentDay;

        int age = currentYear - birthYear;
        if (birthMonth > currentMonth || (birthMonth == currentMonth && birthDay > currentDay)) {
            age--;
        }
        return age;
    }

    // Calculate maximum heart rate
    int getMaximumHeartRate(int age) const {
        return 220 - age;
    }

    // Calculate target heart rate
    void getTargetHeartRate(int& targetLow, int& targetHigh, int age) const {
        int maxHeartRate = getMaximumHeartRate(age);
        targetLow = static_cast<int>(maxHeartRate * 0.5);
        targetHigh = static_cast<int>(maxHeartRate * 0.85);
    }
};

int main() {
    string firstName, lastName;
    int month, day, year;

    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    cout << "Enter your birth month (MM): ";
    cin >> month;
    cout << "Enter your birth day (DD): ";
    cin >> day;
    cout << "Enter your birth year (YYYY): ";
    cin >> year;

    HeartRates person(firstName, lastName, month, day, year);
    int age = person.getAge();
    int maxHeartRate = person.getMaximumHeartRate(age);
    int targetLow, targetHigh;
    person.getTargetHeartRate(targetLow, targetHigh, age);

    cout << "\nFirst Name: " << person.getFirstName() << "\nLast Name: " << person.getLastName()
         << "\nDate of Birth: " << person.getBirthMonth() << "/" << person.getBirthDay() << "/" << person.getBirthYear()
         << "\nAge: " << age << "\nMaximum Heart Rate: " << maxHeartRate
         << "\nTarget Heart Rate Range: " << targetLow << " - " << targetHigh << " bpm" << endl;

    return 0;
}
