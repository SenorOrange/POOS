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
void cornerSAWP() {
    chassis.setBrakeMode(MOTOR_BRAKE_BRAKE);
    chassis.setPose(flip * 48, 14, 180);
    chassis.moveToPoint(flip * 48, 20, 100, {.forwards=false});
    chassis.turnToHeading(flip * -90, 1000);
    chassis.moveToPoint(flip * 72, 20, 1000, {.forwards=false});
    chassis.turnToHeading(flip * 0, 1000);
    chassis.moveToPoint(flip * 72, 10, 1000, {.forwards=false});
    pros::delay(80);
    spinIntake();
    chassis.moveToPoint(flip * 72, 24, 1000);
    chassis.turnToHeading(flip * 135, 1000);
    stopIntake();
    chassis.moveToPoint(flip * 48, 48, 2000, {.forwards=false, .maxSpeed=50});
    chassis.waitUntilDone();
    pros::delay(500);
    clamp();
    spinIntake();
    pros::delay(1000);
    chassis.turnToHeading(flip * -90, 500);
    chassis.moveToPoint(flip * 20, 48, 500);
    chassis.turnToHeading(flip * 180, 500);
    
    /*
    //If on red minus & blue plus
    //For Clearing Corner
    if (flip == 1) {
        chassis.waitUntilDone();
        chassis.moveToPoint(flip * 20, 14, 500);
        chassis.turnToHeading(flip * -100, 500);
        chassis.waitUntilDone();
        pros::delay(500);
        lowerDoinker();
        pros::delay(500);
        chassis.turnToHeading(0, 500);
        pros::delay(500);
        raiseDoinker();
        //chassis.moveToPoint(flip * 10, 10, 500);
    }

    //If on blue minus & red plus
    //For Clearing Corner
    if (flip == -1) {
        chassis.waitUntilDone();
        chassis.moveToPoint(flip * 9, 16, 500);
        //chassis.turnToHeading(flip * -135, 1000);
        chassis.waitUntilDone();
        pros::delay(500);
        lowerDoinker();
        chassis.turnToHeading(-90, 500);
        pros::delay(500);
        raiseDoinker();
    }*/
    chassis.turnToHeading(flip * 45, 500);
    chassis.moveToPoint(flip * 68, 68, 2000, {.maxSpeed=50});
    pros::delay(1000);
    //stopIntake();
}
