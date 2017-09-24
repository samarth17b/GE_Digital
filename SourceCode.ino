#include <SPI.h>
#include <Adafruit_GFX.h>
#include <gfxfont.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>



#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

int emflevel = 0;
int ledlevel = 0;

void setup() 
{ 
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.display();
  delay(2000);
  display.clearDisplay(); 
  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("GE HACK: ");
  display.println("EMF DETECTOR");
  display.display();
  display.setTextSize(2);
  display.println("RADIOHEADS");
  display.display();
  display.clearDisplay();
  delay(2000);
  display.display();
}

void loop() 
{
  emflevel = analogRead(A0);
  Serial.println(emflevel);
  ledlevel = map(emflevel, 0, 1023, 0, 255);
  if(emflevel > 20)
  {
    display.clearDisplay(); 
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print("EMF LEVEl: ");
    display.setCursor(0,20);
    display.println(emflevel);
    display.display();
    analogWrite(9, (ledlevel*5));
    display.clearDisplay();
  }
  else
  {
    display.clearDisplay(); 
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print("EMF LEVEl: ");
    display.setCursor(0,20);
    display.print("0");
    display.display();
    analogWrite(9, 0);
    display.clearDisplay();
  }
  delay(200);
}
