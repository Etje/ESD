//declareer variablen die de tijden bijhouden
unsigned long vorigeMillis; 
unsigned long vorigeMillisBuzzer; 
unsigned long vorigeMillisRequest; 

//setup van de timers
void setupTimers(){
  vorigeMillis = millis(); 
  vorigeMillisBuzzer = millis(); 
  vorigeMillisRequest = millis(); 
}

//standaard timer functie
boolean stopwatch(int interval){
  unsigned long huidigeMillis = millis();

  if(huidigeMillis - vorigeMillis >= interval){
    vorigeMillis = huidigeMillis;
    return true;
  }

  return false; 
}

//timer voor buzzer
boolean stopwatchBuzzer(int interval){
  unsigned long huidigeMillis = millis();

  if(huidigeMillis - vorigeMillisBuzzer >= interval){
    vorigeMillisBuzzer = huidigeMillis;
    return true;
  }

  return false; 
}

//timer voor request
boolean stopwatchRequest(int interval){
  unsigned long huidigeMillis = millis();

  if(huidigeMillis - vorigeMillisRequest >= interval){
    vorigeMillisRequest = huidigeMillis;
    return true;
  }

  return false; 
}
