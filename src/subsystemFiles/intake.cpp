#include "main.h"
#include "pros/misc.h"
#include "pros/motors.hpp"

bool x = false;

//DRIVER CONTROL FUNCTIONS
void setIntakeMotors() {

    //FORWARD INTAKE ON/OFF (R1)

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        // Wait for R1 to be released to avoid multiple state changes on one press
        while (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            pros::delay(20);
        }

   

        if (x == true) {
            intake.move_velocity(0);
        } else {
            intake.move_velocity(200);
        }

        x = !x;

    }

    //REVERSE INTAKE (L1)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        

        intake.move_velocity(-200);

        x =!x;
        }
    
    
}