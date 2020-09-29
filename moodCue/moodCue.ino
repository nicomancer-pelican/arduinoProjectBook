#include <Servo.h>
Servo myServo;

int const potPin = A0;
int potVal;
int angle;

void setup() {
  // set pin
  myServo.attach(9);

  // open serial port
  Serial.begin(9600);

}

void loop() {
  // read pot value and print
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);

  // map pot value to servo value and print
  angle = map(potVal, 0, 1023, 0, 179); // scales numbers from 0-1023 to 0-179
  Serial.print(", angle : ");
  Serial.println(angle);

  // move servo
  myServo.write(angle);
  delay(15);
  
}
