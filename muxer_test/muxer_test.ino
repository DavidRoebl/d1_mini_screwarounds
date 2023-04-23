// muxer stuff
const int SIGNAL    = D8; // "SIG"
const int ADDRESS[4] ={
  D0, // "S0"
  D1, // "S1"
  D2, // "S2"
  D3  // "S3"
};
const int table[16][4] = {
  {0,0,0,0}, // "C0"
  {0,0,0,1}, // "C1"
  {0,0,1,0}, // "C2"
  {0,0,1,1}, // "C3"
  {0,1,0,0}, // "C4"
  {0,1,0,1}, // "C5"
  {0,1,1,0}, // "C6"
  {0,1,1,1}, // "C7"
  {1,0,0,0}, // "C8"
  {1,0,0,1}, // "C9"
  {1,0,1,0}, // "C10"
  {1,0,1,1}, // "C11"
  {1,1,0,0}, // "C12"
  {1,1,0,1}, // "C13"
  {1,1,1,0}, // "C14"
  {1,1,1,1}  // "C15"
};


// rot enc pins
const int CLK = D7;
const int DT = D6;
const int SM = D5;

int readChannel(int inputChannel){
  for(int i = 0; i<4; i++) {
    digitalWrite(ADDRESS[i], table[inputChannel][i]);
  }
  return digitalRead(SIGNAL);
}

void setup() {
  for(int i=0; i<4; i++) {
    pinMode(ADDRESS[i], OUTPUT);
  }

  pinMode(SIGNAL, INPUT); 
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  for(int i=0; i<16; i++){
    int value = readChannel(i);
    Serial.print(" " + String(value));
  }
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println();
  delay(10);
}
