#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp"


void rush() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, -42, 1000, {.forwards=false});
    chassis.turnToHeading(30, 1000);
    chassis.moveToPose(flip * -13, -60, 30, 1000, {.forwards=false});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    chassis.moveToPose(flip * -15, -40, 110, 1000);
    pros::delay(1000);
    chassis.waitUntilDone();
    unclamp();
    chassis.moveToPose(flip * -25, -0, 45, 1000);
    pros::delay(500);
    stopIntake();
    chassis.moveToPose(flip * 15, -40, 60, 1000, {.forwards=false});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    raiseLadyBrown();
    chassis.moveToPose(flip * -60, 60, 90, 1000, {.forwards=false});
    stopIntake();
}
 