#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/rtos.hpp"
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp"
#include "subsystemHeaders/doinker.hpp"


//Code for the minus side but really just code for all the basic 4 corner autons.
void minusSide() {
    chassis.setBrakeMode(MOTOR_BRAKE_BRAKE);
    chassis.setPose(flip * 48, 16, 180);
    chassis.moveToPoint(flip * 48, 38, 1000, {.forwards=false, .maxSpeed=150});
    chassis.waitUntilDone();
    pros::delay(1000);
    clamp();
    spinIntake();
    pros::delay(1000);
    chassis.turnToHeading(flip * -90, 1000);
    chassis.moveToPoint(flip * 24, 48, 1000);
    chassis.turnToHeading(flip * 180, 1000);
    chassis.moveToPoint(flip * 18, 18, 1000);
    chassis.turnToHeading(flip * -135, 1000);
    chassis.waitUntilDone();
    pros::delay(1000);
    lowerDoinker();

    //If on red minus & blue plus
    //For Clearing Corner
    if (flip == 1) {
        chassis.turnToHeading(0, 1000);
        pros::delay(1000);
        chassis.turnToHeading(-135, 1000);
    }

    //If on blue minus & red plus
    //For Clearing Corner
    if (flip == -1) {
        chassis.turnToHeading(-90, 1000);
        pros::delay(1000);
        chassis.turnToHeading(135, 1000);
    }
    
    chassis.waitUntilDone();
    raiseDoinker();
    chassis.moveToPoint(flip * 14, 14, 1000);
    pros::delay(1000);
    stopIntake();
    chassis.turnToHeading(flip * 45, 1000);
    chassis.moveToPoint(flip * 72, 48, 1000, {.maxSpeed=150});
}
