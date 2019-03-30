//constanten om de standen van de servo te bepalen
const int GESLOTEN = 0; 
const int OPEN = 90;
const int KLEINE_UITSLAG = 35;

const int INTERVAL = 20;

//functie voor het laten werken van de slagboom
void slagboom(String actie){
  if(actie == "Openen"){
    servo.write(OPEN);
  } else if(actie == "Sluiten") {
    servo.write(GESLOTEN);  
  } else if(actie == "Langzaam openen"){
    int servoValue = servo.read();
    if(stopwatch(INTERVAL)){
      if(servoValue < OPEN){
        servoValue ++;
      }
    }
    servo.write(servoValue);
  }else if(actie == "Langzaam sluiten"){
    int servoValue = servo.read();
    if(stopwatch(INTERVAL)){
      if(servoValue > GESLOTEN){
        servoValue--;
      }
    }
    servo.write(servoValue);
  } else if(actie == "kleine uitslag"){
    int servoValue = servo.read();
    if(stopwatch(INTERVAL)){
      if(servoValue < KLEINE_UITSLAG){
        servoValue ++;
      }
    }
    servo.write(servoValue);
  } else if(actie == "kleine uitslag sluiten"){
    int servoValue = servo.read();
    if(stopwatch(INTERVAL)){
      if(servoValue > KLEINE_UITSLAG){
        servoValue--;
      }
    }
    servo.write(servoValue);
}
}

//functie om de stanten van de slagboom te kunnen controleren
boolean helemaalGeopend(){
  return (servo.read() >= OPEN);
}

boolean helemaalGesloten(){
  return (servo.read() <= GESLOTEN);
}

boolean kleinStukjeGeopend(){
  return (servo.read() >= KLEINE_UITSLAG);
}
