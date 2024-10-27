#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"

//DRIVER CONTROL FUNCTIONS
void setDoinker() {

  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
    doinker.set_value(true);
  } 
}

//AUTON FUNCTIONS
