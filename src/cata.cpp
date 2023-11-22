#include "main.h"



void cata_down(double angle){
    Cata_Mtrs.set_brake_modes(MOTOR_BRAKE_HOLD);
    while (cata_rot_sens.get_angle() < angle)
    {
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

void cata_fire(double angle){
    Cata_Mtrs.set_brake_modes(MOTOR_BRAKE_HOLD);
    while(cata_rot_sens.get_angle() > angle){
        Cata_Mtrs.move(127);
    }
    cata_down();
}