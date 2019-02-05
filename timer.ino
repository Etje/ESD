//declareer variablen die de tijden bijhouden
unsigned long vorigeMillis; 
unsigned long vorigeMillisBuzzer; 
unsigned long vorigeMillisRequest; 

void setupTimers(){
  previousMillis = millis(); 
  previousMillisBuzzer = millis(); 
  previousMillisRequest = millis(); 
}

boolean stopwatch(int interval){
  unsigned long huidigeMillis = millis();

  if(huidigeMillis - vorigeMillis >= interval){
    vorigeMillis = huidigeMillis;
    return true;
  }

  return false; 
}

boolean stopwatchBuzzer(int interval){
  unsigned long huidigeMillis = millis();

  if(huidigeMillis - vorigeMillisBuzzer >= interval){
    vorigeMillis = huidigeMillis;
    return true;
  }

  return false; 
}

boolean stopwatchRequest(int interval){
  unsigned long huidigeMillis = millis();

  if(huidigeMillis - vorigeMillisRequest >= interval){
    vorigeMillis = huidigeMillis;
    return true;
  }

  return false; 
}
