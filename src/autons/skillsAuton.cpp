#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/rtos.hpp"
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp"



void skills() {

    //Red Positive Corner
    chassis.setBrakeMode(MOTOR_BRAKE_BRAKE);
    chassis.setPose(72, 16, 180);
    chassis.moveToPoint(72, 24, 2000, {.forwards=false, .maxSpeed=150});
    chassis.turnToHeading(-90, 2000, {.maxSpeed=150});
    chassis.moveToPoint(96, 24, 2000, {.forwards=false, .maxSpeed=50});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    chassis.turnToHeading(0, 2000, {.maxSpeed=150});
    chassis.moveToPoint(96, 48, 2000, {.maxSpeed=150});
    chassis.turnToHeading(90, 2000, {.maxSpeed=150});
    chassis.moveToPoint(120, 48, 2000, {.maxSpeed=150});
    chassis.turnToHeading(180, 2000, {.maxSpeed=150});
    chassis.moveToPoint(120, 17, 2000, {.maxSpeed=150});
    chassis.turnToHeading(45, 2000, {.maxSpeed=150});
    chassis.moveToPoint(130, 24, 2000, {.maxSpeed=150});
    chassis.moveToPoint(130, 14, 2000, {.forwards=false, .maxSpeed=150});
    chassis.turnToHeading(-45, 2000, {.maxSpeed=150});
    chassis.waitUntilDone();
    unclamp();
    stopIntake();

    //Reset Position
    chassis.moveToPoint(130, 24, 2000, {.forwards=false, .maxSpeed=150});
    chassis.turnToHeading(90, 2000, {.maxSpeed=150});
    chassis.moveToPoint(144, 24, 2000, {.maxSpeed=150});
    chassis.setPose(135, 24, 90);

    //Red Negative Corner
    chassis.moveToPoint(48, 24, 2000, {.forwards=false, .maxSpeed=150});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    chassis.turnToHeading(0, 2000, {.maxSpeed=150});
    chassis.moveToPoint(48, 48, 2000, {.maxSpeed=150});
    chassis.turnToHeading(-90, 2000, {.maxSpeed=150});
    chassis.moveToPoint(24, 48, 2000, {.maxSpeed=150});
    chassis.turnToHeading(-25, 2000, {.maxSpeed=150});
    chassis.moveToPoint(12, 72, 2000, {.maxSpeed=150});
    chassis.moveToPoint(24, 48, 2000, {.forwards=false, .maxSpeed=150});
    chassis.turnToHeading(180, 2000, {.maxSpeed=150});
    chassis.moveToPoint(24, 17, 2000, {.maxSpeed=150});
    chassis.turnToHeading(45, 2000, {.maxSpeed=150});
    chassis.moveToPoint(14, 24, 2000, {.maxSpeed=150});
    chassis.moveToPoint(14, 14, 2000, {.forwards=false, .maxSpeed=150});
    chassis.turnToHeading(45, 2000, {.maxSpeed=150});
    chassis.waitUntilDone();
    unclamp();
    stopIntake();

    //Reset Position
    chassis.moveToPoint(24, 24, 2000, {.forwards=false, .maxSpeed=150});
    chassis.turnToHeading(180, 2000, {.maxSpeed=150});
    chassis.moveToPoint(24, 0, 2000, {.maxSpeed=150});
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
    chassis.setPose(9, 120, -90);

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


}
