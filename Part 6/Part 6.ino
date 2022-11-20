/*
  REFERENCE MATERIAL
  Setup & Sanity Testing: 
  - https://learn.adafruit.com/adafruit-2-8-tft-touch-shield-v2/connecting
  Various Examples from Adafruit: 
  - GFX Library: https://learn.adafruit.com/adafruit-gfx-graphics-library
  - ILI9341 Library: https://github.com/adafruit/Adafruit_ILI9341 
*/

#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// Data/command and chip select pins required for the ILI9341 as per documentation
#define TFT_DC 9
#define TFT_CS 10

// Screen size is 240 X 320
#define BUTTON_SIZE 40 

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

// Colors to refer to when displaying things to the screen
int colors[4] = {ILI9341_RED, ILI9341_GREEN, ILI9341_BLUE, ILI9341_WHITE};

void setup() {
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);
}

void loop() {

  // Prints my name to the screen
  displayName();

  // Changes the color of the 4 squares displayed on the screen
  for(int i = 0; i < 4; i++){
    rotateSquares(i);
    delay(500);
  }
    
}

void rotateSquares(int position){

  // Square colors which will reference the colors array defined above
  int square1, square2, square3, square4;

  switch(position){
    case 0:
      square1 = 0;
      square2 = 1;
      square3 = 2;
      square4 = 3;
      break;
    case 1:
      square1 = 1;
      square2 = 2;
      square3 = 3;
      square4 = 0;
      break;
    case 2:
      square1 = 2;
      square2 = 3;
      square3 = 0;
      square4 = 1;
      break;
    case 3:
      square1 = 3;
      square2 = 0;
      square3 = 1;
      square4 = 2;
      break;
  }

  // Print the square to the display
  tft.fillRect(0, 0, BUTTON_SIZE, BUTTON_SIZE, colors[square1]);
  tft.fillRect(0, BUTTON_SIZE*7, BUTTON_SIZE, BUTTON_SIZE, colors[square2]);
  tft.fillRect(BUTTON_SIZE*5, BUTTON_SIZE*7, BUTTON_SIZE, BUTTON_SIZE, colors[square3]);
  tft.fillRect(BUTTON_SIZE*5, 0, BUTTON_SIZE, BUTTON_SIZE, colors[square4]);

}

void displayName(){
  // Set the cursor to display characters roughly in the center of the screen
  tft.setCursor(tft.width()/4, tft.height()/2);
  // Set size and color, then display the text
  tft.setTextColor(ILI9341_RED);  
  tft.setTextSize(4);
  tft.println("David");
}