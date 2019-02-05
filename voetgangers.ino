const int SLAGBOOM_LANGZAAM_OMHOOG = 0;
const int VOETGANGERS_OVERSTEKEN = 1;
const int AFTELLEN = 2;
const int SLAGBOOM_LANGZAAM_OMLAAG = 3;

int nr = 6; 

const int DISPLAY_AFTELLEN = 1000;
const int VOETGANGERS_OVERSTEKEN_INTERVAL = 10000; 

int voetgangersState = SLAGBOOM_LANGZAAM_OMHOOG;

void voetgangersStateMachine() {  
  switch (voetgangersState) {
    case SLAGBOOM_LANGZAAM_OMHOOG:
      slagboom_langzaam_omhoog_do();
      
      if (slagboomVolledigGeopend()) {
        slagboom_langzaam_omhoog_exit();
        voetgangers_oversteken_entry();
        voetgangersState = VOETGANGERS_OVERSTEKEN;
      }
      break;
    case VOETGANGERS_OVERSTEKEN:
      voetgangers_oversteken_do();
        if (timer(VOETGANGERS_OVERSTEKEN_INTERVAL)) {
          voetgangers_oversteken_exit();
          oversteken_entry();
          voetgangersState = AFTELLEN;
        }
      break;
      
    case AFTELLEN:
      oversteken_do();

      if(nr == 0){
        aftellen_exit(); 
        slagboom_langzaam_omlaag_entry();
        huidigeState = DAG; 
      }
    break;
    default:
    break;
  }
}

void slagboom_langzaam_omhoog_entry(){
  // <nothing>
}

void slagboom_langzaam_omhoog(){
  slagboom("langzaam openen");  
}

void slagboom_langzaam_omhoog_exit(){
  // <nothing>
}

void voetgangers_oversteken_entry() {
  ledAan(0, 0);
  ledAan(1, 0);
}

void voetgangers_oversteken_do() {
  matrixBord(9);
  setBuzzer("Snel tikken");
} 

void aftellen_entry(){
  matrixBord(nr);
}

void aftellen_do() {
  setBuzzer("3 snelle tikken");
  if(timer(DISPLAY_AFTELLEN)){
    nr--;
    matrixBord(nr);   
  }
}

void aftellen_exit() {
  nr = 6;
}

void slagboom_langzaam_omlaag_entry() {
  // <nothing>
}

void slagboom_langzaam_omlaag_do() {
  setBuzzer("Langzaam tikken");
  slagboom("langzaam dicht");
}

void slagboom_langzaam_omlaag_exit() { 
  voetgangersState = SLAGBOOM_LANGZAAM_OMHOOG; 
  normaalTikken = 0;
}
