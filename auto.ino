const int ORANJE_INTERVAL = 3000;
const int GROEN_INTERVAL = 8000; 
  
const int ROOD = 2;
const int ORANJE = 1;
const int GROEN = 0;

int huidigeStaat = GROEN; 

void autoStatemachine(String kant) {
  switch(huidigeStaat){
    case GROEN: 
      groen_do(kant);
        if(timer(GROEN_INTERVAL)){
          groen_exit();
          oranje_entry();
        }
    break;
    case ORANJE: 
      oranje_do();
        if(timer(ORANJE_INTERVAL)){
          oranje_exit();
          dag_stand_entry();
          mainSituatie = DAG;
        }
    break; 
    default: 
    break;
  }
}

void groen_entry(){
  // <nothing>
}

void groen_do(String kant){
  setBuzzer("Langzaam tikken");
  if(kant == "Links"){
    zetStoplichtenAan(GROEN, ROOD); 
  }else {
    zetStoplichtenAan(ROOD, GROEN);
  }
}

void groen_exit(){
  huidigeStaat = ORANJE;
}

void oranje_entry(){
  // <nothing>
}

void oranje_do(){
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
