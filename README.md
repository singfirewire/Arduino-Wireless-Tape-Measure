โค้ดนี้ใช้อุปกรณ์ดังนี้:
1. บอร์ด Arduino (Arduino UNO หรือ Nano) https://s.shopee.co.th/2LIweABVmT
2. เซ็นเซอร์วัดระยะทาง HC-SR04 https://s.shopee.co.th/9Um7BNnpSa
3. จอ LCD I2C ขนาด 16x2 https://s.shopee.co.th/8zpqaYMQfw
4. ปุ่มกด 1 ตัว

การต่อวงจร:
- เซ็นเซอร์ HC-SR04:
  - VCC -> 5V
  - Trig -> D9
  - Echo -> D10
  - GND -> GND

- จอ LCD I2C:
  - VCC -> 5V
  - GND -> GND
  - SDA -> A4
  - SCL -> A5

- ปุ่มกด:
  - ขาหนึ่งต่อกับ D2
  - อีกขาต่อกับ GND

คุณสมบัติของโปรแกรม:
1. วัดระยะทางได้ตั้งแต่ 2-400 เซนติเมตร
2. แสดงผลทศนิยม 1 ตำแหน่ง
3. มีการกรองสัญญาณรบกวนด้วยการเฉลี่ยค่า
4. มีปุ่มกดเพื่อเริ่ม/หยุดการวัด
5. แสดงผลผ่านจอ LCD แบบ I2C

คุณต้องติดตั้งไลบรารี LiquidCrystal_I2C ก่อนใช้งาน สามารถติดตั้งได้ผ่าน Library Manager ใน Arduino IDE
