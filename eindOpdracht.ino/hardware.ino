//initialiseren van de button hardware
void btnHardware_Setup() {
  for(int i = 0; i < LENGTE_BUTTON_ARRAY; i++){
    pinMode(BUTTON_PIN[i], INPUT);
  }
}

boolean hardwareDown(int pin){
  return (digitalRead(pin) == HIGH);
}

boolean hardwareUp(int pin){
  return !hardwareDown(pin);
}
