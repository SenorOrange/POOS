#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/rtos.hpp"
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp" 


void rush() {
    chassis.setBrakeMode(MOTOR_BRAKE_BRAKE);
    rotSensor.set_position(2400);
    chassis.setPose(flip * -41, 20, 20);
    //chassis.turnToHeading(90, 5000);
    chassis.moveToPose(flip * -26, 55, 20, 2000, {.minSpeed = 600});
    pros::delay(500);
    ladyBrownScore();
    chassis.waitUntilDone();
    chassis.moveToPose(flip * -48, 47, 90, 1500, {.forwards = false, .minSpeed = 40});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    chassis.moveToPose(flip * -16, 48, 90, 2000);
    chassis.waitUntilDone();
    chassis.moveToPose(flip * -11, 1, 135, 3000);
    stopIntake();
    ladyBrownPrime();
    pros::delay(500);
    HookStage.move_velocity(-600);
    pros::delay(550);
    HookStage.move_velocity(0);
    ladyBrownLower();
    spinIntake();
    
    //Quals Bit
    if (Quals == true) {
        chassis.moveToPose(flip * 52, 52, -45, 2000);
    }

    //Elims Bit
    else if (Elims == true) {

    }
}
 