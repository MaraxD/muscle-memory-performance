
#include "BLEDevice.h"
#include <esp_wifi.h>
#include <esp_now.h>
#include <WiFi.h>
//#include "BLEScan.h"


int muscleAnalogPin=5;

typedef struct struct_message {
  int heartbeat;
  int muscleTension;
} struct_message;

struct_message sensorsReadings;

int muscleImpulse;


void setup() {
  Serial.begin(115200);
  pinMode(muscleAnalogPin, INPUT);

}  

// This is the Arduino main loop function.
void loop() {
  muscleImpulse=analogRead(muscleAnalogPin);

  Serial.println(muscleImpulse);

  delay(800);  // Delay a second between loops.
} 
