#include "RudderCommand.h"

RudderCommand::RudderCommand() {
	m_steeringValue = 0;
}

RudderCommand::~RudderCommand() {
}

int RudderCommand::getCommand(int courseToSteer, int heading) {

	m_course = heading;
	calcSteeringValue(courseToSteer);
	return m_steeringValue;

}

void RudderCommand::setCommandValues(int starboardExtreme, int starboardMedium, int starboardSmall, int midships) {
	m_extremeCommand = extreme;
	m_mediumCommand = medium;
	m_smallCommand = small;
	m_midshipsCommand = midships;
}

void RudderCommand::setAngleValues(int medium, int small, int midships) {
	m_mediumAngle = medium;
	m_smallAngle = small;
	m_midshipsAngle = midships;
}

int RudderCommand::getMidShipsCommand() {
	return 	m_midshipsCommand;
}

void RudderCommand::modifyDegreeRange() {

	if (m_offCourse > 180) {
		m_offCourse -= 360;
	}
	if (m_offCourse < -180) {
		m_offCourse += 360;
	}
}

void RudderCommand::calcSteeringValue(int courseToSteer) {

	m_offCourse = courseToSteer - m_course;
	modifyDegreeRange();

	if (m_offCourse < -m_mediumAngle) {
		m_steeringValue = m_midshipsCommand - (m_extremeCommand - m_midshipsCommand);
	} else if (m_offCourse < -m_smallAngle) {
		m_steeringValue = m_midshipsCommand - (m_mediumCommand - m_midshipsCommand);
	} else if (m_offCourse < -m_midshipsAngle) {
		m_steeringValue = m_midshipsCommand - (m_smallCommand - m_midshipsCommand);
	} else if (m_offCourse > m_mediumAngle) {
		m_steeringValue = m_extremeCommand;
	} else if (m_offCourse > m_smallAngle) {
		m_steeringValue = m_mediumCommand;
	} else if (m_offCourse > m_midshipsAngle) {
		m_steeringValue = m_smallCommand;
	} else {
		m_steeringValue = m_midshipsCommand;
	}
}
