#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int IN1 = 9;
int IN2 = 8;
int IN3 = 7;
int IN4 = 6;
float angle = 0.0;
bool forward = false;
bool backward = false;
int delaytime = 100;

void lcd_setup(){
  lcd.init();
  lcd.backlight();
}

void printStepper(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sudut: ");
  lcd.print(angle);
  lcd.setCursor(0,1);
  if (forward){
    lcd.print("Forward");
  }
  else if (backward){
    lcd.print("Backward");
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop()
{
  // Karena 1 step adalah 11.25 derajat dan
  // 1 kali maju terdiri dari 4 step, maka
  // 1 kali maju sama dengan 45 derajat
//  writeStepper_forward(6);
  maju();
}



void writeStepper_forward(int num){
  forward = true;
  backward = false;
  for (int i=0; i<num; i++){
    maju();
    angle += 45.0;
  }
}

void writeStepper_backward(int num){
  forward = false;
  backward = true;
  for (int i=0; i<num; i++){
    mundur();
    angle -= 45.0; 
  }
}

void maju()
{
    // step 4
    step1();
    delay(delaytime);
    // step 3
    step2();
    delay(delaytime);
    // step 2
    step3();
    delay(delaytime);
    // step 1
    step4();
    delay(delaytime);
}

void mundur()
{
    // step 4
    step4();
    delay(delaytime);
    // step 3
    step3();
    delay(delaytime);
    // step 2
    step2();
    delay(delaytime);
    // step 1
    step1();
    delay(delaytime);
}

void step1()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
}

void step2()
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void step3()
{
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

void step4()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}
