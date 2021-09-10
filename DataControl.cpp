#include "DataControl.h"



DataControl::DataControl()
{
    //ctor
}

void DataControl::readFile(string filename)
{

    ifstream infile; //ifstream to open main file that contain the filename

    ifstream tempfile;//ifstream to open each file in the txt file

    string file;//hold the filename in the textfile

    infile.open(filename);
    if(!infile)
    {
        cout<<"unable to find file"<<endl;
        exit(1);
    }
    else
    {
        while(infile>>file)
        {
            //for user to know what file is loaded
            cout<<"Loading file:"<<file<<endl;

            file="data/"+file;
            tempfile.open(file);
            if(!tempfile)
            {
                cout<<"unable to find file"<<file<<endl;
                continue;
            }
            //pass to loadfile function where data of each folder will be loaded into the structure
            loadFile(tempfile);

            tempfile.close();

        }
    }

    infile.close();

}


void DataControl::loadFile(ifstream& infile)
{
    //d-day m-month y-year h-hours mi-minute s-speed r-radiation t-temperature temp-temporary
    string d,m,y,h,mi,s,r,t,temp;


    int dd,yrs,mm;
    int hrs,mins;
    string line;
    Records tempR;// temporary record object

    getline(infile,temp); //avoid header of file
    while(infile.good())
    {
        getline(infile,d,'/');
        istringstream(d)>>dd;//convert string d to int day

        getline(infile,m,'/');
        istringstream(m)>>mm;//convert string m to int month
        getline(infile,y,' ');

        istringstream(y)>>yrs;//int years
        getline(infile,h,':');
        istringstream(h)>>hrs;//int hrs
        getline(infile,mi,',');

        istringstream(mi)>>mins;//int min

        getline(infile,temp,',');

        getline(infile,temp,',');

        getline(infile,temp,',');

        getline(infile,temp,',');

        getline(infile,temp,',');

        getline(infile,temp,',');

        getline(infile,temp,',');
        getline(infile,temp,',');
        getline(infile,temp,',');
        getline(infile,s,',');//speed
        getline(infile,r,',');//solar radiation
        getline(infile,temp,',');
        getline(infile,temp,',');
        getline(infile,temp,',');


        getline(infile,temp,',');


        getline(infile,temp,',');

        getline(infile,t,'\n');//temperature

        //skip line that has to data
        if(s=="N/A"|| t=="N/A" ||r=="N/A")
        {
            continue;
        }


        //convert speed,solar rad and temp to float
        float speed=stof(s);
        float rad=stof(r);
        float temperature=stof(t);




        years.InsertNode(yrs); //load year into tree


        //create record key
        string Recordskey=genRecordkey(d,h,mi);

        //create map key
        long long mapkey=genMonthYearKey(mm,yrs);


        //set records info
        tempR.setInfo(speed,rad,temperature,dd,mm,yrs,hrs,mins,Recordskey);


        //load data into map and set
        RecordsMap[mapkey].insert(tempR);




    }

    /*for(auto const& pair : RecordsMap) { //this can be used to check if the correct data in being inserted
     		if(pair.first==12016){
     		for(auto const& elem : pair.second) {
     			cout << elem<<endl;
     		}
     		//cout<<pair.first<<endl;
     }
    }*/

//    years.InOrder(out); //can be used to check if  all the correct years are inserted into the tree
}



bool DataControl::getWindSpeed(int month,int year,vector<float>&speed)
{
    bool found=false;

    long long searchkey=genMonthYearKey(month,year);
//int count=0;
    for(auto const& pair : RecordsMap)
    {
        if(pair.first == searchkey) //if the mapkey match the key for the specificed month and year entered by the user
        {
            found=true;
            for(auto const& elem : pair.second)
            {

                //cout<<elem.getDate().getDay()<<"/"<<elem.getDate().getMonth()<<"/"<<elem.getDate().getYear()<<" "<<elem.getTime().getHours()<<":"<<elem.getTime().getMin()<<","<<elem.getWeather().getSpeed()<<endl;
                speed.push_back(elem.getWeather().getSpeed()); //load data into the dynamic array speed
                //count++;
            }

        }

    }
    //cout<<count<<endl;
    return found;
}


bool DataControl::getAmbTemp(int month,int year,vector<float>&temp)
{
    bool found=false;


    long long searchkey=genMonthYearKey(month,year);
//int count=0;
    for(auto const& pair : RecordsMap)
    {
        if(pair.first == searchkey)
        {
            found=true;
            for(auto const& elem : pair.second)
            {
                // count++;
                //cout<<elem.getWeather().getTemp()<<endl;
                //cout<<elem.getDate().getDay()<<"/"<<elem.getDate().getMonth()<<"/"<<elem.getDate().getYear()<<" "<<elem.getTime().getHours()<<":"<<elem.getTime().getMin()<<","<<elem.getWeather().getTemp()<<endl;
                temp.push_back(elem.getWeather().getTemp());

            }

        }

    }
//cout<<count<<endl;
    return found;

}


bool DataControl::getSolarRad(int month,int year,vector<float>&sr)
{
    bool found=false;
    long long searchkey=genMonthYearKey(month,year);

    for(auto const& pair : RecordsMap)
    {
        if(pair.first == searchkey)
        {
            found=true;
            for(auto const& elem : pair.second)
            {
                if(elem.getWeather().getRad()>=100)
                {
                    //cout<<elem.getWeather().getRad()<<endl;
                    sr.push_back(elem.getWeather().getRad());
                }
            }

        }

    }

    return found;

}




void DataControl::out(int& y)
{
    cout<<y<<endl;
}


long long DataControl::genMonthYearKey(int month,int year)
{
    long long mapKey=((month*10000)+year);//example:(3*10000)+2017=32017
    return mapKey;
}


string DataControl::genRecordkey(string day,string hr,string mins)
{
    string setKey;
    setKey=hr+mins+day;//example day=1 hour=9 mins=00 key=9001
    return setKey;
}

bool DataControl::checkYear(int year)
{
    return (years.SearchNode(year)); //return true if found else false
}


