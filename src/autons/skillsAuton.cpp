#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp"


//Set of Functions to put ring in lady brown mech
//ladyBrownPrime();
//spinIntake();
//pros::delay(1000);
//reverseIntake();
//pros::delay(100);
//stopIntake();


void skills() {
    chassis.setBrakeMode(MOTOR_BRAKE_BRAKE);
    chassis.setPose(72, 16, 180);
    chassis.turnToHeading(-90, 2000);
    chassis.moveToPoint(96, 24, 2000, {.forwards=false});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    chassis.turnToHeading(0, 2000);
    chassis.moveToPoint(96, 48, 2000);
    chassis.turnToHeading(90, 2000);
    chassis.moveToPoint(120, 48, 2000);
    chassis.turnToHeading(180, 2000);
    pros::delay(2000);
    chassis.moveToPoint(120, 17, 2000);
    chassis.turnToHeading(45, 2000);
    chassis.moveToPoint(130, 24, 2000);
    chassis.moveToPoint(136, 16, 2000, {.forwards=false});
    chassis.waitUntilDone();
    unclamp();
    stopIntake();

}
