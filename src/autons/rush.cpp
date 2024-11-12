#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"



void rush() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, -42, 1000, {.forwards=false});
    chassis.turnToHeading(30, 1000);
    chassis.moveToPose(-13, -60, 30, 5000, {.forwards=false});
    pros::delay(1000);
    clamp();
    spinIntake();
    chassis.moveToPose(-15, -40, 110, 1000);
    pros::delay(1000);
    unclamp();
    chassis.moveToPose(-25, -0, 45, 1000);
    pros::delay(500);
    stopIntake();
    chassis.moveToPose(15, -40, 60, 1000, {.forwards=false});
    clamp();
    spinIntake();
    raiseLadyBrown();
    chassis.moveToPose(-60, 60, 90, 1000, {.forwards=false});
}
 