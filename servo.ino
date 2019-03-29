#include <Servo.h>

Servo servo; 
const int SERVO_PIN = A2;


void servo_setup() {
  servo.attach(SERVO_PIN);
}
