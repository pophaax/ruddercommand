#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "RudderCommand.h"


TEST_CASE("RudderCommandTest")
{
	SECTION("Test courseToSteer to be values between 0-360, resulting command should stay between 97-103")
	{
		/* Constant heading position */
		const int gps_heading = 76;
		
		/* Output to servo */
		const int command_min = 97;
		const int command_max = 103;

		RudderCommand rc;
		/* Magic values from example.cpp */
		rc.setCommandValues(103, 102, 101, 100); 
		rc.setAngleValues(18, 12, 6);
		
		int rudder;

		/* Loops through every possible degree value based on a compass 0 - 360 */
		for(int i = 0; i <= 360; i++) {
			rudder = rc.getCommand(i, gps_heading);

			REQUIRE(rudder >= command_min);
			REQUIRE(rudder <= command_max);
		}
	}

	SECTION("Test courseToSteer to be 10 different values, check if resulting command is correct")
	{
		/* Constant heading position */
		const int gps_heading = 76;
		/* CTS from example.cpp */
		const int CTS[] = { 70, 71, 72, 75, 76, 80, 81, 85, 86, 90 };
		/* Resulting commands taken from running example.cpp*/
		const int result_command[] = { 100,102,103,97,100,97,97,103,97,102 }; 
		const int noOfCTS = 10;

		RudderCommand rc;
		/* Magic values from example.cpp */
		rc.setCommandValues(103, 102, 101, 100); 
		rc.setAngleValues(18, 12, 6);
		
		int rudder;
		for(int i = 0; i < noOfCTS; i++) {
			rudder = rc.getCommand(CTS[i], gps_heading);
			REQUIRE(rudder == result_command[i]);
		}
	}
}