const int pinHIGH = 1; 

void controlSetup(int nr){
  pinMode(nr, OUTPUT);
}

void lampjeAan(int nr){
  digitalWrite(nr, HIGH);
}

void lampjeUit(int nr){
  digitalWrite(nr, LOW);
}

void lampjeKnipperen(int nr){
  if(digitalRead(nr) == pinHigh){
    digitalWrite(nr, LOW);
  }else {
    digitalWrite(nr, HIGH);
  }
}
