//www.elegoo.com
//2016.12.08
// include the library code:
#include <LiquidCrystal.h>
#include "SR04.h"
#include <LcdBarGraph.h>



#define TRIG_PIN 10
#define ECHO_PIN 13
// Maximum distance we want to ping for (in centimetres). Maximum sensor distance is rated at 400-500cm.
#define MAX_DISTANCE 30 
// -- number of columns in the LCD
byte lcdNumCols = 16; 

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// Creating bargraph instance, format is (&lcd, lcdNumCols, start X, start Y). So (&lcd, 16, 0, 1) would set the bargraph length to 16 columns and start the bargraph at column 0 on row 1.
LcdBarGraph lbg(&lcd, lcdNumCols);

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
  
    // -- initializing the LCD
    lcd.begin(2,lcdNumCols);
    lcd.clear();
    lcd.print("Christophe"); 
    lcd.setCursor (0,1); //  
    lcd.print("Bargraph"); 
   
  // -- do some delay: some time I've got broken visualization
  delay(2000);
  lcd.clear();

}

void loop() {
   a=sr04.Distance();

    // -- draw bar graph from the analog value 
    lbg.drawValue( a, MAX_DISTANCE);
    // -- do some delay: frequent draw may cause broken visualization
  
   lcd.setCursor (0,1); //
   lcd.print("Distance:"); 
   lcd.setCursor (10,1); //
   lcd.print(a); // print
   lcd.setCursor (14,1); //  
   lcd.print("cm");   
   
   delay(1000);
}
