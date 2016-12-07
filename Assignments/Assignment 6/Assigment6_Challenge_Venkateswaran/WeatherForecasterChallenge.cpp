/**Assignment 6 Challenge CSCI 1310 REC 101
  *Aparajithan Venkateswaran
  *TA: Camilla Lambrocco
  *WeatherForecasterChallenge.cpp
 */

#include "WeatherForecasterChallenge.h"
#include <cmath>

/*Constructor*/
WeatherForecaster::WeatherForecaster(){
    arrayLength = 246;
    index = -1;
}

/*Destructor*/
WeatherForecaster::~WeatherForecaster(){}

/*Add Day To Data*/
void WeatherForecaster::addDayToData(ForecastDay temp){
    //add element to either directly to the struct or to the vector
    if(index == -1 || yearData[index].ff.size() == 3){
        index++;
        yearData[index] = temp;
    }
    else{
        yearData[index].ff.push_back(temp);
    }
}

/*Print Days In Data*/
void WeatherForecaster::printDaysInData(){
    //print the days in the yearData
    for(int i = 0; i < arrayLength; ++i){
        cout << yearData[i].day << endl;
    }
}

/*Print Forecast For Day*/
void WeatherForecaster::printForecastForDay(string date){
    //search for date
    for(int i = 0; i < arrayLength; ++i){
        if(yearData[i].day == date){
            cout << "Forecast for " << date << endl;
            cout << "H: " << yearData[i].highTemp << endl;
            cout << "L: " << yearData[i].lowTemp << endl;
            cout << "Humidity: " << yearData[i].humidity << endl;
            cout << "Avg. Wind: " << yearData[i].avgWind << endl;
            cout << "Avg. Wind Direction: " << yearData[i].avgWindDir << endl;
            cout << "Max. Wind: " << yearData[i].maxWind << endl;
            cout << "Max. Wind Direction: " << yearData[i].maxWindDir << endl;
            cout << "Precipitation: " << yearData[i].precip << endl;
            return;
        }
    }
    //if no match is found
    cout << "Date not found." << endl;
}

/*Print Four Day Forecast*/
void WeatherForecaster::printFourDayForecast(string date){
    //search for date
    for(int i = 0; i < arrayLength; ++i){
        if(yearData[i].day == date){
            //forecast for that day
            cout << "Forecast for " << date << endl;
            cout << "H: " << yearData[i].highTemp << endl;
            cout << "L: " << yearData[i].lowTemp << endl;
            cout << "Humidity: " << yearData[i].humidity << endl;
            cout << "Avg. Wind: " << yearData[i].avgWind << endl;
            cout << "Avg. Wind Direction: " << yearData[i].avgWindDir << endl;
            cout << "Max. Wind: " << yearData[i].maxWind << endl;
            cout << "Max. Wind Direction: " << yearData[i].maxWindDir << endl;
            cout << "Precipitation: " << yearData[i].precip << endl << endl;
            //future forecasts
            for(unsigned int j = 0; j < yearData[i].ff.size(); ++j){
                //stop if 4 forecasts are made
                if(j == 3){
                    return;
                }
                cout << "Forecast for " << yearData[i].ff[j].day << " made on " << date << endl;
                cout << "H: " << yearData[i].ff[j].highTemp << endl;
                cout << "L: " << yearData[i].ff[j].lowTemp << endl;
                cout << "Humidity: " << yearData[i].ff[j].humidity << endl;
                cout << "Avg. Wind: " << yearData[i].ff[j].avgWind << endl;
                cout << "Avg. Wind Direction: " << yearData[i].ff[j].avgWindDir << endl;
                cout << "Max. Wind: " << yearData[i].ff[j].maxWind << endl;
                cout << "Max. Wind Direction: " << yearData[i].ff[j].maxWindDir << endl;
                cout << "Precipitation: " << yearData[i].ff[j].precip << endl << endl;
            }
            return;
        }
    }
    //if no match is found
    cout << "Date not found." << endl;
}

/*Calculate Total Precipitation*/
double WeatherForecaster::calculateTotalPrecipitation(){
    double sum = 0;
    //sum all precipitations
    for(int i = 0; i < arrayLength; ++i){
        sum += yearData[i].precip;
    }
    return sum;
}

/*Print Last Day It Rained*/
void WeatherForecaster::printLastDayItRained(){
    //loop from end
    for(int i = arrayLength - 1; i >= 0; --i){
        if(yearData[i].precip > 0){
            cout << yearData[i].day << endl;
            return;
        }
    }
    //if no match is found
    cout << "It never rained :(" << endl;
}

/*Print Last Day Above Temperature*/
void WeatherForecaster::printLastDayAboveTemperature(int temp){
    //loop from end
    for(int i = arrayLength - 1; i >= 0; --i){
        //check whether the temperature input is within the forecast range
        if(yearData[i].highTemp > temp){
            cout << yearData[i].day << endl;
            return;
        }
    }
    //if no match is found
    cout << "No match found :(" << endl;
}

/*Print Temperature Forecast Difference*/
void WeatherForecaster::printTemperatureForecastDifference(string date){
    //find the actual data
    for(int i = 0; i < arrayLength; ++i){
        if(yearData[i].day == date){
            //go back and find the forecasts
            for(int j = i - 3; j < i; ++j){
                //find data in the forecasts vector
                for(int k = 0; k < yearData[j].ff.size(); ++k){
                    if(yearData[j].ff[k].day == date){
                        //print forecasts
                        cout << "Forecast for " << date << " issued on " << yearData[j].day << ":" << endl;
                        cout << "H: " << yearData[j].ff[k].highTemp << " F" << endl;
                        cout << "L: " << yearData[j].ff[k].lowTemp << " F\n" << endl;
                    }
                }
            }
            //print actual data
            cout << "Actual forecast on " << date << ":" << endl;
            cout << "H: " << yearData[i].highTemp << " F" << endl;
            cout << "L: " << yearData[i].lowTemp << " F" << endl;
            return; //stop function
        }
    }
}

/*Predicted vs Actual Rainfall*/
void WeatherForecaster::printPredictedVsActualRainfall(int daysOut){
    double predRain = 0;
    double actualRain = 0;
    string future;
    //loop through data set
    for(int i = 0; i < arrayLength; ++i){
        //check whether future forecast is available
        if(daysOut - 1 < yearData[i].ff.size()){
            predRain += yearData[i].ff[daysOut - 1].precip;
            future = yearData[i].ff[daysOut - 1].day;
            //check whether the actual forecast for that day is available
            for(int j = i + 1; j < i + daysOut + 1; ++j){
                if(yearData[j].day == future){
                    actualRain += yearData[j].precip;
                    break;//stop the inner for loop
                }
            }
        }
    }
    cout << "Predicted rainfall in " << daysOut << "-day forecast:" << endl;
    cout << predRain << " inches" << endl;
    cout << "Actual rainfall in day of forecast:" << endl;
    cout << actualRain << " inches" << endl << endl;
}

/*First Day In Data*/
string WeatherForecaster::getFirstDayInData(){
    return yearData[0].day;
}

/*Last Day In Data*/
string WeatherForecaster::getLastDayInData(){
    return yearData[index].day;
}
