#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define RST_PIN 9
#define SS_PIN 10
#define BUZZER_PIN 8

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C LCD address may vary

// Two valid RFID tag UIDs
byte validUID1[4] = {0x57, 0x30, 0x8D, 0x02};
byte validUID2[4] = {0x53, 0x6A, 0xB1, 0x2C};

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  lcd.begin(16, 2);
  lcd.backlight();

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  lcd.setCursor(0, 0);
  lcd.print("Scan your card");
}

void loop() {
  // Wait for card
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  if (isValidUID(mfrc522.uid.uidByte)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door Opened!");
    digitalWrite(BUZZER_PIN, LOW); // No buzzer
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access Denied!");
    tone(BUZZER_PIN, 1000);
    delay(1000);
    noTone(BUZZER_PIN);
  }

  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scan your card");

  mfrc522.PICC_HaltA(); // Stop reading
}

// Check against both valid UIDs
bool isValidUID(byte *uid) {
  return compareUID(uid, validUID1) || compareUID(uid, validUID2);
}

// Compare 4-byte UID
bool compareUID(byte *uid, byte *valid) {
  for (byte i = 0; i < 4; i++) {
    if (uid[i] != valid[i]) return false;
  }
  return true;
}
