#pragma config(Motor,  port1,           leftMotor,     tmotorVex269_HBridge, openLoop)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex269_MC29, openLoop)

task main(){
rampUp(127);

}

void rampUp(int finSpeed){
	int time = 10;
	finSpeed = finSpeed-20;

	for(int i = 1; i < time; i++){
		motor[leftMotor] = i*finSpeed/time;
		motor[rightMotor] = i*finSpeed/time;
		wait1Msec(100);
	//}

	motor[leftMotor] = finSpeed;
	motor[rightMotor] = finSpeed;
}
