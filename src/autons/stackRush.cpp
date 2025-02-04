#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp"
#include "subsystemHeaders/doinker.hpp"

void ringRush() {
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(flip * 48, 20, 180);
    chassis.moveToPose(flip * 48, 47, 180, 2000, {.forwards = false, .minSpeed = 60});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    pros::delay(200);
    chassis.moveToPose(flip * 30, 66, -30, 2000, {.minSpeed = 60});
    chassis.swingToHeading(-90, DriveSide::LEFT, 1000);
    chassis.moveToPoint(flip * 20, 66, 1000);
    chassis.swingToHeading(180, DriveSide::LEFT, 1000);
    chassis.moveToPose(flip * 24, 24, -135, 2000);

    //Score alliance stake
    chassis.moveToPose(flip * 72, 24, 135, 2000);
    chassis.moveToPose(flip * 62, 16, -135, 2000);
    ladyBrownScore();

    //Quals Bit
    if (Quals == true) {
        chassis.moveToPose(flip * 72, 40, 0, 2000);
    }

    //Elims Bit
    else if (Elims == true) {
        chassis.moveToPose(flip * 100, 24, 70, 2000);
    }

}