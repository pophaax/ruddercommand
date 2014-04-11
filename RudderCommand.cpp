#include "RudderCommand.h"

RudderCommand::RudderCommand() {
	m_steeringValue = 0;
}

RudderCommand::~RudderCommand() {
}

int RudderCommand::getOffCourse() {
	return m_offCourse;
}

int RudderCommand::getSteeringCnst() {
	return m_steeringValue;
}

void RudderCommand::calcSteeringConstant(int cts) {

	m_offCourse = cts - m_course;
	if (m_offCourse > 180) {
		m_offCourse = -360 + m_offCourse;
	}
	if (m_offCourse < -180) {
		m_offCourse = 360 + m_offCourse;
	}

	if (m_offCourse < -17) {
		m_steeringValue = -3;
	} else if (m_offCourse < -11) {
		m_steeringValue = -2;
	} else if (m_offCourse < -5) {
		m_steeringValue = -1;
	} else if (m_offCourse < 6) {
		m_steeringValue = 0;
	} else if (m_offCourse < 12) {
		m_steeringValue = 1;
	} else if (m_offCourse < 17) {
		m_steeringValue = 2;
	} else {
		m_steeringValue = 3;
	}
}

// int RudderCommand::calcTurningConstant() {

//   int tmpTurnConst = 0;
//   int tps = 0;

//   m_turnRate = m_course - m_course;  //needs fix

//   if (m_turnRate < tps) {
//     tmpTurnConst = -1;
//   } else if (m_turnRate == tps) {
//     tmpTurnConst = 0;
//   } else if (m_turnRate > tps) {
//     tmpTurnConst = 1;
//   }

//   return tmpTurnConst;

// }

int RudderCommand::getRudderValue(int cts, int heading) {

	// m_course = heading;
	// double tmpTurnConst;
	// double tmpRudderValue;

	// calcSteeringConstant(cts);
	// tmpTurnConst = calcTurningConstant();

	// tmpRudderValue = m_steeringValue + tmpTurnConst + 100;

	// if (tmpRudderValue < 97) {
	//   tmpRudderValue = 97;
	// } else if (tmpRudderValue > 103) {
	//   tmpRudderValue = 103;
	// }

	// return tmpRudderValue;

	m_course = heading;
	calcSteeringConstant(cts);
	return 100 + m_steeringValue;

}
