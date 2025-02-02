#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/rtos.hpp"
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp" 


void rush() {
    chassis.setBrakeMode(MOTOR_BRAKE_BRAKE);
    rotSensor.set_position(2400);
    chassis.setPose(-41, 20, 20);
    //chassis.turnToHeading(90, 5000);
    chassis.moveToPose(-26, 55, 20, 2000, {.minSpeed = 600});
    pros::delay(500);
    ladyBrownScore();
    chassis.waitUntilDone();
    chassis.moveToPose(-48, 47, 90, 1500, {.forwards = false, .minSpeed = 40});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    chassis.moveToPose(-16, 48, 90, 2000);
    chassis.waitUntilDone();
    chassis.moveToPose(-11, 1, 135, 3000);
    stopIntake();
    ladyBrownPrime();
    pros::delay(500);
    HookStage.move_velocity(-600);
    pros::delay(550);
    HookStage.move_velocity(0);
    ladyBrownLower();
    spinIntake();
    /*pros::delay(500); //needs to be tuned to lower lady brown at the right time
    ladyBrownScore();
    chassis.moveToPose(flip * 48, 48, 45 ,1000, {.forwards=false});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    chassis.moveToPose(flip * 24, 48, 90, 1000);
    chassis.moveToPose(flip * 72, 24, -90, 1000);
    ladyBrownPrime();
    intakeUp();
    chassis.waitUntilDone();
    intakeDown();
    pros::delay(500); //needs to be tuned till ring is in lady brown
    chassis.moveToPose(flip * 72, 12, 180, 1000);
    chassis.waitUntilDone();
    ladyBrownScore();

    //Code for AWP
    chassis.moveToPose(flip * 72, 40, 180, 1000);
    ladyBrownLower();

    //Code for Elims
    chassis.moveToPose(flip * 24, 24, 135, 1000);
    ladyBrownLower();
    lowerDoinker();*/
}
 