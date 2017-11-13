/*
 * Filename: program9.cpp 
 * Name: George Shaw
 * WSUID: g829g576
 * HW#: 9
 * Description: Program that draws from a data file to draw conclusions about various temperatures.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

void show_warmer(double temperature[][24], int days, double cutoff);
double find_average(double temperature[][24], int days);
void find_daily_mmm(double day_temps[], double &max, double &min, double &mean);

int main() {
	double celcius[7][24];
	ifstream data;

	double in, max, min, mean;
	int day = 0, hour = 0;

	data.open("temperature.dat", ios::in);
	if (data.is_open()) {
		while(data >> in) {
			if(hour == 24) {
				day++;
				hour = 0;
			}

			celcius[day][hour] = ((in - 32.0) * (5.0/9.0));
			hour++;
		}
	}
	data.close();

	cout << "Enter the value for which to find warmer temperatures (C): ";
	cin >> in;

	show_warmer(celcius, 7, in);

	in = find_average(celcius, 7);
	cout << "\nThe average temperature over all the days was: " << fixed << setprecision(2) << in << " C.\n\n";

	for(int i = 0; i < 7; i++) {
		find_daily_mmm(celcius[i], max, min, mean);

		cout << "Day " << (i + 1) << ": ";
		cout << "max " << fixed << setprecision(2) << max << " C, ";
		cout << "min " << fixed << setprecision(2) << min << " C, ";
		cout << "mean " << fixed  << setprecision(2) << mean << " C.\n";
	}

	return 0;
}

/*
   show_warmer function takes in an array of x amount of days of temperatures and
   finds all of the temperatures warmer than the parameter cutoff.
 */
void show_warmer(double temperature[][24], int days, double cutoff) {
	cout << "\nTimes at which temperatures warmer than 22.30 C were found:\n\n";

	for(int day = 0; day < days; day++) {
		for(int hour = 0; hour < 24; hour++) {
			if(temperature[day][hour] > cutoff) {
				cout << "At day " << (day + 1);
				cout << ", hour " << (hour + 1);
				cout << ", the temperature was " << fixed << setprecision(2) << temperature[day][hour] << " C.\n";
			}
		}
	}
}

/*
   find_average function takes in an array of x amount of days of temperatures and
   finds the average temperature for the week.
 */
double find_average(double temperature [][24], int days) {
	double sum = 0;
	int total = 0;

	for(int day = 0; day < days; day++) {
		for(int hour = 0; hour < 24; hour++) {
			sum += temperature[day][hour];
			total++;
		}
	}

	return (sum/(double)total);
}

/*
   find_daily_mmm function takes in an array of temperatures for a day and finds
   the max, min, and average temperature of that whole day.
 */
void find_daily_mmm(double day_temps[], double &max, double &min, double &mean) {
	max = mean = 0;
	min = 10000;

	for(int i = 0; i < 24; i++) {
		if(day_temps[i] > max) max = day_temps[i];
		if(day_temps[i] < min) min = day_temps[i];

		mean += day_temps[i];
	}

	mean = (mean/24.0);
}
