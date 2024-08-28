#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.hpp"
#include "pros/motors.hpp"

//MOTORS
pros::Motor lift(4, pros::v5::MotorGears::red, pros::v5::MotorUnits::counts);
pros::Motor intake(5, pros::v5::MotorGears::green);

//Pneumatics
pros::adi::DigitalOut mogoMech ('A');

//CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);