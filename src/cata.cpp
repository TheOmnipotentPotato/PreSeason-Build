#include "main.h"
#include <iostream>
#define REST_ANGLE 200

//MMMMMM Variables in the global scope and functions with side effects :)




void cata_down(){
    Cata_Mtrs.set_brake_modes(MOTOR_BRAKE_HOLD);
    while (cata_rot_sense.get_angle() < REST_ANGLE)
    {
        std::cout << cata_rot_sense.get_angle() << std::endl;
        std::cout << "I want to die :)" << std::endl;
        Intake_Mtr.move(127);
        Cata_Mtrs.move(127);
    }
    Cata_Mtrs.move(0);
    Cata_Mtrs.brake();
}

void cata_up(){
    Cata_Mtrs.set_brake_modes(MOTOR_BRAKE_COAST);
    Cata_Mtrs.move(0);
    Cata_Mtrs.brake();
}

void cata_fire(){
    Cata_Mtrs.set_brake_modes(MOTOR_BRAKE_HOLD);
    while(cata_rot_sense.get_angle() > REST_ANGLE){
        Cata_Mtrs.move(127);
    }
    cata_down();
}