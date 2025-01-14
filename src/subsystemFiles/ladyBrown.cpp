#include "main.h"
#include "pros/misc.h"
#include "pros/motors.hpp"



//DRIVER CONTROL FUNCTIONS
void setLadyBrown() {

    //SCORE POSITION (A)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {

        const double target_position_deg = 145; // Target position in degrees
        const int tolerance_cdeg = 500;      // Tolerance in centidegrees (±1 degree)
        const double kP = 0.3;               // Proportional gain for smooth control
        const int max_velocity = 200;        // Max motor velocity for safe movement

        // Convert target position from degrees to centidegrees
        const int target_position_cdeg = target_position_deg * 100;

        while (abs(rotSensor.get_position() - target_position_cdeg) > tolerance_cdeg) {
            // Calculate error in centidegrees
            int error_cdeg = target_position_cdeg - rotSensor.get_position();

            // Proportional control for velocity
            double velocity = kP * error_cdeg;

            // Clamp the velocity to safe limits
            if (velocity > max_velocity) velocity = max_velocity;
            if (velocity < -max_velocity) velocity = -max_velocity;

            ladyBrown.move_velocity(velocity);

            pros::delay(20);  // Small delay to stabilize the control loop
        }

        // Stop the motor when target is reached
        ladyBrown.move_velocity(0);

    }

    //DOWN POSITION (Left)
     if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        
        const double target_position_deg = 5; // Target position in degrees
        const int tolerance_cdeg = 500;      // Tolerance in centidegrees (±1 degree)
        const double kP = 0.3;               // Proportional gain for smooth control
        const int max_velocity = 200;        // Max motor velocity for safe movement

        // Convert target position from degrees to centidegrees
        const int target_position_cdeg = target_position_deg * 100;

        while (abs(rotSensor.get_position() - target_position_cdeg) > tolerance_cdeg) {
            // Calculate error in centidegrees
            int error_cdeg = target_position_cdeg - rotSensor.get_position();

            // Proportional control for velocity
            double velocity = kP * error_cdeg;

            // Clamp the velocity to safe limits
            if (velocity > max_velocity) velocity = max_velocity;
            if (velocity < -max_velocity) velocity = -max_velocity;

            ladyBrown.move_velocity(velocity);

            pros::delay(20);  // Small delay to stabilize the control loop
        }

        // Stop the motor when target is reached
        ladyBrown.move_velocity(0);
    
    }

    //PRIME POSITION (R2)
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        
        const double target_position_deg = 30; // Target position in degrees
        const int tolerance_cdeg = 300;      // Tolerance in centidegrees (±1 degree)
        const double kP = 0.3;               // Proportional gain for smooth control
        const int max_velocity = 200;        // Max motor velocity for safe movement

        // Convert target position from degrees to centidegrees
        const int target_position_cdeg = target_position_deg * 100;

        while (abs(rotSensor.get_position() - target_position_cdeg) > tolerance_cdeg) {
            // Calculate error in centidegrees
            int error_cdeg = target_position_cdeg - rotSensor.get_position();

            // Proportional control for velocity
            double velocity = kP * error_cdeg;

            // Clamp the velocity to safe limits
            if (velocity > max_velocity) velocity = max_velocity;
            if (velocity < -max_velocity) velocity = -max_velocity;

            ladyBrown.move_velocity(velocity);

            pros::delay(20);  // Small delay to stabilize the control loop
        }

        // Stop the motor when target is reached
        ladyBrown.move_velocity(0);
    
    }
}

void printRotSensor() {
    // Get the current position of the rotation sensor in centidegrees
        int current_position_cdeg = rotSensor.get_position();

        // Convert centidegrees to degrees
        double current_position_deg = current_position_cdeg / 100.0;

        // Display the position in degrees on the controller
        controller.set_text(0, 0, "Pos: " + std::to_string(current_position_deg) + " deg");

        pros::delay(100);  // Delay to avoid spamming updates
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

