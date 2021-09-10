#ifndef TIME_H
#define TIME_H
#include <string>
#include <cstring>

using namespace std;
/**
*@brief Time.h - Time class that will set the date
*@author Manveer
*/

class Time
{
public:

    /**
    *@brief Default constructor
    */
    Time();


    /**
    *@brief constant getter function to get hours of the record
    *@return integer
    */
    int getHours()const;
    /**
    *@brief constant getter function to get minutes of the record
    *@return integer
    */
    int getMin()const;

    /**
    *@brief function to  set the hours
    *@param h
    *@return void
    */
    void setHours(int h);
    /**
    *@brief function to  set the minutes
    *@param m
    *@return void
    */
    void setMin(int m);

    /**
    *@brief function to  set the time
    *@param h
    *@param m
    *@return void
    */
    void setTime(int h,int m);

    /**
    *@brief function to print the time
    *@param t -time object
    *@return string -time
    */
    string tostring(Time T);


private:
    ///hours of the time
    int hours;
    ///minutes of the time
    int minutes;
    ///time of the record
    string time;
};
#endif // TIME_H
