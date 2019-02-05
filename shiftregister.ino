const int PIN_ARRAY[] = {11, 12, 13};
const int LENGTE_VAN_PIN_ARRAY = sizeof(PIN_ARRAY / sizeof(int));

const int DATASERIAL = 11;
const int CLOCK = 12;
const int STORAGECLOCKPIN = 13;
const int OUTPUT_PINS = 8;

void SetupShiftRegister() {
  for(int teller = 0; teller < LENGTE_VAN_PIN_ARRAY; teller++){
    pinMode(PIN_ARRAY[teller], OUTPUT);
  }
}

void ClearShiftRegister(){
  for(int i = 0; i < OUTPUT_PINS; i++){
    digitalWrite(DATASERIAL, HIGH);
    digitalWrite(CLOCK, HIGH);
    digitalWrite(CLOCK, LOW);
  }
  digitalWrite(STORAGECLOCKPIN, HIGH);
  digitalWrite(STORAGECLOCKPIN, LOW);
}

void setShiftRegister(byte patroon) {
  for(int i = 0; i < OUTPUT_PINS; i++){
    if(patroon & (B00000001 << i)){
      digitalWrite(DATASERIAL, HIGH);
    } else {
      digitalWrite(DATASERIAL, LOW);
    }
    digitalWrite(CLOCK, HIGH);
    digitalWrite(CLOCK, LOW);
  }
}
