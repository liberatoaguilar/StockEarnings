#ifndef _EARNINGS
#define _EARNINGS

#include <vector>
#include <string>
#include "date.h"

using std::vector, std::string;

class Stock
{
private:
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
    Stock(vector<Date> d, vector<double> o, 
          vector<double> h, vector<double> l,
          vector<double> c, vector<double> a,
          vector<int> v, vector<Date> e) 
            : dates{d}, open{o}, high{h}, low{l}, close{c},
              adjClose{a}, volume{v}, earningsDates{e} {}

    Stock(string dataFile, string earningsFile)
    {
        this->parseDataFile(dataFile);
        this->parseEarningsFile(earningsFile);
    }

    vector<Date>& getDates() { return this->dates; }
    vector<double>& getOpen() { return this->open; }
    vector<double>& getHigh() { return this->high; }
    vector<double>& getLow() {return this->low; }
    vector<double>& getClose() {return this->close; }
    vector<double>& getAdjClose() { return this->adjClose; }
    vector<int>& getVolume() { return this->volume; }
    vector<Date>& getEarningsDates() { return this->earningsDates; }
};

#endif

