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


lv_group_t * bluePos;
lv_group_t * blueNeg;
lv_group_t * redPos;
lv_group_t * redNeg;
lv_group_t * skillsb;

lv_obj_t * bluePosBtn;
lv_obj_t * bluePosLabel;
lv_obj_t * blueNegBtn;
lv_obj_t * blueNegLabel;
lv_obj_t * redPosBtn;
lv_obj_t * redPosLabel;
lv_obj_t * redNegBtn;
lv_obj_t * redNegLabel;
lv_obj_t * skillsBtn;
lv_obj_t * skillsLabel;

lv_obj_t * myButtonLabel;
lv_obj_t * allianceSwitch;
lv_obj_t * cornerSwitch;
lv_obj_t * obj;
lv_obj_t * testImg;


//Used to switch which side the auton is on to fix the asymmetrical field layout
int flip = 1;

//Color Sort Variables
int Ring_Hue;
int Blue = 240;
int Red = 0;

//POOS FUNCTIONS
void drawGUI() {

    //Not Pressed Blue Style
    static lv_style_t styleBlue;
    lv_style_init(&styleBlue);

    lv_style_set_radius(&styleBlue, 1);

    lv_style_set_bg_opa(&styleBlue, LV_OPA_100);
    lv_style_set_bg_color(&styleBlue, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_bg_grad_color(&styleBlue, lv_palette_darken(LV_PALETTE_BLUE, 2));
    lv_style_set_bg_grad_dir(&styleBlue, LV_GRAD_DIR_VER);

    lv_style_set_border_opa(&styleBlue, LV_OPA_40);
    lv_style_set_border_width(&styleBlue, 2);
    lv_style_set_border_color(&styleBlue, lv_palette_main(LV_PALETTE_GREY));

    lv_style_set_shadow_width(&styleBlue, 3);
    lv_style_set_shadow_color(&styleBlue, lv_palette_main(LV_PALETTE_GREY));
    lv_style_set_shadow_ofs_y(&styleBlue, 8);

    lv_style_set_outline_opa(&styleBlue, LV_OPA_COVER);
    lv_style_set_outline_color(&styleBlue, lv_palette_main(LV_PALETTE_BLUE));

    lv_style_set_text_color(&styleBlue, lv_color_white());
    lv_style_set_pad_all(&styleBlue, 10);

    //pressed blue Style
    static lv_style_t styleBlue_pr;
    lv_style_init(&styleBlue_pr);

    /*Add a large outline when pressed*/
    lv_style_set_outline_width(&styleBlue_pr, 30);
    lv_style_set_outline_opa(&styleBlue_pr, LV_OPA_TRANSP);

    lv_style_set_translate_y(&styleBlue_pr, 5);
    lv_style_set_shadow_ofs_y(&styleBlue_pr, 3);
    lv_style_set_bg_color(&styleBlue_pr, lv_palette_darken(LV_PALETTE_BLUE, 2));
    lv_style_set_bg_grad_color(&styleBlue_pr, lv_palette_darken(LV_PALETTE_BLUE, 4));

    //Not Pressed Red Style
    static lv_style_t styleRed;
    lv_style_init(&styleRed);

    lv_style_set_radius(&styleRed, 1);

    lv_style_set_bg_opa(&styleRed, LV_OPA_100);
    lv_style_set_bg_color(&styleRed, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_bg_grad_color(&styleRed, lv_palette_darken(LV_PALETTE_RED, 2));
    lv_style_set_bg_grad_dir(&styleRed, LV_GRAD_DIR_VER);

    lv_style_set_border_opa(&styleRed, LV_OPA_40);
    lv_style_set_border_width(&styleRed, 2);
    lv_style_set_border_color(&styleRed, lv_palette_main(LV_PALETTE_GREY));

    lv_style_set_shadow_width(&styleRed, 3);
    lv_style_set_shadow_color(&styleRed, lv_palette_main(LV_PALETTE_GREY));
    lv_style_set_shadow_ofs_y(&styleRed, 8);

    lv_style_set_outline_opa(&styleRed, LV_OPA_COVER);
    lv_style_set_outline_color(&styleRed, lv_palette_main(LV_PALETTE_RED));

    lv_style_set_text_color(&styleRed, lv_color_white());
    lv_style_set_pad_all(&styleRed, 10);

    //pressed Red Style
    static lv_style_t styleRed_pr;
    lv_style_init(&styleRed_pr);

    /*Add a large outline when pressed*/
    lv_style_set_outline_width(&styleRed_pr, 30);
    lv_style_set_outline_opa(&styleRed_pr, LV_OPA_TRANSP);

    lv_style_set_translate_y(&styleRed_pr, 5);
    lv_style_set_shadow_ofs_y(&styleRed_pr, 3);
    lv_style_set_bg_color(&styleRed_pr, lv_palette_darken(LV_PALETTE_RED, 2));
    lv_style_set_bg_grad_color(&styleRed_pr, lv_palette_darken(LV_PALETTE_RED, 4));

    static lv_style_t redToggle;
    lv_style_init(&redToggle);

    lv_style_set_bg_color(&redToggle, lv_palette_main(LV_PALETTE_RED));
    lv_style_set_bg_grad_color(&redToggle, lv_palette_darken(LV_PALETTE_RED, 2));

    static lv_style_t blueToggle;
    lv_style_init(&blueToggle);

    lv_style_set_bg_color(&blueToggle, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_bg_grad_color(&blueToggle, lv_palette_darken(LV_PALETTE_BLUE, 2));
    
    static lv_style_t posToggle;
    lv_style_init(&posToggle);

    lv_style_set_bg_color(&posToggle, lv_palette_main(LV_PALETTE_GREY));
    lv_style_set_bg_grad_color(&posToggle, lv_palette_darken(LV_PALETTE_GREY, 4));
    obj = lv_label_create(lv_scr_act());
    lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);
    lv_style_set_text_color(&posToggle, lv_palette_main(LV_PALETTE_ORANGE));
    lv_label_set_text(obj, "text");

    static lv_style_t negToggle;
    lv_style_init(&negToggle);

    lv_style_set_bg_color(&negToggle, lv_palette_main(LV_PALETTE_GREY));
    lv_style_set_bg_grad_color(&negToggle, lv_palette_darken(LV_PALETTE_GREY, 4));
    obj = lv_label_create(lv_scr_act());
    lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);
    lv_style_set_text_color(&negToggle, lv_palette_main(LV_PALETTE_ORANGE));





    //Creating Groups
    bluePos = lv_group_create();
    blueNeg = lv_group_create();
    redPos = lv_group_create();
    redNeg = lv_group_create();
    skillsb = lv_group_create();

    //Creating Objects
    allianceSwitch = lv_switch_create(lv_scr_act());
    cornerSwitch = lv_switch_create(lv_scr_act());
    testImg = lv_img_create(lv_scr_act());

    bluePosBtn = lv_btn_create(lv_scr_act());
    bluePosLabel = lv_label_create(bluePosBtn);
    blueNegBtn = lv_btn_create(lv_scr_act());
    blueNegLabel = lv_label_create(blueNegBtn);
    redPosBtn = lv_btn_create(lv_scr_act());
    redPosLabel = lv_label_create(redPosBtn);
    redNegBtn = lv_btn_create(lv_scr_act());
    redNegLabel = lv_label_create(redNegBtn);
    skillsBtn = lv_btn_create(lv_scr_act());
    skillsLabel = lv_label_create(skillsBtn);


    //Assigning Objects into Groups
    lv_group_add_obj(bluePos, bluePosBtn);
    lv_group_add_obj(blueNeg, blueNegBtn);
    lv_group_add_obj(redPos, redPosBtn);
    lv_group_add_obj(redNeg, redNegBtn);
    lv_group_add_obj(skillsb, skillsBtn);

    lv_group_add_obj(bluePos, bluePosLabel);
    lv_group_add_obj(blueNeg, blueNegLabel);
    lv_group_add_obj(redPos, redPosLabel);
    lv_group_add_obj(redNeg, redPosLabel);
    lv_group_add_obj(skillsb, skillsLabel);
    


    lv_label_set_text(bluePosLabel, "Blue\nPositive");
    lv_obj_add_style(bluePosBtn, &styleBlue, 0);
    lv_obj_add_style(bluePosBtn, &styleBlue_pr, LV_STATE_PRESSED);
    lv_obj_set_size(bluePosBtn, 70, 70);
    lv_obj_align(bluePosBtn, LV_ALIGN_TOP_LEFT, 10, 10);

    lv_label_set_text(blueNegLabel, "Blue\nNegative");
    lv_obj_add_style(blueNegBtn, &styleBlue, 0);
    lv_obj_add_style(blueNegBtn, &styleBlue_pr, LV_STATE_PRESSED);
    lv_obj_set_size(blueNegBtn, 70, 70);
    lv_obj_align(blueNegBtn, LV_ALIGN_LEFT_MID, 10, 10);

    lv_label_set_text(redPosLabel, "Red\nPositive");
    lv_obj_add_style(redPosBtn, &styleRed, 0);
    lv_obj_add_style(redPosBtn, &styleRed_pr, LV_STATE_PRESSED);
    lv_obj_set_size(redPosBtn, 70, 70);
    lv_obj_align(redPosBtn, LV_ALIGN_TOP_LEFT, 90, 10);

    lv_label_set_text(redNegLabel, "Red\nNegative");
    lv_obj_add_style(redNegBtn, &styleRed, 0);
    lv_obj_add_style(redNegBtn, &styleRed_pr, LV_STATE_PRESSED);
    lv_obj_set_size(redNegBtn, 70, 70);
    lv_obj_align(redNegBtn, LV_ALIGN_LEFT_MID, 90, 10);

    lv_label_set_text(skillsLabel, "Skills\nAuton");
    lv_obj_add_style(skillsBtn, &styleRed, 0);
    lv_obj_add_style(skillsBtn, &styleRed_pr, LV_STATE_PRESSED);
    lv_obj_set_size(skillsBtn, 70, 155);
    lv_obj_align(skillsBtn, LV_ALIGN_TOP_LEFT, 170, 10);


    lv_obj_add_style(allianceSwitch, &blueToggle, LV_STATE_CHECKED);
    lv_obj_add_style(allianceSwitch, &redToggle, LV_STATE_DEFAULT);
    lv_obj_set_size(allianceSwitch, 100, 50);
    lv_obj_align(allianceSwitch, LV_ALIGN_BOTTOM_LEFT, 20, -10);
    
    lv_obj_add_style(cornerSwitch, &posToggle, LV_STATE_CHECKED);
    lv_obj_add_style(cornerSwitch, &negToggle, LV_STATE_DEFAULT);
    lv_obj_set_size(cornerSwitch, 100, 50);
    lv_obj_align(cornerSwitch, LV_ALIGN_BOTTOM_LEFT, 130, -10);


    lv_img_set_src(testImg, "F:POOS/lvgl/kung-fu-panda.bmp");
    lv_obj_center(testImg);
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
