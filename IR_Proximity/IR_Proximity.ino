#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define IRpin A0 

LiquidCrystal_I2C lcd(0x27, 16, 2);

float distance, volts;
                                 
void setup() {
  Serial.begin(9600);                             
  lcd_setup();
}
void loop() {
  volts = analogRead(IRpin)*0.0048828125;   
  distance = 65*pow(volts, -1.10);   
  distance_print();
  Serial.print(distance);     
  Serial.println(" cm");
  delay(100);                                     
}

void lcd_setup(){
  lcd.init();                      // Inisialisasi LCD
  lcd.backlight();
}

void distance_print(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Jarak: ");
  lcd.print(distance);
  lcd.print(" cm");
}
