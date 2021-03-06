#ifndef _DATE
#define _DATE

#include <string>
#include <sstream>

using std::string;

class Date
{
private:
    int year;
    int month;
    int day;
    string date;
public:
    // Constructor
    Date(string dateString);

    // Getters
    int getYear() { return this->year; }
    int getMonth() { return this->month; }
    int getDay() { return this->day; }
    string getDateString() { return this->date; }

    // Overloaded Operators
    bool operator==(Date& other);
    bool operator<(Date& other);
};

#endif

