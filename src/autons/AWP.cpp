#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp"



void AWP() {
    chassis.setBrakeMode(MOTOR_BRAKE_BRAKE);
    chassis.setPose(flip * 48, 10, 180);
    chassis.moveToPoint(flip * 48, 46, 1000, {.forwards=false}); 
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    pros::delay(1000);
    chassis.moveToPoint(flip * 48, 56, 1000);
    chassis.turnToHeading(-90, 1000);
    chassis.moveToPoint(flip * 15, 55, 1000);
    pros::delay(2000);
    chassis.moveToPoint(flip * 28, 40, 1000);
    chassis.moveToPoint(flip* 72, 30, 1000);
}
