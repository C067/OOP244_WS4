// TODO: add file header comments here

// Workshop 4 - Constructors - Test Main
// Passenger.cpp
// Callum Dodge
// 6/08/2018
//100 229 178

#define _CRT_SECURE_NO_WARNINGS
// TODO: add your headers here
#include "Passenger.h"
#include <iostream>
#include <cstring>

using namespace std;

// TODO: continue your namespace here
namespace sict {

	// TODO: implement the default constructor here
	Passenger::Passenger() {
		//Safe empty state
		*passenger_name = '\0';
		*destination = '\0';
		year = 0;
		month = 0;
		day = 0;
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char * n_passenger, const char * n_destination) {

		//Compare if the passenger and destination fields are empty 
		if (*n_passenger == '\0' || *n_destination == '\0') {
			*passenger_name = '\0';
			*destination = '\0';
			year = 0;
			month = 0;
			day = 0;
		}
		else {
			//Copy the values to the data members
			strncpy(passenger_name, n_passenger, size);
			strncpy(destination, n_destination, size);
			
			//Preset the date
			year = 2017;
			month = 7;
			day = 1;
		}

	}

	Passenger::Passenger(const char * n_passenger, const char * n_destination, int n_year, int n_month, int n_day) {

		//Compare to see if the entered passenger and destination is not empty or null
		if (n_passenger != nullptr && n_destination != nullptr && strlen(n_passenger) > 0 && strlen(n_destination) > 0 ) {

			//Compare to see if the dates are valued 
			if ( n_year > 2016 && n_year < 2021 && n_month > 0 && n_month < 13 && n_day > 0 && n_day < 32) {

				//Copy the values over to the data members
				year = n_year;
				month = n_month;
				day = n_day;

				strncpy(passenger_name, n_passenger, size);
				strncpy(destination, n_destination, size);
			}
			else {
				//Safe Empty State
				*passenger_name = '\0';
				*destination = '\0';
				year = 0;
				month = 0;
				day = 0;
			}
		}

		else {
			//Safe Empty State
			*passenger_name = '\0';
			*destination = '\0';
			year = 0;
			month = 0;
			day = 0;
		}

	}

	const char* Passenger::name() const {
		//Return the passenger's name
		return passenger_name;
	}

	bool Passenger::canTravelWith(const Passenger& passenger) const {
		bool result;
		
		//Compare to see if the Passenger has the same destination on the same date. 
		//Will be able to travel with each other if the days and destination match.
		if ((strcmp(passenger.destination, destination) == 0) && passenger.year == year && passenger.month == month && passenger.day == day) {
			result = true;
		}
		else {
			result = false;
		}

		return result;
	}

	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		bool value;

		//Compare if the passenger and destination fields are empty
		if ( *passenger_name == '\0' || *destination == '\0') {

			//return true if they are
			value = true;

		}
		else {
			//return false if they aren't 
			value = false;
		}

		return value;
	}

	// TODO: implement display query here
	void Passenger::display() const {
		
		//Displaying the passengers
		bool result = isEmpty();

		if (result == true) {
			cout << "No passenger!" << endl;
		}
		else {
			cout << passenger_name << " - " << destination << " on " << year << "/";
			
			//If the month is less than 10 add a zero before. 
			if (month < 10) {
				cout << "0" << month << "/";
			}
			else {
				cout << month << "/";
			}

			//If the day is less than 10 add a zero before. 
			if (day < 10) {
				cout << "0" << day << endl;
			}
			else {
				cout << day << endl;
			}
		}
	}
}