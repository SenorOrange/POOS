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
    chassis.setPose(flip * 55, 24, flip * 0);
    chassis.moveToPose(flip * 67, 8, flip * 135, 5000, {.maxSpeed = 60});
    pros::delay(2000);
    chassis.moveToPoint(flip  * 48, 48, 2000, {.forwards = false, .maxSpeed = 60});
    chassis.moveToPose(flip * 28, 61, flip * -30, 5000, {.maxSpeed = 60});
    chassis.moveToPose(flip * 26, 24, flip * 180, 5000, {.maxSpeed = 60});
    /*chassis.waitUntilDone();
    clamp();
    spinIntake();
    pros::delay(500);
    //chassis.moveToPose(flip * 31, 67, flip * -30, 2000, {.minSpeed = 50});
    //chassis.turnToHeading(flip * 180, 1000);
    chassis.moveToPose(flip * 18, 48, flip * 90, 3000);
    chassis.waitUntilDone();
    chassis.moveToPose(flip * 70, 48, flip * 90, 3000);
    pros::delay(1500);

    //Quals Bit
    if (Quals == true) {
        chassis.moveToPose(flip * 72, 40, flip * 0, 2000, {.maxSpeed = 50});
    }

    //Elims Bit
    if (Elims == true) {
        chassis.moveToPose(flip * 72, 24, flip * 90, 2000);
        chassis.moveToPose(flip * 100, 24, flip * 70, 2000);
    }

    //SAWP Bit
    if (SAWP == true) {
    unclamp();
    chassis.moveToPose(flip * 72, 28, flip * 0, 5000);
    stopIntake();
    chassis.moveToPose(flip * 96, 48, flip * 0, 5000, {.forwards = false, .maxSpeed = 40});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    chassis.moveToPose(flip * 80, 50, flip * 45, 5000);
    }*/
}