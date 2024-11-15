#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.hpp"
#include "pros/motors.hpp"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/optical.hpp"


//MOTORS
pros::Motor ladyBrown(-5, pros::v5::MotorGears::green);
pros::Motor intake(-21, pros::v5::MotorGears::blue);
pros::MotorGroup leftMotors({-2, -1, -3}, pros::MotorGearset::blue); 
pros::MotorGroup rightMotors({8, 7, 10}, pros::MotorGearset::blue); 


//Pneumatics
pros::adi::DigitalOut mogoMech ('A');
pros::adi::DigitalOut doinker ('B');

//CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);

//SENSORS
pros::Imu imu(16);
pros::Optical colorSensor(4);

// drivetrain settings
lemlib::Drivetrain drivetrain(&leftMotors,
                              &rightMotors, 
                              13.5,
                              lemlib::Omniwheel::NEW_275,
                              450,
                              2
);

// lateral motion controller
lemlib::ControllerSettings linearController(10, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            3, // derivative gain (kD)
                                            3, // anti windup
                                            1, // small error range, in inches
                                            100, // small error range timeout, in milliseconds
                                            3, // large error range, in inches
                                            500, // large error range timeout, in milliseconds
                                            20 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angularController(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// sensors for odometry
lemlib::OdomSensors sensors(nullptr, 
                            nullptr, 
                            nullptr, 
                            nullptr, 
                            &imu 
);

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttleCurve(3, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1.019 // expo curve gain
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steerCurve(3, // joystick deadband out of 127
                                  10, // minimum output where drivetrain will move out of 127
                                  1.019 // expo curve gain
);

// create the chassis
lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors, &throttleCurve, &steerCurve);

