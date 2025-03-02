#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/rtos.hpp"
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp"
#include "subsystemHeaders/doinker.hpp"



void skills() {

        //First Section
        //Consists of Red Wall Stake, Full Mogo and Corner
        chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
        rotSensor.set_position(2450);
        chassis.setPose(57, 16, 90);
        
        //Tune For Speed Later
        chassis.moveToPose(67, 8, 135, 1500);
        chassis.waitUntilDone();
        ladyBrownScore();
        pros::delay(1000);
        spinIntake();
        chassis.moveToPose(46, 26, 135, 1000, {.forwards = false});
        chassis.waitUntilDone();
        pros::delay(500);
        ladyBrownLower();
        clamp();
        spinIntake();
        chassis.moveToPose(46, 54, 0, 2000, {.minSpeed = 40});
        chassis.moveToPose(22, 100, 0, 2500, {.minSpeed = 60});
        chassis.moveToPose(9, 122, 0, 2000, {.minSpeed = 60});
        chassis.waitUntilDone();
        pros::delay(200);
        chassis.moveToPose(24, 74, 0, 2000, {.forwards = false, .minSpeed = 60});
        chassis.moveToPose(2, 74, -90, 3000);
        chassis.waitUntilDone();
        pros::delay(1000);
        chassis.moveToPose(22, 9, 180, 3500, {.minSpeed = 60});
        chassis.moveToPose(2, 28, -45, 3000, {.minSpeed = 60});
        chassis.moveToPose(10, 14, 45, 2000, {.forwards = false});
        chassis.waitUntilDone();
        unclamp();

        //Second Part
        chassis.moveToPose(24, 24, 90, 1500);
        chassis.moveToPose(94, 24, -90, 4000, {.forwards = false});



}