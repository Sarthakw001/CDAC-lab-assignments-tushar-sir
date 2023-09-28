#include <iostream>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() : day(0), month(0), year(0) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    void Read() {
        cout << "Enter day, month, and year (DD MM YYYY): ";
        cin >> day >> month >> year;
    }

    void Write() const {
        cout << day << "/" << month << "/" << year;
    }

    Date operator+(int days) const {
        Date result = *this;
        result.day += days;
        while (result.day > 31) {
            result.day -= 31;
            result.month += 1;
            if (result.month > 12) {
                result.month -= 12;
                result.year += 1;
            }
        }
        return result;
    }

    int operator-(const Date& other) const {
        int days1 = year * 365 + month * 30 + day;
        int days2 = other.year * 365 + other.month * 30 + other.day;
        return days1 - days2;
    }

    Date operator-(int days) const {
        Date result = *this;
        result.day -= days;
        while (result.day < 1) {
            result.month -= 1;
            if (result.month < 1) {
                result.month = 12;
                result.year -= 1;
            }
            result.day += 31;
        }
        return result;
    }

    Date operator++() {
        *this = *this + 1;
        return *this;
    }

    Date operator++(int) {
        Date temp(*this);
        *this = *this + 1;
        return temp;
    }

    Date operator--() {
        *this = *this - 1;
        return *this;
    }

    Date operator--(int) {
        Date temp(*this);
        *this = *this - 1;
        return temp;
    }

    bool operator<(const Date& other) const {
        if (year < other.year) return true;
        if (year > other.year) return false;
        if (month < other.month) return true;
        if (month > other.month) return false;
        return day < other.day;
    }

    bool operator<=(const Date& other) const {
        return (*this < other) || (*this == other);
    }

    bool operator>(const Date& other) const {
        return !(*this <= other);
    }

    bool operator>=(const Date& other) const {
        return !(*this < other);
    }

    bool operator==(const Date& other) const {
        return (day == other.day) && (month == other.month) && (year == other.year);
    }

    bool operator!=(const Date& other) const {
        return !(*this == other);
    }
};

int main() {
    Date date1, date2;

    cout << "Enter date 1:\n";
    date1.Read();

    cout << "Enter date 2:\n";
    date2.Read();

    cout << "Date 1: ";
    date1.Write();
    cout << "\nDate 2: ";
    date2.Write();

    int daysToAdd;
    cout << "\nEnter days to add to Date 1: ";
    cin >> daysToAdd;

    Date date3 = date1 + daysToAdd;
    cout << "Date 1 + " << daysToAdd << " days = ";
    date3.Write();
    cout << endl;

    int daysDifference = date1 - date2;
    cout << "Date 1 - Date 2 = " << daysDifference << " days difference." << endl;

    int daysToSubtract;
    cout << "Enter days to subtract from Date 1: ";
    cin >> daysToSubtract;

    Date date4 = date1 - daysToSubtract;
    cout << "Date 1 - " << daysToSubtract << " days = ";
    date4.Write();
    cout << endl;

    Date date5(2023, 9, 25);
    cout << "\nInitial date: ";
    date5.Write();
    cout << endl;

    cout << "Prefix increment (++date5): ";
    (++date5).Write();
    cout << endl;

    cout << "Postfix increment (date5++): ";
    (date5++).Write();
    cout << "\nAfter postfix increment: ";
    date5.Write();
    cout << endl;

    cout << "Prefix decrement (--date5): ";
    (--date5).Write();
    cout << endl;

    cout << "Postfix decrement (date5--): ";
    (date5--).Write();
    cout << "\nAfter postfix decrement: ";
    date5.Write();
    cout << endl;

    if (date1 < date2) {
        cout << "\nDate 1 is less than Date 2." << endl;
    } else if (date1 <= date2) {
        cout << "\nDate 1 is less than or equal to Date 2." << endl;
    }

    if (date1 > date2) {
        cout << "Date 1 is greater than Date 2." << endl;
    } else if (date1 >= date2) {
        cout << "Date 1 is greater than or equal to Date 2." << endl;
    }

    if (date1 == date2) {
        cout << "Date 1 is equal to Date 2." << endl;
    } else if (date1 != date2) {
        cout << "Date 1 is not equal to Date 2." << endl;
    }

    return 0;
}
