#include "main.h"
#include "pros/misc.h"

//DRIVER CONTROL FUNCTIONS
void setLadyBrown() {

    //SCORE POSITION (R2)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && ladyBrown.get_position() < 100) {

        ladyBrown.move_absolute(100, 200);
        }

    //DOWN POSITION (L2)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && ladyBrown.get_position() > 0) {

        ladyBrown.move_absolute(0, 200);
        }

    //PRIME POSITION (A)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A) && ladyBrown.get_position() != 30) {

        ladyBrown.move_absolute(30, 200);
        }
}