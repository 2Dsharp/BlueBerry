/**
 * Runs the servo
 * @author Dedipyaman Das
 * github.com/2DSharp/BlueBerry
 * @version 1.0/17 
 */
#include <Servo.h>

Servo HorizontalServo;  
/**
 * Initializing position from 0
 */
int pos = 90;    

void initServo() {
  Serial.println("Initializing servo...");
  /** 
   * HorizontalServo goes to pin 9
   */
  HorizontalServo.attach(9);
  HorizontalServo.write(90);
  Serial.println("Servo initialized");
}
void stopServo() {
  HorizontalServo.detach();
  
}
/**
 * Looks left to find if path is clear
 */
boolean lookLeft() {

  boolean clearPath = false;
  for (pos = 90; pos >= 0; pos--) {
    
    HorizontalServo.write(pos);
    // The speed
    if (pathClear(30)) {
      Serial.println("Left is clear");
      clearPath = true;
    }
    delay(15);
  }

  return clearPath;
}
/**
 * Looks right to find if path is clear
 */
boolean lookRight() {
  boolean clearPath = false;
  for (pos = 90; pos <= 180; pos++) {

    HorizontalServo.write(pos);
    if (pathClear(30)) {
      
      Serial.println("Right is clear");
      clearPath = true;
    }
    delay(17);
  }

  return clearPath;
  }
/**
 * Mean positioning to keep the head straight
 */
void returnToMean(int currentFacing) {

  switch (currentFacing) {

    case LEFT:
      for (int i = 0; i <= 90; i++) {
        HorizontalServo.write(i);
        delay(8);    
      }
      break;
      
    case RIGHT:
      for (int i = 0; i <= 90; i++) {
        HorizontalServo.write(i);
        delay(8);    
      }
      break;    
  }
  delay(1000);
}
