/*********************************************************************
This is an example sketch for our Monochrome Nokia 5110 LCD Displays
  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/338
These displays use SPI to communicate, 4 or 5 pins are required to
interface
Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!
Written by Limor Fried/Ladyada  for Adafruit Industries.
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

// Nokia 5110 LCD (PCD8544) from https://code.google.com/p/pcd8544/

/* niq_ro ( http://nicuflorica.blogspot.ro ) case for Nokia 5110 LCD (PCD8544) - LPH 7366:
 For module from China, you must connect like this:
* Pin 1 (RST) -> Arduino digital 6 (D6)
* Pin 2 (CE) -> Arduino digital 7 (D7)
* Pin 3 (DC) -> Arduino digital 5 (D5)
* Pin 4 (DIN) -> Arduino digital 4 (D4)
* Pin 5 (CLK) - Arduino digital 3 (D3)
* Pin 6 (Vcc) -> +5V thru adaptor module (see http://nicuflorica.blogspot.ro/2013/06/afisajul-folosit-la-telefoanele-nokia.html )
* Pin 7 (LIGHT) -> +5V thru 56-100 ohms resistor (for permanent lights) or... other pin control
* Pin 8 (GND) -> GND1 or GND2 
*/

// version 1.0

#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
// Adafruit_PCD8544 display = Adafruit_PCD8544(SCLK, DIN, DC, CS, RST);
Adafruit_PCD8544 display = Adafruit_PCD8544(3, 4, 5, 7, 6);

/*
static unsigned char PROGMEM picatura[] =
{ B0001000,
  B0001000,
  B0001000,
  B0010100,
  B0100010,
  B0100010,
  B0011100
};
*/

// from http://www.xappsoftware.com/wordpress/2012/03/15/how-to-interface-the-hc-sr04-ultrasonic-ranging-module-to-arduino/
#define ECHOPIN 8      // Pin to receive echo pulse
#define TRIGPIN 9        // Pin to send trigger pulse



void setup () {
  
    Serial.begin(9600);

  display.begin();
  // init done

// setting rx & tx for ultrasonic sensor
pinMode(ECHOPIN, INPUT);
pinMode(TRIGPIN, OUTPUT);

  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(50);
  display.clearDisplay();

  // Print a logo message to the LCD.
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(17, 0);
  display.print("masurare");
  display.setCursor(10, 8);
  display.print("distanta cu");
  display.setCursor(0, 16);
  display.print("senzor HC-SR04");
  display.setCursor(4, 24);
  display.print("versiunea ");
  display.setTextColor(WHITE, BLACK);
  display.print("1.0");
  display.drawLine(0, 32, 83, 32, BLACK);
  display.setTextColor(BLACK);
  display.setCursor(8, 32);
  display.print("sketch scris");
  display.setCursor(15, 40);
  display.print("de ");
  display.setTextColor(WHITE, BLACK);
  display.print("niq_ro");
  display.display();
  delay (5000);
  display.clearDisplay(); 
  

int k1;
int ko;
int h, t1, tv;
float t;
}

void loop () {

  display.clearDisplay(); 
 // Start Ranging
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  // Compute distance
  float distance = pulseIn(ECHOPIN, HIGH);
  distance= distance/58;

display.setTextSize(2);
display.setTextColor(BLACK);
display.setCursor(0, 0);
display.print(distance,1);
display.print("cm");
display.display();
 
    delay(250);
}
