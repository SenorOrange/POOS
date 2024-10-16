#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.hpp"
#include "pros/motors.hpp"

//MOTORS
pros::Motor ladyBrown(5, pros::v5::MotorGears::green);
pros::Motor intake(-21, pros::v5::MotorGears::blue);

//Pneumatics
pros::adi::DigitalOut mogoMech ('A');


//CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);