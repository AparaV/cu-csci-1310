/**Assignment 6 CSCI 1310 REC 101
  *Aparajithan Venkateswaran
  *TA: Camilla Lambrocco
  *main.cpp
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "WeatherForecaster.h"

using namespace std;

void readFile(string, WeatherForecaster*);//function to read file
int extractTemp(string);//extract temperature from the string

/*Main Function Begins*/
int main(){

    WeatherForecaster wf;
    readFile("boulderData", &wf);

    cout << "Forecast Statistics:\n" << endl;
    wf.printLastDayItRained();//last day it rained
    cout << "Total Rainfall: " << wf.calculateTotalPrecipitation() << endl;//total precipitation
    cout << "First Day in Data: " << wf.getFirstDayInData() << endl;//first day in data
    cout << "Last Day in Data: " << wf.getLastDayInData() << endl << endl;//last day in data
    cout << "==================" << endl << endl;

    //all days in data
    cout << "Days in Data\n" << endl;
    wf.printDaysInData();
    cout << "==================" << endl << endl;

    string date;
    cout << "Enter a date: ";
    getline(cin, date);

    //forecast for day
    cout << "\nForecast for day\n" << endl;
    wf.printForecastForDay(date);
    cout << "==================" << endl << endl;

    //four-day forecast
    cout << "Four day forecast\n" << endl;
    wf.printFourDayForecast(date);
    cout << "==================" << endl << endl;

    //temperature forecast difference
    wf.printTemperatureForecastDifference(date);
    cout << "==================" << endl << endl;

    int temp;
    cout << "Enter a temperature to search for a day with higher temperature:" << endl;
    cin >> temp;

    //last day above temperature
    wf.printLastDayAboveTemperature(temp);
    cout << "==================" << endl << endl;

    int daysOut;
    cout << "Enter a number between 1 and 3 to compare predicted and actual rainfall:" << endl;
    cin >> daysOut;

    //predicted vs actual rainfall
    wf.printPredictedVsActualRainfall(daysOut);
    cout << "==================" << endl << endl;

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
    while(getline(inFile, line, '\n')){
        stringstream ss;
        ss << line;
        while(getline(ss, line, ',')){
            //cout << line << endl;
            //Today
            if(memberIndex == 0){
                //cout << line << endl;
                temp.day = line;
                ++memberIndex;
            }
            //Forecast Day
            else if(memberIndex == 1){
                temp.forecastDay = line;
                //cout << line << endl;
                ++memberIndex;
            }
            //High Temp
            else if(memberIndex == 2){
                temp.highTemp = extractTemp(line);
                //cout << line << endl;
                ++memberIndex;
            }

            //Low Temp
            else if(memberIndex == 3){
                temp.lowTemp = extractTemp(line);
                //cout << line << endl;
                ++memberIndex;
            }
            //Humidity
            else if(memberIndex == 4){
                temp.humidity = stoi(line);
                //cout << line << endl;
                ++memberIndex;
            }
            //Avg Wind
            else if(memberIndex == 5){
                temp.avgWind = stoi(line);
                //cout << line << endl;
                ++memberIndex;
            }
            //Avg Wind Dir
            else if(memberIndex == 6){
                temp.avgWindDir = line;
                //cout << line << endl;
                ++memberIndex;
            }
            //Max Wind
            else if(memberIndex == 7){
                temp.maxWind = stoi(line);
                //cout << line << endl;
                ++memberIndex;
            }
            //Max Wind Dir
            else if(memberIndex == 8){
                temp.maxWindDir = line;
                //cout << line << endl;
                ++memberIndex;
            }
            //Precip
            else if(memberIndex == 9){
                temp.precip = stof(line);
                //cout << line << endl;
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
