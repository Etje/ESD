//variablen en konstanten voor het shiftregister
const int PIN_ARRAY[] = {11, 12, 13};
const int LENGTE_VAN_PIN_ARRAY = sizeof(PIN_ARRAY) / sizeof(int);

const int DATASERIAL = 11;
const int CLOCK = 13;
const int STORAGECLOCKPIN = 12;
const int OUTPUT_PINS = 8;

//functie voor de setup van het shiftregister
void setupShiftRegister() {
  for(int teller = 0; teller < LENGTE_VAN_PIN_ARRAY; teller++){
    pinMode(PIN_ARRAY[teller], OUTPUT);
  }
}

//functie voor het leegmaken van het shiftregister
void clearShiftRegister(){
  for(int i = 0; i < OUTPUT_PINS; i++){
    digitalWrite(DATASERIAL, HIGH);
    digitalWrite(CLOCK, HIGH);
    digitalWrite(CLOCK, LOW);
  }
  digitalWrite(STORAGECLOCKPIN, HIGH);
  digitalWrite(STORAGECLOCKPIN, LOW);
}

//functie voor het uitvoeren en het mee kunnen geven van een patroon voor op het shiftregister
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
  digitalWrite(STORAGECLOCKPIN, HIGH);
  digitalWrite(STORAGECLOCKPIN, LOW);
}
