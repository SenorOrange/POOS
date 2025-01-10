#include "main.h"
#include "pros/misc.h"
#include "pros/motors.hpp"



//DRIVER CONTROL FUNCTIONS
void setLadyBrown() {

    //SCORE POSITION (A)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
        const double target_position = 180;
        const double deadband = 1;
        const double kP = 1.5;
        const int max_velocity = 200;

        while (std::abs(rotSensor.get_position() - target_position) > deadband) {
            // Calculate error
            double error = target_position - rotSensor.get_position();

            // Calculate velocity based on proportional control
            double velocity = kP * error;

            // Clamp velocity to maximum limits
            if (velocity > max_velocity) velocity = max_velocity;
            if (velocity < -max_velocity) velocity = -max_velocity;

            // Move the motor
            ladyBrown.move_velocity(velocity);

            pros::delay(20);
        }

        ladyBrown.move_velocity(0);
    }

    //DOWN POSITION (Left)
     if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        const double target_position = 0;
        const double deadband = 1;
        const double kP = 1.5;
        const int max_velocity = 200;

        while (std::abs(rotSensor.get_position() - target_position) > deadband) {
            // Calculate error
            double error = target_position - rotSensor.get_position();

            // Calculate velocity based on proportional control
            double velocity = kP * error;

            // Clamp velocity to maximum limits
            if (velocity > max_velocity) velocity = max_velocity;
            if (velocity < -max_velocity) velocity = -max_velocity;

            // Move the motor
            ladyBrown.move_velocity(velocity);

            pros::delay(20);
        }

        ladyBrown.move_velocity(0);
    }

    //PRIME POSITION (R2)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        const double target_position = 20;
        const double deadband = 1;
        const double kP = 1.5;
        const int max_velocity = 200;

        while (std::abs(rotSensor.get_position() - target_position) > deadband) {
            // Calculate error
            double error = target_position - rotSensor.get_position();

            // Calculate velocity based on proportional control
            double velocity = kP * error;

            // Clamp velocity to maximum limits
            if (velocity > max_velocity) velocity = max_velocity;
            if (velocity < -max_velocity) velocity = -max_velocity;

            // Move the motor
            ladyBrown.move_velocity(velocity);

            pros::delay(20);
        }

        ladyBrown.move_velocity(0);
    }
}

void rotateLadyBrown() {
    int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

        ladyBrown.move(rightY);
    
}

//AUTON FUNCTIONS
void ladyBrownPrime() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {

        while (abs(rotSensor.get_position() - 20) > 0.5) {

            if (rotSensor.get_position() < 20) {

                ladyBrown.move_velocity(200);
            } else if (rotSensor.get_position() > 20) {

                ladyBrown.move_velocity(-200);
            }
        }

        ladyBrown.move_velocity(0);
        
        }
}

void ladyBrownLower() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {

        while (abs(rotSensor.get_position() - 0) > 1) {
            
            if (rotSensor.get_position() < 0) {

                ladyBrown.move_velocity(200);
            } else if (rotSensor.get_position() > 0) {

                ladyBrown.move_velocity(-200);
            }

            pros::delay(20);
        }

        ladyBrown.move_velocity(0);
        
        }
}

void ladyBrownScore() {
if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {

        while (abs(rotSensor.get_position() - 180) > 0.5) {
            
            if (rotSensor.get_position() < 180) {

                ladyBrown.move_velocity(200);
            } else if (rotSensor.get_position() > 180) {

                ladyBrown.move_velocity(-200);
            }
        }

        ladyBrown.move_velocity(0);
        
        }
}

