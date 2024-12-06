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
    chassis.turnToHeading(flip * -90, 2000);
    chassis.moveToPoint(flip * 72, 16, 2000, {.forwards=false});
    chassis.turnToHeading(flip * 0, 2000);
    chassis.moveToPoint(flip * 72, 10, 2000, {.forwards=false});
    spinIntake();
    chassis.moveToPoint(flip * 72, 24, 2000);
    chassis.turnToHeading(flip * 135, 2000);
    stopIntake();
    chassis.moveToPoint(flip * 48, 48, 4000, {.forwards=false, .maxSpeed=50});
    chassis.waitUntilDone();
    pros::delay(1000);
    clamp();
    spinIntake();
    pros::delay(1000);
    chassis.turnToHeading(flip * -90, 1000);
    chassis.moveToPoint(flip * 20, 48, 1000);
    chassis.turnToHeading(flip * 180, 1000);
    

    //If on red minus & blue plus
    //For Clearing Corner
    if (flip == 1) {
        chassis.moveToPoint(flip * 12, 12, 1000);
        chassis.turnToHeading(flip * -100, 1000);
        chassis.waitUntilDone();
        pros::delay(2000);
        lowerDoinker();
        chassis.turnToHeading(0, 1000);
        pros::delay(1000);
        chassis.turnToHeading(-135, 1000);
    }

    //If on blue minus & red plus
    //For Clearing Corner
    if (flip == -1) {
        chassis.moveToPoint(flip * 18, 14, 1000);
        chassis.turnToHeading(flip * -135, 1000);
        chassis.waitUntilDone();
        pros::delay(1000);
        lowerDoinker();
        chassis.turnToHeading(-90, 1000);
        pros::delay(1000);
        chassis.turnToHeading(135, 1000);
    }
    
    chassis.waitUntilDone();
    raiseDoinker();
    chassis.moveToPoint(flip * 5, 5, 1000);
    pros::delay(1000);
    stopIntake();
    chassis.turnToHeading(flip * 45, 1000);
    chassis.moveToPoint(flip * 68, 48, 2000, {.maxSpeed=50});
}
