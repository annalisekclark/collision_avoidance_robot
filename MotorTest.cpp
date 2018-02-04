// Motor Test

// code assumes that both motors are enabled either wiht jumpers to the enable pins or via writing them high.

// Written by Annalise Kennedy-Clark

// The pins on the L298N PCB are labelled  ENA, IN1, IN2, IN3, IN4 and ENB

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


// this code  only runs once
void setup()
{
    // set all the motor control pins to outputs
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);

    // First set all pins low
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);

    // *** Left Motor ****

    // To run the left motor forward for 3 seconds  
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    delay(3000);

    // To run the left motor Backwards for 3 seconds  
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    delay(5000);

    // now stop the left motor
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);

    // *** Right Motor ****

    // To run the Right motor forward for 5 seconds  
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(5000);

    // To run the Right motor Backwards for 5 seconds  
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(5000);


    // stop all motors
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  
}

void loop(){
    // do nothing
}
