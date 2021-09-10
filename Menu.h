#ifndef MENU_H
#define MENU_H
#include "DataControl.h"
#include <string>
#include <vector>
#include <limits>
#include <stdexcept>
#include "Calculation.h"

using namespace std;
/**
*@brief Menu.h - Menu class contains all the menu functions that the main program will need to perform the required calculations on the sensor data
*@author Manveer
*/
class Menu
{
public:

    Menu();
    /**
    *@brief a function that has a while loop and switch case of choice will loop until user desired to exit
    *@return void
    */
    void menuLoop();

private:

///Datacontrol object
    DataControl DC;

    /**
    *@brief function to perform the first menu.Caluclate average speed
    *and sample dev of a specified month and year in km/h
    *@param DC (DataControl&)
    *@return void
    */

    void menuOne(DataControl& DC);

    /**
    *@brief function to perform the second menu.Caluclate average ambient temperature
    *and sample dev for each month of a specified year
    *@param DC (DataControl&)
    *@return void
    */

    void menuTwo(DataControl& DC);
    /**
    *@brief function to perform the third menu.Caluclate total solar radiation
    *for each month of a specified year in kWh/m^2
    *@param DC (DataControl&)
    *@return void
    */

    void menuThree(DataControl& DC);

    /**
    *@brief function to perform the fourth menu.Caluclate average speed
    *and sample dev in km/h, average ambient temperature
    *and sample dev and total solar radiation in kWh/m^2
    *for each month of a specified year  and load the results into a WindTempSolar.csv file
    *@param DC (DataControl&)
    *@return void
    */
    void menuFour(DataControl& DC);


    /**
    *@brief a fucntion to display the month  name
    *@param x (int)-month
    *@return void
    */

    string printMonth(int x);

    /**
    *@brief a function to convert the solar radiation into kWh/m^2
    *@param sr(float)
    *@return float
    */

    float convertSolarRad(float sr);
    /**
    *@brief a fucntion to round the value to 1 decimal place
    *@param num (float)
    *@return float
    */

    float roundToOneDecimal(float num);
    /**
    *@brief a function to convert speed to km/h
    *@param s (float)
    *@return float
    */

    float convertWSpeed(float s);

    /**
    *@brief a function to check if the day entered by user is within the valid range
    *@param day (int)
    *@return int
    */
    int checkDayValidity(int day);
    /**
    *@brief a function to check if the month is within the valid range
    *@param month (int)
    *@return int
    */
    int checkMonthValidity(int month);
    /**
    *@brief a fucntion to check if year enter is within a given range
    *@param year-int
    *@return int
    */

    int checkYearValidity(int year);
    /**
    *@brief a function to display the menu
    *@return void
    */

    void DisplayMenu();
    /**
    *@brief a function to check if choice is within the valid range(1-5)
    *@param c (int)
    *@return bool
    */
    bool isChoiceValid(int c);

};

#endif // MENU_H
