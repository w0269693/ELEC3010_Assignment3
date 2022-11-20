// Shift Register Pins
int dataPin = 8, clockPin = 11, latch = 10;

// Digit Controlling pins
int D1 = 5, D2 = 6;

// Binary numbers that create a visual representation of the values 0-9
// when mapped to individual segments on the 7 segment display
int numbers[10] = {
  B00000011,  // 0
  B10011111,  // 1
  B00100101,  // 2
  B00001101,  // 3
  B10011001,  // 4
  B01001001,  // 5
  B01000001,  // 6
  B00011111,  // 7
  B00000001,  // 8
  B00011001   // 9
};

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
}

void loop() {
  
  // Track 10's from 0 to 50
  for(int tens = 0; tens < 6; tens++){

    // Trak ones from 0 to 9
    for(int ones = 0; ones < 10; ones++){

      // There are two 5 ms delays in this loop so if executed 100 times it should be ~1s
      for(int i = 0; i < 100; i++){
      
        // Display both digits "at the same time" by alternating between them rapidly (5ms intervals)
        // There's definitely some "ghosting" going here when you look at the display
        digitalWrite(D2, HIGH);
        digitalWrite(latch, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST, numbers[ones]);
        digitalWrite(latch, HIGH);
        digitalWrite(D2, LOW);
        delay(5);

        digitalWrite(D1, HIGH);
        digitalWrite(latch, LOW);
        shiftOut(dataPin, clockPin, LSBFIRST, numbers[tens]);
        digitalWrite(latch, HIGH);
        digitalWrite(D1, LOW);
        delay(5);
      
      }

    }

  }
}