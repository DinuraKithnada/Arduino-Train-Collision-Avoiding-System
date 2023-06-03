#include<LiquidCrystal_I2C.h>//LCD Library
#include<Servo.h>//Servo Library

LiquidCrystal_I2C lcd(0x27,16,4);//defining lcd display

int irSens1 = 2;//creating variables for each IR Sensor Input Pin
int irSens2 = 3;
int irSens3 = 4;
//int irSens4 = 9;
int irSens1In;//creating variables for each IR Sensor Input value
int irSens2In;
int irSens3In;
//int irSens4In;
//int batteryVolSens = 5; for future videos
int redTraffic = 6;//defining LEDs
int yellowTraffic = 7;
int greenTraffic = 8;
Servo Servo1;



void setup() {
  pinMode(irSens1,INPUT);//setting up IR Sensor Pins
  pinMode(irSens2,INPUT);
  pinMode(irSens3,INPUT);
  //pinMode(irSens4,INPUT);
  //pinMode(batteryVolSens,INPUT);
  pinMode(redTraffic,OUTPUT);
  pinMode(yellowTraffic,OUTPUT);
  pinMode(greenTraffic,OUTPUT);
  lcd.init();
  lcd.backlight();
  Servo1.attach(10);
  Serial.begin(9600);

}

void loop() {
  irSens1In = digitalRead(irSens1);
  irSens2In = digitalRead(irSens2);
  irSens3In = digitalRead(irSens3);
  //irSens4In = digitalRead(irSens4);

  /*if (irSens1In == 0){
    lcd.setCursor(0,0);
    lcd.print("The Train is");
    lcd.setCursor(0,1);
    lcd.print("comming 1500");
    lcd.setCursor(12,1);
    lcd.print("m");
    lcd.setCursor(-4,2);
    lcd.print("away");
    Servo1.write(0);
    digitalWrite(redTraffic,HIGH);
    digitalWrite(greenTraffic,LOW);
    digitalWrite(yellowTraffic,LOW);
  }*/
  if (irSens1In == 0){
    lcd.setCursor(0,0);
    lcd.print("The Train is");
    lcd.setCursor(0,1);
    lcd.print("comming 1000");
    lcd.setCursor(12,1);
    lcd.print("m");
    lcd.setCursor(-4,2);
    lcd.print("away");
    Servo1.write(0);
    digitalWrite(redTraffic,HIGH);
    digitalWrite(greenTraffic,LOW);
    digitalWrite(yellowTraffic,LOW);
  }
  else if (irSens2In == 0){
    lcd.setCursor(0,0);
    lcd.print("The Train is");
    lcd.setCursor(0,1);
    lcd.print("comming 500");
    lcd.setCursor(11,1);
    lcd.print("m");
    lcd.setCursor(-4,2);
    lcd.print("away");
    Servo1.write(0);
    digitalWrite(redTraffic,HIGH);
    digitalWrite(greenTraffic,LOW);
    digitalWrite(yellowTraffic,LOW);
  }
  else if (irSens3In == 0){
    lcd.setCursor(0,0);
    lcd.print("Train left");
    lcd.setCursor(0,1);
    lcd.print("Cross Now");
    lcd.setCursor(-4,2);
    lcd.print("Thank You For");
    lcd.setCursor(-4,3);
    lcd.print("Your Patience");
    digitalWrite(redTraffic,LOW);
    digitalWrite(yellowTraffic,HIGH);
    delay(2000);
    digitalWrite(yellowTraffic,LOW);
    digitalWrite(greenTraffic,HIGH);
    Servo1.write(90);
  }
  else{
    Servo1.write(90);
    lcd.setCursor(0, 0);
    lcd.print("You can Cross");
    lcd.setCursor(0, 1);
    lcd.print("No Train Comming");
    digitalWrite(redTraffic,LOW);
    digitalWrite(yellowTraffic,LOW);
    digitalWrite(greenTraffic,HIGH);
  }
  delay(1250);
  lcd.clear();
  
}
