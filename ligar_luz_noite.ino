#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int ldr = 4;
int rele = 2;

LiquidCrystal_I2C lcd(0x27, 16,2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(ldr, INPUT);
  pinMode(rele, OUTPUT);
    
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(ldr); 

  Serial.print("sensor: " );
  Serial.println(sensorValue);

  if(sensorValue <= 60){
    lcd.clear();
    lcd.print("Anoiteceu...");
    lcd.setCursor(0,1);
    lcd.print(sensorValue);
    digitalWrite(rele, LOW);
    
  }else{
    lcd.clear();
    lcd.print("Amanheceu...");
    lcd.setCursor(0,1);
    lcd.print(sensorValue);
    digitalWrite(rele, HIGH);
    
  }
  
  delay(700);
}
