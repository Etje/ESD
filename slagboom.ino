//constanten om de standen van de servo te bepalen
const int GESLOTEN = 0; 
const int OPEN = 90;

const int interval = 20;

void slagboom(String actie){
  switch(actie){
    case "openen":
      servo.write(OPEN);
      break;
    case "sluiten":
      servo.write(GESLOTEN);
      break;
    case "langzaam openen":
      int value = servo.read();
      if(stopwatch(servo_interval)){
        if(servoValue < GESLOTEN){
          value++;
        }
      }
      servo.write(servoValue);
      break;
    case "langzaam dicht":
      int value = servo.read();
      if(stopwatch(servo_interval)){
        if(value > GESLOTEN){
          value--;
        }
      }
      servo.write(value);
      break;
  }
}

boolean helemaalGeopend(){
  return (servo.read() >= OPEN);
}

boolean helemaalGesloten(){
  return (servo.read() <= GESLOTEN);
}
