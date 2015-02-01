const int L_MOTOR = 3;
const int R_MOTOR = 1;
const int SLEEP_CONVERSION=35;
const double WHEEL_CORRECTION = .80;
const int SPEED = 100;
int moveDist(int distInCenti)
{
	int direction = 0;
	if(distInCenti < 0)
	{
		motor(L_MOTOR, -SPEED*WHEEL_CORRECTION);
		motor(R_MOTOR, -SPEED);
		msleep(-distInCenti*SLEEP_CONVERSION);
	}
	if(distInCenti > 0)
	{
		motor(L_MOTOR, SPEED*WHEEL_CORRECTION);
		motor(R_MOTOR, SPEED);
		msleep(distInCenti*SLEEP_CONVERSION);
	}
	return 0;
}
int main(){
	moveDist(50);
	/*
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
