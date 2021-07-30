#include <iostream>
#include <fstream>
#include <sstream>
#include "earnings.h"

using std::cin, std::cout, std::endl;

void Stock::parseDataFile(string dataFile)
{
    std::ifstream ifs(dataFile);
    if (!ifs.is_open())
    {
        cout << "Error: cannot open file " << dataFile << endl;
        return;
    }

    string hdr;
    getline(ifs, hdr);

    string s_date;
    string s_open;
    string s_high;
    string s_low;
    string s_close;
    string s_adjClose;
    string s_volume;

    string line;

    while (!ifs.eof())
    {
        getline(ifs, line);
        std::istringstream lineSS(line);

        getline(lineSS, s_date, ',');
        getline(lineSS, s_open, ',');
        getline(lineSS, s_high, ',');
        getline(lineSS, s_low, ',');
        getline(lineSS, s_close, ',');
        getline(lineSS, s_adjClose, ',');
        getline(lineSS, s_volume, ',');

        Date dateObj(s_date);
        this->dates.push_back(dateObj);
        this->open.push_back(std::stod(s_open));
        this->high.push_back(std::stod(s_high));
        this->low.push_back(std::stod(s_low));
        this->close.push_back(std::stod(s_close));
        this->adjClose.push_back(std::stod(s_adjClose));
        this->volume.push_back(std::stol(s_volume));
    }
}

void Stock::parseEarningsFile(string earningsFile)
{
    std::ifstream ifs(earningsFile);
    if (!ifs.is_open())
    {
        cout << "Error: cannot open file " << earningsFile << endl;
        return;
    }

    string hdr;
    getline(ifs, hdr);

    string s_date;
    string line;

    while (!ifs.eof())
    {
        getline(ifs, line);
        std::istringstream lineSS(line);

        getline(lineSS, s_date);
        if (s_date != "")
        {
            Date dateObj(s_date);
            this->earningsDates.push_back(dateObj);
        }
    }
}
