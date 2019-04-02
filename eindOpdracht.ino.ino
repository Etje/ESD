//status waarin het programma verkeerd
int mainSituatie; 

//kies tussen 1 = 'Nederlands', 2 = 'Duits', of 3 = 'Oostenrijks'
//door het kiezen van een nummer tussen de 0 en 4 word bepaald welke stoplichten sequence gekozen moet worden 
int soortStoplicht = 1;

//konstanten die de verschillende situaties aangeven
const int DAG = 0; 
const int AUTO_LINKS = 1; 
const int AUTO_RECHTS = 2; 
const int VOETGANGER_VRAAGT_OM_OVER_TE_STEKEN = 3;
const int TEST = 4;

//konstanten voor het controleren van de volgende request
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
