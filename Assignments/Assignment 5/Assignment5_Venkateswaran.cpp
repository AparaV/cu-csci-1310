/*Assignment 5 CSCI 1310 REC 101
 *Aparajithan Venkateswaran
 *TA: Camilla Lambrocco
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//Forecast Class
class Forecast{
public:
    string day;
    string forecastDay;
    int highTemp;
    int lowTemp;
    int humidity;
    int avgWind;
    string avgWindDir;
    int maxWind;
    string maxWindDir;
    double precip;

    //default constructor
    Forecast(){
        day = "NULL";
        forecastDay = "NULL";
        highTemp = -9999;
        lowTemp = -9999;
        humidity = -9999;
        avgWind = -9999;
        avgWindDir = "NULL";
        maxWind = -9999;
        maxWindDir = "NULL";
        precip = -9999;
    }
};

//Date Class
class Date{
public:
    int dd;
    int mm;
    int yy;
    //constructors
    Date(){};//default
    Date(int mm, int dd, int yy){
        this->dd = dd;
        this->mm = mm;
        this->yy = yy;
    }

    //Define incrementing
    Date& operator ++(){
        if(dd == 30){
            //if the month has only 30 days, set day to 1 and increment month
            if(mm == 4 || mm == 6 || mm == 9 || mm == 11){
                dd = 1;
                mm++;
            }
            //else increment date
            else{
                dd++;
            }
        }
        else if(dd == 31){
            dd = 1;//a month can have only 31 days at most
            if (mm != 12){
                mm++;//not december
            }
            else{
                mm = 1;//set month to 1 if december
                yy++;//increment year
            }
        }
        //we are dealing only with 2016 (leap year) so feb has 29 days
        else if(dd == 29 && mm == 2){
            mm++;
            dd = 1;
        }
        //every other case
        else{
            dd++;
        }

        return *this;
    }

    //Define decrementing
    Date& operator --(){
        //if date is 1
        if(dd == 1){
            if(mm != 1){
                mm--;//decrease month
                if(mm == 4 || mm == 6 || mm == 9 || mm == 11){
                    dd = 30;//these months have only 30 days
                }
                else if(mm = 2){
                    dd = 29;//feb has 29 days (2016 is a leap year)
                }
                else{
                    dd = 31;//other months that have 31 days
                }
            }
            else{//month is january. so we  need to set month to 12, day to 31 and decrement year
                mm = 12;
                dd = 31;
                yy--;
            }
        }
        else{//all other cases
            dd--;
        }
        return *this;
    }
    //Display Date
    void display(){
        cout << mm << "-" << dd << "-" << yy << endl;
    }

};

/*Function Prototypes*/
int countLines(string fileName);//count number of lines in file
void readFile(string fileName, Forecast data[]);//read data from file into array
int extractTemp(string stemp);//extract the temperature from the string in file (the string format is specific)
Date extractDate(string date);//extract date from the string
string dateToString(Date day);//converts Date into a string
bool operator== (Date day1, Date day2);//== operator for Date class

/*Functions for assessment*/
string lastDayItRained(Forecast forecastData[]);//returns the last day it rained
double totalRainfall(Forecast data[]);//returns the total rainfall
int maxWindSpeed(Forecast data[]);//returns the index of maximum wind speed
int maxRainfall(Forecast data[]);//returns the index of maximum rainfall
int maxTempDifference(Forecast data[]);//returns the index of maximum temperature difference
Forecast forecastForDay(Forecast data[], string day);//returns the forecast for the day
string worstTempPrediction(Forecast data[]);//returns the day with worst three-day temperature prediction
vector<string> missingDataPoints(Forecast data[]);//returns the missing data points in file


const int DAYS = countLines("boulderData");//determine array size

/*Main Function Begins*/
int main(){

    Forecast forecastData[DAYS];//declare the array of classes

    readFile("boulderData", forecastData);//initialize the array

    //Output
    cout << "Last Day It Rained: " << lastDayItRained(forecastData) << endl;//output last day it rained

    cout << "Total Rainfall: " << totalRainfall(forecastData) << endl;//output total rainfall

    int dayOfMaxWind = maxWindSpeed(forecastData);//index of day with max wind speed

    cout << "Maximum Wind Speed: " << forecastData[dayOfMaxWind].maxWind << " mph on " << forecastData[dayOfMaxWind].day << endl;//output max wind speed

    int dayOfMaxRain = maxRainfall(forecastData);//index of day with max rainfall

    cout << "Maximum Rainfall: " << forecastData[dayOfMaxRain].precip << " inches on " << forecastData[dayOfMaxRain].day << endl;//output max rainfall

    int maxTempDiff = maxTempDifference(forecastData);//index of day with max temperature difference

    cout << "Maximum Temperature Difference: " << forecastData[maxTempDiff].highTemp - forecastData[maxTempDiff].lowTemp;//output max temp diff
    cout << " F on " << forecastData[maxTempDiff].day << endl;//output max temp diff

    string day;

    cout << "Enter a date: ";
    getline(cin, day);//get the date to search from user

    Forecast dayForecast =forecastForDay(forecastData, day);
    //check whether the date is found.. default constructor initializes forecast to null values
    if(dayForecast.day == "NULL"){
        cout << "Date not found" << endl;
    }
    else{//output the forecast
        cout << "Forecast for " << dayForecast.day << endl;
        cout << "H: " << dayForecast.highTemp << " F" << endl;
        cout << "L: " << dayForecast.lowTemp << " F" << endl;
        cout << "Humidity: " << dayForecast.humidity << endl;
        cout << "Avg. wind speed: " << dayForecast.avgWind << endl;
        cout << "Avg. wind direction: " << dayForecast.avgWindDir << endl;
        cout << "Max. wind speed: " << dayForecast.maxWind << endl;
        cout << "Max. wind direction: " << dayForecast.maxWindDir << endl;
        cout << "Precipitation: " << dayForecast.precip << endl;
    }

    cout << "=============" << endl;

    /*Challenge Problems*/
    cout << "\nChallenge Problems" << endl << endl;

    cout << "Worst three-day prediction was for the date: " << worstTempPrediction(forecastData) << endl;//output worst prediction

    cout << "\nMissing Data Points:" << endl;
    vector<string> missing = missingDataPoints(forecastData);

    for(int i = 0; i < missing.size(); ++i){//output all missing data points
        cout << missing[i] << endl;
    }

    return 0;
}
/*Main Function Ends*/

/*Count the number of lines in file*/
int countLines(string fileName){
    int numberOfLines = 0;

    ifstream inFile;
    inFile.open(fileName);
    //error check
    if(inFile.fail()){
        cout << "ERROR: Could not open file" << endl;
        return -1;
    }

    string line;
    //count lines in file
    while(getline(inFile, line, '\n')){
        ++numberOfLines;
    }

    return numberOfLines;
}

/*Read Data from File into Class*/
void readFile(string fileName, Forecast data[]){

    ifstream inFile;
    inFile.open(fileName);
    //error check
    if(inFile.fail()){
        cout << "ERROR: Could not open file" << endl;
        return;
    }

    string line;
    int arrayIndex = 0;//index for keeping track of array of classes index
    int memberIndex = 0;//index for keeping track of which class member to update

    while(getline(inFile, line, '\n')){
        stringstream ss;
        ss << line;

        while(getline(ss, line, ',')){
            //Today
            if(memberIndex == 0){
                data[arrayIndex].day = line;
                ++memberIndex;
            }

            //Forecast Day
            else if(memberIndex == 1){
                data[arrayIndex].forecastDay = line;
                ++memberIndex;
            }

            //High Temp
            else if(memberIndex == 2){
                data[arrayIndex].highTemp = extractTemp(line);
                ++memberIndex;
            }

            //Low Temp
            else if(memberIndex == 3){
                data[arrayIndex].lowTemp = extractTemp(line);
                ++memberIndex;
            }

            //Humidity
            else if(memberIndex == 4){
                data[arrayIndex].humidity = stoi(line);
                ++memberIndex;
            }

            //Avg Wind
            else if(memberIndex == 5){
                data[arrayIndex].avgWind = stoi(line);
                ++memberIndex;
            }

            //Avg Wind Dir
            else if(memberIndex == 6){
                data[arrayIndex].avgWindDir = line;
                ++memberIndex;
            }

            //Max Wind
            else if(memberIndex == 7){
                data[arrayIndex].maxWind = stoi(line);
                ++memberIndex;
            }

            //Max Wind Dir
            else if(memberIndex == 8){
                data[arrayIndex].maxWindDir = line;
                ++memberIndex;
            }

            //Precip
            else if(memberIndex == 9){
                data[arrayIndex].precip = stof(line);
                memberIndex = 0;//reset memberIndex to 0 for next iteration

            }
        }

        ++arrayIndex;//increment arrayIndex for next iteration
    }

}

/*Extract the temperature from the string*/
int extractTemp(string stemp){
    return (stemp[2] - '0')*10 + (stemp[3] - '0');//in the given format, 2nd and 3rd element of temp string contain the digits of temp
}

/*Last Day It Rained*/
string lastDayItRained(Forecast data[]){
    //loop from end of array
    for(int i = DAYS; i >= 0; --i){
        //match today and forecast day; check precipitation > 0
        if(data[i].day == data[i].forecastDay && data[i].precip > 0){
                return data[i].day;
        }
    }

    return "NO RAINY DAY FOUND";//if it has never rained
}

/*Total Rainfall*/
double totalRainfall(Forecast data[]){
    double sum = 0;

    for(int i = 0; i < DAYS; ++i){
        //match today and forecast day; sum precipitation
        if(data[i].day == data[i].forecastDay){
            sum += data[i].precip;
        }
    }

    return sum;
}

/*Max Wind Speed*/
int maxWindSpeed(Forecast data[]){
    int maxSpeed;
    int index;

    for(int i = 0; i < DAYS; ++i){
        //match today and forecast day
        if(data[i].day == data[i].forecastDay){
            //initialize maxSpeed and index; update them when necessary
            if(i == 0 || data[i].maxWind > maxSpeed){
                maxSpeed = data[i].maxWind;
                index = i;
            }
        }
    }

    return index;
}

/*Max Rainfall*/
int maxRainfall(Forecast data[]){
    double rainfall;
    int index;

    for(int i = 0; i < DAYS; ++i){
        //match today and forecast day
        if(data[i].day == data[i].forecastDay){
            //initialize rainfall and index; update them when necessary
            if(i == 0 || data[i].precip > rainfall){
                rainfall = data[i].precip;
                index = i;
            }
        }
    }

    return index;
}

/*Maximum Temperature Difference*/
int maxTempDifference(Forecast data[]){
    int index;
    int tempDiff;

    for(int i = 0; i < DAYS; ++i){
        //match today and forecast day
        if(data[i].day == data[i].forecastDay){
            //initialize tempDiff and index; update when necessary
            if(i == 0 || (data[i].highTemp - data[i].lowTemp) > tempDiff){
                tempDiff = data[i].highTemp - data[i].lowTemp;
                index = i;
            }
        }
    }

    return index;
}

/*Forecast for the Day*/
Forecast forecastForDay(Forecast data[], string day){

    for(int i = 0; i < DAYS; ++i){
        //match today with argument; match today and forecast day
        if(data[i].day == day && data[i].forecastDay == day){
            return data[i];
        }
    }
    //if the argument day is not found, return an empty(null) forecast
    Forecast newForecast;
    return newForecast;
}

/*Extract Date from String*/
Date extractDate(string date){
    //user should preserve type safety
    stringstream ss;
    ss << date;//pass the string into a stream
    Date newDate;
    int index = 1;

    //split it with delimiter '-'
    while(getline(ss, date, '-')){
        //first part is the month
        if(index == 1){
            stringstream ss2;
            ss2 << date;
            ss2 >> newDate.mm;
            ++index;
        }
        //second part is the day
        else if(index == 2){
            stringstream ss2;
            ss2 << date;
            ss2 >> newDate.dd;
            ++index;
        }
        //last part is the year
        else if(index == 3){
            stringstream ss2;
            ss2 << date;
            ss2 >> newDate.yy;
        }
    }

    return newDate;
}

/*Convert Date into String*/
string dateToString(Date day){

    string str = to_string(day.mm);//create a new string starting with month
    str.append("-");//append '-'
    str.append(to_string(day.dd));//append the day
    str.append("-");//append '-'
    str.append(to_string(day.yy));//append the year

    return str;
}

/*Worst three-day temperature prediction*/
string worstTempPrediction(Forecast data[]){

    int tempDiff = 0;
    string the_answer;

    for(int i = 0; i < DAYS; ++i){
        //skip if the forecast day and today are the same
        if(data[i].day == data[i].forecastDay){
            continue;
        }

        Date day3 = extractDate(data[i].forecastDay);//get forecast day
        Date day1 = extractDate(data[i].day);//get today
        //increase day1 3 times
        ++day1;
        ++day1;
        ++day1;
        //check if it is a three day forecast
        if(day3 == day1){
            int temp1 = data[i].highTemp;//three day highTemp prediction
            //find the actual forecast for day3
            Forecast future = forecastForDay(data, dateToString(day3));
            //check if forecast data point exists
            if(future.highTemp > 0){
                int currDiff = future.highTemp - temp1;//calculate tempDiff for prediction and actual
                if(currDiff < 0){
                    currDiff = -1 * currDiff;//make the difference positive
                }
                if(currDiff > tempDiff){
                    tempDiff = currDiff;//update maximum tempDiff
                    the_answer = future.day;//update the day whose prediction was the worst three days earlier
                }
            }
        }
    }

    cout << "The worst temperature difference in forecast is " << tempDiff << " F" << endl;
    return the_answer;
}

/*Missing Data Points*/
vector<string> missingDataPoints(Forecast data[]){
    string finish = data[DAYS - 1].day;//last date in the file
    Date current = extractDate(data[0].day);//first date in the file
    string curr = data[0].day;//string to store a temporary date;

    vector<string> missing;//a vector to store all missing data points

    while(curr != finish){
        ++current;//increment date
        curr = dateToString(current);//convert it to string
        Forecast isThere = forecastForDay(data, dateToString(current));//search for that date
        if(isThere.day == "NULL"){//add that if not present
            missing.push_back(curr);
        }
    }

    return missing;
}

/*== Operator for Date class*/
bool operator== (Date day1, Date day2){
    if(day1.dd != day2.dd){//days are not the same
        return false;
    }
    if(day1.mm != day2.mm){//months are not the same
        return false;
    }
    if(day1.yy != day2.yy){//years are not the same
        return false;
    }
    return true;
}
