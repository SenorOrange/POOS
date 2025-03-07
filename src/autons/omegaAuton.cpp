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
    chassis.moveToPose(flip * 48, 47, flip * 180, 2500, {.forwards = false, .minSpeed = 60});
    chassis.waitUntilDone();
    ladyBrownLower();
    clamp();
    pros::delay(750);
    chassis.moveToPose(flip * 26, 62, flip * -90, 1500, {.minSpeed = 80});
    chassis.moveToPose(flip * 14, 62, flip * -90, 1000, {.minSpeed = 80});
    chassis.moveToPose(flip * 31, 36, flip * 180, 600, {.minSpeed = 80});
    chassis.moveToPose(flip * 31, 24, flip * 180, 1000, {.minSpeed = 80});
    chassis.turnToHeading(flip * 90, 750);
    chassis.moveToPose(flip * 116, 24, flip * 90, 2500);


    //Second Half
    chassis.turnToHeading(flip * -90, 750);
    chassis.waitUntilDone();
    pros::delay(500);
    unclamp();
    chassis.moveToPose(flip * 120, 24, flip * -90, 2500, {.forwards = false, .minSpeed = 70});
    chassis.waitUntilDone();
    unclamp();
    stopIntake();
    //chassis.moveToPose(flip * 110, 24, flip * -90, 1500, {.minSpeed = 60});
    chassis.moveToPose(flip * 100, 54, flip * 180, 2500, {.forwards = false, .minSpeed = 60});
    chassis.waitUntilDone();
    clamp();
    pros::delay(500);
    spinIntake();
    chassis.moveToPose(flip * 134, 48, flip * 90, 3000, {.minSpeed = 60});
    chassis.waitUntilDone();
    stopIntake();
    chassis.moveToPose(flip * 90, 51, flip * 90, 1500, {.forwards = false, .minSpeed = 100});
}