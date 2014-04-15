#ifndef __RUDDERCOMMAND_H__
#define __RUDDERCOMMAND_H__

class RudderCommand {

	/* RudderCommand handles the calculations for the rudder, the calculations is based
	 from a CTS value and returns a value between 97-103 to be used with the servo 
	 module. */

public:

	/* The construtor, the parameter is a value that represent the boatspeed 
	 and which sensor the RudderCommand use is based on this. */
	RudderCommand();
	~RudderCommand(); //destructor

	/* Returns a value between 97-103 for the rudder. Takes a CTS value as 
	 parameter. */
	int getRudderValue(int cts, int heading);
	int getSteeringValue();
	int getOffCourse();

private:

	/* Rudder commands send to the rudder's servo */
	enum rudderCommands {
		EXTREME_STARBOARD 	= 97,
		STARBOARD 			= 98,
		SMALL_STARBOARD 	= 99,
		AMIDSHIPS 			= 100,
		SMALL_PORT 			= 101,
		PORT 				= 102,
		EXTREME_PORT 		= 103 
	};

	/* Calculates the steeringconstant based on CTS and heading */
	void calcSteeringConstant(int cts);

	/* Sets the degree range from 0->360, to -180->180 */
	void modifyDegreeRange();

	/* Calculates the turningconstant based on an older course and a newer course */
	int m_steeringValue;
	int m_offCourse;
	int m_course;

};

#endif