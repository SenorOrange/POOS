#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/rtos.hpp"
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp" 


void rush() {
    chassis.setBrakeMode(MOTOR_BRAKE_BRAKE);
    rotSensor.set_position(2400);
    chassis.setPose(flip * -41, 15, flip * 180);
    //chassis.turnToHeading(90, 5000);
    chassis.moveToPose(flip * -26, 67, flip * -150, 2000, {.forwards = false});
    chassis.waitUntilDone();
    clamp();
    pros::delay(800);
    spinIntake();
    chassis.moveToPose(flip * -25, 46, flip * 180, 2000, {.maxSpeed = 60});
    chassis.moveToPose(flip * -25, 36, flip * 0, 1000);
    chassis.waitUntilDone();
    pros::delay(500);
    unclamp();
    chassis.moveToPose(flip * -49, 53, flip * 90, 1500, {.forwards = false, .minSpeed = 40});
    chassis.waitUntilDone();
    pros::delay(500);
    clamp();
    pros::delay(500);
    chassis.moveToPose(flip * -50, 15, flip * -90, 2000);
    chassis.moveToPose(flip * -68, 46, flip * -90, 5000, {.maxSpeed = 60});
    
}
 