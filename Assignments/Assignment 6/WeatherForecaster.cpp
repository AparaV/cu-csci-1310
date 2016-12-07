/**Assignment 6 CSCI 1310 REC 101
  *Aparajithan Venkateswaran
  *TA: Camilla Lambrocco
  *WeatherForecaster.cpp
 */

#include "WeatherForecaster.h"
#include "cmath"

/*Constructor*/
WeatherForecaster::WeatherForecaster(){
    arrayLength = 984;//set the array size
    index = -1;//initially the index is set to -1 (array is empty)
}

/*Destructor*/
WeatherForecaster::~WeatherForecaster(){}

/*Add Day To Data*/
void WeatherForecaster::addDayToData(ForecastDay temp){
    index++;
    if(index < arrayLength){
        yearData[index] = temp;
    }
    else{
        cout << "Array is Full" << endl;
    }
}

/*Print Unique Days In Data*/
void WeatherForecaster::printDaysInData(){
    //loop through available data
    for(int i = 0; i <= index; ++i){
        //match day and forecast data
        if(yearData[i].day == yearData[i].forecastDay){
            cout << yearData[i].day << endl;
        }
    }
}

/*Print Forecast For Day*/
void WeatherForecaster::printForecastForDay(string today){
    //loop through available data
    for(int i = 0; i <= index; ++i){
        //match today and forecast day
        if(yearData[i].day == today && yearData[i].forecastDay == today){
            cout << "Forecast for " << today << endl;
            cout << "H: " << yearData[i].highTemp << endl;
            cout << "L: " << yearData[i].lowTemp << endl;
            cout << "Humidity: " << yearData[i].humidity << endl;
            cout << "Avg. Wind: " << yearData[i].avgWind << endl;
            cout << "Avg. Wind Direction: " << yearData[i].avgWindDir << endl;
            cout << "Max. Wind: " << yearData[i].maxWind << endl;
            cout << "Max. Wind Direction: " << yearData[i].maxWindDir << endl;
            cout << "Precipitation: " << yearData[i].precip << endl << endl;
            break;//leave the loop immediately
        }
        //if no match is found
        if(i == index){
            cout << "No match is found for the date: " << today << endl;
        }
    }
}

/*Print Four Day Forecast*/
void WeatherForecaster::printFourDayForecast(string today){
    int dayCount = 0;
    //loop through available data
    for(int i = 0; i <= index; ++i){
        //match today and forecast day
        if(yearData[i].day == today && yearData[i].forecastDay == today){
            cout << "Forecast for " << today << endl;
            cout << "H: " << yearData[i].highTemp << endl;
            cout << "L: " << yearData[i].lowTemp << endl;
            cout << "Humidity: " << yearData[i].humidity << endl;
            cout << "Avg. Wind: " << yearData[i].avgWind << endl;
            cout << "Avg. Wind Direction: " << yearData[i].avgWindDir << endl;
            cout << "Max. Wind: " << yearData[i].maxWind << endl;
            cout << "Max. Wind Direction: " << yearData[i].maxWindDir << endl;
            cout << "Precipitation: " << yearData[i].precip << endl << endl;
            dayCount++;
            continue;
        }
        //print the future forecast
        if(dayCount != 0 &&  yearData[i].day == today){
            cout << "Forecast for " << yearData[i].forecastDay << endl;
            cout << "H: " << yearData[i].highTemp << endl;
            cout << "L: " << yearData[i].lowTemp << endl;
            cout << "Humidity: " << yearData[i].humidity << endl;
            cout << "Avg. Wind: " << yearData[i].avgWind << endl;
            cout << "Avg. Wind Direction: " << yearData[i].avgWindDir << endl;
            cout << "Max. Wind: " << yearData[i].maxWind << endl;
            cout << "Max. Wind Direction: " << yearData[i].maxWindDir << endl;
            cout << "Precipitation: " << yearData[i].precip << endl << endl;
            dayCount++;
        }
        //if we have already printed four forecasts
        if(dayCount == 4){
            break;
        }
    }
    //if no match is found
    if(dayCount == 0){
        cout << "No match is found." << endl;
    }
}

/*Calculate Total Precipitation*/
double WeatherForecaster::calculateTotalPrecipitation(){
    double sum = 0;
    //loop through available data
    for(int i = 0; i <= index; ++i){
        //match today and forecast day
        if(yearData[i].day == yearData[i].forecastDay){
            sum += yearData[i].precip;
        }
    }
    return sum;
}

/*Last Day It Rained*/
void WeatherForecaster::printLastDayItRained(){
    //loop through available data from the end
    for(int i = index; i >= 0; --i){
        //match day and forecast day; check whether precipitation was above 0
        if(yearData[i].day == yearData[i].forecastDay && yearData[i].precip > 0){
            cout << "Last day it rained was " << yearData[i].day << endl;
            return;
        }
    }
    //if no match was found
    cout << "It never rained :(" << endl;
}

/*Last Day Above Temperature*/
void WeatherForecaster::printLastDayAboveTemperature(int temp){
    //loop through available data from the end
    for(int i = index; i >= 0; --i){
        //match today and forecast day
        if(yearData[i].day == yearData[i].forecastDay){
            //check whether temperature lies in the range on that day
            if(yearData[i].highTemp > temp){
                cout << "Last day above the temperature " << temp << " was on " << yearData[i].day << endl;
                return;
            }
        }
    }
    //if no match is found
    cout << "No days above that temperature." << endl;
}

/*Print Temperature Forecast Difference*/
void WeatherForecaster::printTemperatureForecastDifference(string date){
    //find actual forecast
    for(int i = 0; i < arrayLength; ++i){
        if(yearData[i].day == date && yearData[i].forecastDay == date){
            //get forecasts
            for(int j = 0; j < i; ++j){
                //print forecasts
                if(yearData[j].forecastDay == date){
                    cout << "Forecast for " << date << " on " << yearData[j].day << endl;
                    cout << "H: " << yearData[j].highTemp << endl;
                    cout << "L: " << yearData[j].lowTemp << endl;
                }
            }
            //print actual forecast
            cout << "Forecast for " << date << " on " << yearData[i].day << endl;
            cout << "H: " << yearData[i].highTemp << endl;
            cout << "L: " << yearData[i].lowTemp << endl << endl;
            return;//stop function
        }
    }
}

/*Print Predicted vs Actual Rainfall*/
void WeatherForecaster::printPredictedVsActualRainfall(int days){
    double predRain = 0;
    //loop through available data set
    for(int i = 0; i <= index; i++){
        //check whether future forecast is available
        if(yearData[i].forecastDay == yearData[i].day){
            predRain += yearData[i+days].precip;
        }
    }
    //output
    cout << "Predicted rainfall in " << days << "-day of forecast:" << endl;
    cout << predRain << " inches" << endl;
    cout << "Actual rainfall in day of forecast:" << endl;
    cout << calculateTotalPrecipitation() << " inches" << endl << endl;
}

/*Get First Day In Data*/
string WeatherForecaster::getFirstDayInData(){
    //loop through available data
    for(int i = 0; i <= index; ++i){
        if(yearData[i].day == yearData[i].forecastDay){
            return yearData[i].day;
        }
        //if no match
        if( i == index){
            return "NULL";
        }
    }
}

/*Get Last Day In Data*/
string WeatherForecaster::getLastDayInData(){
    //loop through available data
    for(int i = index; i >= 0; --i){
        if(yearData[i].day == yearData[i].forecastDay){
            return yearData[i].day;
        }
        //if no match
        if( i == 0){
            return "NULL";
        }
    }
}
