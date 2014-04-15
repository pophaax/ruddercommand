#include "RudderCommand.h"

RudderCommand::RudderCommand() {
	m_steeringValue = 0;
}

RudderCommand::~RudderCommand() {
}

int RudderCommand::getOffCourse() {
	return m_offCourse;
}

int RudderCommand::getSteeringValue() {
	return m_steeringValue;
}

void RudderCommand::modifyDegreeRange() {

	if (m_offCourse > 180) {
		m_offCourse - 360;
	}
	if (m_offCourse < -180) {
		m_offCourse + 360;
	}
}

void RudderCommand::calcSteeringConstant(int cts) {

	m_offCourse = cts - m_course;
	modifyDegreeRange();

	if (m_offCourse < -17) {
		m_steeringValue = EXTREME_STARBOARD;
	} else if (m_offCourse < -11) {
		m_steeringValue = STARBOARD;
	} else if (m_offCourse < -5) {
		m_steeringValue = SMALL_STARBOARD;
	} else if (m_offCourse < 6) {
		m_steeringValue = AMIDSHIPS;
	} else if (m_offCourse < 12) {
		m_steeringValue = SMALL_PORT;
	} else if (m_offCourse < 17) {
		m_steeringValue = PORT;
	} else {
		m_steeringValue = EXTREME_PORT;
	}
}

int RudderCommand::getRudderValue(int cts, int heading) {

	m_course = heading;
	calcSteeringConstant(cts);
	return m_steeringValue;

}
