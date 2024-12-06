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
        //Consists of Right Wall Stake, Full Mogo and Corner
        chassis.setBrakeMode(MOTOR_BRAKE_BRAKE);
        chassis.setPose(72, 16, 0);
        chassis.moveToPoint(72, 10, 1000, {.forwards=false});
        spinIntake();
        chassis.moveToPoint(72, 24, 2000);
        chassis.turnToHeading(-90, 2000, {.maxSpeed=150});
        chassis.moveToPoint(96, 24, 2000, {.forwards=false, .maxSpeed=50});
        chassis.waitUntilDone();
        pros::delay(1000);
        clamp();
        spinIntake();
        chassis.turnToHeading(0, 1000);
        chassis.moveToPoint(96, 48, 1000);
        chassis.turnToHeading(45, 1000);
        chassis.moveToPoint(110, 72, 1000);
        chassis.waitUntilDone();
        chassis.moveToPoint(120, 96, 1000);
        chassis.moveToPoint(110, 86, 1000, {.forwards=false});
        stopIntake();
        chassis.moveToPoint(120, 72, 1000);
        chassis.turnToHeading(90, 1000);
        chassis.waitUntilDone();
        spinIntake();
        pros::delay(1000);
        chassis.moveToPoint(120, 72, 1000, {.forwards=false});
        chassis.turnToHeading(180, 1000);
        chassis.waitUntilDone();
        chassis.moveToPoint(120, 16, 1000);
        chassis.moveToPoint(132, 24, 1000);
        chassis.moveToPoint(144, 0, 1000, {.forwards=false, .maxSpeed=150});

        chassis.waitUntilDone();
        unclamp();
        stopIntake();
        
        //Second Section
        //Consists of Blue Goal in Corner and Half Fill Empty Mogo
        chassis.moveToPoint(108, 120, 1000, {.forwards=false});
        chassis.turnToHeading(135, 1000);
        chassis.moveToPoint(96, 132, 1000, {.forwards=false, .maxSpeed=150});
        chassis.waitUntilDone();
        pros::delay(1000);
        clamp();
        chassis.moveToPoint(120, 132, 1000);
        chassis.waitUntilDone();
        lowerDoinker();
        chassis.turnToHeading(180, 1000);
        pros::delay(1000);
        raiseDoinker();
        chassis.turnToHeading(-90, 1000);
        chassis.moveToPoint(132, 132, 1000, {.forwards=false});
        chassis.waitUntilDone();
        unclamp();
        chassis.moveToPoint(96, 120, 1000, {.forwards=false, .maxSpeed=150});
        chassis.waitUntilDone();
        pros::delay(1000);
        clamp();
        spinIntake();
        chassis.moveToPoint(96, 96, 1000);
        chassis.turnToHeading(135, 1000);


        //Third Section
        //Consists of Traveling Under Tower, Filling Up Mogo, Corner, Pick Up Empty Mogo and Score Left Wall Stake
        chassis.moveToPoint(48, 48, 1000);
        chassis.turnToHeading(-90, 1000);
        chassis.moveToPoint(24, 48, 1000);
        chassis.turnToHeading(180, 1000);
        chassis.moveToPoint(24, 16, 1000);
        chassis.turnToHeading(-45, 1000);
        chassis.waitUntilDone();
        pros::delay(1000);
        ladyBrownPrime();
        chassis.moveToPoint(12, 24, 1000);
        chassis.moveToPoint(12, 12, 1000, {.forwards=false});
        chassis.waitUntilDone();
        unclamp();
        stopIntake();
        chassis.moveToPoint(48, 24, 1000, {.forwards=false, .maxSpeed=150});
        chassis.waitUntilDone();
        pros::delay(1000);
        clamp();
        chassis.moveToPoint(24, 72, 1000);
        chassis.turnToHeading(-90, 1000);
        chassis.moveToPoint(0, 72, 1000);
        chassis.waitUntilDone();
        ladyBrownScore();
        spinIntake();


        //Final Section
        //Consists of Filling Up Final Mogo and Putting it in the corner
        chassis.moveToPoint(24, 96, 1000);
        chassis.turnToHeading(90, 1000);
        ladyBrownLower();
        chassis.moveToPoint(48, 96, 1000);
        chassis.turnToHeading(-45, 1000);
        chassis.moveToPoint(24, 120, 1000);
        chassis.turnToHeading(0, 1000);
        chassis.moveToPoint(24, 132, 1000);
        chassis.turnToHeading(-135, 1000);
        chassis.moveToPoint(12, 120, 1000);
        chassis.moveToPoint(12, 132, 1000);
        chassis.waitUntilDone();
        lowerDoinker();
        chassis.turnToHeading(90, 1000);
        pros::delay(1000);
        raiseDoinker();
        chassis.moveToPoint(12, 132, 1000, {.forwards=false});
        chassis.waitUntilDone();
        unclamp();

}

//Old Version of Skills
/*//Red Positive Corner
    chassis.setBrakeMode(MOTOR_BRAKE_BRAKE);
    chassis.setPose(72, 16, 180);
    chassis.moveToPoint(72, 24, 2000, {.forwards=false, .maxSpeed=150});
    chassis.turnToHeading(-90, 2000, {.maxSpeed=150});
    chassis.moveToPoint(96, 24, 2000, {.forwards=false, .maxSpeed=50});
    chassis.waitUntilDone();
    pros::delay(1000);
    clamp();
    spinIntake();
    chassis.turnToHeading(0, 2000, {.maxSpeed=150});
    chassis.moveToPoint(96, 48, 2000, {.maxSpeed=150});
        pros::delay(1000);

    chassis.turnToHeading(90, 2000, {.maxSpeed=150});
    chassis.moveToPoint(120, 54, 2000, {.maxSpeed=150});
        pros::delay(1000);

    chassis.turnToHeading(180, 2000, {.maxSpeed=150});
    chassis.moveToPoint(120, 17, 2000, {.maxSpeed=150});
        pros::delay(1000);

    chassis.turnToHeading(45, 2000, {.maxSpeed=150});
    chassis.moveToPoint(130, 24, 2000, {.maxSpeed=150});
        pros::delay(1000);

    chassis.moveToPoint(130, 14, 2000, {.forwards=false, .maxSpeed=150});
    chassis.turnToHeading(-45, 2000, {.maxSpeed=150});
    chassis.waitUntilDone();
    unclamp();
    stopIntake();

    //Reset Position
    chassis.moveToPoint(130, 24, 2000, {.forwards=false, .maxSpeed=150});
    chassis.turnToHeading(90, 2000, {.maxSpeed=150});
    chassis.moveToPoint(150, 24, 2000, {.maxSpeed=150});
    chassis.setPose(135, 24, 90);

    //Red Negative Corner
    chassis.moveToPoint(48, 24, 2000, {.forwards=false, .maxSpeed=150});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    chassis.turnToHeading(0, 2000, {.maxSpeed=150});
    chassis.moveToPoint(48, 48, 2000, {.maxSpeed=150});
            pros::delay(1000);

    chassis.turnToHeading(-90, 2000, {.maxSpeed=150});
    chassis.moveToPoint(24, 48, 2000, {.maxSpeed=150});
            pros::delay(1000);

    chassis.turnToHeading(-25, 2000, {.maxSpeed=150});
    chassis.moveToPoint(12, 72, 2000, {.maxSpeed=150});
            pros::delay(1000);

    chassis.moveToPoint(24, 48, 2000, {.forwards=false, .maxSpeed=150});
            pros::delay(1000);

    chassis.turnToHeading(180, 2000, {.maxSpeed=150});
    
    chassis.moveToPoint(24, 17, 2000, {.maxSpeed=150});
            pros::delay(1000);

    chassis.turnToHeading(45, 2000, {.maxSpeed=150});
    chassis.moveToPoint(14, 24, 2000, {.maxSpeed=150});
            pros::delay(1000);

    chassis.moveToPoint(14, 14, 2000, {.forwards=false, .maxSpeed=150});
    chassis.turnToHeading(45, 2000, {.maxSpeed=150});
    chassis.waitUntilDone();
    unclamp();
    stopIntake();

    //Reset Position
    chassis.moveToPoint(24, 24, 2000, {.forwards=false, .maxSpeed=150});
    chassis.turnToHeading(180, 2000, {.maxSpeed=150});
    chassis.moveToPoint(24, -6, 2000, {.maxSpeed=150});
    chassis.setPose(24, 9, 180);

    //Blue Negative Corner
    spinIntake();
    chassis.moveToPoint(24, 96, 2000, {.maxSpeed=150});
    stopIntake();
    chassis.turnToHeading(90, 2000, {.maxSpeed=150});
    spinIntake();
    chassis.moveToPoint(48, 96, 2000, {.maxSpeed=150});
    stopIntake();
    chassis.turnToHeading(33, 2000, {.maxSpeed=150});
    chassis.moveToPoint(60, 132, 2000, {.maxSpeed=150});
    chassis.moveToPoint(0, 144, 2000, {.maxSpeed=150});

    //Reset Position
    chassis.moveToPoint(24, 120, 2000, {.forwards=false, .maxSpeed=150});
    chassis.turnToHeading(-90, 2000, {.maxSpeed=150});
    chassis.moveToPoint(0, 120, 2000, {.maxSpeed=150});
    chassis.setPose(3, 120, -90);

    //Blue Positive Corner
    chassis.moveToPoint(72, 120, 2000, {.forwards=false, .maxSpeed=150});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    pros::delay(5000);
    chassis.turnToHeading(135, 2000, {.maxSpeed=150});
    chassis.moveToPoint(96, 96, 2000, {.maxSpeed=150});
    chassis.turnToHeading(45, 2000, {.maxSpeed=150});
    chassis.moveToPoint(120, 96, 2000, {.maxSpeed=150});
    chassis.turnToHeading(25, 2000, {.maxSpeed=150});
    chassis.moveToPoint(132, 72, 2000, {.maxSpeed=150});
    chassis.turnToHeading(0, 2000, {.maxSpeed=150});
    chassis.moveToPoint(132, 120, 2000, {.maxSpeed=150});
*/