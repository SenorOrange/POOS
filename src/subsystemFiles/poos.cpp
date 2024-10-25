#include "main.h"
#include "pros/screen.hpp"

//POOS FUNCTIONS
void drawGUI() {

    //Blue Boxes
    pros::screen::set_pen(pros::c::COLOR_BLUE);
    pros::screen::fill_rect(5,5,95,120);
    pros::screen::fill_rect(100,5,190,120);
    pros::screen::fill_rect(195,5,285,120);
    pros::screen::fill_rect(290,5,380,120);
    //Blue Text
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 35, 55, "+");



    //Red Boxes
    pros::screen::set_pen(pros::c::COLOR_RED);
    pros::screen::fill_rect(5,125,95,235);
    pros::screen::fill_rect(100,125,190,235);
    pros::screen::fill_rect(195,125,285,235);
    pros::screen::fill_rect(290,125,380,235);

    //Skills Box
    pros::screen::set_pen(pros::c::COLOR_WHITE_SMOKE);
    pros::screen::fill_rect(385,5,475,235);
}
