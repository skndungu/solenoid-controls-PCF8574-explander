/*
* Title: Solenoids Control
*
* Author: Simon
*
* Date: 29th June 2021
*/

/* U1 --> A0,A1,A2 = 0 => address => 0x20 */
/* U2 --> A0 = 1, A1&A2 = 0 address => 0x24 */

#include "Arduino.h"
#include "PCF8574.h"

/* Set i2c address */ 
// create an object of the PCF8574 
PCF8574 pcf8574_U1(0x20);
PCF8574 pcf8574_U2(0x24);


/* does a pin mapping for the pumps as on the dev board */
#define pump_1 4; 
#define pump_2 5;

/* does a pin mapping for the solenoids as on the dev board */
#define solenoid_1 6;
#define solenoid_2 7;
#define solenoid_3 8;
#define solenoid_4 9;
#define solenoid_5 10;
#define solenoid_6 11;
#define solenoid_7 12;
#define solenoid_8 13;
#define solenoid_9 A0;
#define solenoid_10 A1;
#define solenoid_11 A2;
#define solenoid_12 A3;
#define solenoid_13 A6;
#define solenoid_14 A7;

void setup(){
	Serial.begin(9600);
	// initialize pins as outputs *for pins connected directly on the development board
	pinMode(pump_1, OUTPUT);
    pinMode(pump_2, OUTPUT);
	pinMode(solenoid_1, OUTPUT);
	pinMode(solenoid_2, OUTPUT);
	pinMode(solenoid_3, OUTPUT);
	pinMode(solenoid_4, OUTPUT);
	pinMode(solenoid_5, OUTPUT);
	pinMode(solenoid_6, OUTPUT);
	pinMode(solenoid_7, OUTPUT);
	pinMode(solenoid_8, OUTPUT);
	pinMode(solenoid_9, OUTPUT);
	pinMode(solenoid_10, OUTPUT);
	pinMode(solenoid_11, OUTPUT);
	pinMode(solenoid_12, OUTPUT);
	pinMode(solenoid_13, OUTPUT);
	pinMode(solenoid_14, OUTPUT);

	/* Setting pinmodes onthe Exapander */ 
      pcf8574_U1.pinMode(P0, OUTPUT); // solenoid 15
      pcf8574_U1.pinMode(P1, OUTPUT); // solenoid 16
      pcf8574_U1.pinMode(P2, OUTPUT); // solenoid 17
      pcf8574_U1.pinMode(P3, OUTPUT); // solenoid 18
      pcf8574_U1.pinMode(P4, OUTPUT); // solenoid 19
      pcf8574_U1.pinMode(P5, OUTPUT); // solenoid 20
      pcf8574_U1.pinMode(P6, OUTPUT); // solenoid 21
      pcf8574_U1.pinMode(P7, OUTPUT); // solenoid 22

      pcf8574_U2.pinMode(P0, OUTPUT); // solenoid 23
      pcf8574_U2.pinMode(P1, OUTPUT); // solenoid 24
      pcf8574_U2.pinMode(P2, OUTPUT); // solenoid 25
      pcf8574_U2.pinMode(P3, OUTPUT); // solenoid 26
      pcf8574_U2.pinMode(P4, OUTPUT); // solenoid 27
      pcf8574_U2.pinMode(P5, OUTPUT); // solenoid 28

     
      pcf8574_U1.begin();
      pcf8574_U2.begin();

}

/* Main Loop */ 
void loop(){
	pumps_on();
	solenoids_on();
	delay(1000); // delays for 1 sec
	solenoids_off();
	pumps_off();
	delay(1000); // delays for 1 sec

}

/* Method puts on the pumps */
void pumps_on(){
	digitalWrite(pump_1, HIGH);
	digitalWrite(pump_2, HIGH);
}

/* Method puts off the pumps */
void pumps_off(){
	digitalWrite(pump_1, LOW);
	digitalWrite(pump_2, LOW);
}


/* Method puts the solenoids on */ 
void solenoids_on(){
	digitalWrite(solenoid_1, HIGH);
	digitalWrite(solenoid_2, HIGH);
	digitalWrite(solenoid_3, HIGH);
	digitalWrite(solenoid_4, HIGH);
	digitalWrite(solenoid_5, HIGH);
	digitalWrite(solenoid_6, HIGH);
	digitalWrite(solenoid_7, HIGH);
	digitalWrite(solenoid_8, HIGH);
	digitalWrite(solenoid_9, HIGH);
	digitalWrite(solenoid_10, HIGH);
	digitalWrite(solenoid_11, HIGH);
	digitalWrite(solenoid_12, HIGH);
	digitalWrite(solenoid_13, HIGH);
	digitalWrite(solenoid_14, HIGH);

	pcf8574_U1.digitalWrite(P0, HIGH);
	pcf8574_U1.digitalWrite(P2, HIGH);
	pcf8574_U1.digitalWrite(P3, HIGH);
	pcf8574_U1.digitalWrite(P4, HIGH);
	pcf8574_U1.digitalWrite(P5, HIGH);
	pcf8574_U1.digitalWrite(P6, HIGH);
	pcf8574_U1.digitalWrite(P7, HIGH);

    pcf8574_U2.digitalWrite(P0, HIGH);
	pcf8574_U2.digitalWrite(P2, HIGH);
	pcf8574_U2.digitalWrite(P3, HIGH);
	pcf8574_U2.digitalWrite(P4, HIGH);
	pcf8574_U2.digitalWrite(P5, HIGH);

}

/* Method puts the solenoids off */ 
void solenoids_off(){
    digitalWrite(solenoid_1, LOW);
	digitalWrite(solenoid_2, LOW);
	digitalWrite(solenoid_3, LOW);
	digitalWrite(solenoid_4, LOW);
	digitalWrite(solenoid_5, LOW);
	digitalWrite(solenoid_6, LOW);
	digitalWrite(solenoid_7, LOW);
	digitalWrite(solenoid_8, LOW);
	digitalWrite(solenoid_9, LOW);
	digitalWrite(solenoid_10, LOW);
	digitalWrite(solenoid_11, LOW);
	digitalWrite(solenoid_12, LOW);
	digitalWrite(solenoid_13, LOW);
	digitalWrite(solenoid_14, LOW);

    pcf8574_U1.digitalWrite(P0, LOW);
	pcf8574_U1.digitalWrite(P2, LOW);
	pcf8574_U1.digitalWrite(P3, LOW);
	pcf8574_U1.digitalWrite(P4, LOW);
	pcf8574_U1.digitalWrite(P5, LOW);
	pcf8574_U1.digitalWrite(P6, LOW);
	pcf8574_U1.digitalWrite(P7, LOW);

    pcf8574_U2.digitalWrite(P0, LOW);
	pcf8574_U2.digitalWrite(P2, LOW);
	pcf8574_U2.digitalWrite(P3, LOW);
	pcf8574_U2.digitalWrite(P4, LOW);
	pcf8574_U2.digitalWrite(P5, LOW);

}
