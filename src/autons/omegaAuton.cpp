#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/rtos.hpp"
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp"
#include "subsystemHeaders/doinker.hpp"

void omegaAuton() {
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    rotSensor.set_position(2450);
    chassis.setPose(flip * 59, 15, flip * 90);

    //First Half
    chassis.moveToPose(flip * 67, 8, flip * 135, 1500, {.maxSpeed = 60});
    chassis.waitUntilDone();
    ladyBrownScore();
    pros::delay(1000);
    spinIntake();
    chassis.moveToPoint(flip * 48, 42, 3000, {.forwards = false, .maxSpeed = 60});
    chassis.waitUntilDone();
    ladyBrownLower();
    clamp();
    chassis.moveToPose(flip * 29, 66, flip * -10, 2000);
    chassis.moveToPose(flip * 25, 66, flip * -90, 2000, {.maxSpeed = 60});
    chassis.moveToPose(flip * 25, 36, flip * 180, 3000);
    chassis.moveToPose(flip * 80, 24, flip * 90, 3000);

    //Second Half
    chassis.moveToPose(flip * 120, 12, flip * -90, 2000, {.forwards = false});
    chassis.waitUntilDone();
    unclamp();
    stopIntake();
    chassis.moveToPoint(flip * 96, 24, 2000);
    chassis.moveToPose(flip * 96, 42, flip * 180, 2000, {.forwards = false, .maxSpeed = 60});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    chassis.moveToPose(flip * 122, 48, flip * 90, 2000);
    chassis.moveToPose(flip * 76, 46, flip * -90, 3000, {.maxSpeed = 60});
}