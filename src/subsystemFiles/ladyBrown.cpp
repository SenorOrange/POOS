#include "main.h"
#include "pros/misc.h"
#include "pros/motors.hpp"

bool primePosition = false;
bool firstRing = true;

//DRIVER CONTROL FUNCTIONS
void setLadyBrown() {

    //SCORE POSITION (A)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {

        ladyBrown.move_absolute(820, 200);
        primePosition = false;
        firstRing = true;

        }

    //DOWN POSITION (Left)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        
        ladyBrown.move_absolute(0, 200);
        primePosition = false;
        firstRing = true;

        }

    //PRIME POSITION (R2)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {

        while (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
            pros::delay(20);
        }

        if (firstRing == true) {
            ladyBrown.move_absolute(265, 200);
            firstRing = true;
        } /*else {
            ladyBrown.move_absolute(280, 150);
            firstRing = true;
        }*/

        primePosition = true;
        

        }
}

//MOTOR POSITION
/*void displayMotorPosition() {
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
}*/

//AUTON FUNCTIONS
void raiseLadyBrown() {
    ladyBrown.move_absolute(700, 200);
}

void allianceStakePosition() {
    ladyBrown.move_absolute(260, 200);
}

void allianceScorePosition() {
    ladyBrown.move_absolute(700, 200);
}

//SKILLS FUNCTIONS
void ladyBrownLower() {
    ladyBrown.move_absolute(0, 200);
}

void ladyBrownPrime() {
    ladyBrown.move_absolute(260, 200);
}

void ladyBrownScore() {
    ladyBrown.move_absolute(820, 200);
}