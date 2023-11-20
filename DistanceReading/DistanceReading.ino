#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Alamat I2C LCD 16x2 (Cek alamatnya menggunakan scanner I2C)

const int trigPin = 2;  // Pin Trigger sensor ultrasonik
const int echoPin = 3; // Pin Echo sensor ultrasonik

long duration, distance_cm;

// Melakukan setup LCD
void lcd_setup(){
  lcd.init();                      // Inisialisasi LCD
  lcd.backlight();
}

// Melakukan setup HCSR04
void ultrasonic_setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

// Melakukan pembacaan jarak
void distance_reading(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Menerima waktu perjalanan gelombang ultrasonik
  duration = pulseIn(echoPin, HIGH);
  // Menghitung jarak dalam sentimeter
  distance_cm = duration / 29 / 2;
}

// Print pembacaan jarak ke LCD device
void distance_print(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Jarak: ");
  lcd.print(distance_cm);
  lcd.print(" cm");
}

void distance_print_awikwok(){
//  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pinjam dulu 100");
//  lcd.setCursor(0,1);
//  lcd.print("Seratus");
}

// Print pembacaan jarak ke serial device
void distance_print_serial(){
  Serial.print("Jarak: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
}

void setup() {
  lcd_setup();
  ultrasonic_setup();
  Serial.begin(9600);
}

void loop() {
  // Membaca jarak
//  distance_reading();
  // Menampilkan hasil bacaan di LCD
//  distance_print();
  // Menampilkan hasil bacaan di Serial Monitor
//  distance_print_serial();
distance_print_awikwok();
  
}
