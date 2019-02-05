#include <Servo.h>
 
const int SERVO_PIN = A2;

Servo servo;

void servo_setup() {
  servo.attach(SERVO_PIN);
}
