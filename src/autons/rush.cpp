#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "subsystemHeaders/globals.hpp"


void rush() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, -42, 1000, {.forwards=false});
    chassis.turnToHeading(30, 1000);
    chassis.moveToPose(-13, -60, 30, 5000, {.forwards=false});
    pros::delay(1000);
    clamp();
    chassis.moveToPose(-15, -40, 110, 1000);
    pros::delay(1000);
    spinIntake();
    chassis.moveToPoint(-15, -22, 1000);

}
