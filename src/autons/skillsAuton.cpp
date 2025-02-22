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
        chassis.setBrakeMode(MOTOR_BRAKE_BRAKE);
        chassis.setPose(72, 11, 0);
        spinIntake();
        pros::delay(1000);
        chassis.moveToPose(72, 24, 0, 500);
        chassis.moveToPose(44, 24, 90, 4000, {.forwards = false, .maxSpeed = 40});
        chassis.waitUntilDone();
        clamp();
        chassis.moveToPose(48, 50, 0, 2000);
        chassis.moveToPose(22, 48, -90, 2000);
        chassis.moveToPose(24, 11, 180, 3500, {.maxSpeed = 70});
        chassis.moveToPose(11, 24, -45, 1000);
        chassis.moveToPose(14, 14, 45, 2000, {.forwards = false});
        chassis.waitUntilDone();
        unclamp();
        stopIntake();
        chassis.moveToPose(100, 24, -90, 6000, {.forwards = false, .maxSpeed = 40});
        chassis.waitUntilDone();
        clamp();
        spinIntake();
        chassis.moveToPose(96, 50, 0, 2000);
        chassis.moveToPose(122, 48, 90, 2000);
        chassis.moveToPose(120, 11, 180, 3500, {.maxSpeed = 70});
        chassis.moveToPose(133, 24, 45, 1000);
        chassis.moveToPose(130, 14, 45, 2000, {.forwards = false});
        chassis.waitUntilDone();
        unclamp();
        chassis.moveToPose(120, 98, 0, 5000);
        pros::delay(500);
        stopIntake();
        chassis.moveToPose(72, 120, 135, 5000, {.forwards = false});
        chassis.waitUntilDone();
        clamp();
        spinIntake();
        chassis.moveToPose(30, 96, -90, 2500);
        chassis.waitUntilDone();
        chassis.moveToPose(18, 128, 135, 2000, {.forwards = false});
        chassis.waitUntilDone();
        unclamp();
        stopIntake();
        chassis.moveToPose(92, 128, 45, 5000);
        chassis.moveToPose(130, 130, 45, 5000);
        chassis.moveToPose(96, 96, 0, 2000);

        
}