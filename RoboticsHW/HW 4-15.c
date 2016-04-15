void GoForwardUntil(int dist){

	motor[leftMotor] = 65;
	motor[rightMotor] = 65;
	untilSonarLessThan(dist, dgt18);
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;

}