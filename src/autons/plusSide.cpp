#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "subsystemHeaders/globals.hpp"
#include "subsystemHeaders/intake.hpp"
#include "subsystemHeaders/mogoMech.hpp"
#include "subsystemHeaders/ladyBrown.hpp"
#include "subsystemHeaders/poos.hpp"


void plusSide() {
    chassis.setPose(0, 0, 0);
    allianceStakePosition();
    chassis.moveToPose(flip * -10, 15, 90, 0);
    chassis.moveToPose(flip * -24, 3, 180, 1000);
    chassis.waitUntilDone();
    allianceScorePosition();
    chassis.moveToPose(flip * 0, 48, 60, 1000, {.forwards=false});
    chassis.waitUntilDone();
    clamp();
    spinIntake();
    chassis.moveToPose(flip * 24, 48, 90, 1000);
    chassis.moveToPose(flip * 44, 0, 130, 1000);
    chassis.waitUntilDone();
    raiseLadyBrown();
    chassis.moveToPose(flip * -60, 60, 90, 1000, {.forwards=false});
    stopIntake();
}
