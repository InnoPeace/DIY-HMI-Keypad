/*
 *  DIY HMI KeyPad
 *  PCB Version: A0
 *  Created by: InnoPeace
 *  Publish date: Jun 1, 2020
 *  PB_Pin[0] - I/O 2
 *  PB_Pin[1] - I/O 3
 *  PB_Pin[2] - I/O 4
 *  PB_Pin[3] - I/O 5
 *  PB_Pin[4] - I/O 6
 *  PB_Pin[5] - I/O 7
 *  PB_Pin[6] - I/O 8
 *  PB_Pin[7] - I/O 9
 *  PB_Pin[8] - I/O 14
 *  PB_Pin[9] - I/O 15
 *  PB_Pin[10] - I/O 18
 *  PB_Pin[11] - I/O 19
 *  Software Serial TX - I/O 10
 *  Software Serial RX - I/O 16
 *
 */

#include <SoftwareSerial.h>
#include <Nextion.h>
#include "Keyboard.h"

SoftwareSerial nextion(10, 16);// Nextion TX to pin 10 and RX to pin 16 of Arduino Pro Micro

Nextion myNextion(nextion, 9600); //create a Nextion object named myNextion using the nextion serial port @ 9600bps

const int PB_Pin[] = {2,3,4,5,6,7,8,9,14,15,18,19};         // input pin for push button
const int PB_Size = sizeof(PB_Pin)/sizeof(int);   // Size of push button
boolean previousButtonState[PB_Size] = {HIGH};   // for checking the state of a pushButton
boolean buttonState[PB_Size] = {HIGH};   // for checking the state of a pushButton
unsigned long lastDebounceTime[PB_Size] = {0};
unsigned long debounceDelay = 5;

void setup() {
  Serial.begin(9600);
  myNextion.init();
  // make the pushButton pin an input:
  for (int i=0; i < PB_Size; i++){
    pinMode(PB_Pin[i], INPUT_PULLUP);
  }
  
  // initialize control over the keyboard:
  Keyboard.begin();

}

void loop() {
  for (int i=0; i < PB_Size; i++){
    buttonState[i] = digitalRead(PB_Pin[i]);
    if (buttonState[i] != previousButtonState[i]){
      if ((millis() - lastDebounceTime[i]) > debounceDelay){
        lastDebounceTime[i] = millis();
        if (buttonState[i] == LOW) {
          switch(i){
          case (0): {Keyboard.press(KEY_F13);Keyboard.releaseAll();} break; //F13
          case (1): {Keyboard.press(KEY_F14);Keyboard.releaseAll();} break; //F14
          case (2): {Keyboard.press(KEY_F15);Keyboard.releaseAll();} break; //F15
          case (3): {Keyboard.press(KEY_F16);Keyboard.releaseAll();} break; //F16
          case (4): {Keyboard.press(KEY_F17);Keyboard.releaseAll();} break; //F17
          case (5): {Keyboard.press(KEY_F18);Keyboard.releaseAll();} break; //F18
          case (6): {Keyboard.press(KEY_F19);Keyboard.releaseAll();} break; //F19
          case (7): {Keyboard.press(KEY_F20);Keyboard.releaseAll();} break; //F20
          case (8): {Keyboard.press(KEY_F21);Keyboard.releaseAll();} break; //F21
          case (9): {Keyboard.press(KEY_F22);Keyboard.releaseAll();} break; //F22
          case (10): {Keyboard.press(KEY_F23);Keyboard.releaseAll();} break; //F23
          case (11): {Keyboard.press(KEY_F24);Keyboard.releaseAll();} break; //F24
          }
        }
        previousButtonState[i] = buttonState[i];
      }
    } 
  }
  String message = myNextion.listen(); //check for message
  if(message != ""){ // if a message is received...
    if (message[0]==0x65){ //Button or Hotspot actions
      switch(message[1]){
        case (0x00): //Page 0
          if (message[2]==0x01 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x02 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x03 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x04 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x05 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x06 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x07 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x08 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x09 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0A && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0B && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0C && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll(); 
          }
          if (message[2]==0x0D && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0E && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0F && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x10 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x11 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x12 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x13 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x14 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x15 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x16 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x17 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x18 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x19 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1A && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
            }
          if (message[2]==0x1B && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1C && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1D && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1E && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1F && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x20 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x21 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x22 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x23 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x24 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x25 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();          }
          if (message[2]==0x26 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x27 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x28 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
        break;
        case (0x01): //Page 1
          if (message[2]==0x01 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x02 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x03 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x04 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            /*Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press('1');*/
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x05 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x06 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x07 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x08 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x09 && message[3]==0x00){  //Comment
            /*Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);*/
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press('2');
            delay(10);
            Keyboard.releaseAll();
            }
          if (message[2]==0x0A && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0B && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0C && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0D && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0E && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0F && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x10 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x11 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x12 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x13 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x14 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x15 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x16 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x17 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x18 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x19 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1A && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1B && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1C && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1D && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1E && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1F && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
            }
          if (message[2]==0x20 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x21 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x22 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x23 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x24 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x25 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x26 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x27 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x28 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F13);
            delay(10);
            Keyboard.releaseAll();
          }
        break; 
        case (0x02): //Page 2
          if (message[2]==0x01 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x02 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x03 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x04 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x05 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x06 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x07 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x08 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x09 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0A && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0B && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0C && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll(); 
          }
          if (message[2]==0x0D && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0E && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0F && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x10 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x11 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x12 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x13 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x14 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x15 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x16 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x17 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x18 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x19 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1A && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
            }
          if (message[2]==0x1B && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1C && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1D && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1E && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1F && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x20 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x21 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x22 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x23 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x24 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x25 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();          }
          if (message[2]==0x26 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x27 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x28 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
        break;
        case (0x03): //Page 3
          if (message[2]==0x01 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x02 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x03 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x04 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x05 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x06 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x07 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x08 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x09 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
            }
          if (message[2]==0x0A && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0B && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0C && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0D && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0E && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0F && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x10 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x11 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x12 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x13 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x14 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x15 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x16 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x17 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x18 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x19 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1A && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1B && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1C && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1D && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1E && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1F && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
            }
          if (message[2]==0x20 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x21 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x22 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x23 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x24 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x25 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x26 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x27 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x28 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F14);
            delay(10);
            Keyboard.releaseAll();
          }
        break;
        case (0x04): //Page 4
          /*if (message[2]==0x01 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x02 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x03 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x04 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x05 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x06 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x07 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x08 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x09 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0A && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0B && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0C && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll(); 
          }
          if (message[2]==0x0D && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0E && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x0F && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x10 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x11 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x12 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x13 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x14 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x15 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x16 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x17 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F1);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x18 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x19 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1A && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
            }
          if (message[2]==0x1B && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1C && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1D && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1E && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x1F && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x20 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(KEY_RIGHT_GUI);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x21 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x22 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x23 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x24 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x25 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();          }
          if (message[2]==0x26 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_ALT);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x27 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_CTRL);
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_RIGHT_SHIFT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }
          if (message[2]==0x28 && message[3]==0x00){  //Comment
            Keyboard.press(KEY_LEFT_GUI);
            Keyboard.press(KEY_LEFT_SHIFT);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F15);
            delay(10);
            Keyboard.releaseAll();
          }*/
        break;
        /* Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_GUI);
        Keyboard.press(KEY_LEFT_ALT);
        Keyboard.press(KEY_LEFT_SHIFT);
        Keyboard.press(KEY_RIGHT_CTRL);
        Keyboard.press(KEY_RIGHT_GUI);
        Keyboard.press(KEY_RIGHT_ALT);
        Keyboard.press(KEY_RIGHT_SHIFT);
        Keyboard.press(KEY_F14);
        delay(10);
        Keyboard.releaseAll(); */
        default: // Other Pages
        break;
      }
    }
  }
}
