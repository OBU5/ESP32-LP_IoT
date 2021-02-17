    /////////////////////////////////////////////////////////////////
   //             ESP32 2.9" E-PAPER EXAMPLE             v1.00    //
  //       Get the latest version of the code here:              //
 //        https://educ8s.tv/2-9-e-paper-display                //
/////////////////////////////////////////////////////////////////

#include <GxEPD.h>
#include <GxGDEH029A1/GxGDEH029A1.cpp>      // 2.9" b/w
#include <GxIO/GxIO_SPI/GxIO_SPI.cpp>
#include <GxIO/GxIO.cpp>
#include "BitmapGraphics.h"
#include <Fonts/FreeSansBold24pt7b.h>


GxIO_Class io(SPI, SS, 27, 21); 
GxEPD_Class display(io, 16, 19); 

const char* name = "FreeSansBold24pt7b";
const GFXfont* f = &FreeSansBold24pt7b;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");
  display.init();
  display.setRotation(1);
  display.fillScreen(GxEPD_WHITE);
  display.update();
  display.setTextColor(GxEPD_BLACK);
  display.setFont(f);
  display.setCursor(50, 15);
  display.println();
  display.println(" Daily Quote");
  display.update();
  delay(6000);
  display.setRotation(0);

}
  

void loop() {
  
  display.drawExampleBitmap(gImage_quote, 0, 0, GxEPD_WIDTH,GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
  delay(10000);
  display.drawExampleBitmap(gImage_quote2, 0, 0, GxEPD_WIDTH,GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
  delay(10000);
  display.drawExampleBitmap(gImage_quote3, 0, 0, GxEPD_WIDTH,GxEPD_HEIGHT, GxEPD_BLACK);
  display.update();
  delay(10000);
  
}
