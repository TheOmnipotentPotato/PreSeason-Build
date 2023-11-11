#include "main.h"



//Brain and Controler Deffs

pros::Controller con(pros::E_CONTROLLER_MASTER);

//Drive Train Defs
pros::Motor DT_Right_Back(11, MOTOR_GEAR_200, true, MOTOR_ENCODER_DEGREES);
pros::Motor DT_Right_Front(20, MOTOR_GEAR_200, true, MOTOR_ENCODER_DEGREES);
pros::Motor DT_Left_Back(10, MOTOR_GEAR_200, false, MOTOR_ENCODER_DEGREES);
pros::Motor DT_Left_Front(1, MOTOR_GEAR_200, false, MOTOR_ENCODER_DEGREES);

//Cata Motor Defs
pros::Motor Cata_Mtr_Right(15, MOTOR_GEAR_600, true, MOTOR_ENCODER_DEGREES);
pros::Motor Cata_Mtr_Left(5, MOTOR_GEAR_600, false, MOTOR_ENCODER_DEGREES);

//Intake Motor Def
pros::Motor Intake_Mtr(19, MOTOR_GEAR_200, false, MOTOR_ENCODER_DEGREES);

//Smart Devices
pros::Imu imu(21);
pros::Distance load_check(6);

//Tri-Port Devices
pros::ADIDigitalIn Cata_Limit(8);

//Motor Groups
pros::Motor_Group Cata_Mtrs({Cata_Mtr_Left, Cata_Mtr_Right});
pros::Motor_Group DT_Right({DT_Right_Back, DT_Right_Front});
pros::Motor_Group DT_Left({DT_Left_Back, DT_Left_Front});