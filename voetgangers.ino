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
      
      if (helemaalGeopend()) {
        slagboom_langzaam_omhoog_exit();
        voetgangers_oversteken_entry();
        voetgangersState = VOETGANGERS_OVERSTEKEN;
      }
      break;
    case VOETGANGERS_OVERSTEKEN:
      voetgangers_oversteken_do();
        if (stopwatch(VOETGANGERS_OVERSTEKEN_INTERVAL)) {
          voetgangers_oversteken_exit();
          aftellen_entry();
          voetgangersState = AFTELLEN;
        }
      break;
    case AFTELLEN:
      aftellen_do();
      
      if(nr == 0){
        aftellen_exit(); 
        slagboom_langzaam_omlaag_entry();
        voetgangersState = SLAGBOOM_LANGZAAM_OMLAAG;
      }
    break;
    case SLAGBOOM_LANGZAAM_OMLAAG: 
      slagboom_langzaam_omlaag_do();
      
      if(helemaalGesloten()){
        slagboom_langzaam_omlaag_exit();
        dagstand_aan_entry(); 
        mainSituatie = DAG; 
      }
    break;
    default:
    break;
  }
}

void slagboom_langzaam_omhoog_entry(){
  // <nothing>
}

void slagboom_langzaam_omhoog_do(){
  slagboom("Langzaam openen");  
}

void slagboom_langzaam_omhoog_exit(){
  // <nothing>
}

void voetgangers_oversteken_entry() {
  //<nothing>
}

void voetgangers_oversteken_do() {
  matrixBord(9);
  setBuzzer("Snel tikken");
} 

void voetgangers_oversteken_exit(){
  //<nothing>
}

void aftellen_entry(){
  matrixBord(nr);
}

void aftellen_do() {
  setBuzzer("3 keer snel tikken");
  if(stopwatch(DISPLAY_AFTELLEN)){
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
  slagboom("Langzaam sluiten");
}

void slagboom_langzaam_omlaag_exit() { 
  voetgangersState = SLAGBOOM_LANGZAAM_OMHOOG; 
  normaalTikken = 0;
}
