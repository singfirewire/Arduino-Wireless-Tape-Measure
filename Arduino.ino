#include <LiquidCrystal_I2C.h>

// กำหนดพิน
const int trigPin = 9;    // พินส่งสัญญาณ
const int echoPin = 10;   // พินรับสัญญาณ
const int buttonPin = 2;  // พินปุ่มกด

// ตั้งค่าจอ LCD I2C ที่ address 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ตัวแปรสำหรับเก็บค่าต่างๆ
float duration;
float distance;
float lastDistance = 0;
int buttonState;
bool measurementMode = false;

void setup() {
  // ตั้งค่าพินอินพุต/เอาต์พุต
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
  // เริ่มต้นจอ LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("Distance Meter");
  delay(2000);
}

void loop() {
  // อ่านสถานะปุ่มกด
  buttonState = digitalRead(buttonPin);
  
  // ถ้ากดปุ่ม ให้สลับโหมดการวัด
  if (buttonState == LOW) {
    measurementMode = !measurementMode;
    delay(200); // ป้องกันการกระเด้งของปุ่ม
  }

  // ส่งสัญญาณอัลตร้าโซนิค
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // อ่านค่าระยะเวลาที่สัญญาณเดินทางไป-กลับ
  duration = pulseIn(echoPin, HIGH);
  
  // คำนวณระยะทางเป็นเซนติเมตร
  distance = duration * 0.034 / 2;

  // กรองสัญญาณรบกวนด้วยการเฉลี่ยค่า
  distance = (distance + lastDistance) / 2;
  lastDistance = distance;

  // แสดงผลบนจอ LCD
  lcd.clear();
  
  if (measurementMode) {
    lcd.print("Measuring...");
    lcd.setCursor(0, 1);
    lcd.print(distance, 1);
    lcd.print(" cm");
  } else {
    lcd.print("Press button");
    lcd.setCursor(0, 1);
    lcd.print("to measure");
  }

  delay(100); // หน่วงเวลาเล็กน้อยเพื่อให้จอ LCD แสดงผลได้เสถียร
}
