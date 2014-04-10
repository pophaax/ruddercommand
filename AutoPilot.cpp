#include "AutoPilot.h"

#include <iostream>

AutoPilot::AutoPilot() {
  m_steeringValue = 0;
}

AutoPilot::~AutoPilot() { }


int AutoPilot::getOffCourse() {
	return m_offCourse;
}

int AutoPilot::getSteeringCnst() {
	return m_steeringValue;
}

void AutoPilot::calcSteeringConstant(int cts) {

  m_offCourse = cts - m_course;
  if (m_offCourse > 180) {
    m_offCourse = -360 + m_offCourse;
  }
  if (m_offCourse < -180) {
    m_offCourse = 360 + m_offCourse;
  }
  std::cout << "adjusted offc: " << m_offCourse << "\n";
  
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

int AutoPilot::calcTurningConstant() {
  
  int tmpTurnConst = 0;
  int tps = 0;
    
  m_turnRate = m_course - m_course;  //needs fix
  
  if (m_turnRate <= tps) {
    tmpTurnConst = -1;
  } else if (m_turnRate == tps) {
    tmpTurnConst = 0;
  } else if (m_turnRate >= tps) {
    tmpTurnConst = 1;
  }

  return tmpTurnConst;
  
}

double AutoPilot::getRudderValue(double cts, double heading) {
  
  m_course = heading;
  double tmpTurnConst;
  double tmpRudderValue;
  
  calcSteeringConstant(cts);
  tmpTurnConst = calcTurningConstant();
  
  tmpRudderValue = m_steeringValue + tmpTurnConst + 100;
  
  if (tmpRudderValue < 97) {
    tmpRudderValue = 97;
  } else if (tmpRudderValue > 103) {
    tmpRudderValue = 103;
  }
    
  return tmpRudderValue;
  
}