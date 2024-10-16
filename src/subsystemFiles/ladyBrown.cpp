#include "main.h"
#include "pros/misc.h"
#include "pros/motors.hpp"

//DRIVER CONTROL FUNCTIONS
void setLadyBrown() {

    //SCORE POSITION (A)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {

        ladyBrown.move_absolute(100, 200);
        }

    //DOWN POSITION (Left)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {

        ladyBrown.move_absolute(0, 200);
        }

    //PRIME POSITION (R2)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {

        ladyBrown.move_absolute(50, 200);
        }
}