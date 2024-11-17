#include "main.h"
#include "pros/adi.hpp"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/optical.hpp"
#include "pros/vision.h"


//MOTORS
extern pros::Motor ladyBrown;
extern pros::Motor intake;
extern pros::MotorGroup leftMotors; 
extern pros::MotorGroup rightMotors; 


//3 WIRE
extern pros::adi::DigitalOut mogoMech;
extern pros::adi::DigitalOut doinker;


//CONTROLLER
extern pros::Controller controller;

//SENSORS
extern pros::Imu imu;
extern pros::Optical colorSensor;

// drivetrain settings
extern lemlib::Drivetrain drivetrain;

// lateral motion controller
extern lemlib::ControllerSettings linearController;

// angular motion controller
extern lemlib::ControllerSettings angularController;

// sensors for odometry
extern lemlib::OdomSensors sensors;

// input curve for throttle input during driver control
extern lemlib::ExpoDriveCurve throttleCurve;

// input curve for steer input during driver control
extern lemlib::ExpoDriveCurve steerCurve;

// create the chassis
extern lemlib::Chassis chassis;

void testPosition();

