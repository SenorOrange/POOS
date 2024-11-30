#include "main.h"
#include "liblvgl/lvgl.h"
#include "pros/colors.h"
#include "pros/screen.h"
#include "pros/screen.hpp"
#include "subsystemHeaders/poos.hpp"


bool bluePlusSide = false;
bool blueMinusSide = false;
bool blueRush = false;
bool blueAWP = false;
bool redPlusSide = false;
bool redMinusSide = true;
bool redRush = false;
bool redAWP = false;
bool skillsAuton = false;


lv_obj_t * myButton;
lv_obj_t * myButtonLabel;
lv_obj_t * myLabel;

//Used to switch which side the auton is on to fix the asymmetrical field layout
int flip = 1;

//Color Sort Variables
int Ring_Hue;
int Blue = 240;
int Red = 0;

//POOS FUNCTIONS
void drawGUI() {

    myButton = lv_btn_create(lv_scr_act()); //create button, lv_scr_act() is deafult screen object
    myLabel = lv_label_create(myButton);

    lv_label_set_text(myLabel, "Hello World");
    lv_obj_set_style_text_color(myLabel, lv_palette_main(LV_PALETTE_ORANGE), LV_STATE_ANY);
    lv_obj_set_style_bg_color(myButton, lv_color_make(255, 153, 0), LV_STATE_ANY);
    lv_obj_set_size(myButton, 200, 100); //set the button size
    lv_obj_align(myButton, LV_ALIGN_TOP_LEFT, 10, 10); //set the position to top mid
    lv_obj_align(myLabel, LV_ALIGN_CENTER, 0, 0);
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
    bluePlusSide = true;
    blueMinusSide = false;
    blueRush = false;
    blueAWP = false;
    redPlusSide = false;
    redMinusSide = false;
    redRush = false;
    redAWP = false;
    skillsAuton = false;

    flip = 1;
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
    bluePlusSide = false;
    blueMinusSide = true;
    blueRush = false;
    blueAWP = false;
    redPlusSide = false;
    redMinusSide = false;
    redRush = false;
    redAWP = false;
    skillsAuton = false;

    flip = -1;
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
    bluePlusSide = false;
    blueMinusSide = false;
    blueRush = true;
    blueAWP = false;
    redPlusSide = false;
    redMinusSide = false;
    redRush = false;
    redAWP = false;
    skillsAuton = false;

    flip = -1;
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
    bluePlusSide = false;
    blueMinusSide = false;
    blueRush = false;
    blueAWP = true;
    redPlusSide = false;
    redMinusSide = false;
    redRush = false;
    redAWP = false;
    skillsAuton = false;

    flip = -1;
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
    bluePlusSide = false;
    blueMinusSide = false;
    blueRush = false;
    blueAWP = false;
    redPlusSide = true;
    redMinusSide = false;
    redRush = false;
    redAWP = false;
    skillsAuton = false;

    flip = -1;
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
    bluePlusSide = false;
    blueMinusSide = false;
    blueRush = false;
    blueAWP = false;
    redPlusSide = false;
    redMinusSide = true;
    redRush = false;
    redAWP = false;
    skillsAuton = false;

    flip = 1;
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
    bluePlusSide = false;
    blueMinusSide = false;
    blueRush = false;
    blueAWP = false;
    redPlusSide = false;
    redMinusSide = false;
    redRush = true;
    redAWP = false;
    skillsAuton = false;

    flip = 1;
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
    bluePlusSide = false;
    blueMinusSide = false;
    blueRush = false;
    blueAWP = false;
    redPlusSide = false;
    redMinusSide = false;
    redRush = false;
    redAWP = true;
    skillsAuton = false;

    flip = 1;
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
    bluePlusSide = false;
    blueMinusSide = false;
    blueRush = false;
    blueAWP = false;
    redPlusSide = false;
    redMinusSide = false;
    redRush = false;
    redAWP = false;
    skillsAuton = true;
    }
  }
    pros::delay(10); // Small delay to prevent overwhelming the CPU

}

void testBools() {
    // Print the current states of the boolean variables
    std::cout << "Testing Bool States:\n";
    std::cout << "Blue Plus Side: " << bluePlusSide << "\n";
    std::cout << "Blue Minus Side: " << blueMinusSide << "\n";
    std::cout << "Blue Rush: " << blueRush << "\n";
    std::cout << "Blue AWP: " << blueAWP << "\n";
    std::cout << "Red Plus Side: " << redPlusSide << "\n";
    std::cout << "Red Minus Side: " << redMinusSide << "\n";
    std::cout << "Red Rush: " << redRush << "\n";
    std::cout << "Red AWP: " << redAWP << "\n";
    std::cout << "Skills Auton: " << skillsAuton << "\n";
}
