#include "main.h"


struct Vec3 {
    int kI;
    int kD;
    int kP;
};


void pid(int& power, int& goal_value, int& sensor_value, int& last, int& integral, Vec3& coef);