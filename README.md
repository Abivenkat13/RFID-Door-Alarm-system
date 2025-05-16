# 🔐 RFID Door Access Control System

<div align="center">
  <img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=25&duration=3000&pause=1000&color=4E94F7&center=true&vCenter=true&width=600&lines=Smart+Access+Control;Security+System;Arduino-based+Solution;RFID+Authentication" alt="Typing SVG" />

  ![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)
  ![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
  ![IoT](https://img.shields.io/badge/IoT-2C3E50?style=for-the-badge&logo=iot&logoColor=white)
  ![Security](https://img.shields.io/badge/Security-FF5733?style=for-the-badge)
</div>

## 📋 Table of Contents
- [Overview](#-overview)
- [Features](#-features)
- [Components Required](#-components-required)
- [Circuit Diagram](#-circuit-diagram)
- [Installation and Setup](#-installation-and-setup)
- [How It Works](#-how-it-works)
- [Code Explanation](#-code-explanation)
- [Future Enhancements](#-future-enhancements)
- [Troubleshooting](#-troubleshooting)
- [License](#-license)

## 🔍 Overview

This project implements a secure RFID-based door access control system using Arduino. The system authenticates users via RFID cards and grants or denies access accordingly. When a valid RFID card is scanned, the system displays an "Access Granted" message and simulates opening a door. Invalid cards trigger an alert sound and display an "Access Denied" message. The system is ideal for implementing basic security measures in homes, offices, or small businesses.

## ✨ Features

- **Secure Authentication**: Validates RFID cards against pre-registered UIDs
- **Visual Feedback**: Displays status messages on a 16x2 LCD screen
- **Audio Alerts**: Provides buzzer alerts for unauthorized access attempts
- **Multiple User Support**: Currently configured for two authorized users, expandable to more
- **Simple User Interface**: Clear instructions and status updates on the LCD display
- **Quick Response Time**: Instant authentication and feedback

## 🛒 Components Required

| Component | Quantity | Purpose |
|-----------|----------|---------|
| Arduino UNO | 1 | Main controller |
| MFRC522 RFID Reader | 1 | Reads RFID cards/tags |
| RFID Cards/Tags | 2+ | Authentication tokens |
| 16x2 I2C LCD Display | 1 | User interface |
| Buzzer | 1 | Audio feedback |
| Jumper Wires | Many | Connections |
| Breadboard | 1 | Circuit prototyping |
| 5V Power Supply | 1 | System power |

## 🔌 Circuit Diagram

```
Arduino UNO  <-->  MFRC522 RFID Reader
     3.3V    <-->  3.3V
     GND     <-->  GND
     RST     <-->  9
     MOSI    <-->  11 (ICSP)
     MISO    <-->  12 (ICSP)
     SCK     <-->  13 (ICSP)
     SDA     <-->  10

Arduino UNO  <-->  I2C LCD Display
     5V      <-->  VCC
     GND     <-->  GND
     A4      <-->  SDA
     A5      <-->  SCL

Arduino UNO  <-->  Buzzer
     8       <-->  Positive
     GND     <-->  Negative
```

## 🛠️ Installation and Setup

### Hardware Setup
1. Connect all components according to the circuit diagram above
2. Ensure the I2C LCD address is set to 0x27 (or update in code if different)
3. Power the Arduino using USB or external 5V supply

### Software Setup
1. Install the required libraries in Arduino IDE:
   - SPI Library (built-in)
   - MFRC522 Library (by GithubCommunity)
   - Wire Library (built-in)
   - LiquidCrystal_I2C Library (by Frank de Brabander)

2. Upload the provided code to your Arduino UNO
3. Configure valid UIDs by replacing the example values with your own RFID card UIDs

```cpp
// Replace these with your actual RFID card UIDs
byte validUID1[4] = {0x57, 0x30, 0x8D, 0x02};
byte validUID2[4] = {0x53, 0x6A, 0xB1, 0x2C};
```

## 🔄 How It Works

1. **Initialization**: The system initializes the RFID reader, LCD display, and buzzer
2. **Standby Mode**: LCD displays "Scan your card" and waits for a card
3. **Card Detection**: When a card is presented, the system reads its unique ID
4. **Authentication**:
   - The system compares the scanned UID with pre-stored valid UIDs
   - If matched: "Door Opened!" message appears
   - If not matched: "Access Denied!" message appears with buzzer alert
5. **Reset**: After 2 seconds, the system returns to standby mode

## 💻 Code Explanation

```cpp
#include 
#include 
#include 
#include 

#define RST_PIN 9    // RFID reader reset pin
#define SS_PIN 10    // RFID reader SS pin
#define BUZZER_PIN 8 // Buzzer for alerts

// Initialize RFID reader and LCD
MFRC522 mfrc522(SS_PIN, RST_PIN);  
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address may vary

// Two valid RFID tag UIDs - replace with your own card UIDs
byte validUID1[4] = {0x57, 0x30, 0x8D, 0x02};
byte validUID2[4] = {0x53, 0x6A, 0xB1, 0x2C};

void setup() {
  // Initialize serial, SPI, RFID module, LCD, and buzzer
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.begin(16, 2);
  lcd.backlight();
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  
  // Display initial message
  lcd.setCursor(0, 0);
  lcd.print("Scan your card");
}

void loop() {
  // Wait for new card and select it
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  
  // Check if scanned card is authorized
  if (isValidUID(mfrc522.uid.uidByte)) {
    // Access granted
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Door Opened!");
    digitalWrite(BUZZER_PIN, LOW); // No sound for valid access
  } else {
    // Access denied
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access Denied!");
    tone(BUZZER_PIN, 1000); // 1kHz tone for 1 second
    delay(1000);
    noTone(BUZZER_PIN);
  }
  
  // Wait and reset to initial state
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scan your card");
  
  // Stop reading
  mfrc522.PICC_HaltA();
}

// Function to check if scanned UID matches any valid UID
bool isValidUID(byte *uid) {
  return compareUID(uid, validUID1) || compareUID(uid, validUID2);
}

// Helper function to compare two UIDs
bool compareUID(byte *uid, byte *valid) {
  for (byte i = 0; i < 4; i++) {
    if (uid[i] != valid[i]) return false;
  }
  return true;
}
```

### Key Parts:
- **Libraries**: Uses SPI, MFRC522, Wire, and LiquidCrystal_I2C libraries
- **Pin Definitions**: Configures pins for RFID reader and buzzer
- **Valid UIDs**: Stores UIDs of authorized cards
- **Authentication Logic**: Compares scanned UID with valid UIDs
- **User Feedback**: Provides visual and audio feedback based on authentication result

## 🚀 Future Enhancements

1. **Relay Integration**: Add relay module to control actual door locks
2. **Database Storage**: Store valid UIDs in EEPROM to persist after power cycles
3. **Admin Card**: Special card to enter "programming mode" to add/remove authorized cards
4. **Time-Based Access**: Restrict access based on time of day
5. **Log System**: Record access attempts with timestamp (requires RTC module)
6. **Mobile Notifications**: Send alerts for unauthorized access attempts
7. **Password Backup**: Add keypad for PIN entry as backup authentication
8. **Multiple Door Support**: Expand system to control multiple doors

## ❓ Troubleshooting

| Problem | Possible Cause | Solution |
|---------|----------------|----------|
| LCD not displaying | Incorrect I2C address | Run I2C scanner sketch to find correct address |
| RFID reader not detecting cards | Wiring issue | Double-check SPI connections |
| System not recognizing valid cards | Incorrect UID values | Use UID dump sketch to get correct UIDs |
| Buzzer not working | Incorrect polarity | Reverse buzzer connections |
| Arduino not powering up | Power supply issue | Check USB connection or external power supply |

## 📝 License

This project is open-source and available under the MIT License.

---

<div align="center">
  <p>Developed with ❤️ by V Abishek</p>
  
  [![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/Abivenkat13)
  [![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/vabishek13)
</div>
