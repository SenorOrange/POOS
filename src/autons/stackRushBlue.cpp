#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/rtos.hpp"
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp"
#include "subsystemHeaders/doinker.hpp"

void ringRushBlue() {

    chassis.setPose(-10, 16, 0);
    lowerDoinker();
    chassis.moveToPose(-24, 70, -35, 1000);
    pros::delay(200);
    chassis.moveToPose(-48, 48, 45, 1000);
    chassis.waitUntilDone();
    clamp();
    raiseDoinker();
    spinIntake();
    chassis.moveToPose(-24, 52, 90, 1000);
    chassis.moveToPose(-24, 48, 180, 1000);
    chassis.moveToPose(-12, 12, 135, 1000);
    chassis.moveToPose(-60, 12, -135, 1000);
    chassis.waitUntilDone();
    ladyBrownScore();
    chassis.moveToPose(-72, 36, 0, 1000);

}