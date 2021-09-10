#include "Menu.h"

Menu::Menu()
{
    //ctor
}

void Menu::menuLoop()
{

    DC.readFile("data/met_index.txt");
    while(1)
    {
        int choice;
        cin.exceptions(ios_base::failbit);
        try
        {
            DisplayMenu();
            cout<<"Enter your choice:"<<endl;
            cin>>choice;
            if(!isChoiceValid(choice))
            {
                throw out_of_range("Enter a value between 1-5");
            }
        }
        catch (const out_of_range &e)
        {
            cout << "\n " << e.what() <<endl;
            cout << "Please try again"<<endl;
        }
        catch (const ios_base::failure &)
        {
            cout  << "\n Please enter numbers only!" <<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }


        switch(choice)
        {

        case 1:
            menuOne(DC);
            break;
        case 2:
            menuTwo(DC);
            break;

        case 3:
            menuThree(DC);
            break;
        case 4:
            menuFour(DC);

            break;
        case 5:
            exit(1);

        }
    }


}

void Menu::menuOne(DataControl& DC)
{

    vector<float>tempspeed;

    string m,y;

    int month,year;

    string dates;
    cout<<"Please enter a month and a year (mm/yyyy):"<<endl;
    cin>>dates;
    stringstream ss(dates);

    getline(ss, m, '/');
    getline(ss, y);


    istringstream(m)>>month;

    istringstream(y)>>year;

    month=checkMonthValidity(month);

    year=checkYearValidity(year);

    if(DC.checkYear(year))
    {

        if(DC.getWindSpeed(month,year,tempspeed)==true)
        {
            float avgSpeed=Calculation<float>::average(tempspeed);

            float stdSpeed=Calculation<float>::standarddeviation(tempspeed);


            cout<<printMonth(month)<<" "<<year<<":"<<endl;

            //cout<<"Average Speed:"<<avgspeed<<endl;
            //cout<<"Sample stdev:"<<stdspeed<<endl;

            cout<<"Average Speed:"<<roundToOneDecimal(convertWSpeed(avgSpeed))<<"km/h"<<endl;

            cout<<"Sample dev:"<<roundToOneDecimal(convertWSpeed(stdSpeed))<<endl;

        }
        else
        {
            cout<<printMonth(month)<<" "<<year<<":"<<"No Data"<<endl;
        }

    }
    else
    {
        cout<<printMonth(month)<<" "<<year<<":"<<"No Data"<<endl;
    }
    tempspeed.clear();

}

void Menu::menuTwo(DataControl& DC)
{

    vector<float>temp;
    int year;
    cout<<"Enter year:";
    cin>>year;
    year=checkYearValidity(year);
    cout<<year<<endl;
    if(DC.checkYear(year))
    {
        for(int month=1; month<=12; month++)
        {

            if(DC.getAmbTemp(month,year,temp))
            {

                float avgTemp=Calculation<float>::average(temp);

                float stdTemp=Calculation<float>::standarddeviation(temp);

                avgTemp=roundToOneDecimal(avgTemp);

                stdTemp=roundToOneDecimal(stdTemp);
                cout<<printMonth(month)<<":"<<"Average temp:"<<avgTemp<<"degrees C"<<",";
                cout<<"Sample dev:"<<stdTemp<<endl;
            }


            else
            {
                cout<<printMonth(month)<<":"<<"No Data"<<endl;
            }
            //important to release memory
            temp.clear();

        }

    }
    else
    {
        for(int month=1; month<=12; month++)
        {
            cout<<printMonth(month)<<":"<<"No Data"<<endl;
        }
    }


}


void Menu::menuThree(DataControl& DC)
{

    vector<float>sr;
    int year;
    cout<<"Enter year:";
    cin>>year;
    year=checkYearValidity(year);

    cout<<year<<endl;
    if(DC.checkYear(year))
    {
        for(int month=1; month<=12; month++)
        {

            if(DC.getSolarRad(month,year,sr))
            {
                float total=0;
                for(int i=0; i<sr.size(); i++)
                {

                    total+=sr[i];
                }


                cout<<printMonth(month)<<":"<<roundToOneDecimal(convertSolarRad(total))<<"kWh/m^2"<<endl;



            }
            else
            {
                cout<<printMonth(month)<<":"<<"No Data"<<endl;
            }
            //important to release memory
            sr.clear();
        }
    }

    else
    {
        for(int month=1; month<=12; month++)
        {
            cout<<printMonth(month)<<":"<<"No Data"<<endl;
        }
    }

}


void Menu::menuFour(DataControl& DC)
{

    vector<float>S;
    vector<float>T;
    vector<float>SR;


    int year;
    cout<<"Enter year:";
    cin>>year;
    year=checkYearValidity(year);
    cout<<year<<endl;
    if(DC.checkYear(year))
    {
        ofstream outfile;
        outfile.open( "WindTempSolar.csv");
        for(int month=1; month<=12; month++)
        {
            float avgspeed=0;
            float stdspeed=0;
            float avgTemp=0;
            float stdTemp=0;
            float totalsr=0;
            outfile<<printMonth(month)<<",";
            if(DC.getWindSpeed(month,year,S))
            {

                avgspeed=Calculation<float>::average(S);
                stdspeed=Calculation<float>::standarddeviation(S);
                if(avgspeed>0)
                    outfile<<roundToOneDecimal(convertWSpeed(avgspeed))<<"("<<roundToOneDecimal(convertWSpeed(stdspeed))<<")"<<",";

                else
                {
                    outfile<<",";
                }

            }

            else
            {
                outfile<<",";
            }


            if(DC.getAmbTemp(month,year,T))
            {


                avgTemp=Calculation<float>::average(T);

                stdTemp=Calculation<float>::standarddeviation(T);
                if(avgTemp>0)
                    outfile<<roundToOneDecimal(avgTemp)<<"("<<roundToOneDecimal(stdTemp)<<")"<<",";
                else
                    outfile<<",";
            }
            else
            {
                outfile<<",";
            }


            if(DC.getSolarRad(month,year,SR))
            {

                for(int i=0; i<SR.size(); i++)
                {

                    totalsr+=SR[i];
                }
                if(totalsr>0)
                    outfile<<roundToOneDecimal(convertSolarRad(totalsr))<<endl;
                else
                    outfile<<endl;
            }
            else
            {
                outfile<<endl;
            }

            //important to deallocate memory
            S.clear();
            T.clear();
            SR.clear();


        }
    }
    else
    {
        cout<<"No data"<<endl;
    }

}



string Menu::printMonth(int x)
{
    switch(x)
    {

    case 1:
        return "January";
        break;
    case 2:
        return "February";
        break;
    case 3:
        return "March";
        break;
    case 4:
        return "April";
        break;
    case 5:
        return"May";
        break;
    case 6:
        return "June";
        break;
    case 7:
        return "July";
        break;
    case 8:
        return "August";
        break;
    case 9:
        return "September";
        break;
    case 10:
        return "October";
        break;
    case 11:
        return "November";
        break;
    case 12:
        return "December";
        break;
    default:
        return "This month does not exists please enter a months between 1 and 12";
    }
}


int Menu::checkYearValidity(int year)
{

    if(year>=1900 && year<=2021)
    {
        return year;
    }
    else
    {
        cout<<"Please enter a valid year between 1900-2021:"<<endl;
        cin>>year;
        return year;
    }

}

int Menu::checkMonthValidity(int month)
{
    if(month>=1 && month<=12)
    {
        return month;
    }
    else
    {
        cout<<"Please enter a valid month from 1 to 12:"<<endl;
        cin>>month;
        return month;
    }
}


int Menu::checkDayValidity(int day)
{
    if(day>=1 && day<=31)
    {
        return day;
    }
    else
    {
        cout<<"Please enter a valid month from 1 to 31:"<<endl;
        cin>>day;
        return day;
    }
}


float Menu::convertSolarRad(float sr)
{
    return (sr* (1.0/6.0)) / 1000;
}

float   Menu::roundToOneDecimal(float num)
{
    return round(num * 10)/10;
}

float Menu::convertWSpeed(float s)
{

    return (3.6 * s);
}


void Menu::DisplayMenu()
{
    cout<<"****** Make your choice ******"<<endl;
    cout<<"1.Calculate average wind speed and sample standard deviation for specified month and year.\n\n";
    cout<<"2.Calculate average ambient air temperature and standard deviation for each month of a specificed year.\n\n";
    cout<<"3.Calculate total solar radiation in(kWh/m^2) for each month of a specified year.\n\n";
    cout<<"4.Calculate avergae wind speed(km/h),average ambient air temperature and total solar radiation (kWh/m^2) for each month of a specified year.\n\n";
    cout<<"5.Quit."<<endl;
}

bool Menu::isChoiceValid(int c)
{
    return ((c >= 1) && (c <=6));
}
