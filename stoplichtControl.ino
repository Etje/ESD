const int TOTAAL_AANTAL_STOPLICHTEN = 2; 
const int LEDS_PER_STOPLICHT = 3; 
const int LINKS = 0; 
const int RECHT = 1; 
    
const int stoplicht[TOTAAL_AANTAL_STOPLICHTEN][LEDS_PER_STOPLICHT] = {
  {10, 9, 8},
  {7, 6, 5}
};

void stoplichtSetup() {
  for (int stoplicht = 0; stoplicht < TOTAAL_AANTAL_STOPLICHTEN; stoplicht++) {
    for (int nr = 0; nr < LEDS_PER_STOPLICHT; nr++) {
      controlSetup(stoplicht[stoplicht][nr], OUTPUT);
    }
  }
}

void stoplichtUit() {
  for (int stoplicht = 0; stoplicht < TOTAAL_AANTAL_STOPLICHTEN; stoplicht++) {
    for (int nr = 0; nr < LEDS_PER_STOPLICHT; nr++) {
      lampjeUit(stoplicht[stoplicht][nr]);
    }
  }
}

void zetStoplichtenAan(int _Links, int _Rechts){
  stoplichtUit();
  lampjeAan(stoplicht(LINKS, _Links));
  lampjeAan(stoplicht(RECHTS, _Rechts));
}

void laatLampjeKnipperen(){
  if(stopwatchBuzzer(buzzer_tijd_snel_tikken)){
    lampjeKnipperen(stoplicht(LINKS, ORANJE));
    lampjeKnipperen(stoplicht(RECHTS, ORANJE));
  }
}
