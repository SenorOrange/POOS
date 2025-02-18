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
        
        const double target_position_deg = 22; // Target position in degrees
        const int tolerance_cdeg = 100;      // Tolerance in centidegrees (±1 degree)
        const double kP = 0.2;               // Proportional gain for smooth control
        const int max_velocity = 200;        // Max motor velocity for safe movement
        const int timeout_ms = 1500;            // Timeout in milliseconds

        // Convert target position from degrees to centidegrees
        const int target_position_cdeg = target_position_deg * 100;

        int start_time = pros::millis(); // Record the start time

        while (abs(rotSensor.get_position() - target_position_cdeg) > tolerance_cdeg) {
            if (pros::millis() - start_time > timeout_ms) {
            break; // Stop trying after 1 second
            }
            // Calculate error in centidegrees
            int error_cdeg = target_position_cdeg - rotSensor.get_position();

            // Proportional control for velocity
            double velocity = kP * error_cdeg;

            // Clamp the velocity to safe limits
            if (velocity > max_velocity) velocity = max_velocity / 3;
            if (velocity < -max_velocity) velocity = -max_velocity;

            ladyBrown.move_velocity(velocity);

        }

        // Stop the motor when target is reached
        ladyBrown.move_velocity(0);
    
    }
}

const int numStates = 3;
int states[numStates] = {0, 2200, 17000};
int currState = 0;
int target = 0;

void nextState() {
    currState += 1;
    if (currState == numStates) {
        currState = 0;
    }
    target = states[currState];
}

void liftControl() {
    double kp = .025;
    double error = target - rotSensor.get_position();
    double velocity = kp * error;
    ladyBrown.move(velocity);
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
        const double target_position_deg = 22; // Target position in degrees
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

void ladyBrownLower() {
        const double target_position_deg = 0; // Target position in degrees
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

void ladyBrownScore() {
        
        const double target_position_deg = 210; // Target position in degrees
        const int tolerance_cdeg = 500;      // Tolerance in centidegrees (±1 degree)
        const double kP = 0.3;               // Proportional gain for smooth control
        const int max_velocity = 200;        // Max motor velocity for safe movement
        const int timeout_ms = 1000;            // Timeout in milliseconds

        // Convert target position from degrees to centidegrees
        const int target_position_cdeg = target_position_deg * 100;

        int start_time = pros::millis(); // Record the start time


        while (abs(rotSensor.get_position() - target_position_cdeg) > tolerance_cdeg) {
            if (pros::millis() - start_time > timeout_ms) {
            break; // Stop trying after 1 second
            }
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

void ladyBrownIdle() {
        
        const double target_position_deg = 60; // Target position in degrees
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
