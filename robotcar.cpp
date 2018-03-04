/*****************************************************

Obstacle avoiding robot car.

This code is for the cheep robot car arduino kit you can get on ebay for about $20
Code authored by: Annalise Kenedy-Clark ( with a little help from dad )


*****************************************************/

// Servo 
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int servoPin = 5;   // this can be changed but it must be a PWM pin

//  Ultrasonic Sensor HC-SR04 
const int trigPin = A0;
const int echoPin = A1;
long duration;
int distance;

/*
Motor A truth table
ENA	IN1	IN2	Description
0	N/A	N/A	Motor A is off
1	0	0	Motor A is stopped (brakes)
1	0	1	Motor A is on and turning backwards
1	1	0	Motor A is on and turning forwards
1	1	1	Motor A is stopped (brakes)
 

Motor B truth table
ENB	IN3	IN4	Description
0	N/A	N/A	Motor B is off
1	0	0	Motor B is stopped (brakes)
1	0	1	Motor B is on and turning backwards
1	1	0	Motor B is on and turning forwards
1	1	1	Motor B is stopped (brakes)

*/


// Left Motor
int in1 = 11;
int in2 = 10;

// Right Motor
int in3 = 9;
int in4 = 8;

int minumumAlowedDistance = 20; // distance in centimetres at which robot will turn to avoid an object
int timeToTurn90Deg = 1500; // milliseconds to spend turning to turn about 90 deg

// this code  only runs once
// this is where we set up the Arduino, tell it what pins are connected
void setup()
{
    // set all the motor control pins to outputs
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    // attach the servo
    myservo.attach(servoPin);  // attaches the servo on pin to the servo object
    
    // set the ultrasonic sensor pins
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
	pinMode(echoPin, INPUT); // Sets the echoPin as an Input
	
	// turn on serial logging for debugging
	Serial.begin(9600); // Starts the serial communication

    drive();
}


// the logic to check if we should drive or turn, runs over and over in this loop.
void loop(){
    // check to see if the way ahead is clear
    if(getDistanceFoward > minumumAlowedDistance){
        // nothing is too close in front so drive forward
        drive();        
    } else { 
        // opps something is in front of the robot   
        // get distance left and get distance right and turn towards greatest distance
        if ( getDistanceLeft() > getDistanceRight() ){
            turnLeft();
        } else {
            turnRight();
        }        
        // we have turned left or right, assume we can now go foward
        drive();
    }    
}

/* helper functions */

// looking and measuring the distance
int getDistanceLeft(){
    lookLeft();
    return getDistance();
}

int getDistanceRight(){
    lookRight();
    return getDistance();
}

int getDistanceFoward(){
    lookFoward();
    return getDistance();
}


void lookLeft(){
     myservo.write(180);        // tell servo to go to the Right position 
     delay(500);                // give the servo a few millyseconds to reach the position    
}

void lookRight(){
     myservo.write(0);        // tell servo to go to the Right position 
     delay(500);                // give the servo a few millyseconds to reach the position    
}

void lookFoward(){
    myservo.write(80);         // tell servo to go to the center position 
    delay(500);                // give the servo a few millyseconds to reach the center    
}


// get the distance in cm from the HC-SR04 ultrasonic sensor as an int
int getDistance(){

	// Clears the trigPin
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	// Sets the trigPin on HIGH state for 10 micro seconds
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	// Reads the echoPin, returns the sound wave travel time in microseconds
	duration = pulseIn(echoPin, HIGH);
	// Calculating the distance
	distance= (duration * 0.034)/2;
	// Prints the distance on the Serial Monitor
	Serial.print("Distance: ");
	Serial.println(distance);

	return distance;
}



/* drive or change direction functions */
void drive(){
    leftMotorFoward();
    rightMotorFoward();
}
void reverse(){
    leftMotorReverse();
    rightMotorReverse();
}
void stop(){
    leftMotorStop();
    rightMotorStop();
}

void turnLeft(){
    rightMotorStop();
    leftMotorReverse();
    delay(timeToTurn90Deg);
    stop();
}

void turnRight(){
    leftMotorStop();
    rightMotorReverse();
    delay(timeToTurn90Deg);
    stop();
}



/* individual motor controll */
// left motor
void leftMotorFoward(){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
}
void leftMotorReverse(){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
}
void leftMotorStop(){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);  
}

// right motor
void rightMotorFoward(){
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}
void rightMotorReverse(){
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}
void rightMotorStop(){
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW); 
}