#include "main.h"


//DRIVER CONTROL FUNCTIONS
void setLadyBrown();
void rotateLadyBrown();
void printRotSensor();
void nextState();
void liftControl();
void manualLiftControl();


//MOTOR POSITION
void displayMotorPosition();

extern bool primePosition;
extern bool firstRing;
extern bool freeStyle;




//AUTON FUNCTIONS
void ladyBrownLower();
void ladyBrownPrime();
void ladyBrownScore();
void ladyBrownIdle();
