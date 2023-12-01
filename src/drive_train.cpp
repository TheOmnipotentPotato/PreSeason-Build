#include "main.h"
#include <iostream>
#include <vector>

#define OUT_GEAR_RATIO 72
#define IN_GEAR_RATIO 48
#define PI 3.1415926
#define DIAMETER 4.25

bool check_drive_motor_done(std::vector<double> positions, double goal_pos){
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
    std::vector<double> inital_positions = DT.get_positions();
    DT.move_relative(tot_rev, pow);
    if(check_drive_motor_done(inital_positions, tot_rev)){
        pros::delay(5);
    }

}




//left right is determined by the power of the motor
//(-) => 
//(+) => 
void turn_for(int angle, int pow){
    pros::delay(20);
    DT_Left.set_reversed(true);
    int real_turn_angle = (angle*5)-5;
    DT.move_relative(real_turn_angle, pow);
    pros::delay(20);
    std::cout << "Turn Finished" << std::endl;
}


