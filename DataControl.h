#ifndef DATACONTROL_H
#define DATACONTROL_H
#include <iostream>
#include <vector>//stl vector
#include <set>//stl set
#include<map>//stl map
#include "Records.h" //recorder header
#include "BST.h" //BST header
#include <sstream> //std stringstream
#include <fstream> //filestream
#include <string>

using namespace std;
/**
*@brief DataControl.h - DataControl class contains all the functions return the requested data for calculations using the sensor data
*@author Manveer
*/

class DataControl
{
public:
    /**
    *@brief default constructor
    */
    DataControl();

    /**
    *@brief a fucntion to load the data in the file into the structure BST years and map
    *@param infile (ifstream&)
    *@return void
    */
    void loadFile(ifstream& infile);

    /**
    *@brief a function to read the metdataindex txt file and read the each filename and pass it to the loadfile function
    *@param filename (string)
    *@return void
    */
    void readFile(string filename);

    /**
    *@brief a function to generate a key using a month and a year that will be used as key for the map.
    *month is multiplied by 10000 plus the year
    *@param month(int)
    *@param year(int)
    *@return long long
    */
    long long genMonthYearKey(int month,int year);

    /**
    *@brief a function to generate a key using day of a date,minute and hours of time which will be used for ordering the set inside map
    *this will avoid duplication of data
    *@param day (string)
    *@param hr (string)
    *@param mins (string)
    *@return string
    */
    string genRecordkey(string day,string hr,string mins);

    /**
    *@brief a static function used for callback to display the data inside the BST year tree in order
    *@param y (int)
    *@return void
    */

    static void out(int& y);


    /**
    *@brief a function to that will get the windspeed for a given month of a given year from the map.
    *function will return true if data was found else false
    *@param month (int)
    *@param year (int)
    *@param speed (vector<float>&)
    *@return bool
    */
    bool getWindSpeed(int month,int year,vector<float>&speed);

    /**
    *@brief a function to that will get the ambient temperature for a given month of a given year from the map.
    *function will return true if data was found else false
    *@param month (int)
    *@param year (int)
    *@param temp (vector<float>&)
    *@return bool
    */
    bool getAmbTemp(int month,int year,vector<float>&temp);

    /**
    *@brief a function to that will get the windspeed for a given month of a given year from the map.
    *function will return true if data was found else false
    *@param month (int)
    *@param year (int)
    *@param speed (vector<float>&)
    *@return bool
    */
    bool getSolarRad(int month,int year,vector<float>&sr);

    /**
    *@brief a function to check whether a specific year exists in the strucutre.
    *if years does not exist function return false else true
    *@param year (int)
    @return bool
    */
    bool checkYear(int year);







private:
    /// BST store all the years available
    BST<int>years;
    ///a map of sets that have Records for each day of a month of a year
    map<long long,set<Records>>RecordsMap;


};

#endif // DATACONTROL_H
