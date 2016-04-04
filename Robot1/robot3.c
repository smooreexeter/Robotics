#pragma config(Sensor, dgtl1,  button,         sensorTouch)
#pragma config(Motor,  port2,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//graph of distance vs times can be found at https://www.desmos.com/calculator/oki7aqrys9


void wait(int len){
	wait1Msec(len);
}

void rampUp(int length, int targetSpeed, float fac, int dir){
	
	if(length == 0){
		length  = 30;
	}
	int time = length;
	int speed = 20;
	int interval = 5;
	
	while(speed < targetSpeed){
		motor[leftMotor] = speed * sgn(dir);
		motor[rightMotor] = speed * fac * sgn(dir);

		speed += interval;
		wait(time);
	}
	speed = targetSpeed;

}

void move(int length, int dir){
	
		
	int speedl = 58;
	int speedr = 48;


	//dir controls direction. Positive value goes forward, negative value goes backwards.
	//k is some constant which relates distance traveled to time in units of s/cm
	
	length = length * 1.338 - 8.6984;
	
	length -= 9;
	float k = 20.12; //21.739
	float b = 365.78;
	int time = length * k + b;
	speedl = sgn((float) dir) * speedl;
	speedr = sgn((float) dir) * speedr;
	
	rampUp(0,speedl, 0.7931, dir);
	

	motor[leftMotor] = speedl;
	motor[rightMotor] = speedr;
	wait1Msec(time);
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
	
	wait(1000);
}

void turn90(int dir, int mult, bool waitVar){
		
		
	int speedl = 58;
	int speedr = 48;
	

	for(int i = 0; i < mult; i++){
		//change time depending on how long it actually takes to make a right turn;
		//positive dir makes a right turn, negative makes a left turn;
		int time = 1600;
		//speedl = .9 * speedl;//sgn((float) dir) * 58;
		
		
		float tr = 0.8;
		float tl = 0.65;
		
		if(dir > 0){
			motor[leftMotor] = speedl;
			motor[rightMotor] = -speedr;
			wait1Msec(time*tr);
			motor[leftMotor] = 0;
			motor[rightMotor] = 0;
		}
		if(dir < 0){
			motor[rightMotor] = speedr;
			motor[leftMotor] = -speedl;
			wait1Msec(time*tl);
			motor[rightMotor] = 0;
			motor[leftMotor] = 0;
		}
		if(waitVar){
			wait(1000);
		}
	}

}

task main(){

	while(SensorValue[button] == 0){}
	
	//turn90(1, 1);
	//move(200, -1);
	//move(200, 1);
	//move(150, 1);
	///*
	move(200, 1);
	//wait(20000);
	turn90(-1, 1, true);
	move(250,1);
	//move(100, 1);
	//wait(20000);
	turn90(1, 2, true);
	move(56, 1);
	//move(50, 1);
	//wait(20000);
	turn90(1, 3, true);
	move(300, 1);
	turn90(-1, 12, false);
	//*/
	/*
	f 200
	left 90
	f 250
	right 180
	f 56
	right 270
	f 300
	left 360
	*/

}
