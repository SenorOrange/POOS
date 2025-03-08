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
        //Consists of Red Wall Stake, Full Mogo, Corner and 2 Ring Wall Stake
        chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
        rotSensor.set_position(2450);
        chassis.setPose(66, 16, 180);
        
        //Tune For Speed Later

        ladyBrownScore();
        pros::delay(800);
        chassis.moveToPoint(66, 20, 500, {.forwards = false});
        chassis.turnToHeading(90, 500);
        spinIntake();
        chassis.moveToPose(43, 24, 90, 1200, {.forwards = false});
        chassis.waitUntilDone();
        pros::delay(200);
        ladyBrownLower();
        clamp();
        pros::delay(200);
        chassis.turnToHeading(0, 1000);
        spinIntake();
        chassis.moveToPose(48, 54, 0, 2000, {.minSpeed = 100});
        chassis.moveToPose(24, 104, 0, 2500, {.minSpeed = 80});

        //Score Wall Stake Gonna Need Tuning
        pros::delay(900);
        ladyBrownPrime();

        chassis.moveToPose(29, 75, 0, 2000, {.forwards = false, .minSpeed = 50});
        chassis.turnToHeading(-90, 1000);
        chassis.moveToPose(9, 75, -90, 2500, {.minSpeed = 69});
        chassis.waitUntilDone();

        //Score Wall Stake Gonna Need Tuning
        ladyBrownWallStakeScore();
        pros::delay(500);

        spinIntake();
        chassis.moveToPose(21, 75, -90, 2000, {.forwards = false, .minSpeed = 40});
        ladyBrownLower();
        chassis.moveToPose(21, 10, 180, 2000, {.minSpeed = 40});
        chassis.waitUntilDone();
        pros::delay(500);
        chassis.turnToHeading(-45, 1000);
        chassis.moveToPoint(10, 32, 1500);
        chassis.moveToPose(14, 18, 45, 2000, {.forwards = false});
        chassis.waitUntilDone();
        unclamp();
        stopIntake();

        //Transition Into Second Section
        chassis.moveToPoint(24, 26, 2000, {.minSpeed = 30});
        chassis.turnToHeading(-90, 1000);
        chassis.moveToPose(98, 26, -90, 4000, {.forwards = false, .minSpeed = 60});
        chassis.waitUntilDone();
        pros::delay(500);
        clamp();
        pros::delay(800);
        spinIntake();

        //Second Section
        //Consists of Full Mogo, Corner and 2 Ring Wall Stake
        chassis.moveToPose(90, 56, 0, 2000, {.minSpeed = 100});
        chassis.moveToPose(114, 100, 0, 2500, {.minSpeed = 100});
        chassis.moveToPose(126, 124, 0, 2000, {.minSpeed = 100});
                
        //Score Wall Stake Gonna Need Tuning
        ladyBrownPrime();

        chassis.waitUntilDone();
        pros::delay(200);
        chassis.moveToPose(115, 73, 0, 2000, {.forwards = false, .minSpeed = 80});
        chassis.moveToPose(128, 73, 90, 3000);
        chassis.waitUntilDone();

        //Score Wall Stake Gonna Need Tuning
        stopIntake();
        pros::delay(150);
        ladyBrownWallStakeScore();
        pros::delay(600);
        ladyBrownPrime();
        spinIntake();
        pros::delay(600);
        stopIntake();
        ladyBrownWallStakeScore();

        pros::delay(1000);
        ladyBrownLower();
        spinIntake();
        chassis.moveToPose(112, 71, 90, 2000, {.forwards = false, .minSpeed = 60});
        chassis.moveToPose(112, 8, 180, 3500, {.minSpeed = 80});
        chassis.waitUntilDone();
        pros::delay(500);
        chassis.turnToHeading(45, 1000);
        chassis.moveToPoint(126, 32, 3000, {.minSpeed = 60});
        chassis.moveToPose(130, 14, -45, 2000, {.forwards = false});
        chassis.waitUntilDone();
        unclamp();

        //Transition Into Third Section
        chassis.moveToPoint(72, 72, 3000, {.minSpeed = 60});
        chassis.waitUntilDone();
        pros::delay(200);
        stopIntake();
        chassis.moveToPose(54, 96, -90, 3000, {.minSpeed = 60});
        chassis.waitUntilDone();
        ladyBrownPrime();
        spinIntake();

        //Third Section
        //Consists of Blue Wall Stake, Full Mogo and 2 Corners
        chassis.moveToPose(72, 120, -135, 3000, {.forwards = false, .minSpeed = 40});
        chassis.waitUntilDone();
        stopIntake();
        pros::delay(500);
        clamp();
        chassis.turnToHeading(0, 2000);
        chassis.moveToPoint(72, 124, 2000);
        chassis.waitUntilDone();
        ladyBrownScore();
        pros::delay(500);
        chassis.moveToPoint(72, 115, 2000, {.forwards = false, .minSpeed = 60});
        ladyBrownLower();
        spinIntake();
        chassis.moveToPose(48, 96, -90, 2000, {.minSpeed = 60});
        chassis.turnToHeading(-45, 2000);
        chassis.moveToPose(24, 120, 0, 2000, {.minSpeed = 60});
        chassis.moveToPose(24, 134, 0, 2000, {.minSpeed = 60});

        //Place For Maybe Adding Top Blue Ring?

        chassis.turnToHeading(135, 2000);
        chassis.moveToPose(96, 96, 90, 3000, {.minSpeed = 60});
        chassis.turnToHeading(45, 2000);
        chassis.moveToPose(120, 120, 0, 2000, {.minSpeed = 60});
        chassis.moveToPose(120, 134, 0, 2000, {.minSpeed = 60});
        chassis.turnToHeading(-90, 2000);
        chassis.moveToPose(130, 130, -90, 2000, {.forwards = false, .minSpeed = 60});
        chassis.waitUntilDone();
        unclamp();
        stopIntake();

        //Place For Maybe Adding Top Blue Ring?

        chassis.moveToPose(96, 96, -90, 3000, {.minSpeed = 60});
        chassis.moveToPose(72, 130, -90, 2000, {.minSpeed = 60});
        chassis.moveToPose(10, 130, -90, 2500, {.minSpeed = 60});
        chassis.moveToPose(48, 96, -45, 2000, {.forwards = false, .minSpeed = 60});
        ladyBrownScore();
        chassis.moveToPose(58, 58, -45, 2000, {.forwards = false, .minSpeed = 60});

}