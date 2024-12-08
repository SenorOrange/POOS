#include "main.h"
#include <stdbool.h>

//POOS FUNCTIONS

void drawGUI();
void touchTester();
void autonSelector();
void testBools();

static void event_bp();
static void event_bn();
static void event_rp();
static void event_rn();
static void event_s();

static void event_bpr();
static void event_bnr();
static void event_rpr();
static void event_rnr();
static void event_sr();

extern bool bluePlusSide;
extern bool blueMinusSide;
extern bool blueRush;
extern bool blueAWP;
extern bool redPlusSide;
extern bool redMinusSide;
extern bool redRush;
extern bool redAWP;
extern bool skillsAuton;

extern int auton;

extern int flip;

//Color Sort Variables
extern int ringHueMin;
extern int ringHueMax;
extern int RedMin;
extern int RedMax;
extern int BlueMin;
extern int BlueMax;

