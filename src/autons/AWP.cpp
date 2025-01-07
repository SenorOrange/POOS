#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp"



void AWP() {
    chassis.setBrakeMode(MOTOR_BRAKE_BRAKE);
    chassis.setPose(flip * 64, 16, 180);
    chassis.moveToPoint(flip * 48, 44, 1000, {.forwards=false}); 
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    pros::delay(1000);
    chassis.turnToHeading(flip * -100, 1000);
    chassis.moveToPoint(flip * 24, 48, 1000);
    pros::delay(2000);
    chassis.turnToHeading(flip * -5, 1000);
    chassis.moveToPoint(flip * 22, 65, 1000);
    chassis.moveToPoint(flip * 24, 48, 1000, {.forwards=false});
    chassis.turnToHeading(flip * 5, 1000);
    chassis.moveToPoint(flip * 26, 65, 1000);
    chassis.moveToPoint(flip * 24, 24, 1000, {.forwards=false});
    chassis.waitUntilDone();
    unclamp();
    stopIntake();
    chassis.turnToHeading(flip * -135, 1000);
    chassis.moveToPoint(flip * 80, 31, 1000, {.forwards=false});
    chassis.moveToPoint(flip * 96, 48, 1000, {.forwards=false});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    chassis.turnToHeading(flip * 90, 1000);
    chassis.moveToPoint(flip * 120, 48, 1000);
    chassis.turnToHeading(flip * 135, 1000);
    chassis.moveToPoint(flip * 72, 72, 1000, {.forwards=false});

    //Potential Fix
    //chassis.moveToPoint(flip * 79, 65, 1000, {.forwards=false});

    stopIntake();
}
