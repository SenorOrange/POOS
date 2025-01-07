#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/rtos.hpp"
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp"
#include "subsystemHeaders/doinker.hpp"


bool x = false;

// Async task for intake pause logic
void intakePauseTask() {
    while (true) {
        // Check the hue for a blue ring
        int hue = colorSensor.get_hue();
        if (hue >= ringHueMin && hue <= ringHueMax) { 
            if (x) {
                // If intake is running, pause and then resume
                pros::delay(50);
                HookStage.move_velocity(0);   // Stop intake
                PreRoller.move_velocity(0);
                pros::delay(300);          // Pause for 300ms
                HookStage.move_velocity(600); // Resume previous speed
                PreRoller.move_velocity(600);
            }
        }
        pros::delay(20); // Short delay to avoid excessive CPU usage
    }
}

//DRIVER CONTROL FUNCTIONS
void setIntakeMotors() {

    //FORWARD INTAKE ON/OFF (R1)
    if (colorSensor.get_hue() < 10){
        HookStage.move_velocity(0);
        PreRoller.move_velocity(0);
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        // Wait for R1 to be released to avoid multiple state changes on one press
        while (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            pros::delay(20);
        }

        if (x == true) {

            HookStage.move_velocity(0);
            PreRoller.move_velocity(0);

        } else {
            HookStage.move_velocity(600);
            PreRoller.move_velocity(600);
        }

        x = !x;

    }

    //REVERSE INTAKE (L1)
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
        // Wait for R1 to be released to avoid multiple state changes on one press
        while (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
            pros::delay(20);
        }

        if (x == true) {

            HookStage.move_velocity(0);
            PreRoller.move_velocity(0);
        } else {
            HookStage.move_velocity(-600);
            PreRoller.move_velocity(-600);
        }

        x = !x;

        }
    
    
}


//AUTON FUNCTIONS

void spinIntake() {
    HookStage.move_velocity(600);
    PreRoller.move_velocity(600);   
    x = true;
}

void stopIntake() {
    HookStage.move_velocity(0);
    PreRoller.move_velocity(0);
    x = false;
}

void reverseIntake() {
    HookStage.move_velocity(-600);
    PreRoller.move_velocity(-600);
    x = true;
}