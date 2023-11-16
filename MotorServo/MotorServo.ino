#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Alamat I2C LCD 16x2 (Cek alamatnya menggunakan scanner I2C)
Servo myservo;

int pos = 0;

void servo_init(){
  myservo.attach(4);
}

void lcd_setup(){
  lcd.init();                      
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Motor Servo");
  lcd.setCursor(0,1);
  lcd.print("Position");
  delay(1000);
  lcd.clear();
}

void servo_print_lcd(){
  lcd.clear();
  lcd.setCursor(0,0);
  int pwm_print = map(pos,0,180,1000,2000);
  lcd.print("sudut: ");
  lcd.print(pos);
  lcd.setCursor(0,1);
  lcd.print("pwm: ");
  lcd.print(pwm_print);
}

void servo_print_serial(){
  int pwm_print = map(pos,0,180,1000,2000);
  Serial.print("sudut: ");
  Serial.print(pos);
  Serial.print(" || ");
  Serial.print("pwm: ");
  Serial.println(pwm_print);
}

void servo_write(float angle){
  pos = angle;
  myservo.write(pos);
  servo_print_serial();
}

void servo_sweep(){
  for(pos = 0; pos <= 180; pos += 10) 
  {                                  
    myservo.write(pos);              
    servo_print_serial();
    delay(15);                      
  } 
  for(pos = 180; pos>=0; pos-=10)    
  {                                
    myservo.write(pos);              
    servo_print_serial();
    delay(15);                       
  } 
}

void setup() {
  lcd_setup();
  servo_init();
  Serial.begin(9600);
}

void loop() {
  servo_sweep();
}
