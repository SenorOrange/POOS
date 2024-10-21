#include "main.h"
#include "pros/misc.h"
#include "pros/motors.hpp"


//DRIVER CONTROL FUNCTIONS
void setLadyBrown() {

    //SCORE POSITION (A)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {

        ladyBrown.move_absolute(900, 200);

        }

    //DOWN POSITION (Left)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {

        ladyBrown.move_absolute(0, 200);

        }

    //PRIME POSITION (R2)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {

        ladyBrown.move_absolute(250, 200);

        }
}

//MOTOR POSITION
void displayMotorPosition() {
    while (true) {
        // Get the motor position in ticks (degrees)
        double position = ladyBrown.get_position();

        // Clear the screen
        pros::lcd::clear();

        // Print the motor position to the LCD screen
        pros::lcd::print(5, "Motor position: %.2f ticks", position);

        // Delay to prevent excessive CPU usage (refresh every 100ms)
        pros::delay(100);
    }
}