#include "liblvgl/llemu.hpp"
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/abstract_motor.hpp"
#include "pros/colors.h"
#include "pros/misc.h"
#include "subsystemHeaders/globals.hpp"
#include <future>


void AWP() {
    chassis.moveToPoint(0, 72, 1000, {.forwards=false});
    chassis.moveToPose(20, 15, 90, 1000);
    clamp();
}
