/**Assignment 6 Challenge CSCI 1310 REC 101
  *Aparajithan Venkateswaran
  *TA: Camilla Lambrocco
  *main.cpp
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "WeatherForecasterChallenge.h"

using namespace std;

void readFile(string, WeatherForecaster*);//function to read file
int extractTemp(string);//extract temperature from the string

/*Main Function Begins*/
int main(){

    WeatherForecaster wf;
    readFile("boulderData", &wf);

    cout << "Forecast Statistics:\n" << endl;
    cout << "Last Day it Rained: ";
    wf.printLastDayItRained();//last day it rained
    cout << "Total Rainfall: " << wf.calculateTotalPrecipitation() << endl;//total precipitation
    cout << "First Day in Data: " << wf.getFirstDayInData() << endl;//first day in data
    cout << "Last Day in Data: " << wf.getLastDayInData() << endl;//last day in data
    cout << "\n===========================\n" << endl;

    //all days in data
    cout << "Days in Data:\n" << endl;
    wf.printDaysInData();
    cout << "\n===========================\n" << endl;

    string date;
    cout << "Enter a date: ";
    getline(cin, date);

    //forecast for the day
    cout << "\nForecast for day\n" << endl;
    wf.printForecastForDay(date);
    cout << "\n===========================\n" << endl;
    cout << "Four day forecast\n" << endl;

    //four-day forecast for the day
    wf.printFourDayForecast(date);
    cout << "\n===========================\n" << endl;

    //temperature forecast difference
    cout << "Predicted vs Actual Temperature Forecast:" << endl;
    wf.printTemperatureForecastDifference(date);
    cout << "\n===========================\n" << endl;

    //predicted vs actual rainfall
    int daysOut;
    cout << "Enter the number of days for which you want to compare predicted and actual rainfall:" << endl;
    cout << "(The number should be one of these {1, 2, 3})" << endl;
    cin >> daysOut;
    wf.printPredictedVsActualRainfall(daysOut);
    cout << "\n===========================\n" << endl;

    //last day above temperature
    int temp;
    cout << "Enter a temperature to see when the temperature was last above it: ";
    cin >> temp;
    wf.printLastDayAboveTemperature(temp);
    cout << "\n===========================\n" << endl;

    return 0;
}
/*Main Function Ends*/

/*Read File*/
void readFile(string fileName, WeatherForecaster* wf){
    ifstream inFile;
    inFile.open(fileName);
    //check error
    if(inFile.fail()){
        cout << "ERROR. Aborting Program." << endl;
        return;
    }
    string line;
    int memberIndex = 0;
    ForecastDay temp;
    bool forecast = false;//keep track of when to update day to forecast day
    string tempDay = "NULL";//store previous date
    while(getline(inFile, line, '\n')){
        stringstream ss;
        ss << line;
        while(getline(ss, line, ',')){
            //Today
            if(memberIndex == 0){
                //if the day is not the same as the previous day
                if(line != tempDay){
                    temp.day = line;
                    tempDay = temp.day;
                    forecast = false;//not a forecast
                }
                else{
                    forecast = true;//same day, therefore it is a forecast
                }
                ++memberIndex;
            }
            //Forecast Day
            else if(memberIndex == 1){
                //update day if it is a future forecast
                if(forecast == true){
                    temp.day = line;
                }
                ++memberIndex;
            }
            //High Temp
            else if(memberIndex == 2){
                temp.highTemp = extractTemp(line);
                ++memberIndex;
            }

            //Low Temp
            else if(memberIndex == 3){
                temp.lowTemp = extractTemp(line);
                ++memberIndex;
            }
            //Humidity
            else if(memberIndex == 4){
                temp.humidity = stoi(line);
                ++memberIndex;
            }
            //Avg Wind
            else if(memberIndex == 5){
                temp.avgWind = stoi(line);
                ++memberIndex;
            }
            //Avg Wind Dir
            else if(memberIndex == 6){
                temp.avgWindDir = line;
                ++memberIndex;
            }
            //Max Wind
            else if(memberIndex == 7){
                temp.maxWind = stoi(line);
                ++memberIndex;
            }
            //Max Wind Dir
            else if(memberIndex == 8){
                temp.maxWindDir = line;
                ++memberIndex;
            }
            //Precip
            else if(memberIndex == 9){
                temp.precip = stof(line);
                memberIndex = 0;
            }
        }
        wf->addDayToData(temp);
    }

}

/*Extract Temperature*/
int extractTemp(string stemp){
    return (stemp[2] - '0')*10 + (stemp[3] - '0');//in the given format, 2nd and 3rd element of temp string contain the digits of temp
}
