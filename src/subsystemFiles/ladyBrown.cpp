#include "main.h"
#include "pros/misc.h"
#include "pros/motors.hpp"


bool freeStyle = true;



//DRIVER CONTROL FUNCTIONS

const int numStates = 3;
int states[numStates] = {0, 2650, 17000};
int currState = 0;
int target = 0;
double velocity;

void nextState() {
    freeStyle = false;
    currState += 1;
    if (currState == numStates) {
        currState = 0;
    }
    target = states[currState];
}

void liftControl() {
    if (freeStyle == false) {
        double kp = .025;
        double error = target - rotSensor.get_position();
        velocity = kp * error;
    } else if (freeStyle == true) {
        velocity = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        pros::delay(50);
    }

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
    freeStyle = true;
}



//AUTON FUNCTIONS
void ladyBrownPrime() {
    freeStyle = false;
    currState = 1;
    target = states[currState];
}

void ladyBrownLower() {
    freeStyle = false;
    currState = 0;
    target = states[currState];

}

void ladyBrownScore() {
    freeStyle = false;
    currState = 2;
    target = 21000;

}

void ladyBrownIdle() {
    freeStyle = false;
    currState = 2;
    target = 6000;
}
