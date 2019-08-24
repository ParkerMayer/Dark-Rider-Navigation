#include <Arduino.h>

// // // // // // // // //
//						//
//	this code was		//
//	written by ochoa	//
//						//
// // // // // // // // //

void goForward(int driveTime);
void turnLeft(int turnTime);

// assigning pin numbers to variables
byte leftMotorBck = 2; // bytes store values 0 to 255--perfect!
byte leftMotorFwd = 3;
byte leftPWM = 4;
byte rightMotorFwd = 5;
byte rightMotorBck = 6;
byte rightPWM = 7;


void setup() {

	// setting all the motor pins to OUTPUT
	pinMode(leftMotorBck, OUTPUT);
	pinMode(leftMotorFwd, OUTPUT);
	pinMode(leftPWM, OUTPUT);
	pinMode(rightMotorFwd, OUTPUT);
	pinMode(rightMotorBck, OUTPUT);
	pinMode(rightPWM, OUTPUT);

	goForward(1000); // go forward for 1000ms
	delay(100);
	turnLeft(800);	 // turn left for 800ms
	delay(100);
	goForward(3050); // go forward for 3050ms
	delay(100);
	turnLeft(800);	 // turn left for 800ms
	delay(100);
	goForward(1000); // go forward for 1000ms

} // end of setup()

void loop() {

}

// function to make Dark Rider go forward
void goForward(int driveTime){

	digitalWrite(leftMotorBck, LOW);
	digitalWrite(leftMotorFwd, HIGH);
	digitalWrite(rightMotorFwd, HIGH);
	digitalWrite(rightMotorBck, LOW);
	analogWrite(leftPWM, 200); // set a power between 0 and 255
	analogWrite(rightPWM, 200);// set a power between 0 and 255
	delay(driveTime);
	analogWrite(leftPWM, 0); // stop the left motor
	analogWrite(rightPWM, 0);// stop the right motor
}

// function to make Dark Rider turn left
void turnLeft(int turnTime){

	digitalWrite(leftMotorBck, HIGH);
	digitalWrite(leftMotorFwd, LOW);
	digitalWrite(rightMotorFwd, HIGH);
	digitalWrite(rightMotorBck, LOW);
	analogWrite(leftPWM, 200); // set a power between 0 and 255
	analogWrite(rightPWM, 200);// set a power between 0 and 255
	delay(turnTime);
	analogWrite(leftPWM, 0); // stop the left motor
	analogWrite(rightPWM, 0);// stop the right motor
}
