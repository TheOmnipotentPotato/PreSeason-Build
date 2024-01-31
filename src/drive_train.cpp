#include "main.h"
#include <iostream>
#include <vector>

#define OUT_GEAR_RATIO 72
#define IN_GEAR_RATIO 48
#define PI 3.1415926
#define DIAMETER 4.25
#define WHEELBASE_WIDTH 13.5



bool check_drive_motor_not_done(std::vector<double> positions, double goal_pos){
    if(!(positions[0] < goal_pos -5 && positions[0] > goal_pos +5)){
        return true;
    } 
    if(!(positions[1] < goal_pos -5 && positions[1] > goal_pos +5)){
        return true;
    }
    if(!(positions[2] < goal_pos -5 && positions[2] > goal_pos +5)){
        return true;
    }
    if(!(positions[3] < goal_pos -5 && positions[3] > goal_pos +5)){
        return true;
    }
    else{
        return false;
    }
}

void drive_for(double dist, int pow){
    double revs = dist/DIAMETER*PI;
    double encoder_turns = revs*75;
    double tot_rev = (OUT_GEAR_RATIO/IN_GEAR_RATIO)*encoder_turns;
    std::vector<double> positions = DT.get_positions();
    DT.move_relative(tot_rev, pow);
    /*
    while(check_drive_motor_not_done(positions, tot_rev)){
        pros::delay(5);
        positions = DT.get_positions();
    }
    */

}




//left right is determined by the power of the motor
//(-) => 
//(+) => 
void turn_for(double angle, int pow){
    DT_Left.set_reversed(true);
    double real_turn_angle = (angle*5)-5;
    DT.move_relative(real_turn_angle, pow);
    pros::delay(4000);
}

void turn_for_2(double angle, int pow){
    DT_Left.set_reversed(true);
    double revs = (angle*PI*WHEELBASE_WIDTH)/DIAMETER;
    double motor_revs = (OUT_GEAR_RATIO/IN_GEAR_RATIO)*revs;
    //std::vector<double> positions = DT.get_positions();
    DT.move_relative(motor_revs, pow);
    pros::delay(2000);
}


