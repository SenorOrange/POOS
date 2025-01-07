#include "main.h"
#include "pros/misc.h"
#include "pros/motors.hpp"



//DRIVER CONTROL FUNCTIONS
void setLadyBrown() {

    //SCORE POSITION (A)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {

        while (abs(rotSensor.get_position() - 180) > 0.5) {
            
            if (rotSensor.get_position() < 180) {

                ladyBrown.move_velocity(200);
            } else if (rotSensor.get_position() > 180) {

                ladyBrown.move_velocity(-200);
            }
        }

        ladyBrown.move_velocity(0);
        
        }

    //DOWN POSITION (Left)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {

        while (abs(rotSensor.get_position() - 0) > 0.5) {
            
            if (rotSensor.get_position() < 0) {

                ladyBrown.move_velocity(200);
            } else if (rotSensor.get_position() > 0) {

                ladyBrown.move_velocity(-200);
            }
        }

        ladyBrown.move_velocity(0);
        
        }

    //PRIME POSITION (R2)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {

        while (abs(rotSensor.get_position() - 20) > 0.5) {

            if (rotSensor.get_position() < 20) {

                ladyBrown.move_velocity(200);
            } else if (rotSensor.get_position() > 20) {

                ladyBrown.move_velocity(-200);
            }
        }

        ladyBrown.move_velocity(0);
        
        }
}

void rotateLadyBrown() {
    int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    if (abs(rightY) < 10) {
        ladyBrown.move(0);
    }

    if (rotSensor.get_position() >= 200 || rotSensor.get_position() <= 0) {

        ladyBrown.move(0);
    } else {

        ladyBrown.move(rightY);
    }
}

//AUTON FUNCTIONS
void ladyBrownPrime() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {

        while (abs(rotSensor.get_position() - 20) > 0.5) {

            if (rotSensor.get_position() < 20) {

                ladyBrown.move_velocity(200);
            } else if (rotSensor.get_position() > 20) {

                ladyBrown.move_velocity(-200);
            }
        }

        ladyBrown.move_velocity(0);
        
        }
}

void ladyBrownLower() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {

        while (abs(rotSensor.get_position() - 0) > 0.5) {
            
            if (rotSensor.get_position() < 0) {

                ladyBrown.move_velocity(200);
            } else if (rotSensor.get_position() > 0) {

                ladyBrown.move_velocity(-200);
            }
        }

        ladyBrown.move_velocity(0);
        
        }
}

void ladyBrownScore() {
if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {

        while (abs(rotSensor.get_position() - 180) > 0.5) {
            
            if (rotSensor.get_position() < 180) {

                ladyBrown.move_velocity(200);
            } else if (rotSensor.get_position() > 180) {

                ladyBrown.move_velocity(-200);
            }
        }

        ladyBrown.move_velocity(0);
        
        }
}

