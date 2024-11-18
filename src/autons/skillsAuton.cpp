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
    chassis.setPose(60, 12, 135);
    chassis.moveToPoint(47, 25, 2000, {.forwards=false});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    chassis.moveToPoint(40, 65, 2000);
    chassis.turnToHeading(-90, 1000);
    chassis.moveToPoint(23, 65, 1000);
    chassis.turnToHeading(-90, 1000);
    chassis.moveToPoint(23, 40, 2000);
    chassis.turnToHeading(180, 1000);
    pros::delay(2000);
    chassis.moveToPoint(23, 10, 2000);
    chassis.moveToPoint(0, 0, 2000, {.forwards=false});
    chassis.waitUntilDone();
    unclamp();
    stopIntake();

}
