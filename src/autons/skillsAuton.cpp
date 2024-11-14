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
    chassis.setPose(0, 0, 0);

    //Red Negative Section
    chassis.moveToPoint(0, -24, 1000, {.forwards=false});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    chassis.moveToPoint(0, -48, 1000);
    chassis.moveToPose(24, -48, 90, 1000);
    chassis.moveToPose(24, -15, 180, 1000);
    chassis.moveToPose(30, -24, 45, 1000);
    chassis.moveToPose(35, 0, 135, 1000, {.forwards=false});
    chassis.waitUntilDone();
    unclamp();
    stopIntake();

    //Red Positive Section
    chassis.moveToPose(-48, -24, 90, 1000, {.forwards=false});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    chassis.moveToPose(-48, -48, 0, 1000);
    chassis.moveToPose(-65, -48, 90, 1000);
    chassis.moveToPose(-65, -15, 180, 1000);
    chassis.moveToPose(-70, -24, 45, 1000);
    chassis.moveToPose(-75, 0, 135, 1000, {.forwards=false});
    chassis.waitUntilDone();
    unclamp();
    stopIntake();
    chassis.moveToPose(-70, -70, 0, 1000);

    //Blue Positive Section
    chassis.setPose(0, 0, 0);
    ladyBrownPrime();
    spinIntake();
    pros::delay(1000);
    reverseIntake();
    pros::delay(100);
    stopIntake();
    chassis.turnToHeading(90, 1000);
    chassis.waitUntilDone();
    ladyBrownScore();
    chassis.moveToPoint(5, 0, 1000);
    chassis.moveToPoint(0, 0, 1000);
    chassis.moveToPose(-30, 50, 30, 1000, {.forwards=false});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    chassis.moveToPose(-30, 25, 180, 1000);
    chassis.moveToPose(-10, 25, 90, 1000);
    chassis.moveToPose(-10, 80, 0, 1000);
    chassis.moveToPose(0, 75, 135, 1000);
    chassis.moveToPose(5, 80, 45, 1000, {.forwards=false});
    chassis.waitUntilDone();
    unclamp();
    stopIntake();
}
