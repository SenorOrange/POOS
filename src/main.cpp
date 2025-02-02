#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/abstract_motor.hpp"
#include "pros/misc.h"
#include "pros/motors.h"
#include "subsystemHeaders/poos.hpp"
#include "subsystemHeaders/globals.hpp"
#include "pros/rtos.hpp"




/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */


//Competition initialize
void initialize() {
    loading();
    colorSensor.set_led_pwm(100);
    rotSensor.reset_position();
    ladyBrown.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    drawGUI();
    chassis.calibrate(); 
    
}


/**
 * Runs while the robot is disabled
 */
void disabled() {}

/**
 * runs after initialize if the robot is connected to field control
 */
void competition_initialize() {
}

// get a path used for pure pursuit
// this needs to be put outside a function
ASSET(example_txt); // '.' replaced with "_" to make c++ happy

void autonomous() {
//ringRush();
rush();
    /*if (auton == 1) {
    //cornerSAWP();
    ladyBrownScore();
    }

    //Skills
    if (auton == 2) {
    skills();
    }*/
}

// Declare the async task globally
pros::Task intakePause([] { intakePauseTask(); });

void opcontrol() {

    while (true) {
        //some code to make robot go vroom
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int leftX = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);

        chassis.arcade(leftY, leftX);

        //Make Intake Go intaky
        setIntakeMotors();

        //Clamp go pinch
        setMogoMech();

        //Moving Arms
        setLadyBrown();
        rotateLadyBrown();
        printRotSensor();

        //Doinky
        setDoinker();

        //Make Intake Fly
        //setIntakeLift();

        pros::delay(10);
    }

}