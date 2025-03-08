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
        chassis.moveToPose(24, 107, 0, 2500, {.minSpeed = 80});

        //Score Wall Stake Gonna Need Tuning
        pros::delay(900);
        ladyBrownPrime();

        chassis.moveToPose(29, 75, 0, 2000, {.forwards = false, .minSpeed = 50});
        chassis.turnToHeading(-90, 1000);
        chassis.moveToPose(9, 75, -90, 3000, {.minSpeed = 60});
        chassis.waitUntilDone();
        stopIntake();
        pros::delay(200);

        //Score Wall Stake Gonna Need Tuning
        ladyBrownWallStakeScore();
        pros::delay(500);

        spinIntake();
        chassis.moveToPose(24, 75, -90, 2000, {.forwards = false, .minSpeed = 40});
        ladyBrownLower();
        chassis.moveToPose(24, 8, 180, 2500, {.minSpeed = 40});
        chassis.waitUntilDone();
        pros::delay(500);
        chassis.turnToHeading(-45, 1000);
        chassis.moveToPoint(14, 33, 1500);
        chassis.moveToPose(14, 16, 45, 2000, {.forwards = false});
        chassis.waitUntilDone();
        unclamp();
        stopIntake();

        //Transition Into Second Section
        chassis.moveToPoint(24, 22, 2000, {.minSpeed = 30});
        chassis.turnToHeading(-90, 1000);
        chassis.moveToPose(80, 21, -90, 3000, {.forwards = false, .minSpeed = 60});
        chassis.moveToPose(93, 21, -90, 1000, {.forwards = false, .minSpeed = 40});
        chassis.waitUntilDone();
        clamp();
        pros::delay(1000);
        spinIntake();

        //Second Section
        //Consists of Full Mogo, Corner and 2 Ring Wall Stake
        chassis.moveToPose(92, 56, 0, 2000, {.minSpeed = 100});
        chassis.moveToPose(118, 104, 0, 2500, {.minSpeed = 80});
                
        //Score Wall Stake Gonna Need Tuning
        pros::delay(900);
        ladyBrownPrime();

        chassis.waitUntilDone();
        pros::delay(200);
        chassis.moveToPose(115, 70, 0, 2000, {.forwards = false, .minSpeed = 80});
        chassis.turnToHeading(90, 1000);
        chassis.moveToPose(132, 70, 90, 3000, {.minSpeed = 60});
        chassis.waitUntilDone();
        stopIntake();
        pros::delay(200);

        //Score Wall Stake Gonna Need Tuning
        ladyBrownWallStakeScore();
        pros::delay(500);

        ladyBrownLower();
        spinIntake();
        chassis.moveToPose(116, 70, 90, 2000, {.forwards = false, .minSpeed = 40});
        chassis.moveToPose(116, 4, 180, 2500, {.minSpeed = 40});
        chassis.waitUntilDone();
        pros::delay(500);
        chassis.turnToHeading(45, 1000);
        chassis.moveToPoint(128, 32, 1500);
        chassis.moveToPose(128, 16, -45, 2000, {.forwards = false});
        chassis.waitUntilDone();
        unclamp();

        //Transition Into Third Section
        chassis.moveToPoint(72, 66, 2000, {.minSpeed = 100});
        chassis.waitUntilDone();
        stopIntake();
        chassis.moveToPoint(54, 96, 1000, {.minSpeed = 80});
        chassis.waitUntilDone();
        ladyBrownPrime();
        spinIntake();

        //Third Section
        //Consists of Blue Wall Stake, Full Mogo and 2 Corners
        chassis.moveToPose(66, 110, -135, 1500, {.forwards = false, .minSpeed = 70});
        chassis.waitUntilDone();
        stopIntake();
        clamp();
        pros::delay(1000);
        chassis.turnToHeading(0, 1000);
        chassis.moveToPoint(66, 115, 1000, {.minSpeed = 50});
        chassis.waitUntilDone();
        ladyBrownScore();
        pros::delay(1000);
        chassis.moveToPoint(66, 115, 500, {.forwards = false, .minSpeed = 60});
        ladyBrownLower();
        spinIntake();
        chassis.moveToPose(48, 96, -90, 1000, {.minSpeed = 100});
        chassis.turnToHeading(-45, 500);
        chassis.moveToPose(24, 134, 0, 1500, {.minSpeed = 100});

        //Place For Maybe Adding Top Blue Ring?

        /*chassis.turnToHeading(135, 1000);
        chassis.moveToPose(96, 96, 90, 1000, {.minSpeed = 100});
        chassis.turnToHeading(45, 500);
        chassis.moveToPose(120, 134, 0, 1500, {.minSpeed = 100});
        chassis.turnToHeading(-90, 2000);
        chassis.moveToPose(130, 130, -90, 500, {.forwards = false, .minSpeed = 60});
        chassis.waitUntilDone();
        unclamp();
        stopIntake();

        //Place For Maybe Adding Top Blue Ring?

        chassis.moveToPose(96, 96, -90, 1500, {.minSpeed = 100});
        chassis.moveToPose(72, 130, -90, 1000, {.minSpeed = 100});
        chassis.moveToPose(10, 130, -90, 1000, {.minSpeed = 100});
        chassis.moveToPose(48, 96, -45, 1000, {.forwards = false, .minSpeed = 100});
        ladyBrownScore();
        chassis.moveToPose(58, 58, -45, 1000, {.forwards = false, .minSpeed = 100});*/

}