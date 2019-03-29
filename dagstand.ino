const int OPSTARTEN_DAGSTAND = 0; 
const int DAGSTAND_AAN = 1; 

int dagState = DAGSTAND_AAN; 

void dagStandState(){
  switch(dagState){
    case OPSTARTEN_DAGSTAND: 
      opstarten_dagstand_do();
      if(helemaalGesloten()){
        opstarten_dagstand_exit();
        dagstand_aan_entry();
        dagState = DAGSTAND_AAN;
      }
    break; 
    case DAGSTAND_AAN: 
      dagstand_aan_do();
      if(stopwatch(check)){
        checkVolgendeRequest();
      }
    break; 
    default: 
    break;    
   }
}

void opstarten_dagstand_entry(){
  // <nothing>
}

void opstarten_dagstand_do(){
  slagboom("Langzaam sluiten");
  setBuzzer("Langzaam tikken");
  zetStoplichtenAan(ORANJE, ORANJE);
  matrixBord(7);
}

void opstarten_dagstand_exit(){
  // <nothing>
}

void dagstand_aan_entry(){
  zetStoplichtenAan(ROOD, ROOD);
  slagboom("Sluiten");
  matrixBord(7);
}

void dagstand_aan_do(){
  setBuzzer("Langzaam tikken");
}

void dagstand_aan_exit(){
  // <nothing>
}
