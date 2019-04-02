//initialiseren van de request array
int requestArray[] = {0, 0, 0, 0}; 
const int REQUEST_ARRAY_LENGTH = sizeof(requestArray) / sizeof(int);

//const int TEST_KNOP = 4; 

//volledige setup functie
void verkeerSetup(){
  Serial.begin(9600);
  setupTimers();
  setupShiftRegister();
  servo_setup(); 
  stoplichtSetup(); 
  button_Setup();
  btnHardware_Setup(); 
  buzzerSetup();  

  dagstand_aan_entry();
  mainSituatie = DAG; 
}

//regelen van de verschillende toestanden
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
    case TEST: 
      testStateMachine(); 
      break;
    default:
      break;
  }
}

//nummer toevoegen aan de request array als er op een button gedrukt is
void voegRequestsToe(int buttonPin) {
  if(!bestaatRequest(convert(buttonPin))){
    for(int i = 0; i < REQUEST_ARRAY_LENGTH; i++) {
      if(requestArray[i] == 0){
        requestArray[i] = convert(buttonPin);
        break;
      }
    }
  }
}

//kijkt of er een volgende request is
void checkVolgende() {
  for(int i = 0; i < REQUEST_ARRAY_LENGTH; i++) {
    if(requestArray[i] != 0){
      mainSituatie = requestArray[i];
      requestArray[i] = 0;
      break;
    }
  }
}

//checkt of het request al in de array voorkomt
boolean bestaatRequest(int statusNummer) {
  for(int i = 0; i < REQUEST_ARRAY_LENGTH; i++) {
    if(requestArray[i] == statusNummer){
      return true;
      break;
    }
  }
  return false;
}

//convert het nummer naar een status
int convert(int buttonPin) {
 switch(buttonPin){
    case 14:
      return AUTO_LINKS;
    break;
    case 3:
      return VOETGANGER_VRAAGT_OM_OVER_TE_STEKEN;
    break;
    case 2: 
      return TEST;
      break;
    case 4:
      return AUTO_RECHTS;
    break;
  }
}
