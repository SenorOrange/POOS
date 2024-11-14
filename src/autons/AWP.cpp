#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp"



void AWP() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPose(flip * -13, -40, 60, 1000, {.forwards=false});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    chassis.moveToPose(flip * 10, -60, 30, 1000);
    chassis.moveToPose(flip * 15, -60, 90, 1000);
    chassis.moveToPose(flip * 12, -40, 180, 1000);
    chassis.waitUntilDone();
    stopIntake();
    unclamp();
    chassis.moveToPose(flip * -65, -35, 60, 1000, {.forwards=false});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    chassis.moveToPose(flip * -75, -40, 90, 1000);
    chassis.waitUntilDone();
    raiseLadyBrown();
    chassis.moveToPose(flip * -60, -60, 90, 1000, {.forwards=false});
    stopIntake();
}
