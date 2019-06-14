#include <Wire.h> //LCD I2c
#include <LiquidCrystal_I2C.h> //LCD I2c
LiquidCrystal_I2C lcd(0x27, 16, 2); //LCD I2c
#include "DHT.h" //เรียกใช้
DHT dht;  //กำหนดค่าDHT
#define RELAY1  3 //relay ตั้งค่า pin
void setup() {
//DHT  
  Serial.begin(9600);  //DHT
  Serial.println();  //DHT
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");  //DHT
  dht.setup(2); // data pin 2  //DHT
//DHT
//Relay
  pinMode(RELAY1, OUTPUT);  //DHT
 //Relay
}
void loop() {
 //DHT
//delay รับค่า
 delay(dht.getMinimumSamplingPeriod());
//แปลงค่าาเป็นตัวเลข
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();
//แสดงผล
  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");
  Serial.println(dht.toFahrenheit(temperature), 1);
 //เงื่อนไข
  if(temperature<=32.0){//humidityความชื้นในอากาศ
    digitalWrite(RELAY1,HIGH);
    }
   else if(temperature>=33.0){
    digitalWrite(RELAY1,LOW);
    }
//DHT
//LCD I2c
lcd.begin(); //LCD
  lcd.print("Tem:");
  lcd.print(temperature);  //LCD
  lcd.print(" +-2 C");
  lcd.setCursor(0, 1);  //LCD
  lcd.print("hum:");
  lcd.print(humidity);  //LCD
  lcd.print(" +-5%RH");
//LCD I2c
}
