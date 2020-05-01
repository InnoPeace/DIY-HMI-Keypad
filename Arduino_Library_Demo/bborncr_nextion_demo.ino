#include <SoftwareSerial.h>
#include <Nextion.h>
#include "Keyboard.h"

SoftwareSerial nextion(10, 16);// Nextion TX to pin 10 and RX to pin 16 of Arduino

Nextion myNextion(nextion, 9600); //create a Nextion object named myNextion using the nextion serial port @ 9600bps

void setup() {
  Serial.begin(9600);
  myNextion.init();
}

void loop() {

  String message = myNextion.listen();

  if (message == "65 0 1 0 ffff ffff ffff") {
    Keyboard.write('1');
  }
}
