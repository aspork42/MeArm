/* meArm IK test - York Hackspace May 2014
 * Test applying Nick Moriarty's Inverse Kinematics solver
 * to Phenoptix' meArm robot arm, to walk a specified path.
 *
 * Pins:
 * Arduino    Base   Shoulder  Elbow    Gripper
 *    GND    Brown     Brown   Brown     Brown
 *     5V      Red       Red     Red       Red
 *     11    Yellow
 *     10             Yellow
 *      9                     Yellow
 *      6                               Yellow
 */
#include "meArm.h"
#include <Servo.h>

int basePin = 11;
int shoulderPin = 10;
int elbowPin = 3;
int gripperPin = 6;

meArm arm;

void setup() {
  arm.begin(basePin, shoulderPin, elbowPin, gripperPin);
}

void loop() {
  //Clap - so it's obvious we're at this part of the routine
  arm.openGripper();
  //delay(5000);
  arm.closeGripper();
  //delay(5000);
  arm.openGripper();
  //delay(5000);
  arm.closeGripper();
  //delay(5000);
  arm.openGripper();
  //delay(5000);
  
  
  /*
  //Go up and left to grab something
  arm.gotoPoint(-80,100,140); 
  arm.closeGripper();
  //Go down, forward and right to drop it
  arm.gotoPoint(70,200,10);
  arm.openGripper();
  //Back to start position
  arm.gotoPoint(0,100,50);
  */
  //Back to start position
  
  
  arm.gotoPoint(-40,130,60);
  delay(1000);
  arm.gotoPoint(+40,130,60); //stage to grab
  delay(1000);
  arm.openGripper();
  //analogWrite(gripperPin,180);
  
  arm.gotoPoint(+40,130,100); //move in to grab
  delay(50);
  arm.gotoPoint(+40,130,105); //move in to grab
  delay(50);
  arm.gotoPoint(+40,130,110); //move in to grab
  delay(50);
  arm.gotoPoint(+40,130,115); //move in to grab
  delay(50);
  arm.gotoPoint(+40,130,120); //move in to grab
      
  delay(500);
  arm.closeGripper(); //grab object
  //analogWrite(gripperPin, 0);
  //delay(150);
  delay(500);
  
  arm.gotoPoint(+40, 150, 120); //raise object
  delay(500); 
  
  arm.gotoPoint(-40, 200, 50); //high and away
  arm.gotoPoint(-40, 50, 50);  //low and away
  arm.gotoPoint(0, 180, 100);  //another away point
  
  
  arm.gotoPoint(+40, 150, 120); //stage to return
  delay(500);
  arm.gotoPoint(+40,130,120); //return
  delay(250);
  arm.openGripper();
  delay(250);
  
  arm.gotoPoint(+40,130,60); //back away
  
  delay(2000);
  
  
  
  
  
}

/*
X + is to the right hand of center, X- is left hand of center
Y 0 is floor, 200 is ceiling
Z 50 is claw retracted towards base; z150 is pushed out extended
*/
