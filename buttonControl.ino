//konstanten voor de verschillende situaties van de buttons
const int BUTTON_RELEASED = 1; 
const int BUTTON_CHECK_PRESSED = 2; 
const int BUTTON_PRESSED = 3; 
const int BUTTON_CHECK_RELEASED = 4; 

const int BUTTON_PIN[] = {4, 3, 2, A0};
const int LENGTE_BUTTON_ARRAY = sizeof(BUTTON_PIN) / sizeof(int);
int pinClicked;

int button_state; 
boolean button_clicked; 
unsigned long buttonPreviousMillis; 
const int BUTTON_INTERVAL = 10;

void button_Setup() {
  button_clicked = false; 
  button_state = BUTTON_RELEASED; 
  pinClicked = -1;
  button_released_entry();
}

boolean button_click(){
  if(button_clicked == true){
    button_clicked = false; 
    return true; 
  } else {
    return false;
  }
}

//statemachine voor de buttons
void buttonStateMachine(){
  switch(button_state){
    case BUTTON_RELEASED: 
      button_released_do();
      for(int i = 0; i < LENGTE_BUTTON_ARRAY; i++){
        
        if(hardwareDown(BUTTON_PIN[i]) == true){
          pinClicked = BUTTON_PIN[i];
          button_released_exit();
          button_state = BUTTON_CHECK_PRESSED; 
          button_check_pressed_entry();
        }
      }
      break; 
    case BUTTON_CHECK_PRESSED: 
      button_check_pressed_do();
      if(hardwareUp(pinClicked) == true){
        button_check_pressed_exit();
        button_state = BUTTON_RELEASED; 
        button_released_entry();
      }
      else if((hardwareDown(pinClicked) == true) && (millis() - buttonPreviousMillis >= BUTTON_INTERVAL)) {
        button_check_pressed_exit();
        button_state = BUTTON_PRESSED; 
        button_pressed_entry();
      }
      break; 
    case BUTTON_PRESSED: 
      button_pressed_do();
        if(hardwareUp(pinClicked) == true){
          button_pressed_exit();
          button_state = BUTTON_CHECK_RELEASED; 
          button_check_released_entry();            
        }
        break; 
    case BUTTON_CHECK_RELEASED: 
      button_check_released_do(); 
      if(hardwareDown(pinClicked) == true){
        button_check_released_exit();
        button_state = BUTTON_PRESSED; 
        button_check_pressed_entry();
      } 
      else if((hardwareUp(pinClicked) == true) 
               && (millis() - BUTTON_INTERVAL >= buttonPreviousMillis)){
        button_check_released_exit(); 
        button_state = BUTTON_RELEASED; 

        button_clicked = true; 
        Serial.print(pinClicked);
        voegRequestsToe(pinClicked);
        
        button_released_entry();         
      }
      break;         
    }
  }

void button_released_entry(){
  //<nothing>
}

void button_released_do(){
  //<nothing>
}

void button_released_exit(){
  //<nothing>
}

void button_check_pressed_entry(){
  buttonPreviousMillis = millis();
}

void button_check_pressed_do(){
    //<nothing>
}

void button_check_pressed_exit(){
  //<nothing>  
}

void button_pressed_entry(){
  //<nothing>
}

void button_pressed_do(){
  //<nothing>
}

void button_pressed_exit(){
  //<nothing>
}

void button_check_released_entry(){
  buttonPreviousMillis = millis();
}

void button_check_released_do(){
    //<nothing>
}

void button_check_released_exit(){
    //<nothing>
}
