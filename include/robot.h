#include "main.h"

extern pros::Controller con;

//Drive Train Defs
extern pros::Motor DT_Right_Back;
extern pros::Motor DT_Right_Front;
extern pros::Motor DT_Left_Back;
extern pros::Motor DT_Left_Front;

//Cata Motor Defs
extern pros::Motor Cata_Mtr_Right;
extern pros::Motor Cata_Mtr_Left;

//Intake Motor Def
extern pros::Motor Intake_Mtr;

//Smart Devices
extern pros::Imu imu;
extern pros::Distance load_check;

//Tri-Port Devices
extern pros::ADIDigitalIn Cata_Limit;


//Motor groups
extern pros::Motor_Group Cata_Mtrs;
extern pros::Motor_Group DT_Right;
extern pros::Motor_Group DT_Left;