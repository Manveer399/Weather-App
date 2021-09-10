#include "Weather.h"


using namespace std;


Weather::Weather()
{
    speed=0.0;
    radia=0.0;
    temp=0.0;

}

float Weather::getSpeed()const
{
    return speed;
}

float Weather::getRad()const
{
    return radia;
}

float Weather::getTemp()const
{
    return temp;
}

void Weather::setSpeed(float s)
{
    speed=s;
}

void Weather:: setRad(float r)
{
    radia=r;
}

void Weather:: setTemp(float t)
{
    temp=t;
}

void Weather::setWeather(float s,float r,float t)
{
    speed=s;
    radia=r;
    temp=t;
}
