#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"

//DRIVER CONTROL FUNCTIONS


void setMogoMech() {

  /*mogoMech.set_value(true);
  pros::delay(1000);
  mogoMech.set_value(false);*/

  /*int mogoTrigger = (controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN));
    mogoMech.set_value(mogoTrigger);*/

  if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) {
    mogoMech.set_value(true);
  } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
    mogoMech.set_value(false);
  }
    
}