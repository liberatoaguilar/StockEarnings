#include <iostream>
#include "date.h"

using std::cin, std::cout, std::endl;

// Constructor
Date::Date(string dateString) : date(dateString)
{
    // Split date into year, month, day
    std::istringstream dateSS(dateString);
    string s_year;
    string s_month;
    string s_day;
    getline(dateSS, s_year, '-');
    getline(dateSS, s_month, '-');
    getline(dateSS, s_day);
    // Convert and store
    this->year = std::stoi(s_year);
    this->month = std::stoi(s_month);
    this->day = std::stoi(s_day);
}

// Test for equality
bool Date::operator==(Date& other)
{
    return (this->getDateString() == other.getDateString());
}

bool Date::operator<(Date& other)
{
    // First test year
    if (this->getYear() < other.getYear())
    {
        return true;
    } else if (this->getYear() > other.getYear()) {
        return false;
    } else { // Same year
        // Now test month
        if (this->getMonth() < other.getMonth())
        {
            return true;
        } else if (this->getMonth() > other.getMonth()) {
            return false;
        } else { // Same month
            // Now test day
            if (this->getDay() < other.getDay())
            {
                return true;
            } else if (this->getDay() > other.getDay()) {
                return false;
            } else { // Same day (not less than)
                return false;
            }
        }
    }
    // Default
    return false;
}
