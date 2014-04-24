#include "RudderCommand.h"
#include <iostream>

using namespace std;

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
	rc.setCommandValues(103, 102, 101, 100);
	rc.setAngleValues(18, 12, 6);
	int foo, bar, i;
	int rudder;
	foo = 0;
	bar = 10;
	i = 0;

	cout << "Heading: " << gps.getHeading() << endl;
	do {

		cout << "CTS: " << ar[i] << endl;

		i++;
		rudder = rc.getCommand(ar[foo], gps.getHeading());

		cout << "RudderCMD: " << rudder << endl;
		cout << "----------------" << endl;

		foo++;

	} while (foo < bar);

}
