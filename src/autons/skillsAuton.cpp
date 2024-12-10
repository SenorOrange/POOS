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
        chassis.setPose(72, 16, 0);
        chassis.moveToPoint(72, 10, 1000, {.forwards=false});
        spinIntake();
        chassis.moveToPoint(72, 24, 500);
        chassis.turnToHeading(-90, 500, {.maxSpeed=150});
        chassis.moveToPoint(96, 24, 500, {.forwards=false, .maxSpeed=50});
        chassis.waitUntilDone();
        pros::delay(1000);
        clamp();
        spinIntake();
        chassis.turnToHeading(0, 500);
        chassis.moveToPoint(96, 48, 500);
        chassis.turnToHeading(45, 500);
        chassis.moveToPoint(132, 72, 500);
        pros::delay(1000);
        chassis.moveToPoint(120, 72, 500, {.forwards=false});
        chassis.turnToHeading(180, 500);
        chassis.moveToPoint(120, 16, 500, {.maxSpeed=50});
        chassis.turnToHeading(45, 500);
        chassis.moveToPoint(132, 24, 500, {.maxSpeed=50});
        chassis.moveToPoint(132, 12, 500, {.forwards=false});
        chassis.waitUntilDone();
        pros::delay(500);
        unclamp();

        //Second Section
        //Consists of Full Mogo and Corner
        chassis.moveToPoint(120, 24, 500, {.forwards=false});
        chassis.turnToHeading(90, 500);
        chassis.moveToPoint(48, 24, 1000, {.forwards=false, .maxSpeed=50});
        chassis.waitUntilDone();
        pros::delay(1000);
        clamp();
        chassis.turnToHeading(0, 500);
        chassis.moveToPoint(48, 48, 500);
        chassis.turnToHeading(-45, 500);
        chassis.moveToPoint(12, 72, 500);
        pros::delay(1000);
        chassis.moveToPoint(24, 72, 500, {.forwards=false});
        chassis.turnToHeading(180, 500);
        chassis.moveToPoint(24, 16, 500, {.maxSpeed=50});
        chassis.turnToHeading(-45, 500);
        chassis.moveToPoint(12, 24, 500, {.maxSpeed=50});
        chassis.moveToPoint(12, 12, 500, {.forwards=false});
        chassis.waitUntilDone();
        pros::delay(500);
        unclamp();


        //Third Section
        //Consists of Pushing 2 Goals into both corners and scoring on blue wall stake
        chassis.turnToHeading(0, 500);
        chassis.moveToPoint(24, 96, 500);
        chassis.moveToPoint(72, 132, 500);
        stopIntake();
        chassis.moveToPoint(12, 132, 500);
        pros::delay(1000);
        chassis.moveToPoint(132, 132, 500, {.forwards=false});
        pros::delay(1000);
        chassis.moveToPoint(72, 120, 500);
        chassis.turnToHeading(180, 500);
        chassis.moveToPoint(72, 134, 1000, {.forwards=false});
        spinIntake();

        //Fun Section
        //Spin in circles
        pros::delay(4000);
        stopIntake();
        chassis.moveToPoint(72, 120, 500);
        chassis.turnToHeading(99999, 1000000);
}