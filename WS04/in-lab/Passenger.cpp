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
		*passenger_name = '\0';
		*destination = '\0';
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char * n_passenger, const char * n_destination) {

		//Compasre if the passenger and destination fields are empty 
		if (n_passenger == '\0' || n_destination == '\0') {
			*passenger_name = '\0';
			*destination = '\0';
		}
		else {
			//Copy the values 
			strcpy(passenger_name, n_passenger);
			strcpy(destination, n_destination);
		}

	
	}
	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		bool value;

		//Compare if the passenger and destination fields are empty
		if (*passenger_name == '\0' || *destination == '\0') {

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
			cout << passenger_name << " - " << destination << endl;
		}
	}
}