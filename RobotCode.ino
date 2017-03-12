#include <Arduino.h>
#include <Servo.h>

Servo rightServo;
Servo leftServo;

#define leftServoPin 9;
#define rightServoPin 10;
#define detectorTransmitPin 7;
#define detectorRecievePin 8;


int robotDetected(){
	//check for robot, return 1 for detected robot

}
void driveTo(int intersections){
	//code to drive to point
	//intersections is number to skip
}
int randomExit(){
	//generates random number of exits between 0 and 3
	return random(0,4);
}
void stopline(){ //what to do at a stop line
	while(!robotDetected()){
		delay(40);
	}
	driveTo(randomExit());
}

void setup() {
	//Start Serial
	Serial.begin(9600);
	//seed random number generator
	randomSeed(analogRead(0));
	//Start motor servos
	rightServo.attach(rightServoPin);
	leftServo.attach(leftServoPin);
	// Initialize Distance and Line sensors
}

void loop() {
  // put your main code here, to run repeatedly:

}
