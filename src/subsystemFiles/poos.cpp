#include "main.h"
#include "pros/colors.h"
#include "pros/screen.h"
#include "pros/screen.hpp"

bool bluePlusSide = false;
bool blueMinusSide = false;
bool blueRush = false;
bool blueAWP = false;
bool redPlusSide = false;
bool redMinusSide = false;
bool redRush = false;
bool redAWP = false;
bool skillsAuton = false;

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
    pros::screen::print(pros::E_TEXT_MEDIUM, 32, 55, "Plus");
    pros::screen::print(pros::E_TEXT_MEDIUM, 120, 55, "Minus");
    pros::screen::print(pros::E_TEXT_MEDIUM, 220, 55, "Rush");
    pros::screen::print(pros::E_TEXT_MEDIUM, 320, 55, "AWP");

    //Red Boxes
    pros::screen::set_pen(pros::c::COLOR_RED);
    pros::screen::fill_rect(5,125,95,235);
    pros::screen::fill_rect(100,125,190,235);
    pros::screen::fill_rect(195,125,285,235);
    pros::screen::fill_rect(290,125,380,235);
    //Red Text
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 32, 170, "Plus");
    pros::screen::print(pros::E_TEXT_MEDIUM, 120, 170, "Minus");
    pros::screen::print(pros::E_TEXT_MEDIUM, 220, 170, "Rush");
    pros::screen::print(pros::E_TEXT_MEDIUM, 320, 170, "AWP");

    //Skills Box
    pros::screen::set_pen(pros::c::COLOR_WHITE_SMOKE);
    pros::screen::fill_rect(385,5,475,235);
    //Skills Text
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 406, 103, "Auton");
    pros::screen::print(pros::E_TEXT_MEDIUM, 401, 125, "Skills");

}

void touchTester() {
    int i = 0;
    pros::screen_touch_status_s_t status;
    while(1){
       status = pros::c::screen_touch_status();

       // Will print various information about the last touch
       pros::screen::print(pros::E_TEXT_MEDIUM, 1, "Touch Status (Type): %d", status.touch_status);
       pros::screen::print(pros::E_TEXT_MEDIUM, 2, "Last X: %hd", status.x);
       pros::screen::print(pros::E_TEXT_MEDIUM, 3, "Last Y: %hd", status.y);
       pros::screen::print(pros::E_TEXT_MEDIUM, 4, "Press Count: %d", status.press_count);
       pros::screen::print(pros::E_TEXT_MEDIUM, 5, "Release Count: %d", status.release_count);
       pros::delay(20);
    }
}

void autonSelector() {



pros::screen_touch_status_s_t status;
while(1){
    status = pros::c::screen_touch_status();

    //Select Blue Plus
    if (status.x >= 5 && status.y >= 5 && status.x <= 95 && status.y <= 120 && status.touch_status) {
    drawGUI();
    //Edit GUI
    pros::screen::set_pen(pros::c::COLOR_DARK_BLUE);
    pros::screen::fill_rect(5,5,95,120);
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 32, 55, "Plus");

    //Adjust Bools
    bool bluePlusSide = true;
    bool blueMinusSide = false;
    bool blueRush = false;
    bool blueAWP = false;
    bool redPlusSide = false;
    bool redMinusSide = false;
    bool redRush = false;
    bool redAWP = false;
    bool skillsAuton = false;
    }

    //Select Blue Minus
    if (status.x >= 100 && status.y >= 5 && status.x <= 190 && status.y <= 120 && status.touch_status) {
    drawGUI();
    //Edit GUI
    pros::screen::set_pen(pros::c::COLOR_DARK_BLUE);
    pros::screen::fill_rect(100,5,190,120);
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 120, 55, "Minus");

    //Adjust Bools
    bool bluePlusSide = false;
    bool blueMinusSide = true;
    bool blueRush = false;
    bool blueAWP = false;
    bool redPlusSide = false;
    bool redMinusSide = false;
    bool redRush = false;
    bool redAWP = false;
    bool skillsAuton = false;
    }

    //Select Blue Rush
    if (status.x >= 195 && status.y >= 5 && status.x <= 285 && status.y <= 120 && status.touch_status) {
    drawGUI();
    //Edit GUI
    pros::screen::set_pen(pros::c::COLOR_DARK_BLUE);
    pros::screen::fill_rect(195,5,285,120);
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 220, 55, "Rush");

    //Adjust Bools
    bool bluePlusSide = false;
    bool blueMinusSide = false;
    bool blueRush = true;
    bool blueAWP = false;
    bool redPlusSide = false;
    bool redMinusSide = false;
    bool redRush = false;
    bool redAWP = false;
    bool skillsAuton = false;
    }

    //Select Blue AWP
    if (status.x >= 290 && status.y >= 5 && status.x <= 380 && status.y <= 120 && status.touch_status) {
    drawGUI();
    //Edit GUI
    pros::screen::set_pen(pros::c::COLOR_DARK_BLUE);
    pros::screen::fill_rect(290,5,380,120);
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 320, 55, "AWP");

    //Adjust Bools
    bool bluePlusSide = false;
    bool blueMinusSide = false;
    bool blueRush = false;
    bool blueAWP = true;
    bool redPlusSide = false;
    bool redMinusSide = false;
    bool redRush = false;
    bool redAWP = false;
    bool skillsAuton = false;
    }

    //Select Red Plus
    if (status.x >= 5 && status.y >= 125 && status.x <= 95 && status.y <= 235 && status.touch_status) {
    drawGUI();
    //Edit GUI
    pros::screen::set_pen(pros::c::COLOR_DARK_RED);
    pros::screen::fill_rect(5,125,95,235);
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 32, 170, "Plus");

    //Adjust Bools
    bool bluePlusSide = false;
    bool blueMinusSide = false;
    bool blueRush = false;
    bool blueAWP = false;
    bool redPlusSide = true;
    bool redMinusSide = false;
    bool redRush = false;
    bool redAWP = false;
    bool skillsAuton = false;
    }

    //Select Red Minus
    if (status.x >= 100 && status.y >= 125 && status.x <= 190 && status.y <= 235 && status.touch_status) {
    drawGUI();
    //Edit GUI
    pros::screen::set_pen(pros::c::COLOR_DARK_RED);
    pros::screen::fill_rect(100,125,190,235);
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 120, 170, "Minus");

    //Adjust Bools
    bool bluePlusSide = false;
    bool blueMinusSide = false;
    bool blueRush = false;
    bool blueAWP = false;
    bool redPlusSide = false;
    bool redMinusSide = true;
    bool redRush = false;
    bool redAWP = false;
    bool skillsAuton = false;
    }

    //Select Red Rush
    if (status.x >= 195 && status.y >= 125 && status.x <= 285 && status.y <= 235 && status.touch_status) {
    drawGUI();
    //Edit GUI
    pros::screen::set_pen(pros::c::COLOR_DARK_RED);
    pros::screen::fill_rect(195,125,285,235);
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 220, 170, "Rush");

    //Adjust Bools
    bool bluePlusSide = false;
    bool blueMinusSide = false;
    bool blueRush = false;
    bool blueAWP = false;
    bool redPlusSide = false;
    bool redMinusSide = false;
    bool redRush = true;
    bool redAWP = false;
    bool skillsAuton = false;
    }

    //Select Red AWP
    if (status.x >= 290 && status.y >= 125 && status.x <= 380 && status.y <= 235 && status.touch_status) {
    drawGUI();
    //Edit GUI
    pros::screen::set_pen(pros::c::COLOR_DARK_RED);
    pros::screen::fill_rect(290,125,380,235);
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 320, 170, "AWP");

    //Adjust Bools
    bool bluePlusSide = false;
    bool blueMinusSide = false;
    bool blueRush = false;
    bool blueAWP = false;
    bool redPlusSide = false;
    bool redMinusSide = false;
    bool redRush = false;
    bool redAWP = true;
    bool skillsAuton = false;
    }

    //Select Auton Skills
    if (status.x >= 385 && status.y >= 5 && status.x <= 475 && status.y <= 235 && status.touch_status) {
    drawGUI();
    //Edit GUI
    pros::screen::set_pen(pros::c::COLOR_DARK_GRAY);
    pros::screen::fill_rect(385,5,475,235);
    pros::screen::set_pen(pros::c::COLOR_WHITE);
    pros::screen::print(pros::E_TEXT_MEDIUM, 406, 103, "Auton");
    pros::screen::print(pros::E_TEXT_MEDIUM, 401, 125, "Skills");

    //Adjust Bools
    bool bluePlusSide = false;
    bool blueMinusSide = false;
    bool blueRush = false;
    bool blueAWP = false;
    bool redPlusSide = false;
    bool redMinusSide = false;
    bool redRush = false;
    bool redAWP = false;
    bool skillsAuton = true;
    }
  }
}
