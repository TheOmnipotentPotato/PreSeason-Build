#include "main.h"

extern pros::Controller con;

//Drive Train Defs
extern pros::Motor DT_Right_Back;
extern pros::Motor DT_Right_Front;
extern pros::Motor DT_Right_Middle;
extern pros::Motor DT_Left_Back;
extern pros::Motor DT_Left_Front;
extern pros::Motor DT_Left_Middle;

//Cata Motor Defs
extern pros::Motor Flywheel_Mtr_Right;
extern pros::Motor Flywheel_Mtr_Left;



//Smart Devices
extern pros::Imu imu;

//Tri-Port Devices
extern pros::ADIDigitalOut wings_pistons;


//Motor groups
extern pros::Motor_Group Flywheel_Mtrs;
extern pros::Motor_Group DT_Right;
extern pros::Motor_Group DT_Left;
extern pros::Motor_Group DT;

