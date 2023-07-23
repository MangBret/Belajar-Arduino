//#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x3F,16,2);  // GANTI 0x3F Ke 0x27 kalau LCD ga muncul
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
DHT dht(2, DHT11); //Pin, Jenis DHT


#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


int powerPin = 3;    // untuk pengganti VCC/5vOLT
 
void setup(){
  //lcd.init();
  // Print a message to the LCD.
  //lcd.backlight(); 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  display.clearDisplay();
  // jadikan pin power sebagai output
  pinMode(powerPin, OUTPUT);
  // default bernilai LOW
  digitalWrite(powerPin, LOW);
  Serial.begin(9600);
  dht.begin();
}
 
void loop(){
 digitalWrite(powerPin, HIGH);
  
 int kelembaban = dht.readHumidity();
 int suhu = dht.readTemperature();

 Serial.print("hum: ");
 Serial.print(kelembaban);
 Serial.println(" C");
 Serial.print("suhu: ");
 Serial.print(suhu);
 Serial.print(" C");
 
  //display.clear();

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.cp437(true);
  display.setCursor(0,0);
  display.print("Humid:");
  display.print(kelembaban);
  display.println(" %");

  display.setCursor(0,15);
  display.print("Temp:");
  //display.setCursor(5,11);
  display.print(suhu);
  display.println(" C");

  display.display();
  delay(1000);

}
