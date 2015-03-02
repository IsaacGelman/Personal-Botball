const int L_MOTOR = 3;
const int R_MOTOR = 1;
const double WHEEL_CORRECTION_FACTOR = 1.03;
const int TICKS_PER_CM = 50;
const double TURN_CONVERSION = 6.4;
const int MOVE_SPEED = 50;
const int SLEEP = 58;
const int INFRARED_SENSOR = 2;
int ticks = 0;


//Conversions
int cmToTicks(double cm){
	
	return (cm*TICKS_PER_CM);
	
}

//Turning
void turn(int degrees, int turnSpeed) {
	
	//Turn Left if Negative
	if(degrees/TURN_CONVERSION < 0) {
			motor(L_MOTOR, -turnSpeed*WHEEL_CORRECTION_FACTOR);
			motor(R_MOTOR, turnSpeed);
			msleep(degrees/TURN_CONVERSION*SLEEP);
	}
	
	//Turn Right if Positive
	if(degrees/TURN_CONVERSION > 0) {
			motor(L_MOTOR, turnSpeed*WHEEL_CORRECTION_FACTOR);
			motor(R_MOTOR, -turnSpeed);
			msleep(degrees/TURN_CONVERSION*SLEEP);
		
	}
	
}

//Moving
void moveToDist(int distInCm, int velocity){
		
	clear_motor_position_counter(L_MOTOR);
	clear_motor_position_counter(R_MOTOR);
	
	//dist is positive
	if (velocity > 0){
		
		clear_motor_position_counter(L_MOTOR);
		clear_motor_position_counter(R_MOTOR);
		
		ticks = cmToTicks(distInCm);
		
		while (get_motor_position_counter(R_MOTOR) < ticks){
			motor(L_MOTOR, velocity * WHEEL_CORRECTION_FACTOR);
			motor(R_MOTOR, velocity);
			msleep(50);
		}
	}
	
	//dist is negative
	if (velocity < 0){
		
		clear_motor_position_counter(R_MOTOR);
		clear_motor_position_counter(L_MOTOR);
		
		ticks = -(cmToTicks(distInCm));
		
		while (get_motor_position_counter(R_MOTOR) > ticks){
			motor(L_MOTOR, velocity * WHEEL_CORRECTION_FACTOR);
			motor(R_MOTOR, velocity);
			msleep(50);
		}	
	
		}

	}
 
//Main
	
void main(){
	while (1 == 1){
		while (1 == 1){
		motor(R_MOTOR, 50);
		motor(L_MOTOR, 50 * WHEEL_CORRECTION_FACTOR);
			if(analog10(INFRARED_SENSOR) <= 500){
			break;
			}
		}
		turn(180, 50);
	}
	
}	
	
