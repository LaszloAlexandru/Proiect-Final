#include <AFMotor.h>

AF_DCMotor motorOne(2);
AF_DCMotor motorTwo(3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {

  if(Serial.available() > 0)
  {
    char data;
    data = (char)Serial.read();
    Serial.write(data);

    switch (data)
    {
      case 'F': //FORWARD

        motorOne.run(FORWARD);
        motorTwo.run(FORWARD);
        motorOne.setSpeed(255);
        motorTwo.setSpeed(255);
        break;
      case 'B': //REVERSE
        motorOne.run(BACKWARD);
        motorTwo.run(BACKWARD);
        motorOne.setSpeed(255);
        motorTwo.setSpeed(255);
        break;
      case 'G': //FORWARD LEFT
        motorOne.run(FORWARD);
        motorTwo.run(FORWARD);
        motorOne.setSpeed(255);
        motorTwo.setSpeed(100);
        break;
      case 'I': //FORWARD RIGHT
        motorOne.run(FORWARD);
        motorTwo.run(FORWARD);
        motorOne.setSpeed(100);
        motorTwo.setSpeed(255);
        break;
      case 'H': //REVERSE LEFT 
        motorOne.run(BACKWARD);
        motorTwo.run(BACKWARD);
        motorOne.setSpeed(255);
        motorTwo.setSpeed(100);
        break;
      case 'J': //REVERSE RIGHT
        motorOne.run(BACKWARD);
        motorTwo.run(BACKWARD);
        motorOne.setSpeed(100);
        motorTwo.setSpeed(255);
        break;
      case 'S': //If bluetooth module receives any value not listed above, both motors turn off
        motorOne.setSpeed(0);
        motorTwo.setSpeed(0);
        break;
      case 'L':
        motorOne.run(FORWARD);
        motorOne.setSpeed(255);
        motorTwo.setSpeed(0);
        break;
      case 'R':
        motorTwo.run(FORWARD);
        motorTwo.setSpeed(255);
        motorOne.setSpeed(0);
        break;
    }
  }
}
