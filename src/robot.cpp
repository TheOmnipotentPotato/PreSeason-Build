#include "main.h"



//Brain and Controler Deffs

pros::Controller con(pros::E_CONTROLLER_MASTER);

//Drive Train Defs
pros::Motor DT_Right_Back(11, MOTOR_GEAR_200, false, MOTOR_ENCODER_DEGREES);
pros::Motor DT_Right_Front(20, MOTOR_GEAR_200, false, MOTOR_ENCODER_DEGREES);
pros::Motor DT_Right_Middle(15, MOTOR_GEAR_200, false, MOTOR_ENCODER_DEGREES);
pros::Motor DT_Left_Back(1, MOTOR_GEAR_200, true, MOTOR_ENCODER_DEGREES);
pros::Motor DT_Left_Front(10, MOTOR_GEAR_200, true, MOTOR_ENCODER_DEGREES);
pros::Motor DT_Left_Middle(5, MOTOR_GEAR_200, true, MOTOR_ENCODER_DEGREES);

//Cata Motor Defs
pros::Motor Flywheel_Mtr_Right(16, MOTOR_GEAR_600, false, MOTOR_ENCODER_DEGREES);
pros::Motor Flywheel_Mtr_Left(6, MOTOR_GEAR_600, true, MOTOR_ENCODER_DEGREES);


//Smart Devices
pros::Imu imu(21);

//Tri Port Devices
pros::ADIDigitalOut wings_pistons(1);

//Motor Groups
pros::Motor_Group Flywheel_Mtrs({Flywheel_Mtr_Left, Flywheel_Mtr_Right});
pros::Motor_Group DT_Right({DT_Right_Back, DT_Right_Front, DT_Right_Middle});
pros::Motor_Group DT_Left({DT_Left_Back, DT_Left_Front, DT_Left_Middle});
pros::Motor_Group DT({DT_Left_Back, DT_Left_Front,DT_Left_Middle , DT_Right_Back, DT_Right_Front, DT_Right_Middle});
