int requestArray[] = {0, 0, 0, 0}; 
const int REQUEST_ARRAY_LENGTH = sizeof(requestArray) / sizeof(int);

const int TEST_KNOP = 4; 

void verkeerSetup(){
  
  Serial.begin(9600);
  setupTimers();
  SetupShiftRegister();
  servo_setup(); 
  stoplichtSetup(); 
  button_Setup();
  btnHardware_Setup(); 
  buzzerSetup();  

  dagstand_aan_entry();
  mainSituatie = DAG; 

}

void verkeer(){
  switch(mainSituatie){
    case DAG: 
      dagStandState(); 
      break; 
    case AUTO_LINKS: 
      autoStatemachine("Links");
      break; 
    case AUTO_RECHTS: 
      autoStatemachine("Rechts");
      break; 
    case VOETGANGER_VRAAGT_OM_OVER_TE_STEKEN: 
      voetgangersStateMachine(); 
      break; 
    case TEST_KNOP: 
      testStateMachine(); 
      break;
    default:
      break;
  }
}

void voegToeAanRequests(int buttonPin) {
  if(!bestaatRequestInArray(convertButtonNaarStatus(buttonPin))){
    for(int i = 0; i < REQUEST_ARRAY_LENGTH; i++) {
      if(requestArray[i] == 0){
        requestArray[i] = convertButtonNaarStatus(buttonPin);
        break;
      }
      for(int i = 0; i < 4; i++){
        Serial.print(requestArray[i]);
      }
    }
  }
}

//checkt of er een nieuw request is
void checkVolgendeRequest() {
  for(int i = 0; i < REQUEST_ARRAY_LENGTH; i++) {
    if(requestArray[i] != 0){
      mainSituatie = requestArray[i];
      requestArray[i] = 0;
      break;
    }
  }
}

//controleert of een request al in de wachtrij staat
boolean bestaatRequestInArray(int statusNummer) {
  for(int i = 0; i < REQUEST_ARRAY_LENGTH; i++) {
    if(requestArray[i] == statusNummer){
      return true;
      break;
    }
  }
  return false;
}

//zet een buttonpin om naar een state
int convertButtonNaarStatus(int buttonPin) {
 switch(buttonPin){
    case 14:
      return AUTO_LINKS;
    break;
    case 3:
      return VOETGANGER_VRAAGT_OM_OVER_TE_STEKEN;
    break;
    case 2: 
      return TEST_KNOP;
      break;
    case 4:
      return AUTO_RECHTS;
    break;
  }
}
