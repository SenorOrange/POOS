#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.hpp"
#include "pros/motors.hpp"

//MOTORS
pros::Motor ladyBrown(4, pros::v5::MotorGears::green, pros::v5::MotorUnits::counts);
pros::Motor intake(5, pros::v5::MotorGears::blue);

//3 WIRE
pros::adi::DigitalOut mogoMech ('A');
pros::adi::Encoder rotSensor ('C', 'D', false);


//CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);