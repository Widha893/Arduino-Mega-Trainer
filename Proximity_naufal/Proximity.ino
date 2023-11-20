#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <SharpIR.h>

// Deklarasi
LiquidCrystal_I2C lcd(0x27, 16, 2);
float distance_cm; // PERHITUNGAN JARAK

SharpIR sensor( SharpIR::GP2Y0A41SK0F, A0 );


// fungsi baca dan print jarak
void print_IR_distance_cm()
{
  sensor.getDistance(); //Calculate the distance in centimeters and store the value in a variable
  
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance_cm);
  lcd.print(" cm");
  lcd.setBacklight(1);
  delay(500); 
}

void setup()
{
  lcd.init();                      // Inisialisasi LCD
  lcd.backlight();
}

void loop()
{
  print_IR_distance_cm();
}