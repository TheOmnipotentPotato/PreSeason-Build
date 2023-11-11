#include "main.h"

void cata_down(){
    Cata_Mtrs.set_brake_modes(MOTOR_BRAKE_HOLD);
    while (!Cata_Limit.get_value())
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

void cata_fire(){
    Cata_Mtrs.set_brake_modes(MOTOR_BRAKE_HOLD);
    while(Cata_Limit.get_value()){
        Cata_Mtrs.move(127);
    }
    cata_down();
}