#include "RudderCommand.h"
#include <math.h>


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

void RudderCommand::setCommandValues(int starboardExtreme, int midships) {
	m_extremeCommand = starboardExtreme;
	m_midshipsCommand = midships;
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
	int deltaCommand = m_extremeCommand - m_midshipsCommand;
	if ( cos(m_offCourse) > 0) {
		m_steeringValue = m_midshipsCommand + deltaCommand * sin(m_offCourse);
	}
	else {
		if (sin(m_offCourse) > 0) {
			m_steeringValue = m_midshipsCommand + deltaCommand;
		}
		else {
			m_steeringValue = m_midshipsCommand - deltaCommand;
		}
	}
}