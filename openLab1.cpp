/*
PROGRAMMER: Jonathan Jackson
Assignment: which assignment is this? OLA 1
Class: CSCI 2170, Section 1
Course Instructor: Dr. Li
Due Date: Midnight, Monday, 9/7/2017
Description:   
*/

#include <iostream>
#include <string>
using namespace std;

// Global Constants

// Initialize User Functions
bool CheckMonthValidity(int);
bool CheckDayValidity(int);
bool CheckYearValidity(int);

int CorrectMonth(int);
int CorrectYear(int, int);

int main()
{
    int month; // User input month
    int day;   // User input day
    int year;  // User input year
    int f;     // resulting day of the week
    int d;     // day of the month
    int m;     // month number (see Zeller's Rule)
    int D;     // decade; last 2 digits of the modified year
    int C;     // century; first 2 digits of the modified year 
    int adjustedMonth;  //month adjusted for Zeller Rule
    int adjustedYear;   //year adjusted for Zeller Rule
    string resultingDay;   //day of the week User was born on
    
    cout << "Welcome ! \n"
    << "Just tell me your birth date, and I will tell which day of the week you were born. \n"
    << "Lets get started ...\n\n"
    << "Please tell me your birth date, in the form of: month day year\n";
    
    // accpet input from User setting variables for month, day & year
    cin >> month >> day >> year;
    
    // verify dates are in possible ranges && NOT negative
    // i.e. "month" between 1 && 12; "day" between 1 && 31; Year non-negative && below 2016
    
    
    //if ((CheckMonthValidity == false) || (CheckDayValidity == false) || (CheckYearValidity == false))
    if((month < 1) || (month>12) || (day<1) || (day>31) || (year<0) || (year>2016))
        {
            cout << "Your input is not correct.\n";
            cout << "The computation is not carried out.\n\n";
        }
    else
        {
        // fix "month" to Zeller Rule (Jan=11, Feb=12,Mar=1...)
        adjustedMonth = CorrectMonth(month);
        // use adjustedMonth to determine if year needs adjustment as well.
        adjustedYear = CorrectYear(year, adjustedMonth);
       
        D = adjustedYear % 100;
        //cout << "D is " << D << endl;
        
        C = adjustedYear / 100;
        //cout << "C is " << C << endl << endl;
        
        // Zeller's Algorithm          
        f = day + ((13*adjustedMonth-1)/5) + D + (D/4) + (C/4) - (2*C);

        if (f%7 == 0)
            {
                resultingDay = "Sunday";
            }
        else if (f%7 == 1)
            {
                resultingDay = "Monday";
            }
        else if (f%7 == 2)
            {
                resultingDay = "Tuesday";
            }
        else if (f%7 == 3)
            {
                resultingDay = "Wednesday";
            }
        else if (f%7 == 4)
            {
                resultingDay = "Thursday";
            }
        else if (f%7 == 5)
            {
                resultingDay = "Friday";
            }
        else if (f%7 == 6)
            {
                resultingDay = "Saturday";
            }
        
        cout << "You were born on " << resultingDay << ".\n";
    }
    
    return 0;
}

int CorrectMonth(int month)
{
    if(month > 2)
        {
            month -= 2;
        }
    else if(month == 1)
        {
            month = 11;
        }
    else if(month == 2)
        {
            month = 12;
        }
    return month;

}

int CorrectYear(int year, int adjustedMonth)
{
    if (adjustedMonth > 10)
        {
            year = year-1;
        }
    return year;
    
}
