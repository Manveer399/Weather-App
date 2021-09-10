#ifndef WEATHER_H
#define WEATHER_H
#include<iostream>
/**
*@brief Weather.h - Weather class that will be use to keep track of the sensor data
*@author Manveer
*/
class Weather
{
public:

    /**
    *@brief Default constructor
    *@return void
    */
    Weather();

    /**
    *@brief constant function to get the wind speed
    *@return float
    */
    float getSpeed()const;
    /**
    *@brief constant function to get the solar radiation
    *@return float
    */
    float getRad()const;
    /**
    *@brief constant function to get ambient temperature
    *@return float
    */
    float getTemp()const;
    /**
    *@brief function to  set the wind speed
    *@param s
    *@return void
    */
    void setSpeed(float s);
    /**
    *@brief function to  set the solar radiation
    *@param r
    *@return void
    */
    void setRad(float r);
    /**
    *@brief function to  set ambient temperature
    *@param t
    *@return void
    */
    void setTemp(float t);

    /**
    *@brief function to set set the weather sensor data
    *@param s -speed
    *@param r -radiation
    *@param t -temperature
    *@return void
    */
    void setWeather(float s,float r,float t);



private:
    ///wind speed
    float speed;
    ///solar radiation
    float radia;
    ///ambient temperature
    float temp;
};

#endif // WEATHER_H
