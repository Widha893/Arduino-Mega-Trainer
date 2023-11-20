#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <string.h>


float pwm;
int DCpwm_pin = 9;
int in1_DC = 11;
int in2_DC = 12;

String DC_state[2] = {"start","stop"};
String DC_direction[2] = {"CW","CCW"};
  
LiquidCrystal_I2C lcd(0x27, 16, 2);

void dcpin_init()
{
	pinMode(in1_DC, OUTPUT);
	pinMode(in2_DC, OUTPUT);
	pinMode(DCpwm_pin, OUTPUT);
}

void DC_spin (String direction, float pwm)
{
  if (direction.equalsIgnoreCase(DC_direction[0]))
  {
    analogWrite(in2_DC,pwm);

    lcd.setCursor(0, 0);
    lcd.print(DC_direction[0]);
    lcd.print(", PWM: ");
    lcd.print(pwm);
    lcd.setBacklight(1);
  // delay(500);
  }
  else if (direction.equalsIgnoreCase(DC_direction[1]))
  {
  	analogWrite(in1_DC,pwm);

    lcd.setCursor(0, 0);
    lcd.print(DC_direction[1]);
    lcd.print(", PWM: ");
    lcd.print(pwm);
    lcd.setBacklight(1);
  }
  else {}
  // delay(500);
}


void setup()
{
  dcpin_init();
  lcd.init();                      // Inisialisasi LCD
  lcd.backlight();
}

void loop()
{
	DC_spin ("cw", 1600);
}