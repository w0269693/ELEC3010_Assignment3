/*
  Reference material:
  1) Mark Bramwell's example sketch: https://codebender.cc/sketch:95561#Arduino%20LCD%20KeyPad%20Shield.ino 
  2) ELEC3010 Assignment 3 document example
  3) Pixel art: http://www.photonstorm.com/art/tutorials-art/16x16-pixel-art-tutorial
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

byte frog_top_left[8] = {
  0b01110, 
  0b10001, 
  0b10101, 
  0b10001, 
  0b01110, 
  0b10000, 
  0b10111, 
  0b10000
};

byte frog_top_right[8] = {
  0b01110, 
  0b10001, 
  0b10101, 
  0b10001, 
  0b01110, 
  0b00001, 
  0b11101, 
  0b00001
};

byte frog_bottom_left[8] = {
  0b01111, 
  0b01000, 
  0b10000, 
  0b10000, 
  0b11001, 
  0b01010, 
  0b10010, 
  0b01100
};

byte frog_bottom_right[8] = {
  0b11110, 
  0b00010, 
  0b00001, 
  0b00001, 
  0b10011, 
  0b01010, 
  0b01001, 
  0b00110
};

int lcd_key = 0;
int lcd_key_debounce = 0;
int adc_key_in = 0;
 
#define btnRIGHT  0
// #define btnUP     1
// #define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

int screenPosition = 6;
bool moveActionProcessed = false;

int read_LCD_buttons(){

  adc_key_in = analogRead(0);
 
  if (adc_key_in > 1000) return btnNONE;
  if (adc_key_in < 5)   return btnRIGHT; 
  if (adc_key_in < 555)  return btnLEFT;
  if (adc_key_in < 790)  return btnSELECT;  
  //if (adc_key_in < 195)  return btnUP;
  //if (adc_key_in < 380)  return btnDOWN;
  return btnNONE;
}

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(1, frog_top_left);
  lcd.createChar(2, frog_top_right);
  lcd.createChar(3, frog_bottom_left);
  lcd.createChar(4, frog_bottom_right);
  Serial.begin(9600);  
 }
void loop() {

  lcd_key = read_LCD_buttons();
  delay(10);
  lcd_key_debounce = read_LCD_buttons();

  if (lcd_key == lcd_key_debounce) {
    Serial.println(lcd_key_debounce);

    if(lcd_key_debounce == btnRIGHT && !moveActionProcessed){
      if(screenPosition < 14){
        screenPosition++;       
      }
      moveActionProcessed = true;
    }
    else if(lcd_key_debounce == btnLEFT && !moveActionProcessed){
      if(screenPosition > 0){
        screenPosition--;       
      }
      moveActionProcessed = true;
    }
    else if(lcd_key_debounce == btnSELECT && !moveActionProcessed){
        screenPosition = 6;       
      moveActionProcessed = true;
    }
    else if(lcd_key_debounce == btnNONE){
      moveActionProcessed = false;
    }

  }

  lcd.clear();
  lcd.setCursor(screenPosition, 0);
  lcd.write(1);
  lcd.setCursor(screenPosition + 1, 0);
  lcd.write(2);
  lcd.setCursor(screenPosition, 1);
  lcd.write(3);
  lcd.setCursor(screenPosition + 1, 1);
  lcd.write(4);

}