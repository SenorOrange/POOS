#include "liblvgl/core/lv_disp.h"
#include "liblvgl/core/lv_group.h"
#include "liblvgl/core/lv_obj.h"
#include "liblvgl/core/lv_obj_pos.h"
#include "liblvgl/core/lv_obj_style.h"
#include "liblvgl/font/lv_font.h"
#include "liblvgl/misc/lv_area.h"
#include "liblvgl/misc/lv_color.h"
#include "liblvgl/misc/lv_style.h"
#include "liblvgl/widgets/lv_canvas.h"
#include "liblvgl/widgets/lv_img.h"
#include "liblvgl/widgets/lv_label.h"
#include "main.h"
#include "liblvgl/lvgl.h"
#include "subsystemHeaders/poos.hpp"


bool bluePlusSide = true;
bool blueMinusSide = false;
bool blueRush = false;
bool blueAWP = false;
bool redPlusSide = false;
bool redMinusSide = false;
bool redRush = false;
bool redAWP = false;
bool skillsAuton = false;


lv_group_t * bluePos;
lv_group_t * blueNeg;
lv_group_t * redPos;
lv_group_t * redNeg;
lv_group_t * skillsb;
lv_group_t * cornerSw;
lv_group_t * autonInfo;

lv_event_cb_t  bluePosClick;
lv_event_cb_t * blueNegClick;
lv_event_cb_t * redPosClick;
lv_event_cb_t * redNegClick;
lv_event_cb_t * skillsClick;

lv_event_cb_t  bluePosReleased;
lv_event_cb_t * blueNegReleased;
lv_event_cb_t * redPosReleased;
lv_event_cb_t * redNegReleased;
lv_event_cb_t * skillsReleased;


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
lv_obj_t * autonPoints;
lv_obj_t * autonTime;
lv_obj_t * autonBox;
lv_obj_t * colorSort;
lv_obj_t * autonTimeEdit;
lv_obj_t * autonPointsEdit;
lv_obj_t * colorSortEdit;
lv_obj_t * autonName;


//Used to determine what Auton is selected by rotating the number
int auton = 0;

//Used to switch which side the auton is on to fix the asymmetrical field layout
int flip = 1;

//Color Sort Variables
int ringHueMin;
int ringHueMax;
int BlueMin = 190;
int BlueMax = 260;
int RedMin = 0;
int RedMax = 80;

static void event_rc(lv_event_t * redChecked) {

}

static void event_bp(lv_event_t * bluePosClick) {
    std::cout << "Blue Plus Side: " << bluePlusSide << "\n";
    lv_label_set_text(autonName, "Blue Positive\nCorner SAWP");
    lv_label_set_text(autonTimeEdit, "13 Seconds");
    lv_label_set_text(autonPointsEdit, "x1 Alliance Stake = 3\nx4 Mogo = 6\n\nTotal = 9 + AWP");
    lv_label_set_text(colorSortEdit, "Sorting Red Rings");
    flip = 1;
    auton = 1;

    //Switch Ring Sort Colour To Red
    ringHueMin = RedMin;
    ringHueMax = RedMax;
}

static void event_bpr(lv_event_t * bluePosReleased) {
    lv_label_set_text(bluePosLabel, "Blue\nPositive");
}

static void event_bn(lv_event_t * blueNegClick) {
    std::cout << "Blue Neg Side: " << blueMinusSide << "\n";
    lv_label_set_text(autonName, "Blue Negative\nCorner SAWP");
    lv_label_set_text(autonTimeEdit, "13 Seconds");
    lv_label_set_text(autonPointsEdit, "x1 Alliance Stake = 3\nx4 Mogo = 6\n\nTotal = 9 + AWP");
    lv_label_set_text(colorSortEdit, "Sorting Red Rings");
    flip = -1;
    auton = 1;

    //Switch Ring Sort Colour To Red
    ringHueMin = RedMin;
    ringHueMax = RedMax;
}

static void event_bnr(lv_event_t * blueNegReleased) {
    lv_label_set_text(blueNegLabel, "Blue\nNegative");
}

static void event_rp(lv_event_t * redPosClick) {
    std::cout << "Red Pos Side: " << redPlusSide << "\n";
    lv_label_set_text(autonName, "Red Positive\nCorner SAWP");
    lv_label_set_text(autonTimeEdit, "13 Seconds");
    lv_label_set_text(autonPointsEdit, "x1 Alliance Stake = 3\nx4 Mogo = 6\n\nTotal = 9 + AWP");
    lv_label_set_text(colorSortEdit, "Sorting Blue Rings");
    flip = -1;
    auton = 1;

    //Switch Ring Sort Colour To Blue
    ringHueMin = BlueMin;
    ringHueMax = BlueMax;
}

static void event_rpr(lv_event_t * redPosReleased) {
    lv_label_set_text(redPosLabel, "Red\nPositive");
}

static void event_rn(lv_event_t * redNegClick) {
    std::cout << "Red Neg Side: " << redMinusSide << "\n";
    lv_label_set_text(autonName, "Red Negative\nCorner SAWP");
    lv_label_set_text(autonTimeEdit, "13 Seconds");
    lv_label_set_text(autonPointsEdit, "x1 Alliance Stake = 3\nx4 Mogo = 6\n\nTotal = 9 + AWP");
    lv_label_set_text(colorSortEdit, "Sorting Blue Rings");
    flip = 1;
    auton = 1;

    //Switch Ring Sort Colour To Blue
    ringHueMin = BlueMin;
    ringHueMax = BlueMax;
}

static void event_rnr(lv_event_t * redNegReleased) {
    lv_label_set_text(redNegLabel, "Red\nNegative");
}

static void event_s(lv_event_t * skillsClick) {
    std::cout << "Skills: " << skillsAuton << "\n";
    lv_label_set_text(autonName, "Skills Auton");
    lv_label_set_text(autonTimeEdit, "60 Seconds");
    lv_label_set_text(autonPointsEdit, "x2 Alliance Stake = 6\nx2 Full Mogo = 16\nx4 Corner = 20\n\nTotal = 42");
    lv_label_set_text(colorSortEdit, "Sorting Blue Rings");
    flip = 1;
    auton = 2;

    //Switch Ring Sort Colour To Blue
    ringHueMin = BlueMin;
    ringHueMax = BlueMax;
}

static void event_sr(lv_event_t * skillsReleased) {
    lv_label_set_text(skillsLabel, "Skills\nAuton");
}


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

    lv_style_set_bg_color(&posToggle, lv_palette_main(LV_PALETTE_BLUE_GREY));
    lv_style_set_bg_grad_color(&posToggle, lv_palette_darken(LV_PALETTE_BLUE_GREY, 2));

    static lv_style_t negToggle;
    lv_style_init(&negToggle);

    lv_style_set_bg_color(&negToggle, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_bg_grad_color(&negToggle, lv_palette_darken(LV_PALETTE_BLUE, 2));

    //Auton Box Style
    static lv_style_t boxStyle;
    lv_style_init(&boxStyle);

    lv_style_set_bg_color(&boxStyle, lv_palette_darken(LV_PALETTE_GREY, 4));
    lv_style_set_border_color(&boxStyle, lv_color_white());
    
    //Big Text
    static lv_style_t bigText;
    lv_style_init(&bigText);

    lv_style_set_text_font(&bigText, &lv_font_montserrat_20);

    //Creating Groups
    bluePos = lv_group_create();
    blueNeg = lv_group_create();
    redPos = lv_group_create();
    redNeg = lv_group_create();
    skillsb = lv_group_create();
    cornerSw = lv_group_create();
    autonInfo = lv_group_create();

    //Creating Objects
    allianceSwitch = lv_switch_create(lv_scr_act());
    cornerSwitch = lv_switch_create(lv_scr_act());
    autonBox = lv_obj_create(lv_scr_act());
    autonTime = lv_label_create(autonBox);
    autonPoints = lv_label_create(autonBox);
    colorSort = lv_label_create(autonBox);
    autonName = lv_label_create(autonBox);
    autonPointsEdit = lv_label_create(autonBox);
    autonTimeEdit = lv_label_create(autonBox);
    colorSortEdit = lv_label_create(autonBox);

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

    lv_group_add_obj(cornerSw, cornerSwitch);
    lv_group_add_obj(autonInfo, autonBox);
    lv_group_add_obj(autonInfo, autonTime);
    lv_group_add_obj(autonInfo, autonPoints);
    lv_group_add_obj(autonInfo, colorSort);
    lv_group_add_obj(autonInfo, autonTimeEdit);
    lv_group_add_obj(autonInfo, autonPointsEdit);
    lv_group_add_obj(autonInfo, colorSortEdit);



    
    lv_label_set_text(bluePosLabel, "Blue\nPositive");
    lv_obj_center(bluePosLabel);
    lv_obj_add_style(bluePosBtn, &styleBlue, 0);
    lv_obj_add_style(bluePosBtn, &styleBlue_pr, LV_STATE_PRESSED);
    lv_obj_set_size(bluePosBtn, 70, 70);
    lv_obj_align(bluePosBtn, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_obj_add_event_cb(bluePosBtn, event_bp, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(bluePosBtn, event_bpr, LV_EVENT_RELEASED, NULL);

    lv_label_set_text(blueNegLabel, "Blue\nNegative");
    lv_obj_center(blueNegLabel);
    lv_obj_add_style(blueNegBtn, &styleBlue, 0);
    lv_obj_add_style(blueNegBtn, &styleBlue_pr, LV_STATE_PRESSED);
    lv_obj_set_size(blueNegBtn, 70, 70);
    lv_obj_align(blueNegBtn, LV_ALIGN_LEFT_MID, 10, 10);
    lv_obj_add_event_cb(blueNegBtn, event_bn, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(blueNegBtn, event_bnr, LV_EVENT_RELEASED, NULL);

    lv_label_set_text(redPosLabel, "Red\nPositive");
    lv_obj_center(redPosLabel);
    lv_obj_add_style(redPosBtn, &styleRed, 0);
    lv_obj_add_style(redPosBtn, &styleRed_pr, LV_STATE_PRESSED);
    lv_obj_set_size(redPosBtn, 70, 70);
    lv_obj_align(redPosBtn, LV_ALIGN_TOP_LEFT, 90, 10);
    lv_obj_add_event_cb(redPosBtn, event_rp, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(redPosBtn, event_rpr, LV_EVENT_RELEASED, NULL);

    lv_label_set_text(redNegLabel, "Red\nNegative");
    lv_obj_center(redNegLabel);
    lv_obj_add_style(redNegBtn, &styleRed, 0);
    lv_obj_add_style(redNegBtn, &styleRed_pr, LV_STATE_PRESSED);
    lv_obj_set_size(redNegBtn, 70, 70);
    lv_obj_align(redNegBtn, LV_ALIGN_LEFT_MID, 90, 10);
    lv_obj_add_event_cb(redNegBtn, event_rn, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(redNegBtn, event_rnr, LV_EVENT_RELEASED, NULL);

    lv_label_set_text(skillsLabel, "Skills\nAuton");
    lv_obj_center(skillsLabel);
    lv_obj_add_style(skillsBtn, &styleRed, 0);
    lv_obj_add_style(skillsBtn, &styleRed_pr, LV_STATE_PRESSED);
    lv_obj_set_size(skillsBtn, 70, 155);
    lv_obj_align(skillsBtn, LV_ALIGN_TOP_LEFT, 170, 10);
    lv_obj_add_event_cb(skillsBtn, event_s, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(skillsBtn, event_sr, LV_EVENT_RELEASED, NULL);

    lv_obj_add_style(allianceSwitch, &redToggle, LV_STATE_DEFAULT);
    lv_obj_add_style(allianceSwitch, &blueToggle, LV_STATE_CHECKED);
    lv_obj_set_size(allianceSwitch, 100, 50);
    lv_obj_align(allianceSwitch, LV_ALIGN_BOTTOM_LEFT, 20, -10);
    
    lv_obj_add_style(cornerSwitch, &posToggle, LV_STATE_DEFAULT);
    lv_obj_add_style(cornerSwitch, &negToggle, LV_STATE_CHECKED);
    lv_obj_set_size(cornerSwitch, 100, 50);
    lv_obj_align(cornerSwitch, LV_ALIGN_BOTTOM_LEFT, 130, -10);
    

    //Create Box To Show Auton Info
    lv_obj_add_style(autonBox, &boxStyle, LV_STATE_DEFAULT);
    lv_obj_set_size(autonBox, 230, 230);
    lv_obj_align(autonBox, LV_ALIGN_CENTER, 120, 0);
    

    //Create Time Display For Autons
    lv_obj_align(autonTime, LV_ALIGN_CENTER, 0, -50);
    lv_obj_align(autonTimeEdit, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_style(autonTimeEdit, &bigText, 0);
    lv_label_set_text(autonTime, "Time To Complete Auton:");

    //Create Points Breakdown For Autons
    lv_obj_align(autonPoints, LV_ALIGN_CENTER, 0, 80);
    lv_obj_align(autonPointsEdit, LV_ALIGN_CENTER, 0, 150);
    lv_obj_add_style(autonPointsEdit, &bigText, 0);
    lv_label_set_text(autonPoints, "Points Break Down:");

    //Create Colour Sort Info For Autons
    lv_obj_align(colorSort, LV_ALIGN_CENTER, 0, 230);
    lv_obj_align(colorSortEdit, LV_ALIGN_CENTER, 0, 260);
    lv_obj_add_style(colorSortEdit, &bigText, 0);
    lv_label_set_text(colorSort, "Colour Sorting:");

    //Create Name For The Auton Info
    lv_obj_align(autonName, LV_ALIGN_CENTER, 0, -90);
    lv_obj_add_style(autonName, &bigText, 0);
    lv_label_set_text(autonName, "Auton Name:");
}
