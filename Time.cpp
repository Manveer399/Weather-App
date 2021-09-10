#include <iostream>
#include "Time.h"


Time::Time()
{
    hours=0;
    minutes=0;

}
int Time::getHours()const
{
    return hours;
}
int Time:: getMin()const
{
    return minutes;
}
void Time:: setHours(int h)
{
    hours=h;

}
void Time:: setMin(int m)
{
    minutes=m;
}

void Time:: setTime(int h,int m)
{
    hours=h;
    minutes=m;
}

string Time::tostring(Time T)
{

    time=to_string(T.getHours());
    time=time+":"+to_string(T.getMin());
    return time;
}

