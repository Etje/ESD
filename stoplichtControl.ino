const int TOTAAL_AANTAL_STOPLICHTEN = 2; 
const int LEDS_PER_STOPLICHT = 3; 
const int LINKS = 0; 
const int RECHTS = 1; 
    
const int STOPLICHT[TOTAAL_AANTAL_STOPLICHTEN][LEDS_PER_STOPLICHT] = {
  {10, 9, 8},
  {7, 6, 5}
};

void stoplichtSetup() {
  for (int stoplicht = 0; stoplicht < TOTAAL_AANTAL_STOPLICHTEN; stoplicht++) {
    for (int nr = 0; nr < LEDS_PER_STOPLICHT; nr++) {
      controlSetup(STOPLICHT[stoplicht][nr]);
    }
  }
}

void stoplichtUit() {
  for (int stoplicht = 0; stoplicht < TOTAAL_AANTAL_STOPLICHTEN; stoplicht++) {
    for (int nr = 0; nr < LEDS_PER_STOPLICHT; nr++) {
      lampjeUit(STOPLICHT[stoplicht][nr]);
    }
  }
}

void zetStoplichtAan(int welkStoplicht, int _Rechts){
  stoplichtUit();
  lampjeAan(STOPLICHT[welkStoplicht][_Rechts]);
}

void zetStoplichtenAan(int _Links, int _Rechts){
  stoplichtUit();
  lampjeAan(STOPLICHT[LINKS][_Links]);
  lampjeAan(STOPLICHT[RECHTS][_Rechts]);
}

void laatLampjeKnipperen(String kant){
  if(kant == "Links"){
    if(stopwatchBuzzer(BUZZER_TIJD_SNEL_TIKKEN)){
      lampjeKnipperen(STOPLICHT[LINKS][GROEN]);
    }
  } else {
    if(stopwatchBuzzer(BUZZER_TIJD_SNEL_TIKKEN)){
      lampjeKnipperen(STOPLICHT[RECHTS][GROEN]);
    }
  }
}
