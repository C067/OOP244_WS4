// TODO: add file header comments here

// Workshop 4 - Constructors - Test Main
// Passenger.h
// Callum Dodge
// 6/08/2018
//100 229 178

// TODO: add header file guard here
#ifndef PASSENGER_H
#define PASSENGER_H


// TODO: declare your namespace here
namespace sict {
	// TODO: define the Passenger class here
	
	class Passenger{
		char passenger_name[32];
		char destination[32];

	public:
		Passenger();
		Passenger(const	char * passenger, const char * destination);
		bool isEmpty() const;
		void display() const;
	};

}

#endif // !PASSENGER_H