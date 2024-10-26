#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"

//DRIVER CONTROL FUNCTIONS
void setMogoMech() {

  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
    mogoMech.set_value(true);
  } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
    mogoMech.set_value(false);
  }
    
}

//AUTON FUNCTIONS
void clamp() {
    mogoMech.set_value(true);
}

void unclamp() {
    mogoMech.set_value(false);
}