/*
 Reference Material:
 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/
#include <LiquidCrystal.h>

// Program configuration from the Arduino example file
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Variables to track the running balance as coins are added
const int quarterButton = 7, loonieButton = 8;
int quarterRead, quarterCheck, loonieRead, loonieCheck;
bool quarterDeposited = false;
bool loonieDeposited = false;
float currentBalance = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(quarterButton, INPUT);
  pinMode(loonieButton, INPUT);
}

void printBalance(){
      lcd.setCursor(0, 1);
      lcd.print("$");
      lcd.setCursor(1, 1);
      lcd.print(currentBalance);
}
void loop() {

  lcd.setCursor(0, 0);
  lcd.print("Current Balance:");
  printBalance();

  // Debounce routine
  quarterRead = digitalRead(quarterButton);
  loonieRead = digitalRead(loonieButton);
  delay(10);
  quarterCheck = digitalRead(quarterButton);
  loonieCheck = digitalRead(loonieButton);

  // If the QUARTER button has been pressed by a human
  if (quarterRead == quarterCheck) {

    // Add the coin to the current balance if the "coin deposit" event has not been processed
    if(quarterCheck == 1 && !quarterDeposited){
      currentBalance = currentBalance + 0.25;
      quarterDeposited = true;
      printBalance();
    }
    // Otherwise ignore it and make sure to wait for a new event
    else if(quarterCheck == 0){
      quarterDeposited = false;
    }
  }

  // If the LOONIE button has been pressed by a human
  if (loonieRead == loonieCheck) {
    
    // Add the coin to the current balance if the "coin deposit" event has not been processed
    if(loonieCheck == 1 && !loonieDeposited){
      currentBalance = currentBalance + 1.00;
      loonieDeposited = true;
      printBalance();
    }
    // Otherwise ignore it and make sure to wait for a new event
    else if(loonieCheck == 0){
      loonieDeposited = false;
    }
  }
}