#include <iostream>
#include "earnings.h"
#include "date.h"

using std::cin, std::cout, std::endl;

// Given a stock calculate and output change from 
// rangeDays before to rangeDays after earnings dates
vector<double> calculateChange(Stock &stock, int rangeDays)
{
    // Formatting
    cout << endl;
    vector<double> changeVec{};
    double start;
    double end;
    double change;
    // Loop through earnings
    for (size_t i = 0; i < stock.getEarningsDates().size(); ++i)
    {
        // Loop through dates
        for (size_t j = 0; j < stock.getDates().size(); ++j)
        {
            // Wait until the actual earnings date is found or the next day
            if (stock.getDates()[j] < stock.getEarningsDates()[i]) continue;
            else
            {
                // Check for out of range errors
                if (j-rangeDays >= 0)
                {
                    // Closing price of start day
                    start = stock.getClose()[j-rangeDays];
                    cout << "Start: " << stock.getDates()[j-rangeDays].getDateString() << endl;
                } else {
                    // First date
                    start = stock.getClose()[0];
                    cout << "Start: " << stock.getDates()[0].getDateString() << endl;
                }
                // Current earnings date
                cout << "Earnings: " << stock.getEarningsDates()[i].getDateString() << endl;
                // Check for out of range errors
                if (j+rangeDays < stock.getDates().size())
                {
                    // Closing price of start day
                    end = stock.getClose()[j+rangeDays];
                    cout << "End: " << stock.getDates()[j+rangeDays].getDateString() << endl;
                } else {
                    // Last date
                    end = stock.getClose()[stock.getDates().size()-1];
                    cout << "End: " << stock.getDates()[stock.getDates().size()-1].getDateString() << endl;
                }
                // Percent change formula
                change = -1*(100-((end*100)/start));
                cout << "Change: " << change << "%" << endl << endl;
                changeVec.push_back(change);
                break;
            }
        }
    }
    return changeVec;
}

// Given vector of percent changes, calculate and output totals
void processChange(vector<double> &changeVec)
{
    double changeSum{};
    int red{}; // Negative change
    int green{}; // Positive change
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

// Wrapper function
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
    // Get files and range days
    string file{promptStockFile()};
    string earnings{promptEarningsFile()};
    int rangeDays{promptRangeDays()};
    // Create the stock
    Stock stock(file, earnings);
    // Get results
    calculateAndProcessChange(stock, rangeDays);
    return 0;
}
