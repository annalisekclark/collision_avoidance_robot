/*
* Ultrasonic Sensor HC-SR04 Test
*
* by Annalise Kenedy-Clark and Stepehn Kennedy-Clark
*
* LED will blink faster or slower depending on teh distance from 1/10 seconds at 10 cm to 1/second at 100cm
*
*/
// defines pins numbers
const int trigPin = A0;
const int echoPin = A1;

// defines variables
long duration;
int distance;
const int ledPin =  LED_BUILTIN;// the number of the LED pin
int ledState = LOW;             // ledState used to set the LED
unsigned long previousMillis = 0;        // will store last time LED was updated
long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
	pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
	pinMode(echoPin, INPUT); // Sets the echoPin as an Input
	Serial.begin(9600); // Starts the serial communication
	pinMode(ledPin, OUTPUT);
}

void loop() {
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
	distance= duration*0.034/2;
	// Prints the distance on the Serial Monitor
	Serial.print("Distance: ");
	Serial.println(distance);
	
	interval = (1.0/(100.0/distance))*1000;

	if ( distance < 10  ){
		interval = 100;
	}
	
	if ( distance > 100  ){
		interval = 1000;
	}

	// check to see if it's time to blink the LED; that is, if the difference
	// between the current time and last time you blinked the LED is bigger than
	// the interval at which you want to blink the LED.

  unsigned long currentMillis = millis();

	if (currentMillis - previousMillis >= interval) {
			// save the last time you blinked the LED
			previousMillis = currentMillis;

			// if the LED is off turn it on and vice-versa:
			if (ledState == LOW) {
			ledState = HIGH;
		} else {
			ledState = LOW;
		}

		// set the LED with the ledState of the variable:
		digitalWrite(ledPin, ledState);
	}

	delayMicroseconds(50); // wait 1 second
}

