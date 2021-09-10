#include "Records.h"

using namespace std;

Records::Records()
{

}


void Records::setInfo(float s,float r,float t,int day,int mon,int year,int hours,int minutes,string key)
{
    w.setWeather(s,r,t);
    date.setDate(day,mon,year);
    T.setTime(hours,minutes);
    setKey(key);
}

Time & Records::getTime()
{
    return T;
}


Time const &Records::getTime()const
{
    return T;
}

Weather & Records::getWeather()
{
    return w;
}


Weather const &Records::getWeather()const
{
    return w;
}

Date &Records::getDate()
{
    return date;
}


Date const &Records::getDate()const
{
    return date;
}

string Records::getKey()const
{
    return key;
}

void Records::setKey(string k)
{
    key=k;
}

bool Records::operator <(const Records&otherRecords)const
{
    return this->key<otherRecords.key;
}
