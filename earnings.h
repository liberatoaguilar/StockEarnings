#ifndef _EARNINGS
#define _EARNINGS

#include <vector>
#include <string>
#include "date.h"

using std::vector, std::string;

class Stock
{
private:
    // Date from date.h and date.cpp
    vector<Date> dates;
    vector<double> open;
    vector<double> high;
    vector<double> low;
    vector<double> close;
    vector<double> adjClose;
    vector<int> volume;
    vector<Date> earningsDates;

    void parseDataFile(string dataFile);
    void parseEarningsFile(string earningsFile);
public:
    // Manual constructor
    Stock(vector<Date> d, vector<double> o, 
          vector<double> h, vector<double> l,
          vector<double> c, vector<double> a,
          vector<int> v, vector<Date> e) 
            : dates{d}, open{o}, high{h}, low{l}, close{c},
              adjClose{a}, volume{v}, earningsDates{e} {}

    // With data and earnings file
    Stock(string dataFile, string earningsFile)
    {
        this->parseDataFile(dataFile);
        this->parseEarningsFile(earningsFile);
    }

    // With only data file, empty earnings
    Stock(string dataFile)
    {
        this->parseDataFile(dataFile);
        this->earningsDates = {};
    }

    // Getters
    vector<Date>& getDates() { return this->dates; }
    vector<double>& getOpen() { return this->open; }
    vector<double>& getHigh() { return this->high; }
    vector<double>& getLow() {return this->low; }
    vector<double>& getClose() {return this->close; }
    vector<double>& getAdjClose() { return this->adjClose; }
    vector<int>& getVolume() { return this->volume; }
    vector<Date>& getEarningsDates() { return this->earningsDates; }

    // Setters
    void setDates(vector<Date> d) { this->dates = d; }
    void setOpen(vector<double> o) { this->open = o; }
    void setHigh(vector<double> h) { this->high = h; }
    void setLow(vector<double> l) { this->low = l; }
    void setClose(vector<double> c) { this->close = c; }
    void setAdjClose(vector<double> a) { this->adjClose = a; }
    void setVolume(vector<int> v) { this->volume = v; }
    void setEarningsDates(vector<Date> d) {  this->earningsDates = d; }

};

#endif

