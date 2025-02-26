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
        chassis.setPose(59, 15, 90);
        
        //Tune For Speed Later
        chassis.moveToPose(67, 8,135, 1500, {.maxSpeed = 60});
        chassis.waitUntilDone();
        ladyBrownScore();
        pros::delay(1000);
        spinIntake();
        chassis.moveToPose(48, 24, 135, 1000, {.forwards = false});
        chassis.waitUntilDone();
        clamp();
        spinIntake();
        chassis.moveToPose(48, 50, -30,1500);
        chassis.moveToPose(24, 96, 0, 2000);
        chassis.moveToPose(12, 120, 0, 2000);
        pros::delay(500);
        ladyBrownPrime();
        chassis.moveToPose(12, 72, -90, 2000);
        pros::delay(500);
        ladyBrownIdle();
        chassis.waitUntilDone();
        ladyBrownScore();
        pros::delay(200);
        ladyBrownPrime();
        pros::delay(200);
        ladyBrownScore();
        chassis.moveToPose(24, 11, 180, 3500);
        chassis.moveToPose(11, 24, -45, 1000);
        chassis.moveToPose(14, 14, 45, 2000, {.forwards = false});
        chassis.waitUntilDone();
        unclamp();

}