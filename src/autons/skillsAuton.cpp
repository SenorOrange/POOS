#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"



void skills() {
    chassis.setPose(0, 0, 0);

    //Red Negative Section
    chassis.moveToPoint(0, -24, 1000, {.forwards=false});
    clamp();
    spinIntake();
    chassis.moveToPoint(0, -48, 1000);
    chassis.moveToPose(24, -48, 90, 1000);
    chassis.moveToPose(24, -15, 180, 1000);
    chassis.moveToPose(30, -24, 45, 1000);
    chassis.moveToPose(35, 0, 135, 1000, {.forwards=false});
    unclamp();
    stopIntake();

    //Red Positive Section
    chassis.moveToPose(-48, -24, 90, 1000, {.forwards=false});
    clamp();
    spinIntake();
    chassis.moveToPose(-48, -48, 0, 1000);
    chassis.moveToPose(-65, -48, 90, 1000);
    chassis.moveToPose(-65, -15, 180, 1000);
    chassis.moveToPose(-70, -24, 45, 1000);
    chassis.moveToPose(-75, 0, 135, 1000, {.forwards=false});
    unclamp();
    stopIntake();
}
