#include <iostream>
#include <vector>



class AutoPilot {
 
/* Autopilot handles the calculations for the rudder, the calculations is based
   from a CTS value and returns a value between 97-103 to be used with the servo 
   module. */   
  
public:
  
  /* The construtor, the parameter is a value that represent the boatspeed 
     and which sensor the Autopilot use is based on this. */ 
  AutoPilot(); 
  ~AutoPilot(); //destructor

  /* Returns a value between 97-103 for the rudder. Takes a CTS value as 
     parameter. */
  double getRudderValue(double cts, double heading);
  int getOffCourse();
  int getSteeringCnst();
  
  
private:
  
  /* Calculates the steeringconstant based on CTS and heading */
  int getSteeringConstant(int cts, double heading);

  /* Calculates the turningconstant based on an older course and a newer course.
  */
  int getTurningConstant(double heading);

  int steeringConstant;
  int offCourse;
  int m_course;
  int m_newCourse;
  int m_turnRate;
  int m_speedCheck;
  bool m_highSpeed;
  
};