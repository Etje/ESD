const int BUTTON_PIN[4] = {4, 3, 2, A0};
const int LENGTE_BUTTON_ARRAY = sizeof(BUTTON_PIN) / sizeof(int);

int VOETGANGERS_BUTTON;
int VERKEER_LINKS_BUTTON;
int VERKEER_RECHTS_BUTTON;
int TEST_BUTTON;

void button_Setup() {
  for (int i = 0; i < LENGTE_BUTTON_ARRAY; i++) {
    pinMode(BUTTON_PIN[i], INPUT_PULLUP);
  }
}

int gedruktStoplicht(){
  int knop = 0; 
  VOETGANGERS_BUTTON = digitalRead(BUTTON_PIN[0]);
  VERKEER_LINKS_BUTTON = digitalRead(BUTTON_PIN[1]);
  VERKEER_RECHTS_BUTTON = digitalRead(BUTTON_PIN[2]);
  TEST_BUTTON = digitalRead(BUTTON_PIN[3]);

  if(VOETGANGERS_BUTTON == LOW){
    knop = BUTTON_PIN[0];
    Serial.println(knop);
  } 
  
  else if(VERKEER_LINKS_BUTTON == LOW){
    knop = BUTTON_PIN[1];
    Serial.println(knop);
  } 
  
  else if(VERKEER_RECHTS_BUTTON == LOW){
    knop = BUTTON_PIN[2];
    Serial.println(knop);
  } 
  
  else if(TEST_BUTTON == LOW){
    knop = BUTTON_PIN[3];
    Serial.println(knop);
  }

  return knop; 
}



