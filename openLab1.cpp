#include<iostream>
using namespace std;

// Global Constants

// Initialize User Functions
bool CheckMonthValidity(int);
bool CheckDayValidity(int);
bool CheckYearValidity(int);

int CorrectMonth(int);

int main()
{
    int month; // original User input month
    int day;   // original User input day
    int year;  // original User input year
    int f;          // resulting day of the week
    int d;          // day of the month
    int m;          // month number (see Zeller's Rule)
    int D;          // decade; last 2 digits of the modified year
    int C;          // century; first 2 digits of the modified year 
    int adjustedMonth;  //month adjusted for Zeller Rule

    cout << "Welcome ! \n"
    << "Just tell me your birth date, and I will tell which day of the week you were born. \n"
    << "Lets get started ...\n\n"
    << "Please tell me your birth date, in the form of: month day year\n";
        
    cin >> month >> day >> year;
    
    // verify dates are in possible ranges && NOT negative
    if ((CheckMonthValidity == false) || (CheckDayValidity == false) || (CheckYearValidity == false))
        {
            cout << "Your input is not correct.\n"
            << "The computation is not carried out.\n\n";
        }
    else
        {
        cout << endl << "yep it's valid\n\n";
        //adjustedMonth = CorrectMonth(month);
        //cout << adjustedMonth;
        //run through Zeller's with proper output
        // f = day + (13*month-1)/5 + D + D/4 + C/4 - 2*C
        D = year % 100;
        cout << D <<" << this is D\n\n";
        C = year/100;
        cout << C << " << this is C\n";
        }
    
    return 0;
}

bool CheckMonthValidity(int month)
{
    if ((month > 0) && (month < 13))
        {return true;}
    else
        {return false;}
}

bool CheckDayValidity(int day)
{
    if ((day > 0) && (day < 32))
        {return true;}
    else
        {return false;}
}

bool CheckYearValidity(int year)
{
    if ((year > 0) && (year < 2017))
    {return true;}
    else
    {return false;}
}

int CorrectMonth(int month)
{
    if(month > 2)
        {
            return (month -= 2);
        }
    else if(month == 1)
        {
            return (month = 11);
        }
    else if(month == 2)
        {
            return (month = 12);
        }

}
