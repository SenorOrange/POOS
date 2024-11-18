#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp"


void minusSide() {
    chassis.setPose(0, 0, 0);
    clamp();
    pros::delay(10000);
    spinIntake();
    chassis.moveToPoint(0, 48, 100000,  {.maxSpeed=20});
}
