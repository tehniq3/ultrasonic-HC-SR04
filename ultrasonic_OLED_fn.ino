/*********************************************************************
// version fn by niq_ro - 24.06.2015
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>  // https://github.com/adafruit/Adafruit_SSD1306
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


// from http://www.xappsoftware.com/wordpress/2012/03/15/how-to-interface-the-hc-sr04-ultrasonic-ranging-module-to-arduino/
#define ECHOPIN 8      // Pin to receive echo pulse
#define TRIGPIN 9        // Pin to send trigger pulse

int xd;

void setup () {
  
    Serial.begin(9600);

// by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done

  display.begin();
  // init done

// setting rx & tx for ultrasonic sensor
pinMode(ECHOPIN, INPUT);
pinMode(TRIGPIN, OUTPUT);

  // you can change the contrast around to adapt the display
  // for the best viewing!
//  display.setContrast(50);
  display.clearDisplay();

  // Print a logo message to the LCD.
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(15, 0);
  display.print("masurare");
  display.setCursor(15, 16);
  display.print("distanta");
  display.setCursor(10, 32);
  display.print("cu senzor");
  display.setCursor(20, 48);
  display.print("HC-SR04");
 
  display.display();
  delay (5000);
  display.clearDisplay(); 
}
int xd0 = 0;



void loop () {

  display.clearDisplay(); 

  for (int x = 0; x < 128; x++)
{
//  delay(50);
 // Start Ranging
// pinMode(TRIGPIN, OUTPUT);
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  // Compute distance
//  pinMode(ECHOPIN, INPUT);
  float distance = pulseIn(ECHOPIN, HIGH);
delay(75);
  distance= distance/58;
Serial.println(distance);


// erase the part of screen
  for (int y = 0; y < 8; y++)
{
display.drawLine(0, y, 50, y, WHITE);
}
//display.display();
  
display.setTextSize(1);
display.setTextColor(BLACK);
display.setCursor(0, 0);
display.print(distance,1);
display.print("cm");
display.display();


 xd = distance/2;
if (xd > 51) xd = 50;
if (xd == 0) xd = 1;
display.drawLine(x, 64-xd0, x, 64-xd, WHITE);
//   }  

  
//  display.clearDisplay();  
//  delay(250);
xd0 = xd;  
  }
xd0 = xd;  
}
