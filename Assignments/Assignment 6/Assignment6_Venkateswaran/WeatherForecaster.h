#ifndef WEATHERFORECASTER_H
#define WEATHERFORECASTER_H

#include <iostream>

using std::string;
using std::cout;
using std::endl;

struct ForecastDay{
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
};

class WeatherForecaster
{
    public:
        WeatherForecaster();
        ~WeatherForecaster();
        void addDayToData(ForecastDay);
        void printDaysInData(); //prints the unique dates in the data
        void printForecastForDay(string);
        void printFourDayForecast(string);
        double calculateTotalPrecipitation();
        void printLastDayItRained();
        void printLastDayAboveTemperature(int); //argument is the temperature
        void printTemperatureForecastDifference(string);
        void printPredictedVsActualRainfall(int); //argument is days out, such as 1 = 1 day out, 2 = 2 days out, 3 = 3 days out
        string getFirstDayInData();
        string getLastDayInData();
    protected:
    private:
        int arrayLength;
        int index;
        ForecastDay yearData[984]; //data for each day
};

#endif // WEATHERFORECASTER_H
