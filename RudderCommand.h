#ifndef __RUDDERCOMMAND_H__
#define __RUDDERCOMMAND_H__

#include <math.h>

class RudderCommand {

	/* RudderCommand handles the calculations for the rudder, the calculations is based
	 from a course to steer value and returns a value between 97-103 to be used with the servo 
	 module. */

public:

	RudderCommand();
	~RudderCommand();

	/* Returns a value between 97-103 for the rudder. Takes a courseToSteer value as 
	 parameter. */
	int getCommand(int courseToSteer, int heading);

	// sets the values returned by getCommand()
	void setCommandValues(int starboardExtreme, int starboardMedium, int starboardSmall, int midships);

	// sets the angles used by getCommand() to return appropriate command,
	// extreme angle uses whats left over
	void setAngleValues(int medium, int small, int midships);

	//returns m_midshipsCommand
	int getMidShipsCommand();

private:

	/* Calculates the steeringconstant based on course to steer and heading */
	void calcSteeringValue(int courseToSteer);

	/* Sets the degree range from 0->360, to -180->180 */
	void modifyDegreeRange();

	/* Calculates the turningconstant based on an older course and a newer course */
	int m_steeringValue;
	int m_offCourse;
	int m_course;

	int m_extremeCommand;
	int m_mediumCommand;
	int m_smallCommand;
	int m_midshipsCommand;

	int m_mediumAngle;
	int m_smallAngle;
	int m_midshipsAngle;
};

#endif
