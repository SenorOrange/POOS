#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.h"

//DRIVER CONTROL FUNCTIONS
void setIntakeLift() {

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
    liftIntake.set_value(true);
    } 

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
    liftIntake.set_value(false);
    }
}

//AUTON FUNCTIONS
void intakeUp() {
    liftIntake.set_value(true);
}

void intakeDown() {
    liftIntake.set_value(false);
}

