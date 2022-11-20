// Digits
int D1 = 8, D2 = 9, D3 = 10, D4 = 11;

// Segments
int A = 5, B = 7, C = 3, D = 1, E = 0, F = 6, G = 4, DP = 2;

int num_array[10][7] = { 
  { 1,1,1,1,1,1,0 },  // 0
  { 0,1,1,0,0,0,0 },  // 1
  { 1,1,0,1,1,0,1 },  // 2
  { 1,1,1,1,0,0,1 },  // 3
  { 0,1,1,0,0,1,1 },  // 4
  { 1,0,1,1,0,1,1 },  // 5
  { 1,0,1,1,1,1,1 },  // 6
  { 1,1,1,0,0,0,0 },  // 7
  { 1,1,1,1,1,1,1 },  // 8
  { 1,1,1,0,0,1,1 },  // 9
};

int segment_array[8][7] = {
  { 1,0,0,0,0,0,0 },  // A
  { 0,1,0,0,0,0,0 },  // B
  { 0,0,1,0,0,0,0 },  // C
  { 0,0,0,1,0,0,0 },  // D
  { 0,0,0,0,1,0,0 },  // E
  { 0,0,0,0,0,1,0 },  // F
  { 0,0,0,0,0,0,1 }   // G
};

void resetOutputs(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(DP, HIGH);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
}

void setDigitPosition(int digitPosition){

  switch(digitPosition){
    case 1:
      digitalWrite(D1, HIGH);
      break;
    case 2:
      digitalWrite(D2, HIGH);
      break;
    case 3:
      digitalWrite(D3, HIGH);
      break;
    case 4:
      digitalWrite(D4, HIGH);
      break;
  }

}

void displaySegments(int segments[7]){
  
  if(segments[0] == 1){digitalWrite(A, LOW);}
  if(segments[1] == 1){digitalWrite(B, LOW);}
  if(segments[2] == 1){digitalWrite(C, LOW);}
  if(segments[3] == 1){digitalWrite(D, LOW);}
  if(segments[4] == 1){digitalWrite(E, LOW);}
  if(segments[5] == 1){digitalWrite(F, LOW);}
  if(segments[6] == 1){digitalWrite(G, LOW);}

}

void setup() {
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DP, OUTPUT);
}

void loop() {

  // Turn all the LED segments OFF
  resetOutputs();

  // // Display individual segments A through G
  for(int seg = 0; seg < 7; seg++){
    setDigitPosition(1);
    displaySegments(segment_array[seg]);
    delay(1000);
    resetOutputs();
  }
  
  // Display numbers 0 through 9
  for(int num = 0; num < 10; num++){
    setDigitPosition(1);
    displaySegments(num_array[num]);
    delay(1000);
    resetOutputs();
  }
  
  // Blink the decimal places in each digit position
  for(int dig = 1; dig <= 4; dig++){
    setDigitPosition(dig);
    digitalWrite(DP, LOW);
    delay(1000);
    resetOutputs();
  }
    
}