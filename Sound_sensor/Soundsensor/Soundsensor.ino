#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define sound_pin A1  

LiquidCrystal_I2C lcd(0x27, 16, 2);
float sound_val, voltage, dB;
float refVoltage = 5.0;

void lcd_setup(){
 lcd.init();                      // Inisialisasi LCD
 lcd.backlight();
}

void setup() {
 pinMode (sound_pin, INPUT);
  Serial.begin(9600);
 lcd_setup();
}

void read_sound()
{
  sound_val = analogRead(sound_pin); 
  voltage = sound_val * (refVoltage / 1023.0);
  dB = 20 * log10(voltage);

  Serial.print("Sound value: ");
  Serial.print(sound_val);
  Serial.print(" ");
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" ");
  Serial.print("Decibel: ");
  Serial.println(dB);
  
   lcd.setCursor(0,0);
   lcd.print("ADC: ");
   lcd.print(sound_val);
}

void loop() {
  read_sound();

}