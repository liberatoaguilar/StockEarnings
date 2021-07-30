#include <iostream>
#include "date.h"

using std::cin, std::cout, std::endl;

Date::Date(string dateString) : date(dateString)
{
    std::istringstream dateSS(dateString);
    string s_year;
    string s_month;
    string s_day;
    getline(dateSS, s_year, '-');
    getline(dateSS, s_month, '-');
    getline(dateSS, s_day);
    this->year = std::stoi(s_year);
    this->month = std::stoi(s_month);
    this->day = std::stoi(s_day);
}

bool Date::operator==(Date& other)
{
    return (this->getDateString() == other.getDateString());
}

bool Date::operator<(Date& other)
{
    if (this->getYear() < other.getYear())
    {
        return true;
    } else if (this->getYear() > other.getYear()) {
        return false;
    } else {
        if (this->getMonth() < other.getMonth())
        {
            return true;
        } else if (this->getMonth() > other.getMonth()) {
            return false;
        } else {
            if (this->getDay() < other.getDay())
            {
                return true;
            } else if (this->getDay() > other.getDay()) {
                return false;
            } else {
                return false;
            }
        }
    }
    return false;
}
