#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/rtos.hpp"
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp"
#include "subsystemHeaders/doinker.hpp"

void ringRush() {
    //Ring Sort Test
    ringHueMin = BlueMin;
    ringHueMax = BlueMax;
    // *****

    chassis.setBrakeMode(MOTOR_BRAKE_BRAKE);
    chassis.setPose(48, 20, 180);
    chassis.moveToPose(48, 48, 180, 2000, {.forwards = false, .minSpeed = 60});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    chassis.moveToPose(30, 62, 0, 2000);
    chassis.moveToPoint(30, 54, 2000, {.forwards = false});
    chassis.moveToPose(19, 62, 0, 2000);
    chassis.moveToPoint(19, 54, 2000, {.forwards = false});
    chassis.moveToPose(24, 48, 180, 2000);
    chassis.moveToPose(16, 16, -135, 5000);
    chassis.moveToPose(56, 16, 135, 5000);
    chassis.waitUntilDone();
    ladyBrownScore();

}