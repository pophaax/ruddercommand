#include "AutoPilot.h"

#include <iostream>

AutoPilot::AutoPilot() {
  
}

AutoPilot::~AutoPilot() { }


int up(int cts, int heading) {
	bool flag = true;
	int i = 0;
	for (i=0; i<360 && flag == true; i++) {
		if (heading == cts) {
			flag = false;
		}
		
		heading++;

		if (heading == 360) {
			heading = 0;
		}
	}

	return i;
}

int down(int cts, int heading) {
	bool flag = true;
	int i = 0;
	for (i=0; i<360 && flag == true; i++) {
		if (heading == cts) {
			flag = false;
		}
		
		heading--;
		
		if (heading == -1) {
			heading = 359;
		}
	}
	
	return i;
}

int AutoPilot::getOffCourse() {
	return offCourse;
}

int AutoPilot::getSteeringCnst() {
	return steeringConstant;
}

int AutoPilot::getSteeringConstant(int cts, double heading) {
  
  int tmpSteeringConstant = 0;
  offCourse = 0;
 
  m_course = heading;

  int diffUp = up(cts, m_course);
  int diffDown = down(cts, m_course);

	if (diffUp <= diffDown) {
		offCourse = diffUp;
	}
	else {
		offCourse = -diffDown;
	}
  
  if (offCourse >= -12 && offCourse <= -17) {
      
      tmpSteeringConstant = -2;
      
  } else if (offCourse >= -6 && offCourse <= -11) {
      
      tmpSteeringConstant = -1;
      
  } else if (offCourse >= -5 && offCourse <= 5) {
      
      tmpSteeringConstant = 0;
      
  } else if (offCourse >= 6 && offCourse <= 11) {
      
      tmpSteeringConstant = 1;
      
  } else if (offCourse >= 12 && offCourse <= 17) {
      
      tmpSteeringConstant = 2;
      
  } else if (offCourse < -17) {
    
    tmpSteeringConstant = -3;
    
  } else if (offCourse > 17) {
    tmpSteeringConstant = 3;
  }
  return tmpSteeringConstant;
  
}
int AutoPilot::getTurningConstant(double heading) {
  
  int tmpTurnConst = 0;
  int tps = 0;
    
  m_turnRate = m_course - heading;
  
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
  
  double tmpSteeringConstant = 0;
  double tmpTurnConst;
  double tmpRudderValue;
  
  tmpSteeringConstant = getSteeringConstant(cts, heading);
  steeringConstant = tmpSteeringConstant;
  tmpTurnConst = getTurningConstant(heading);
  
  tmpRudderValue = tmpSteeringConstant + tmpTurnConst + 100;
  
  if (tmpRudderValue < 97) {
    tmpRudderValue = 97;
  } else if (tmpRudderValue > 103) {
    tmpRudderValue = 103;
  }
    
  return tmpRudderValue;
  
}