#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"



void AWP() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPose(-13, -40, 60, 1000, {.forwards=false});
    clamp();
    spinIntake();
    chassis.moveToPose(10, -60, 30, 1000);
    chassis.moveToPose(15, -60, 90, 1000);
    chassis.moveToPose(12, -40, 180, 1000);
    stopIntake();
    unclamp();
    chassis.moveToPose(-65, -35, 60, 1000, {.forwards=false});
    clamp();
    spinIntake();
    chassis.moveToPose(-75, -40, 90, 1000);
    raiseLadyBrown();
    chassis.moveToPose(-60, -60, 90, 1000);
}
