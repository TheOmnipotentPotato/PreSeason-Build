#include "main.h"
#define SKILLS true
#define LOAD_TIME 30000



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	imu.reset();
	pros::lcd::initialize();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	if (SKILLS == true){
		DT.move(60);
		pros::delay(650);
		DT.move(0);
		pros::delay(60);
		turn_for_2(8.5, -50);
		pros::delay(20);
		DT.move(60);
		pros::delay(600);
		DT.move(-60);
		pros::delay(250);
		DT.move(60);
		pros::delay(300);
		DT.move(-60);
		pros::delay(500);
	

		
		Flywheel_Mtrs.move(127);
		pros::delay(LOAD_TIME);

	}
}



//--Controll Map--//
//L1 -> Intake
//L2 -> Outake
//R1 -> Shoot
//R2 -> Cata Down
//UP -> Cata Up
//X -> Wings
//A -> Open Wings
//B -> Close Wings
//--END Control Map--//

void opcontrol() {
	//--constants--//
	static int INTAKE_SPEED = 127;
	const static bool PID = true;
	const static bool ODM = true;
	const static bool CATA_STRESS = false;

	
	
	
	
	//--Cata Control Task--//
	

	//--Drive Control Task--//
	pros::Task drive{[=] {
		while(true)
		{	
			int y = con.get_analog(ANALOG_LEFT_Y);
			int x = con.get_analog(ANALOG_RIGHT_X);

			DT_Right.move(y - ((x > 25 or x < -25) ? x : 0));
			DT_Left.move(y + ((x > 25 or x < -25) ? x : 0));
			pros::delay(60);
		}
	}};

	
	//--Intake Control Task--//
	pros::Task intake { [=]{ 
		while(true)
		{
			if(con.get_digital(DIGITAL_R1)){Flywheel_Mtrs.move(127);}
			if(con.get_digital(DIGITAL_R2)){Flywheel_Mtrs.move(0);}
			if(con.get_digital(DIGITAL_L1)){wings_pistons.set_value(true);}
			if(con.get_digital(DIGITAL_L2)){wings_pistons.set_value(false);}
			pros::delay(20);
		}
	}};

	

}
