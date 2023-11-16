
int adc;
float volt, temp;
 
void read_temp(){
    adc = analogRead(A3);
    volt = (adc/1023.0)*5;
//    temp = (volt-0.5)*100.0;
}

void print_temp_serial(){
//    Serial.print("Temp: ");
//    Serial.print(temp);
//    Serial.print(" C");
//    Serial.print(" || ");
    Serial.print("Voltage: ");
    Serial.println(volt);
    delay(80);
}

void setup() 
{  
    Serial.begin(9600);
//    lcd_setup();
}
void loop() 
{
    read_temp();
    print_temp_serial();
}
