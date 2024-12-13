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
        chassis.setPose(71, 18, 0);
        chassis.moveToPoint(72, 12, 500, {.forwards=false});
        spinIntake();
        chassis.moveToPoint(72, 24, 500);
        chassis.turnToHeading(-90, 500);
        chassis.moveToPoint(96, 24, 1000, {.forwards=false, .maxSpeed=50});
        chassis.waitUntilDone();
        pros::delay(500);
        clamp();
        spinIntake();
        chassis.turnToHeading(0, 500);
        chassis.moveToPoint(96, 48, 500);
        chassis.turnToHeading(45, 500);
        chassis.moveToPoint(136, 72, 1000);
        chassis.waitUntilDone();
        pros::delay(1000);
        chassis.moveToPoint(120, 72, 1000, {.forwards=false});
        chassis.turnToHeading(180, 500);
        chassis.moveToPoint(120, 12, 4000, {.maxSpeed=50});
        chassis.turnToHeading(45, 1000);
        chassis.moveToPoint(132, 24, 1000, {.maxSpeed=50});
        chassis.waitUntilDone();
        pros::delay(500);
        chassis.moveToPoint(136, 10, 500, {.forwards=false});
        chassis.waitUntilDone();
        pros::delay(1000);
        unclamp();

        //Second Section
        //Consists of Full Mogo and Corner
        chassis.moveToPoint(120, 24, 1000);
        chassis.turnToHeading(90, 1000);
        chassis.moveToPoint(48, 24, 5000, {.forwards=false, .maxSpeed=50});
        chassis.waitUntilDone();
        pros::delay(1000);
        clamp();
        chassis.turnToHeading(0, 1000);
        chassis.moveToPoint(48, 48, 1000);
        chassis.turnToHeading(-45, 1000);
        chassis.moveToPoint(12, 72, 1000);
        pros::delay(1000);
        chassis.moveToPoint(24, 72, 1000, {.forwards=false});
        chassis.turnToHeading(180, 1000);
        chassis.moveToPoint(24, 12, 4000, {.maxSpeed=50});
        chassis.turnToHeading(-45, 1000);
        chassis.moveToPoint(12, 24, 1000, {.maxSpeed=50});
        chassis.moveToPoint(8, 10, 1000, {.forwards=false});
        chassis.waitUntilDone();
        pros::delay(1000);
        unclamp();


        //Third Section
        //Consists of Pushing 2 Goals into both corners and scoring on blue wall stake
        chassis.turnToHeading(0, 1000);
        chassis.moveToPoint(24, 96, 1000);
        chassis.moveToPoint(72, 130, 1000);
        stopIntake();
        chassis.moveToPoint(12, 130, 4000);
        pros::delay(1000);
        chassis.moveToPoint(132, 130, 4000, {.forwards=false});
        pros::delay(1000);
        chassis.moveToPoint(72, 120, 1000);
        chassis.turnToHeading(180, 1000);
        chassis.moveToPoint(72, 134, 1000, {.forwards=false});
        spinIntake();

        //Fun Section
        //Spin in circles
        pros::delay(4000);
        stopIntake();
        chassis.moveToPoint(72, 120, 1000);
        chassis.turnToHeading(99999, 1000000);
}