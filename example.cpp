#include "RudderCommand.h"
#include "MockGPSReader.h"
#include <iostream>

using namespace std;

int main() {

	GPSReader gps;

	int ar[] = { 70, 71, 72, 75, 76, 80, 81, 85, 86, 90 };
	RudderCommand rc;
	int foo, bar, i;
	int rudder;
	foo = 0;
	bar = 10;
	i = 0;

	cout << "Heading: " << gps.getHeading() << endl;
	do {

		cout << "CTS: " << ar[i] << endl;

		i++;
		rudder = rc.getRudderValue(ar[foo], gps.getHeading());

		cout << "RudderCMD: " << rudder << endl;
		cout << "----------------" << endl;

		foo++;

	} while (foo < bar);

}
