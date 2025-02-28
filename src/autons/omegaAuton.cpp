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
    chassis.setPose(flip * 59, 16, flip * 90);

    //First Half
    chassis.moveToPose(flip * 67, 8, flip * 135, 1200, {.minSpeed = 80});
    chassis.waitUntilDone();
    ladyBrownScore();
    pros::delay(500);
    spinIntake();
    chassis.moveToPose(flip * 48, 42, flip * 180, 1500, {.forwards = false, .minSpeed = 80});
    chassis.waitUntilDone();
    ladyBrownLower();
    clamp();
    pros::delay(500);
    chassis.moveToPose(flip * 26, 62, flip * -90, 1500, {.minSpeed = 80});
    chassis.moveToPose(flip * 19, 62, flip * -90, 1000, {.minSpeed = 80});
    chassis.moveToPose(flip * 31, 36, flip * 180, 1000, {.minSpeed = 80});
    chassis.moveToPose(flip * 100, 24, flip * 90, 2500, {.minSpeed = 80});

    //Second Half
    chassis.turnToHeading(flip * -90, 500);
    chassis.moveToPose(flip * 120, 12, flip * -90, 1500, {.forwards = false, .minSpeed = 150});
    chassis.waitUntilDone();
    unclamp();
    stopIntake();
    chassis.moveToPoint(flip * 96, 24, 1500, {.minSpeed = 80});
    chassis.moveToPose(flip * 96, 42, flip * 180, 1500, {.minSpeed = 80});
    chassis.waitUntilDone();
    clamp();
    pros::delay(500);
    spinIntake();
    chassis.moveToPose(flip * 122, 48, flip * 90, 1000, {.minSpeed = 80});
    chassis.moveToPose(flip * 76, 46, flip * -90, 1500, {.forwards = false});
}