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

        //Score Wall Stake Gonna Need Tuning
        //ladyBrownPrime();

        chassis.waitUntilDone();
        pros::delay(200);
        chassis.moveToPose(24, 74, 0, 2000, {.forwards = false, .minSpeed = 60});
        chassis.moveToPose(2, 74, -90, 3000);
        chassis.waitUntilDone();

        //Score Wall Stake Gonna Need Tuning
        /*stopIntake();
        pros::delay(150);
        ladyBrownWallStakeScore();
        pros::delay(300);
        ladyBrownPrime();
        spinIntake();
        pros::delay(500);
        stopIntake();
        ladyBrownWallStakeScore();*/

        pros::delay(1000);
        //ladyBrownLower();
        chassis.moveToPose(24, 74, -90, 2000, {.forwards = false, .minSpeed = 60});
        chassis.moveToPose(24, 9, 180, 3500, {.minSpeed = 60});
        chassis.moveToPose(2, 28, -45, 3000, {.minSpeed = 60});
        chassis.moveToPose(10, 14, 45, 2000, {.forwards = false});
        chassis.waitUntilDone();
        unclamp();
        stopIntake();

        //Transition Into Second Section
        chassis.moveToPoint(24, 24, 2000, {.minSpeed = 60});
        chassis.moveToPose(96, 24, -90, 4000, {.forwards = false, .minSpeed = 40});
        chassis.waitUntilDone();
        pros::delay(500);
        clamp();
        spinIntake();

        //Second Section
        //Consists of Full Mogo, Corner and 2 Ring Wall Stake
        chassis.moveToPose(96, 54, 0, 2000, {.minSpeed = 40});
        chassis.moveToPose(120, 100, 0, 2500, {.minSpeed = 60});
        chassis.moveToPose(135, 122, 0, 2000, {.minSpeed = 60});
                
        //Score Wall Stake Gonna Need Tuning
        //ladyBrownPrime();

        chassis.waitUntilDone();
        pros::delay(200);
        chassis.moveToPose(120, 74, 0, 2000, {.forwards = false, .minSpeed = 60});
        chassis.moveToPose(142, 74, 90, 3000);
        chassis.waitUntilDone();

        //Score Wall Stake Gonna Need Tuning
        /*stopIntake();
        pros::delay(150);
        ladyBrownWallStakeScore();
        pros::delay(300);
        ladyBrownPrime();
        spinIntake();
        pros::delay(500);
        stopIntake();
        ladyBrownWallStakeScore();*/

        pros::delay(1000);
        //ladyBrownLower();
        chassis.moveToPose(120, 74, 90, 2000, {.forwards = false, .minSpeed = 60});
        chassis.moveToPose(120, 9, 180, 3500, {.minSpeed = 60});
        chassis.moveToPose(142, 28, 45, 3000, {.minSpeed = 60});
        chassis.moveToPose(134, 14, -45, 2000, {.forwards = false});
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