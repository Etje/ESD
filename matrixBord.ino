//genereren van een bitsequence voor het display
const byte SEQUENCEARRAY[] = {
  B11111100, //0
  B01100000, //1
  B11011010, //2
  B11110010, //3
  B01100110, //4
  B10110110, //5
  B10111110, //6
  B11100000, //7
  B11111110, //8
  B11110110, //9
};

//fucntie voor het gebruik van het 7 sigmenten display
void matrixBord(int nr){
  setShiftRegister(SEQUENCEARRAY[nr]);
}
