#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp" 


void rush() {
    /*chassis.setPose(flip * -10, -16, 0);
    //chassis.moveToPoint(0, -32, 1000, {.forwards=false});
    chassis.moveToPoint(flip * -10, -48, 1000, {.forwards=false});
    chassis.turnToHeading(flip * 30, 1000);
    chassis.moveToPoint(flip * -18, -63, 1000, {.forwards=false});
    chassis.waitUntilDone();
    pros::delay(1000);
    clamp();
    spinIntake();
    chassis.moveToPoint(flip * -40, -50, 1000);
    //raiseLadyBrown();
    //chassis.moveToPoint(flip * 0, -67, 1000, {.forwards=false});

    //Potential Fix
    chassis.moveToPoint(flip * -5, -67, 1000, {.forwards=false}); 
    stopIntake();*/

    chassis.setPose(flip * 10, -16, 0);
    //chassis.moveToPoint(0, -32, 1000, {.forwards=false});
    chassis.moveToPoint(flip * 10, -48, 1000, {.forwards=false});
    chassis.turnToHeading(flip * -30, 1000);
    chassis.moveToPoint(flip * 18, -63, 1000, {.forwards=false});
    chassis.waitUntilDone();
    pros::delay(1000);
    clamp();
    spinIntake();
    chassis.moveToPoint(flip * 40, -50, 1000);
    //raiseLadyBrown();
    //chassis.moveToPoint(flip * 0, -67, 1000, {.forwards=false});

    //Potential Fix
    chassis.moveToPoint(flip * 5, -67, 1000, {.forwards=false}); 
    stopIntake();
}
 