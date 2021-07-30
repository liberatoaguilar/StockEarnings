#include <iostream>
#include "earnings.h"
#include "date.h"

using std::cin, std::cout, std::endl;

vector<double> calculateChange(Stock &stock, int rangeDays)
{
    vector<double> changeVec{};
    double start;
    double end;
    double change;
    for (size_t i = 0; i < stock.getEarningsDates().size(); ++i)
    {
        for (size_t j = 0; j < stock.getDates().size(); ++j)
        {
            if (stock.getDates()[j] < stock.getEarningsDates()[i]) continue;
            //else if (stock.getDates()[j] == stock.getEarningsDates()[i])
            else
            {
                if (j-rangeDays >= 0)
                {
                    start = stock.getClose()[j-rangeDays];
                    cout << "Start: " << stock.getDates()[j-rangeDays].getDateString() << endl;
                } else {
                    start = stock.getClose()[0];
                    cout << "Start: " << stock.getDates()[0].getDateString() << endl;
                }
                cout << "Earnings: " << stock.getEarningsDates()[i].getDateString() << endl;
                if (j+rangeDays < stock.getDates().size())
                {
                    end = stock.getClose()[j+rangeDays];
                    cout << "End: " << stock.getDates()[j+rangeDays].getDateString() << endl;
                } else {
                    end = stock.getClose()[stock.getDates().size()-1];
                    cout << "End: " << stock.getDates()[stock.getDates().size()-1].getDateString() << endl;
                }
                change = -1*(100-((end*100)/start));
                cout << "Change: " << change << "%" << endl << endl;
                changeVec.push_back(change);
                break;
            }
        }
    }
    return changeVec;
}

void processChange(vector<double> &changeVec)
{
    double changeSum{};
    int red{};
    int green{};
    for (auto change : changeVec)
    {
        changeSum += change;
        if (change < 0) ++red;
        else ++green;
    }
    double changeAverage = changeSum / changeVec.size();
    cout << "Average: " << changeAverage << "%" << endl;
    cout << "Total: " << changeVec.size() << endl;
    cout << "Red: " << red << " (" << (static_cast<double>(red)/changeVec.size())*100 << "%)" << endl;
    cout << "Green: " << green << " (" << (static_cast<double>(green)/changeVec.size())*100 << "%)" << endl;
}

void calculateAndProcessChange(Stock &stock, int rangeDays)
{
    vector<double> changeVec{calculateChange(stock, rangeDays)};
    processChange(changeVec);
}

string promptStockFile()
{
    cout << "Enter main .csv file: ";
    string file;
    cin >> file;
    return file;
}

string promptEarningsFile()
{
    cout << "Enter earnings .csv file: ";
    string file;
    cin >> file;
    return file;
}

int promptRangeDays()
{
    cout << "Enter range of days before/after earnings: ";
    int days;
    cin >> days;
    return days;
}

int main()
{
    string file{promptStockFile()};
    string earnings{promptEarningsFile()};
    int rangeDays{promptRangeDays()};
    Stock stock(file, earnings);
    calculateAndProcessChange(stock, rangeDays);
    return 0;
}
