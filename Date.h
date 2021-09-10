#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

/**
*@brief Date.h - Date class that will set the date
*@author Manveer
*/
class Date
{
public:

    /**
    *@brief Default constructor
    *@return void
    */
    Date();

    /**
    *@brief constant function to get day of the unit
    *@return integer
    */
    int getDay()const;

    /**
    *@brief a constant function to get month of the unit
    *@return string
    */
    int getMonth()const;

    /**
    *@brief a function to get year of the unit
    *@return integer
    */
    int getYear()const;


    /**
    *@brief function to  set the day
    *@param d
    *@return void
    */
    void setDay(int d);
    /**
    *@brief function to  set the month
    *@param m
    *@return void
    */
    void setMonth(int m);
    /**
    *@brief function to  set the year
    *@param y
    *@return void
    */
    void setYear(int y);

    /**
    *@brief function to set set the date
    *@param d
    *@param mon
    *@param y
    *@return void
    */
    void setDate(int d,int mon,int y);


    /**
    *@brief a constant function to print the date as string
    *@param d -date object
    *@return string
    */
    string toString(Date d);




private:
    ///day of the date
    int day;
    ///year of the date
    int year;
    ///month of the date
    int month;
    ///date of the record
    string date;
};



#endif // DATE_H

