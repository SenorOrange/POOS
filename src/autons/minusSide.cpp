#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp"


void minusSide() {
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
    raiseLadyBrown();
    //chassis.turnToHeading(flip * 135, 1000);
    chassis.turnToHeading(0, 1000);
    chassis.setPose(flip * 24, 24, 0);
    chassis.moveToPoint(flip * 72, 72, 2000, {.forwards=false});
    stopIntake();
}
