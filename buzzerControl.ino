const int BUZZER_PIN = A1;
const int FREQUENCY = 550; 
const int TIJD = 50; 
const int KORTE_TIJD = 1000; 

const int AANTAL_KEER_SNEL_TIKKEN = 3; 
int normaalTikken = 1; 

int buzzer_tijd_steeds_sneller = 1500; 
const int BUZZER_TIJD_KORT = 3000;
const int BUZZER_TIJD_LANGZAAM = 2000;
const int BUZZER_TIJD_SNEL_TIKKEN = 500;
const int BUZZER_TIJD_AFTELLEN = 250;

void buzzerSetup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void setBuzzer(String actie) {
  if(actie == "Langzaam tikken") { 
    if(stopwatchBuzzer(BUZZER_TIJD_LANGZAAM)){
      tone(BUZZER_PIN, FREQUENCY, TIJD);  
    }
  }else if(actie == "Snel tikken") { 
    if(stopwatchBuzzer(BUZZER_TIJD_SNEL_TIKKEN)){
      tone(BUZZER_PIN, FREQUENCY, TIJD);  
    }
  }else if(actie == "3 keer snel tikken") { 
    if (stopwatchBuzzer(BUZZER_TIJD_AFTELLEN)) {
      if (normaalTikken < AANTAL_KEER_SNEL_TIKKEN) {
        normaalTikken++;
        tone(BUZZER_PIN, FREQUENCY, TIJD); 
      }
      else {
        if (stopwatchRequest(BUZZER_TIJD_LANGZAAM)) {
          normaalTikken = 0;
        }
      }    
    }
  } else if(actie == "kort geluid"){
      if(stopwatchBuzzer(BUZZER_TIJD_KORT)){
        tone(BUZZER_PIN, FREQUENCY, KORTE_TIJD);  
      }
  }else if(actie == "Geen geluid") { 
    noTone(BUZZER_PIN);  
  }
}
