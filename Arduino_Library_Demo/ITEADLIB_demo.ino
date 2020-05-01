#include <Keyboard.h>
#include "Nextion.h"
SoftwareSerial HMISerial(10,16);

//Delcare buttons (page, id, name)
NexButton p0b0 = NexButton(0,1,"b0");

//Add buttons to list of touch events
NexTouch *nex_listen_list[] =
{
  &p0b0,
  NULL
};

//PopCallback - Button release event
void p0b0PopCallback(void *ptr){
  Keyboard.write('0');
}

void setup(){
  HMISerial.begin(9600);
  HMISerial.write(0xff);
  HMISerial.write(0xff);
  HMISerial.write(0xff);
  p0b0.attachPop(p0b0PopCallback);
}

void loop(){
  nexLoop(nex_listen_list); //Check for any touch event
  delay(5); // for stability
}
