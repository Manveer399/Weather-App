#include "Date.h"
#include <cstring>
Date::Date()
{
    day=0;
    month=0;
    year=0;
}


int Date::getDay()const
{
    return day;
}
int Date::getMonth()const
{
    return month;
}
int Date::getYear()const
{
    return year;
}

void Date::setDay(int d)
{
    day=d;
}
void Date::setMonth(int m)
{
    month=m;
}
void Date::setYear(int y)
{
    year=y;
}
void Date::setDate(int d,int mon,int y)
{
    day=d;
    month=mon;
    year=y;

}


string Date::toString(Date d)
{
    date=to_string(d.getDay());
    date=date+"/"+to_string(d.getMonth());
    date=date+"/"+to_string(d.getYear());
    return date;
}



