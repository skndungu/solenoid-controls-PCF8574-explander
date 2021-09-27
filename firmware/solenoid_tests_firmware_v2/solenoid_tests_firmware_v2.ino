/*
* Title: Solenoids Control v2
*
* Author: Simon Ndungu
*
* Date: 27th Sep 2021
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
#define pump_1 4
#define pump_2 5

/* does a pin mapping for the solenoids as on the dev board */
#define solenoid_1 6
#define solenoid_2 7
#define solenoid_3 8
#define solenoid_4 9
#define solenoid_5 10
#define solenoid_6 11
#define solenoid_7 12
#define solenoid_8 13
#define solenoid_9 A0
#define solenoid_10 A1
#define solenoid_11 A2
#define solenoid_12 A3
#define solenoid_13 A6 /* A6 is only input NO digital hardware behind this pin */
#define solenoid_14 A7 /* A7 is only input NO digital hardware behind this pin */

/* Input Variables */

int input1_state = 0;
int input2_state = 0;
int input3_state = 0;
int input4_state = 0;
int input5_state = 0;
int input6_state = 0;
int input7_state = 0;
int input8_state = 0;

void setup(){
  Serial.begin(115200);
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
  // pinMode(solenoid_13, OUTPUT); // can't work on current board the pin needs to be changed 
  // pinMode(solenoid_14, OUTPUT); // can't work on current board the pin needs to be changed 

  /* Setting pinmodes onthe Exapander */ 
      pcf8574_U1.pinMode(P0, OUTPUT); // solenoid 15
      pcf8574_U1.pinMode(P1, OUTPUT); // solenoid 16
      pcf8574_U1.pinMode(P2, OUTPUT); // solenoid 17
      pcf8574_U1.pinMode(P3, OUTPUT); // solenoid 18
      pcf8574_U1.pinMode(P4, OUTPUT); // solenoid 19
      pcf8574_U1.pinMode(P5, OUTPUT); // solenoid 20
      pcf8574_U1.pinMode(P6, OUTPUT); // solenoid 21
      pcf8574_U1.pinMode(P7, OUTPUT); // solenoid 22

      pcf8574_U2.pinMode(P0, INPUT); // Input 1
      pcf8574_U2.pinMode(P1, INPUT); // Input 2
      pcf8574_U2.pinMode(P2, INPUT); // Input 3
      pcf8574_U2.pinMode(P3, INPUT); // Input 4
      pcf8574_U2.pinMode(P4, INPUT); // Input 5
      pcf8574_U2.pinMode(P5, INPUT); // Input 6
      pcf8574_U2.pinMode(P6, INPUT); // Input 7
      pcf8574_U2.pinMode(P7, INPUT); // Input 8

     
      pcf8574_U1.begin();
      pcf8574_U2.begin();

}

/* Main Loop */ 
void loop(){
  pumps_on();
  solenoids_on();
  read_input_data()
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

void read_input_data(){
  input1_state = pcf8574_U2.digitalRead(P0);
  input2_state = pcf8574_U2.digitalRead(P1);
  input3_state = pcf8574_U2.digitalRead(P2);
  input4_state = pcf8574_U2.digitalRead(P3);
  input5_state = pcf8574_U2.digitalRead(P4);
  input6_state = pcf8574_U2.digitalRead(P5);
  input7_state = pcf8574_U2.digitalRead(P6);
  input8_state = pcf8574_U2.digitalRead(P7);

  Serial.print("input1: ");
  Serial.println(input1_state);
  Serial.print("input2: ");
  Serial.println(input2_state);
  Serial.print("input3: ");
  Serial.println(input3_state);
  Serial.print("input4: ");
  Serial.println(input4_state);
  Serial.print("input5: ");
  Serial.println(input5_state);
  Serial.print("input6: ");
  Serial.println(input6_state);
  Serial.print("input7: ");
  Serial.println(input7_state);
  Serial.print("input8: ");
  Serial.println(input8_state);
  
  Serial.println(" ");
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
  // digitalWrite(solenoid_13, HIGH);  // can't work on current board the pin needs to be changed 
  // digitalWrite(solenoid_14, HIGH); // can't work on current board the pin needs to be changed 

  pcf8574_U1.digitalWrite(P0, HIGH);
  pcf8574_U1.digitalWrite(P2, HIGH);
  pcf8574_U1.digitalWrite(P3, HIGH);
  pcf8574_U1.digitalWrite(P4, HIGH);
  pcf8574_U1.digitalWrite(P5, HIGH);
  pcf8574_U1.digitalWrite(P6, HIGH);
  pcf8574_U1.digitalWrite(P7, HIGH);

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
  // digitalWrite(solenoid_13, LOW); // can't work on current board the pin needs to be changed 
  // digitalWrite(solenoid_14, LOW); // can't work on current board the pin needs to be changed 


  pcf8574_U1.digitalWrite(P0, LOW);
  pcf8574_U1.digitalWrite(P2, LOW);
  pcf8574_U1.digitalWrite(P3, LOW);
  pcf8574_U1.digitalWrite(P4, LOW);
  pcf8574_U1.digitalWrite(P5, LOW);
  pcf8574_U1.digitalWrite(P6, LOW);
  pcf8574_U1.digitalWrite(P7, LOW);

}
