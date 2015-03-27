#define CATCH_CONFIG_MAIN
#include "catch.hpp"
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
}