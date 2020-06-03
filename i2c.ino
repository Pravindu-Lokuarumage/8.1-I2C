#include <Wire.h>
 
// LED on pin 13
const int ledPin = 13; 
const int ledPin2 = 12;
 
void setup() {
  // Join I2C bus as slave with address 8
  Wire.begin(0x8);
  
  // Call receiveEvent when data received                
  Wire.onReceive(receiveEvent);
  
  // Setup pin 13 as output and turn LED off
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin2, LOW);
}
 
// Function that executes whenever data is received from master
void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a 
    if (c == 0)
      digitalWrite(ledPin, 0);
    if (c == 1)
      digitalWrite(ledPin, 1);
    if (c == 2)
      digitalWrite(ledPin2, 0);
    if (c == 3)
      digitalWrite(ledPin2, 1);
  }
}
void loop() {
  delay(100);
}
