#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	imu.reset();
	pros::lcd::initialize();
	cata_rot_sens.reset_position();

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
void autonomous() {}



//--Controll Map--//
//L1 -> Intake
//L2 -> Outake
//R1 -> Shoot
//R2 -> Cata Down
//UP -> Cata Up
//X -> Wings
//--END Control Map--//

void opcontrol() {
	//--constants--//
	static int INTAKE_SPEED = 127;
	const static bool PID = true;
	const static bool ODM = true;
	const static double CATA_ANGLE = 180;

	
	
	Intake_Mtr.set_brake_mode(MOTOR_BRAKE_COAST);

	
	
	//--Cata Control Task--//
	pros::Task cata{[=] {
		//set start position
		//cata_down();
		//
		while(true)
		{
			if(con.get_digital_new_press(DIGITAL_R1)){cata_fire();}
			if(con.get_digital_new_press(DIGITAL_R2)){cata_down();}
			if(con.get_digital_new_press(DIGITAL_UP)){cata_up();}
			pros::delay(20);
		}
	}};

	//--Drive Control Task--//
	pros::Task drive{[=] {
		while(true)
		{	
			int y = -con.get_analog(ANALOG_LEFT_Y);
			int x = con.get_analog(ANALOG_RIGHT_X);

			DT_Right.move(y + x);
			DT_Left.move(y - x);
			pros::delay(20);
		}
	}};

	//--Odom Control Task--// 
	/*
	pros::Task odm{[=] {
		while (ODM)
		{
			pros::c::imu_gyro_s_t gyro = imu.get_gyro_rate();
			printf("IMU gyro values: {x: %f, y: %f, z: %f}\n", gyro.x, gyro.y, gyro.z);
            pros::delay(20);

		}
		
	}};
	*/


	//--Intake Control Task--//
	pros::Task intake { [=]{ 
		while(true)
		{
			if(con.get_digital(DIGITAL_L1)){Intake_Mtr.move(INTAKE_SPEED);}
			if(con.get_digital(DIGITAL_L2)){Intake_Mtr.move(-INTAKE_SPEED);}
			if(!con.get_digital(DIGITAL_L1) && !con.get_digital(DIGITAL_L2)){Intake_Mtr.move(0);Intake_Mtr.brake();}
			pros::delay(20);
		}
	}};

	//--Error Controller Task--//
	pros::Task control{[=]{
		//--LEFT MOTOR--//
		int left_mtr_power;
		int left_mtr_goal;
		int left_mtr_sensor;
		int left_mtr_last;
		int left_mtr_integral;
		Vec3 left_coef;
		left_coef.kP = 1.0;
		left_coef.kD = 1.0;
		left_coef.kI = 0.0;

		pid(left_mtr_power, left_mtr_goal, left_mtr_sensor, left_mtr_last, left_mtr_integral, left_coef);



		while (PID)
		{
			

		}
		
	}};

}
