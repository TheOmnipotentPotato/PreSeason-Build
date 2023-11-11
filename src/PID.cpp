#include "main.h"


#define MAX_POW 127
#define MIN_POW -127

struct Vec3 {
    int kI;
    int kD;
    int kP;
};


void pid(int& power, int& goal_value, int& sensor_value, int& last, int& integral, Vec3& coef){

    
    int integral_thresh = 100;

    int kI = coef.kI;
    int kD = coef.kD;
    int kP = coef.kP;

    int error = goal_value - sensor_value;
    int derivative;

    if(kI != 0){
        if(abs(error)<=integral_thresh){
            integral += error;
        }else{integral = 0;}
    }
    else{
        integral = 0;
    }


    derivative = error - last;
    last = error;

    power = error*kP + derivative*kD + integral*kI;

    if(power>MAX_POW){power=MAX_POW;}
    else if(power<MIN_POW){power=MIN_POW;}
}