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
    rotSensor.set_position(2400);
    chassis.setPose(flip * 48, 20, flip * 180);
    chassis.moveToPose(flip * 48, 47, flip * 180, 2000, {.forwards = false, .minSpeed = 60});
    ladyBrownIdle();
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    pros::delay(200);
    chassis.moveToPose(flip * 31, 66, flip * -30, 2000, {.minSpeed = 60});
    chassis.swingToHeading(180, DriveSide::LEFT, 1000);
    chassis.moveToPose(flip * 24, 24, flip * -135, 2000);

    //Score alliance stake
    chassis.moveToPose(flip * 62, 16, flip * 135, 5000, {.minSpeed = 60});
    ladyBrownScore();
    chassis.moveToPose(flip * 72, 24, flip * 90, 2000);

    //Quals Bit
    if (Quals == true) {
        chassis.moveToPose(flip * 72, 40, flip * 0, 2000);
    }

    //Elims Bit
    else if (Elims == true) {
        chassis.moveToPose(flip * 100, 24, flip * 70, 2000);
    }

}