/* Servo Test

by Annalise Kennedy-Clark

Tests a servo
    - full left for 3 seconds
    - full right for 3 seconds
    - center
*/


#include <Servo.h>

Servo myservo;  // create servo object to control a servo
int servoPin = 5;   // this can be changed but it must be a PWM pin


void setup() {
  myservo.attach(servoPin);  // attaches the servo on pin to the servo object

  // first turn all the way left
  myservo.write(0);              // tell servo to go to position 
  delay(3000);                   // waits 3 seconds

  // Second turn all the way Right
  myservo.write(180);              // tell servo to go to position 
  delay(3000);                   // waits 3 seconds

 // Lastly center the servo
  myservo.write(90);              // tell servo to go to position 
  delay(150);                    // give the servo a few millyseconds to reach the center

}

void loop() {
  // do nothing
}
