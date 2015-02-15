const int L_MOTOR = 3;
const int R_MOTOR = 1;
const int SLEEP= 58;
const double TURN_CONVERSION= 6;
const double WHEEL_CORRECTION = 0.93;
const int SPEED = 100;
const double TICKS_PER_CM = 67.65;

//Moving
void moveToDist(int distInCm, int velocity){	

		
	int ticks = 0;
	//Moving When Distance is Negative
	if (velocity = 0) {
		
		printf("\nYou gave me a velocity of 0!!");
		
	}if (velocity < 0) {
		
		ticks = cmToTicks(distInCm);
		
		motor(L_MOTOR, -velocity * WHEEL_CORRECTION);
		motor(R_MOTOR, -velocity);
		
		while (get_motor_position_counter(R_MOTOR) < ticks) {
			msleep(15);
		}
	//Moving When Distance is Positive	
	} if ( velocity > 0) {
		
		ticks = -(cmToTicks(distInCm));
		
		motor(L_MOTOR, velocity * WHEEL_CORRECTION);
		motor(R_MOTOR, velocity);
		
		while (get_motor_position_counter(R_MOTOR) > ticks) {
			msleep(15);
		}
		
	}
	
}

//Turning
void turn(int degrees, int turnSpeed) {
	
	//Turn Left if Negative
	if(degrees/TURN_CONVERSION < 0) {
			motor(L_MOTOR, -turnSpeed*WHEEL_CORRECTION);
			motor(R_MOTOR, turnSpeed);
			msleep(degrees/TURN_CONVERSION*SLEEP);
	}
	
	//Turn Right if Positive
	if(degrees/TURN_CONVERSION > 0) {
			motor(L_MOTOR, turnSpeed*WHEEL_CORRECTION);
			motor(R_MOTOR, -turnSpeed);
			msleep(degrees/TURN_CONVERSION*SLEEP);
		
	}
	
}

//Input "moveDist" or "turn"(negative value turns left, positive turns right)
int main()
{
	//moveToDist(distInCm, speed(negative value goes forward))
	//turn(degrees, turnSpeed(turns right if positive)
	
	turn(360,50);
	msleep(50);
	turn(360,-50);
	
	//Straight Move Test//
	/*
	moveDist(40);
	printf("Finished Part 1!\n");
	moveDist(-50);
	printf("Finished Part 2!\n");
	moveDist(200);
	printf("Finished Part 3!\n");
	moveDist(-100);
	printf("Finished Part 4!\n");
	moveDist(400);
	printf("Finished Part 5!\n");
	moveDist(-200);
	printf("Finished Part 6!\n");
	printf("\n\nTa-Da!\n");
	return(0);
	*/
	
}

/*TICKS and MILLIMETERS*/

int cmToTicks(double cm) {
	
	return (cm * TICKS_PER_CM);
	
}
