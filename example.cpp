#include "RudderCommand.h"
#include <iostream>

class GPSReader {
//mock gpsreader, used by example.cpp
public:
	GPSReader() {
	};
	
	int getSpeed() {
		return 2;
	};

	int getHeading() {
	return 76;
	};
};

int main() {

	GPSReader gps;

	int ar[] = { 70, 71, 72, 75, 76, 80, 81, 85, 86, 90 };
	RudderCommand rc;
	rc.setCommandValues(103, 100);
	int foo, bar, i;
	int rudder;
	foo = 0;
	bar = 10;
	i = 0;

	std::cout << "Heading: " << gps.getHeading() << std::endl;
	do {

		std::cout << "CTS: " << ar[i] << std::endl;

		i++;
		rudder = rc.getCommand(ar[foo], gps.getHeading());

		std::cout << "RudderCMD: " << rudder << std::endl;
		std::cout << "----------------" << std::endl;

		foo++;

	} while (foo < bar);

}