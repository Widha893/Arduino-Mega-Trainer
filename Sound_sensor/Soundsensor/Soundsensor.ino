#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define sound_pin A1  

LiquidCrystal_I2C lcd(0x27, 16, 2);
float sound_val;


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
  Serial.println(sound_val);
    lcd.setCursor(0,0);
    lcd.print("ADC: ");
    lcd.print(sound_val);
}

void loop() {
  read_sound();

}
