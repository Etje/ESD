const int BUZZER_PIN = A1;
const int FREQUENCY = 550; 
const int TIJD = 50; 

const int AANTAL_KEER_SNEL_TIKKEN = 3; 
int normaalTikken = 1; 

const int BUZZER_TIJD_LANGZAAM = 1000;
const int BUZZER_TIJD_SNEL_TIKKEN = 500;
const int BUZZER_TIJD_AFTELLEN = 200;

void buzzerSetup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void setBuzzer(String actie) {
  switch(actie){
    case "Langzaam tikken":
      if(stopwatchBuzzer(BUZZER_TIJD_LANGZAAM)){
        tone(BUZZER_PIN, FREQUENCY, TIJD);
      }
      break;
    case "Snel tikken":    
      if(stopwatchBuzzer(BUZZER_TIJD_SNEL_TIKKEN)){
        tone(BUZZER_PIN, FREQUENCY, TIJD);
      }
      break; 
    case "3 snelle tikken":
      if(stopwatchBuzzer(BUZZER_TIJD_AFTELLEN)){
        if(normaalTikken < AANTAL_KEER_SNEL_TIKKEN){
          normaalTikken++; 
          tone(BUZZER_PIN, FREQUENCY, TIJD);
        } else {
          if(stopwatchRequest(BUZZER_TIJD_LANGZAAM)){
            normaalTikken = 0;
          }
        }
      }
      break; 
    case "Geen geluid":
      noTone(BUZZER_PIN); 
      break;
  }
}
