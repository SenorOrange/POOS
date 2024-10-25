#include "liblvgl/llemu.hpp"
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/abstract_motor.hpp"
#include "pros/colors.h"
#include "pros/misc.h"
#include "subsystemHeaders/globals.hpp"


void rush() {
    chassis.moveToPose(20, 15, 90, 4000);

}
