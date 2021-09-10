#ifndef RECORDS_H
#define RECORDS_H
#include<iostream>
#include <string>
#include <cstring>
#include "Date.h"
#include "Time.h"
#include "Weather.h"

/**
*@brief Records.h - Records class that will keep of the entries
*@author Manveer
*/

class Records
{
public:
///default constructor
    Records();
    /**fuction to set all the required info for each records
    *@param s - wind speed
    *@param r -solar radiation
    *@param t -ambient temperature
    *@param day -day  data was recorded
    *@param mon -month data recorded
    *@param year -year  data recorded
    *@param hours -hour section of the time data was recorded
    *@param minutes -minutes section of the time the data was records
    *@param key -string key of the record to avoid duplicates and ordering
    *@return void
    */
    void setInfo(float s,float r,float t,int day,int mon,int year,int hours,int minutes,string key);


    /**a reference to date object (used to access non const method of date)
    *@return date
    */
    Date &getDate();
    /**a reference to date object (used to access const method of date)
      *@return date
      */
    Date const &getDate()const;
    /**a reference to time object (used to access const method of time)
      *@return T
      */
    Time const &getTime()const;
    /**a reference to time object (used to access non const method of time)
     *@return T
     */
    Time &getTime();
    /**a reference to weather object (used to non const method of weather )
       *@return w
       */
    Weather &getWeather();
    /**a reference to weather object (used to access const method of weather)
      *@return w
      */
    Weather const&getWeather()const;
    /**
    *@brief function to get key of the records which will be used for ordering and avoid duplicates
    *@return int
    */
    string getKey()const;

    /**
    *@brief function to set the key of the record
    *@param k (int)
    @return void
    */
    void setKey(string k);

    /**
    *@brief less than operator overloading which will be use for ordering,it will compare the key
    *@param otherRecords (const&)
    *@return bool
    */
    bool operator<(const Records&otherRecords)const;


    /**
    *@brief a friend function useful for debugging but not a very good thing
    *@param os (ostream&)
    *@param r (const Records&)
    *@return ostream
    */
    friend ostream& operator<<(ostream& os, const Records&r);






private:
    ///date object
    Date date;
    ///time object
    Time T;
    ///weather object
    Weather w;
    ///key of the record
    string key;

};


inline ostream& operator<<(ostream& os, const Records&r)
{

    os<<r.getDate().getDay()<<"/"<<r.getDate().getMonth()<<"/"<<r.getDate().getYear()<<","<<r.getTime().getHours()<<":"<<r.getTime().getMin()<<"("<<r.key<<")"<<","<<r.getWeather().getSpeed();

    return os;
}
#endif // RECORDS_H
