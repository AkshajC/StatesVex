#include "main.h"
#include "lemlib/api.hpp"
#include <cmath>

ASSET(wingstart_txt);

// void cata_pulldown(){
// 	while((abs(abs(cur_pos)-target)) > error){
// 		cur_pos=rot_sensor.get_position();
// 		cata = -127;
// 		pros::delay(10);
// 	}
// 	cata =0;
// }

void fastTurn(float thetatarget, float error, bool isClockwise){
	int reverser = 1;
	if(isClockwise){
		reverser = -1;
	}
	leftMotors=64 * reverser;
	rightMotors=-64 * reverser;
	while(abs(thetatarget - chassis.getPose().theta) > error){
		pros::delay(10);
	}
	leftMotors=0;
	rightMotors=0;
}

void rush(float y, float error){
	
	leftMotors = (abs(y)/y) * 127;
	rightMotors = (abs(y)/y) * 127;
	//(abs(x - chassis.getPose().x) > error) &&
	while( (abs(y - chassis.getPose().y) > error)){
		pros::delay(10);
	} 
	leftMotors=0;
	rightMotors=0;
}
void cancel(){
	leftMotors = 0;
	rightMotors = 0;
}
void ram(int time){
	leftMotors = 127;
	rightMotors = 127;
	pros::delay(time);
	leftMotors=0;
	rightMotors=0;
}
void ram_reverse(int time){
	leftMotors=-127;
	rightMotors=-127;
	pros::delay(time);
	leftMotors=0;
	rightMotors=0;
}
void oneBallPush(){
	chassis.moveToPose(22, -17, -90, 3000, {.forwards=false, .minSpeed=65}, false);
	ram(3000);
	chassis.moveToPose(0, 0, 0, 3000);
}
void threeballsafe(){
	chassis.moveToPose(3, 13, 45, 3000, {}, false);
	flapLeftPiston.set_value(true);
	chassis.turnToPoint(0, 20, 3000);
	flapLeftPiston.set_value(false);
	// leftMotors=-36;
	// rightMotors=-36;
	chassis.moveToPose(-4, -4, 0, 3000, {.forwards=false}, false);
	int target = -12000;
	int error= 150;
	while(abs(target - rot_sensor.get_position())> error){
		hang=127;
		pros::delay(10);
	}
	hang = 0;
	leftMotors=-30;
	rightMotors=-30;


	// intake = 127;
	// chassis.moveToPose(0, 7, 0, 3000, {.forwards=true}, false);
	// chassis.moveToPose(1.75, -16, 0, 3000, {.forwards=false}, false);
	// flapLeftPiston.set_value(true);
	// chassis.moveToPose(8.5, -34, -75, 3000, {.forwards=false}, false);
	// flapLeftPiston.set_value(false);
	// chassis.moveToPose(3, -25, -50, 3000);
	// ram(3000);
	// chassis.moveToPose(3, -25, -50, 3000);
	// chassis.turnToPoint(40, -32, 3000);
	// chassis.moveToPose(40, -32, 90, 3000);

}

void sixballsafe(){
	chassis.setPose(0, 0, 0);
		// pros::delay(200);
	intake=127;
	pros::delay(200);
	int msb = 40;
	chassis.moveToPoint(2.5, -32, 1000, {.forwards=false, .minSpeed=msb});
	chassis.turnToPoint(8,-40, 1000, {.forwards=false, .minSpeed=20});
	chassis.moveToPoint(13, -47, 3000, {.forwards=false});
	chassis.turnToPoint(33, -67, 1000, {.minSpeed=20}, false);
	vertWing.set_value(true);
	pros::delay(200);
	// chassis.turnToHeading(34, 3000); //just a test
	chassis.turnToPoint(99, -30, 1000, {.minSpeed=msb}, false);
	pros::delay(200);
	vertWing.set_value(false);
	chassis.turnToHeading(120, 500, {.minSpeed=msb}, false);
	intake=-127;
	// pros::delay(300);
	// chassis.moveToPoint(7, -41, 1000, {.forwards=false});

	// chassis.turnToPoint(1.5, -30, 1000, false);
	// chassis.turnToHeading(-58, 1000, false);
	// vertWing.set_value(true);
	flapLeftPiston.set_value(true);
	ram(700);

	// flapLeftPiston.set_value(false);
	pros::delay(300);
	chassis.moveToPoint(13, -47, 3000, {.forwards=false},false);
		flapLeftPiston.set_value(false);
	ram(650);
	chassis.setPose(37, -59, chassis.getPose().theta);
	ram(100);
	chassis.moveToPose(36, -37.5, 35, 3000, {.forwards=false, .minSpeed=67});
	// chassis.turnToPoint(45, -35, 3000);
	intake=127;
	chassis.moveToPose(51.5, 0, 0, 2000, {.minSpeed=67});
	// pros::delay(200);
	chassis.turnToPoint(68, -40.5, 1000, {.minSpeed=67});
	chassis.moveToPose(68, -40.5, 180, 1000, {.minSpeed=127});
	
	//temporary comment
	// // chassis.waitUntil(7);
	// // flapLeftPiston.set_value(true);
	// intake=0;
	// chassis.moveToPose(52, -5, 135, 3000, {.forwards=false, .minSpeed=64});
	// // flapLeftPiston.set_value(false);
	// chassis.turnToPoint(69, -3.5, 3000, {.minSpeed=64});
	// intake=127;
	// chassis.moveToPose(70.5, 16, 31, 1000, {.minSpeed=64});
	// chassis.turnToPoint(70.5, -36, 1000, {.minSpeed=64});
	// chassis.moveToPose(70.5, -36, 180, 1000, {.minSpeed=64});
	// flapLeftPiston.set_value(true);
	// flapRightPiston.set_value(true);
	// chassis.waitUntil(6);
	// intake=0;

	// chassis.moveToPose(29, -42, 40, 3000);
	// chassis.moveToPose(39, -9, 0, 3000);
	// chassis.moveToPose(36, -58, -90, 1000, {.minSpeed=127}, false);
	// vertWing.set_value(false);
	// pros::delay(700);

	// chassis.setPose(30, -57, chassis.getPose().theta);	

	// //uncomment
	// chassis.moveToPose(21, -35, 50, 3000);
	// intake=127;
	// chassis.moveToPose(39, -3, 0, 3000);
	// chassis.turnToPoint(51, -38, 3000);
	// chassis.moveToPose(49.5, -41, 180, 3000);
	// chassis.waitUntil(8);
	// intake=-127;
	// chassis.moveToPose(36, -16, 150, 3000, {.forwards=false});
	// intake=127;
	// chassis.moveToPose(53, 0.5, 30, 3000);
	// chassis.turnToPoint(49.5, -41, 3000);

	// chassis.moveToPose(51, -41, 180, 3000, {.minSpeed=127});
	// 	flapLeftPiston.set_value(true);
	// flapRightPiston.set_value(true);
	// //uncomment


	/*
	chassis.moveToPose(50, -3, 0, 3000);
	chassis.turnToPoint(47, -41, 3000);
	chassis.moveToPose(47, -41, 180, 3000);
	chassis.waitUntil(6);
	intake=-127;
*/
		// chassis.moveToPose(15, -41, 60, 1000, {.forwards=false, .minSpeed=127}, false);


// flapLeftPiston.set_value(false);
// flapRightPiston.set_value(false);
// while(true){
// 	if()
// }







/*
	chassis.moveToPoint(-42, 51.5, 3000, false);
	chassis.turnToPoint(-23, 77, 1000, false); // move to descore setup
	chassis.moveToPose(-52, 44, 0, 3000, {.forwards=false}); 
	chassis.turnToPoint(-76, 25, 100, false);
	// descore movement
	chassis.moveToPose(-60, 26, 0, 3000, {.forwards=false}); // ram movement
	chassis.moveToPose(-57, 44, 45, 3000, {}); //back up from side of goal to score first triball
	chassis.turnToPoint(-60, 26, 3000);
	//
	/*
	chassis.turnToPoint(-60, 26, 1500);
	chassis.turnToPoint(-51, 31, 1500);
		chassis.turnToPoint(-60, 26, 1500);
	chassis.moveToPose(-60, 26, 0, 3000, {.forwards=false}); // ram movement

/*
	chassis.moveToPose(-60, 26, 180, 3000, {}); // ram movement
	chassis.waitUntil(3);
	intake=-127;
	


	
	chassis.moveToPoint(-48, 41, 3000, false); // posibly need to change back to move to pose for speed (backwards)
	chassis.turnToPoint(-6.5, 23.5, 3000);
	intake=127;
	chassis.moveToPose(-6.5, 23.5, -90, 3000, {}); // ram movement
	chassis.turnToPoint(-45, 13, 3000); // aim left triball 
	chassis.moveToPose(-45, 13, 90, 3000, {}); // pick up first triball
	chassis.turnToPoint(-3.5, 0.5, 3000); //face goal
	chassis.moveToPose(-3.5, 0.5, 90, 3000); // pick up triball
	chassis.turnToPoint(-44, 0, 3000); // face goal
	chassis.moveToPose(-44, 0, -90, 3000); // ram movement

	*/
}

void tuning_movements(){
	// chassis.moveToPose(20, 30, 90, 3000, {.minSpeed=127});
	// rush(20, 0.5);
	// rush(-20, 0.5);
	flapRightPiston.set_value(true);
	intake=127;
	chassis.moveToPose(-9, 50, -10, 3000, {.minSpeed=127});
	pros::delay(300);
	flapRightPiston.set_value(false);
	chassis.moveToPose(-1, 4, 14, 3000, {.forwards=false, .minSpeed=127}, false);
	intake=-127;
	pros::delay(340);
	chassis.turnToPoint(0, -2, 700);
	chassis.moveToPose(-13, -1.25, -90, 3000, {});
	intake=127;
	chassis.moveToPose(-39, -1.25, -90, 3000, {.minSpeed=66});
	chassis.moveToPose(1, 2.5, -90, 3000, {.forwards=false, .minSpeed=66});
	// fastTurn(-90, 20, false);
	// chassis.moveToPose(-6, -1, -90, 3000, {.lead=0.3, .minSpeed=40});

	// intake=127;
	// //-27

	// chassis.moveToPose(-32, -1, -90, 3000, {}, false);
	// // pros::delay(500);
	// chassis.moveToPose(2, -3, -90, 3000, {.forwards=false});
	chassis.turnToPoint(18.5, 25.5, 1000, false);
	// pros::delay(400);
	flapLeftPiston.set_value(true);
	chassis.moveToPose(14, 16, 200, 3000, {.forwards=false,.lead=0.6, .minSpeed=127});
	chassis.waitUntil(16);
	flapRightPiston.set_value(true);
	// flapLeftPiston.set_value(false);
	// ram(400);
	// chassis.moveToPose(10,12 ,215, 3000);
	// chassis.turnToPoint(23, 15, 700);
	// chassis.turnToPoint(27, 30, 700);

	// chassis.moveToPose(32, 38, 45, 3000, {.lead=0.8, .minSpeed=127});
	// flapLeftPiston.set_value(true);
	// chassis.waitUntil(2);
	// intake=-127;
	



}
void winpointScore(){
	vertWing.set_value(true);
	pros::delay(500);
	chassis.turnToHeading(-65, 1000, false);
	vertWing.set_value(false);
	chassis.turnToHeading(0, 1000);
	chassis.moveToPose(2, -15, 45, 3000, {.forwards=false}, false);
	ram_reverse(500);
	chassis.moveToPose(4, 4, -45, 3000);
	intake=-127;
	chassis.moveToPose(-25, 29, -45, 3000);
}
void testing(){
	// Winpoint uncomment later
	// chassis.moveToPose(-22, -17, 90, 3000, {.forwards=false, .minSpeed=65});
	// pros::delay(700);
	// chassis.moveToPose(-10, -12, 45, 3000, {.forwards=true});
	// chassis.turnToPoint(-22, -17, 3000, false);
	// flapLeftPiston.set_value(true);
	// chassis.moveToPose(-3.5, 0, 180, 3000, {.forwards=false, .lead=0.4}, false);
	// flapLeftPiston.set_value(false);
	// // chassis.turnToPoint(2, 31, 3000);
	// intake=-127;
	//feb 24 breakpoint

	vertWing.set_value(true);
	pros::delay(2000);
	chassis.turnToHeading(-45, 3000, false);
	pros::delay(500);
	vertWing.set_value(false);
	chassis.moveToPose(-25, 29, -45, 3000);
	intake=-30;



	// chassis.moveToPose(2, 26.5, 0, 3000, {.forwards=true, .minSpeed=127, .lead=0.4});
	

	//Disrupt Elims
	// flapLeftPiston.set_value(true);
	// intake = 127;
	// chassis.moveToPose(12, 37, 0, 3000, {.forwards=true, .minSpeed=65});
	// pros::delay(300);
	// flapLeftPiston.set_value(false);
	// chassis.moveToPose(6, 32.5, 90, 3000, {.forwards=false});
	// flapLeftPiston.set_value(true);
	// flapRightPiston.set_value(true);
	// chassis.moveToPose(27, 34, 90, 3000, {.forwards=true, .minSpeed=40}, false);
	// intake = -127;
	// pros::delay(3000);
	// flapLeftPiston.set_value(false);
	// flapRightPiston.set_value(false);

}
void states_skills(){
	flapLeftPiston.set_value(true);
	pros::delay(450);
	flapLeftPiston.set_value(false);
	chassis.turnToHeading(165, 3000);
	chassis.moveToPoint(-14, 10, 3000, {.forwards=false, .maxSpeed=80});
	chassis.turnToHeading(60, 3000, false);
	// chassis.moveToPose(-14, 6, 60, 3000, {.forwards=false});
	pros::delay(1000);
	chassis.turnToHeading(180, 3000, false);
	chassis.moveToPose(-17, 28, 180, 3000, {.forwards=false});
	pros::delay(1000);
	chassis.moveToPose(7, 25, 45, 3000);
	chassis.moveToPose(30, 31, 90, 3000, {});
	chassis.turnToHeading(200, 3000, false);
	vertWing.set_value(true);
	chassis.moveToPose(37.5, 104.5, 180,3000, {.forwards=false, .minSpeed=100}, false);
	chassis.moveToPose(36, 90, 192, 3000, {}, false);
	chassis.moveToPose(38.5, 108, 180, 3000, {.forwards=false, .minSpeed=115}, false);
	vertWing.set_value(false);
	pros::delay(200);
	chassis.setPose(0, 0, chassis.getPose().theta-180);
	pros::delay(200);
	chassis.moveToPose(30, 2, 110, 3000, {.minSpeed=70});

	chassis.moveToPose(43, -5, 160, 3000, {.minSpeed=70});
	chassis.moveToPose(30, -24.5, 230, 3000, {.minSpeed=70});
	flapLeftPiston.set_value(true);
	flapRightPiston.set_value(true);
	chassis.moveToPose(11, -28, 270, 3000, {.minSpeed=70});
		flapLeftPiston.set_value(false);
	flapRightPiston.set_value(false);
	chassis.moveToPose(-44, -28.5, 270, 3000, {.minSpeed=70});
	chassis.moveToPose(-78, 10, 360, 3000, {.minSpeed=127});
	flapRightPiston.set_value(true);
	flapLeftPiston.set_value(true);

	chassis.moveToPose(-78, -6, 315, 3000, {.forwards=false});
	flapRightPiston.set_value(false);
		flapLeftPiston.set_value(false);
	chassis.turnToHeading(155, 3000, false);
	ram_reverse(1000);
	pros::delay(200);
	chassis.setPose(0, 0, chassis.getPose().theta);

	// leftMotors=-60;
	// rightMotors=-60;
	// pros::delay(550);
	// leftMotors=0;
	// rightMotors=0;


	// pros::delay(400);
	// chassis.setPose(0, 0, chassis.getPose().theta);
	// pros::delay(400);
	// chassis.moveToPose(0, 10, -168, 3000, {.forwards=false});
	// chassis.moveToPose(-4, -2, 0, 3000, {.forwards=true, .minSpeed=90});
	// ram_reverse(1500);
}
void disrupt(){
	// 	flapLeftPiston.set_value(true);
	// intake = 127;
	// chassis.moveToPose(12, 37, 0, 3000, {.forwards=true, .minSpeed=65});
	// pros::delay(300);
	// flapLeftPiston.set_value(false);
	// chassis.moveToPose(6, 32.5, 90, 3000, {.forwards=false});
	// flapLeftPiston.set_value(true);
	// flapRightPiston.set_value(true);
	// chassis.moveToPose(27, 34, 90, 3000, {.forwards=true, .minSpeed=40}, false);
	// intake = -127;
	// pros::delay(3000);
	// flapLeftPiston.set_value(false);
	// flapRightPiston.set_value(false);
	// flapRightPiston.set_value(true);
	pros::delay(100);
	chassis.moveToPose(7, 47, 0, 1200, {.minSpeed=127});
	intake=127;
	chassis.moveToPose(3, 43, 90, 1200, {.forwards=false, .minSpeed=127});
	// chassis.waitUntil(3);
	// intake=-127;
	chassis.moveToPose(26, 43, 90, 1200, {.minSpeed=127});
	flapLeftPiston.set_value(true);
	chassis.moveToPose(-20, 4, 40, 1800, {.forwards=false});
	flapLeftPiston.set_value(false);
	chassis.turnToHeading(130, 1200);
	chassis.moveToPose(-8.5, -5.5, 90, 1800, {.maxSpeed=80});
	chassis.waitUntil(4);
	vertWing.set_value(true);
	pros::delay(500);
	vertWing.set_value(false);
	chassis.moveToPose(22, -4, 90, 3000);
	intake=-127;
	chassis.moveToPose(-19, -1, 110, 3000, {.forwards=false}, false);
	// vertWing.set_value(true);



	//new disrupt feb 24


	// chassis.setPose(0, 0, 0);
	// pros::delay(50);
	// flapRightPiston.set_value(true);
	// chassis.moveToPose(0, 47, 0, 3000, {.minSpeed=127});
	// intake=127;
	// pros::delay(50);
	// flapRightPiston.set_value(false);
	// chassis.moveToPose(-2, 2, 0, 3000, {.forwards=false, .minSpeed=64});
	// chassis.turnToHeading(80, 1000, false);
	// intake=-127;
	// pros::delay(400);
	// chassis.turnToPoint(8, 55, 1000);
	// chassis.moveToPose(8, 55, -7, 3000);
	// intake=127;
}



// void skills(){
// 	target=3000;
// 	// blocker.set_value(true);
// 	flapRightPiston.set_value(true);
// 	// chassis.turnToPoint(0, -10, 3000);
// 	pros::delay(400);
// 	// blocker.set_value(false);
// 	flapRightPiston.set_value(false);
// 	chassis.moveToPose(-14.5, 9.5, -106.5, 2000, {.forwards=true, .lead=0.45});
// 	// cata=-127;
// 	pros::delay(30500);
// 	chassis.setPose(-14.5, 9.5, -105);
// 	pros::delay(200);
// 	// flapRightPiston.set_value(false);
// 	chassis.moveToPose(10.5, -6.5, -90, 3000, {.forwards=false, .lead=0.6});
// 	// cata_pulldown();
// 	chassis.moveToPose(83.4, -6.5, -90, 3000, {.forwards=false});
// 	chassis.waitUntil(50);
// 	flapRightPiston.set_value(true);
// 	chassis.turnToPoint(106.5, 20.5, 3000, false);
// 	chassis.moveToPose(101.5, 13, -160, 3000, {.forwards=false, .lead = -0.3}, false);
// 	ram(1000);
// 	chassis.moveToPose(101.5, 13, -160, 3000, {.forwards=true, .lead = 0.3}, false);
// 	flapRightPiston.set_value(false);
// 	ram(1000);
// 	pros::delay(700);
// 	chassis.setPose(0, 0, 0);
// 	pros::delay(200);
// 	chassis.moveToPose(17.5, 16.5, 55, 3000);
// 	chassis.turnToPoint(50, -10, 700);
// 	// chassis.follow(wingstart_txt, 15, 3000);
// 	flapRightPiston.set_value(false);
// 	//fix this tmw for DEC 29
// 	chassis.moveToPose(53, -12, 180, 2000, {.lead = 0.43}, false);
// 	chassis.moveToPose(20, -17.5, 90, 2000, {.forwards=false, .lead=-0.4});
// 	// chassis.turnToPoint(83, -14, 700, true, 127, false);
// 	flapLeftPiston.set_value(true);
// 	ram(700);
// 	flapLeftPiston.set_value(false);
// 	chassis.moveToPose(54, -58, 180, 2000);
// 	chassis.turnToPoint(81, -79, 700);
// 		flapLeftPiston.set_value(true);
// 	flapRightPiston.set_value(true);
// 	chassis.moveToPoint(27, -34.5, 3000, false, 64, false);
// 	flapLeftPiston.set_value(false);
// 	flapRightPiston.set_value(false);
// 	chassis.moveToPose(56, -30, 90, 3000, {.forwards=true}, false);
// 	flapLeftPiston.set_value(true);
// 	flapRightPiston.set_value(true);
// 	ram(1300);
// 		flapLeftPiston.set_value(false);
// 	flapRightPiston.set_value(false);
// 	// chassis.moveToPose(45.5, -44, 215, 3000, {.forwards=true});
// 	chassis.moveToPoint(54, -28, 3000);
// 	intake=-127;
// 	// flapLeftPiston.set_value(false);
// 	// flapRightPiston.set_value(false);




// 	// chassis.moveToPose(53, -60, 245, 2000);
// 	// flapLeftPiston.set_value(true);
// 	// 	flapRightPiston.set_value(true);

// 	// chassis.moveToPose(100, 5, -165, 3000, {.forwards=false}, false);
// 	// chassis.moveToPose(90, 0, -150, 3000, {}, false);
// 	// ram(3000);
// 	// chassis.moveToPose(90, 0, -150, 3000, {}, false);
// 	// chassis.turnToPoint(106, 27, 1000, false);
// 	// chassis.moveToPose(103, 20, -180, 3000, {.forwards = false, .lead=0.5});



// 	// blocker.set_value(true);
// 	// flapLeftPiston.set_value(true);
// 	// pros::delay(600);
// 	// flapLeftPiston.set_value(false);
// 	// blocker.set_value(false);
// 	// // chassis.moveToPose(0, 0, 100, 4000, false, true, 0, 0.6, 20, false);
// 	// chassis.turnToPoint(6, -16.3, 3000);
// 	// cata=-127;
// 	// // 26500
// 	// pros::delay(26500);

// 	// // cata=0;
// 	// // chassis.turnToPoint(-28, -5, 3000, true);
// 	// // chassis.turnToPoint(-24, 5, 3000);
// 	// // flapLeftPiston.set_value(true);
// 	// // chassis.turnToPoint(13, 5, 4000);
// 	// flapLeftPiston.set_value(true);
// 	// chassis.moveToPose(-28, -3, 90, 4000, false, false, 4, 0.6, 127);
// 	// flapLeftPiston.set_value(false);
// 	// chassis.setPose(chassis.getPose().x, chassis.getPose().y, 90);
// 	// intake = -127;
// 	// int error=500;
// 	// int cur_pos=0;
// 	// int target= 3900;
// 	// while (abs(abs(cur_pos)-target) > error){
// 	// 	cur_pos=rot_sensor.get_position();
// 	// 	cata = -127;
// 	// }
// 	// cata = 0;
// 	// // cata=-127;
// 	// chassis.moveToPose(-2, 25, 0, 3000, false, true, 4, 0.5, 127);
// 	// chassis.moveToPose(-2, 95, 0, 3000);
// 	// cata=0;
// 	// chassis.moveToPose(-20, 85, 180, 3000, false, true, 4, 0.65, 63);
// 	// chassis.moveToPose(-69, 70, -90, 3000, false, true, 4, 0.85, 63);
// 	// // intake=0;
// 	// // pros::delay(500);
// 	// // chassis.turnToPoint(chassis.getPose().x, -100, 3000, 63);

// 	// flapLeftPiston.set_value(true);
// 	// flapRightPiston.set_value(true);

// 	// chassis.moveToPose(chassis.getPose().x, 100, 180, 3000, false, false, 6, 0, 127);
// 	// chassis.setPose(chassis.getPose().x, chassis.getPose().y, 180);
// 	// flapLeftPiston.set_value(false);
// 	// flapRightPiston.set_value(false);
// 	// chassis.moveToPose(-83, 73, 200, 3000, false, true, 4, -0.8, 127);
// 	// flapLeftPiston.set_value(true);
// 	// flapRightPiston.set_value(true);
// 	// chassis.moveToPose(-68, 100, 220, 3000, false, false, 4, 0, 127);
// 	// flapLeftPiston.set_value(false);
// 	// flapRightPiston.set_value(false);
// 	// chassis.moveToPose(-41.5, 80, 150, 3000, false, true, 4, -0.8, 127);
// 	// flapLeftPiston.set_value(true);
// 	// flapRightPiston.set_value(true);
// 	// chassis.moveToPose(-40, 100, 150, 3000, false,false, 4, 0, 127);
// 	// flapLeftPiston.set_value(false);
// 	// flapRightPiston.set_value(false);
// 	// chassis.moveToPose(-38, 80, 150, 3000, false, true, 4, -0.8, 127);
// 	// flapLeftPiston.set_value(true);
// 	// flapRightPiston.set_value(true);
// 	// chassis.moveToPose(-40, 100, 150, 3000, false,false, 4, 0, 127);
// 	// flapLeftPiston.set_value(false);
// 	// flapRightPiston.set_value(false);
// 	// chassis.moveToPose(-38, 80, 150, 3000, false, true, 4, -0.8, 127);
// 	// chassis.moveToPose(-4, 110, 150, 3000, false, false, 4, 0.9, 127);
// }