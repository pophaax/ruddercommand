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
	int getOffCourse();
	int getSteeringCnst();

private:

	/* Calculates the steeringconstant based on CTS and heading */
	void calcSteeringConstant(int cts);

	/* Calculates the turningconstant based on an older course and a newer course.
	 */
	// int calcTurningConstant();
	int m_steeringValue;
	int m_offCourse;
	int m_course;
	// int m_turnRate;
};

#endif