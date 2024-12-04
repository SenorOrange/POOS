#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/abstract_motor.hpp"
#include "pros/misc.h"
#include "subsystemHeaders/poos.hpp"
#include "subsystemHeaders/globals.hpp"




/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */



void initialize() {
    chassis.calibrate(); // calibrate sensors
    colorSensor.set_led_pwm(50);
    drawGUI();
}

/**
 * Runs while the robot is disabled
 */
void disabled() {}

/**
 * runs after initialize if the robot is connected to field control
 */
void competition_initialize() {
    //autonSelector();
}

// get a path used for pure pursuit
// this needs to be put outside a function
ASSET(example_txt); // '.' replaced with "_" to make c++ happy

void autonomous() {

    //Auto Win Point
    if (blueAWP == true || redAWP == true) {
    AWP();
    }

    //Mogo Rush
    if (blueRush == true || redRush == true) {
    rush();
    }

    //Basic Corners
    if (blueMinusSide == true || redMinusSide == true || bluePlusSide == true || redPlusSide == true) {
    minusSide();
    }

    //Skills
    if (skillsAuton == true) {
    skills();
    }
}

/**
 * Runs in driver control
 */
void opcontrol() {

    while (true) {
        //some code to make robot go vroom
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int leftX = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);

        chassis.curvature(leftY, leftX);

        setIntakeMotors();
        setMogoMech();
        setLadyBrown();
        setDoinker();

        pros::delay(10);
    }

}