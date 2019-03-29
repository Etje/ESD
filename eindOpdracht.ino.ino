int mainSituatie; 

//kies tussen 1 = 'Nederlands', 2 = 'Duits', of 3 = 'Oostenrijks'

int soortStoplicht = 1;

const int DAG = 0; 
const int AUTO_LINKS = 1; 
const int AUTO_RECHTS = 2; 
const int VOETGANGER_VRAAGT_OM_OVER_TE_STEKEN = 3;
const int TEST = 4;

const int check = 3000; 

void setup() {
  // put your setup code here, to run once:
  verkeerSetup();
}

void loop() {
  // put your main code here, to run repeatedly
  buttonStateMachine();
  //verkeer();
}
