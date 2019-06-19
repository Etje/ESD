const int KLEINE_UITSLAG_WAARDE = 50;

const int TEST_INTERVAL = 1000;  

const int ROOD_LICHT = 0;
const int ORANJE_LICHT = 1;
const int GROEN_LICHT = 2;

const int ROOD_LICHT_RECHTS = 0;
const int ORANJE_LICHT_RECHTS = 1;
const int GROEN_LICHT_RECHTS = 2;

const int ROOD_LICHT_LINKS = 3;
const int ORANJE_LICHT_LINKS = 4;
const int GROEN_LICHT_LINKS = 5;

const int SLAGBOOM_UITSLAG_OPEN = 6; 
const int SLAGBOOM_UITSLAG_DICHT = 7;

const int BUZZER_KORT = 500;

int testKnopState = ROOD_LICHT;

void testStateMachine() {  
  switch (testKnopState) {
    case ROOD_LICHT_RECHTS:
        rood_licht_rechts_do();
          if(stopwatch(TEST_INTERVAL)){
            rood_licht_rechts_exit();
            oranje_licht_rechts_entry();
        }
      break;
    case ORANJE_LICHT_RECHTS:
      oranje_licht_rechts_do();
        if (stopwatch(TEST_INTERVAL)) {
          oranje_licht_rechts_exit();
          groen_licht_rechts_entry();
        }
      break;
    case GROEN_LICHT_RECHTS:
      groen_licht_rechts_do();
        if (stopwatch(TEST_INTERVAL)) {
          groen_licht_rechts_exit();
          rood_licht_links_entry();
        }
      break;
    case ROOD_LICHT_LINKS:
        rood_licht_links_do();
          if(stopwatch(TEST_INTERVAL)){
            rood_licht_links_exit();
            oranje_licht_links_entry();
        }
      break;
    case ORANJE_LICHT_LINKS:
      oranje_licht_links_do();
        if (stopwatch(TEST_INTERVAL)) {
          oranje_licht_links_exit();
          groen_licht_links_entry();
        }
      break;
    case GROEN_LICHT_LINKS:
      groen_licht_links_do();
        if (stopwatch(TEST_INTERVAL)) {
          groen_licht_links_exit();
          buzzer_kort_entry();
        }
      break;
    case BUZZER_KORT:
      buzzer_kort_do();
        if (stopwatchBuzzer(BUZZER_TIJD_SNEL_TIKKEN)) {
          buzzer_kort_exit();
          slagboom_uitslag_entry();
        }
      break;
    case SLAGBOOM_UITSLAG_OPEN:
      slagboom_uitslag_open_do(); 
        if(kleinStukjeGeopend()){
          slagboom_uitslag_open_exit();
          slagboom_uitslag_dicht_entry();
        }
        break; 
   case SLAGBOOM_UITSLAG_DICHT:
      slagboom_uitslag_dicht_do(); 
        if(helemaalGesloten()){
          slagboom_uitslag_dicht_exit();
          dagstand_aan_entry();
        }
        break; 
    default:
    break;
  }
}

/* void rechts */

void rood_licht_rechts_entry(){
  //<nothing>
}

void rood_licht_rechts_do(){
  zetStoplichtAan(RECHTS, ROOD_LICHT); 
}

void rood_licht_rechts_exit(){
  testKnopState = ORANJE_LICHT_RECHTS; 
}

void oranje_licht_rechts_entry(){
  //<nothing>
}

void oranje_licht_rechts_do(){
  zetStoplichtAan(RECHTS, ORANJE_LICHT);
}

void oranje_licht_rechts_exit(){
  testKnopState = GROEN_LICHT_RECHTS;
}

void groen_licht_rechts_entry(){
  //<nothing>
}

void groen_licht_rechts_do(){
  zetStoplichtAan(RECHTS, GROEN_LICHT);
}

void groen_licht_rechts_exit(){
  testKnopState = ROOD_LICHT_LINKS;
}


/* Einde rechts void */


/* Begin links void  */

void rood_licht_links_entry(){
  //<nothing>
}

void rood_licht_links_do(){
  zetStoplichtAan(LINKS, ROOD_LICHT); 
}

void rood_licht_links_exit(){
  testKnopState = ORANJE_LICHT_LINKS; 
}

void oranje_licht_links_entry(){
  //<nothing>
}

void oranje_licht_links_do(){
  zetStoplichtAan(LINKS, ORANJE_LICHT);
}

void oranje_licht_links_exit(){
  testKnopState = GROEN_LICHT_LINKS;
}

void groen_licht_links_entry(){
  //<nothing>
}

void groen_licht_links_do(){
  zetStoplichtAan(LINKS, GROEN_LICHT);
}

void groen_licht_links_exit(){
  testKnopState = BUZZER_KORT;
}

/* Einde links void  */

void buzzer_kort_entry(){
  //<nothing>
}

void buzzer_kort_do(){
  stoplichtUit();
  setBuzzer("kort geluid");
}

void buzzer_kort_exit(){
  testKnopState = SLAGBOOM_UITSLAG_OPEN;
}

void slagboom_uitslag_entry(){
  //<nothing>
}

void slagboom_uitslag_open_do(){
  slagboom("kleine uitslag");
}

void slagboom_uitslag_open_exit(){
  testKnopState = SLAGBOOM_UITSLAG_DICHT;
}

void slagboom_uitslag_dicht_entry(){
  //<nothing>
}

void slagboom_uitslag_dicht_do(){
  slagboom("Langzaam sluiten");
}

void slagboom_uitslag_dicht_exit(){
  mainSituatie = DAG;
}
