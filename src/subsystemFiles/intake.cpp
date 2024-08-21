#include "main.h"
#include "pros/motors.hpp"



//DRIVER CONTROL FUNCTIONS
void setIntakeMotors() {
    //bottom trigger intakes, top trigger outtakes
    int intakeVelocity = 200 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2));
    intake.move_velocity(intakeVelocity);
    
}