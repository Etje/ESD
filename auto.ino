const int ORANJE_INTERVAL = 3000;
const int GROEN_INTERVAL = 8000; 
const int KNIPPEREN_INTERVAL = 250; 
  
const int ROOD = 0;
const int ORANJE = 1;
const int GROEN = 2;
const int GROEN_KNIPPEREN = 4; 

int huidigeStaat = huidigeStoplichtStaat(); 

void autoStatemachine(String kant) {
  switch(soortStoplicht){
    case 1:
      switch(huidigeStaat){
        case GROEN: 
          groen_do(kant);
            if(stopwatch(GROEN_INTERVAL)){
              groen_exit();
              oranje_entry();
            }
        break;
        case ORANJE: 
          oranje_do(kant);
            if(stopwatch(ORANJE_INTERVAL)){
              oranje_exit();
              dagstand_aan_entry();
              mainSituatie = DAG;
            }
        break; 
        default: 
        break;
      }
      break; 
    case 2: 
      switch(huidigeStaat){
        case ORANJE: 
          rood_oranje_duits_do(kant);
            if(stopwatch(ORANJE_INTERVAL)){
              rood_oranje_duits_exit();
              groen_duits_entry();
            }
        break; 
        case GROEN: 
          groen_duits_do(kant);
            if(stopwatch(GROEN_INTERVAL)){
              groen_duits_exit();
              dagstand_aan_entry(); 
              mainSituatie = DAG;
            }
        break;
        default: 
        break;
      }
      break;    
    case 3: 
      switch(huidigeStaat){
        case ORANJE: 
          rood_oranje_oostenrijk_do(kant);
            if(stopwatch(ORANJE_INTERVAL)){
              rood_oranje_oostenrijk_exit();
              groen_knipperen_oostenrijk_entry();
            }
        break; 
        case GROEN_KNIPPEREN: 
          groen_knipperen_oostenrijk_do(kant);
            if(stopwatch(ORANJE_INTERVAL)){
              groen_knipperen_oostenrijk_exit();
              groen_oostenrijk_entry();
            }
        break; 
        case GROEN: 
          groen_oostenrijk_do(kant);
            if(stopwatch(GROEN_INTERVAL)){
              groen_oostenrijk_exit();
              dagstand_aan_entry();
            }
        break;
        default: 
        break;
      }
      break;     
  }
}

int huidigeStoplichtStaat(){
  int huidigeStaat; 
  
  if(soortStoplicht == 1){
      huidigeStaat = GROEN; 
  } else {
      huidigeStaat = ORANJE; 
  }

  return huidigeStaat; 
}

void groen_entry(){
  // <nothing>
}

void groen_duits_entry(){
  //<nothing>
}

void groen_oostenrijk_entry(){
  //<nothing>
}

void groen_knipperen_oostenrijk_entry(){
  //<nothing>
}

void groen_do(String kant){
  setBuzzer("Langzaam tikken");
  if(kant == "Links"){
    zetStoplichtenAan(GROEN, ROOD); 
  } else {
    zetStoplichtenAan(ROOD, GROEN);
  }
}

void groen_duits_do(String kant){
  setBuzzer("Langzaam tikken");
  if(kant == "Links"){
    zetStoplichtenAan(GROEN, ROOD); 
  } else {
    zetStoplichtenAan(ROOD, GROEN);
  }  
}

void groen_oostenrijk_do(String kant){

  if(kant == "Links"){
    zetStoplichtenAan(GROEN, ROOD); 
  } else {
    zetStoplichtenAan(ROOD, GROEN);
  }  
  
}

void groen_knipperen_oostenrijk_do(String kant){
  if(kant == "Links"){
     laatLampjeKnipperen(kant);
  } else {
     laatLampjeKnipperen(kant);
  }
}

void groen_exit(){
  huidigeStaat = ORANJE;
}

void groen_duits_exit(){
  huidigeStaat = ORANJE; 
}

void groen_oostenrijk_exit(){
  mainSituatie = DAG;
}

void groen_knipperen_oostenrijk_exit(){
  huidigeStaat = GROEN;
  Serial.println("hij komt in de stopwatch");
}

void oranje_entry(){
  // <nothing>
}

void oranje_do(String kant){
  setBuzzer("Langzaam tikken");
  if(kant == "Links"){
    zetStoplichtenAan(ORANJE, ROOD);
  }else {
    zetStoplichtenAan(ROOD, ORANJE);
  }
}

void oranje_exit(){
  huidigeStaat = GROEN;
}

void rood_oranje_do(String kant){
    if(kant == "Links"){
      zetStoplichtenAan(ROOD, ROOD);
      zetStoplichtenAan(ORANJE, ROOD);
    } else {
      zetStoplichtenAan(ROOD, ROOD);
      zetStoplichtenAan(ROOD, ORANJE);
    }
}

void rood_oranje_duits_do(String kant){
  
    if(kant == "Links"){
      zetStoplichtenAan(ROOD, ROOD);
      zetStoplichtenAan(ORANJE, ROOD);
    } else {
      zetStoplichtenAan(ROOD, ROOD);
      zetStoplichtenAan(ROOD, ORANJE);
    }  
    
}

void rood_oranje_oostenrijk_do(String kant){
  
    if(kant == "Links"){
      zetStoplichtenAan(ORANJE, ROOD);
    } else {
      zetStoplichtenAan(ROOD, ORANJE);
    }  
      
}

void rood_oranje_exit() {
  huidigeStaat = GROEN;
}

void rood_oranje_duits_exit(){
  huidigeStaat = GROEN;
}

void rood_oranje_oostenrijk_exit(){
  huidigeStaat = GROEN_KNIPPEREN; 
}
