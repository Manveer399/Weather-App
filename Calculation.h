#ifndef CALCULATION_H
#define CALCULATION_H
#include <iostream>
#include<cmath>
#include <vector>
using namespace std;

/**
*@brief Calculation.h - template class for common calculations
*@author Manveer
*/


template <class C>
class Calculation
{


public:
    static C average(vector<C>&v);
    static C standarddeviation(vector<C>&v);


};




template <class C>

/**
*@brief template to calculate average
*@param Vector object
*@return average
*/
C Calculation<C>::average(vector<C>&v)
{
    C total=0.0;
    C average=0.0;
    for(int i=0; i<v.size(); i++)
    {
        total+=v.at(i);
    }
    average=total/(v.size());
    return average;
}


/**
*@brief a template to calculate standard deviation
*@param vector object
*@return standardev
*/

template <class C>
C Calculation<C>::standarddeviation(vector<C>&v)
{
    C variance=0.0;
    C standardev=0.0;
    C mean=average(v);
    for(int i=0; i<v.size(); i++)
    {
        variance+=pow((v[i])-mean,2);
    }
    variance=variance/v.size();
    standardev=sqrt(variance);
    return standardev;
}
#endif
