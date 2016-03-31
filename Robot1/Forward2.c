#pragma config(Motor,  port1,           leftMotor,     tmotorVex269_HBridge, openLoop)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex269_MC29, openLoop)

task main(){

}

void move(int length, int dir){

	//dir controls direction. Positive value goes forward, negative value goes backwards.
	//k is some constant which relates distance traveled to time in units of s/cm
	float k = 1;
	int time = length * k;
	int speedl = sgn((float) dir) * 58;
	int speedr = sgn((float) dir) * 46

	motor[leftMotor] = speedl;
	motor[rightMotor] = speedr;
	wait1Msec(time);
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;

}

void turn90(int dir){

	//change time depending on how long it actually takes to make a right turn;
	//positive dir makes a right turn, negative makes a left turn;
	int time = 2000;
	int speed = sgn( (float) dir) * 60;

	motor[leftMotor] = speed;
	wait1Msec(time);
	motor[leftMotor] = 0;

}
