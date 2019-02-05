void setup_all(){
  Serial.begin(9600);
  SetupShiftRegister();
  button_Setup();
  ledPinSetup();
  buzzerSetup();
  servo_setup();
  state_machine_setup(); 
}

void state_machine_setup() {
  stateMachineVoetgangersSetup();
}
