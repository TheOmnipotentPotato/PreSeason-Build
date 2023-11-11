#include "main.h"




void drive(int& x, int& y){
    DT_Right.move(-1*(y + x));
	DT_Left.move(x - y);
}