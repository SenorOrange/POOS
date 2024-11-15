#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp"


void rush() {
    chassis.setPose(0, 0, 0);
    //chassis.moveToPoint(0, -32, 1000, {.forwards=false});
    chassis.moveToPose(flip * -41, -85, 45, 1000, {.forwards=false});
    chassis.waitUntilDone();
    pros::delay(1000);
    clamp();
    spinIntake();
    
    //chassis.moveToPose(flip * -42, -20, 90, 1000);
    //pros::delay(1000);
    //chassis.waitUntilDone();
    //unclamp();
    //chassis.moveToPose(flip * -25, -0, 45, 1000);
    //pros::delay(500);
    //stopIntake();
    //chassis.moveToPose(flip * 15, -40, 60, 1000, {.forwards=false});
    //chassis.waitUntilDone();
    //clamp();
    //spinIntake();
    //raiseLadyBrown();
    //chassis.moveToPose(flip * -60, 60, 90, 1000, {.forwards=false});
    //stopIntake();
}
 