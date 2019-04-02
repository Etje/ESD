//konstanten voor het functioneren van de stoplichten
const int TOTAAL_AANTAL_STOPLICHTEN = 2; 
const int LEDS_PER_STOPLICHT = 3; 
const int LINKS = 0; 
const int RECHTS = 1; 

//array voor het aangeven van de stoplichten
const int STOPLICHT[TOTAAL_AANTAL_STOPLICHTEN][LEDS_PER_STOPLICHT] = {
  {10, 9, 8},
  {7, 6, 5}
};

//functie voor de setup van de stoplichten
void stoplichtSetup() {
  for (int stoplicht = 0; stoplicht < TOTAAL_AANTAL_STOPLICHTEN; stoplicht++) {
    for (int nr = 0; nr < LEDS_PER_STOPLICHT; nr++) {
      controlSetup(STOPLICHT[stoplicht][nr]);
    }
  }
}

//functie voor het uitzetten van de stoplichten
void stoplichtUit() {
  for (int stoplicht = 0; stoplicht < TOTAAL_AANTAL_STOPLICHTEN; stoplicht++) {
    for (int nr = 0; nr < LEDS_PER_STOPLICHT; nr++) {
      lampjeUit(STOPLICHT[stoplicht][nr]);
    }
  }
}

//functie voor het aanzetten van één enkel stoplicht
void zetStoplichtAan(int welkStoplicht, int _Rechts){
  stoplichtUit();
  lampjeAan(STOPLICHT[welkStoplicht][_Rechts]);
}

//functie voor het aanzetten van beide stoplichten
void zetStoplichtenAan(int _Links, int _Rechts){
  stoplichtUit();
  lampjeAan(STOPLICHT[LINKS][_Links]);
  lampjeAan(STOPLICHT[RECHTS][_Rechts]);
}

//functie voor het laten knipperen van de stoplichten
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
