# 🔐 RFID Door Access Control System

<div align="center">
  <img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=25&duration=3000&pause=1000&color=4E94F7&center=true&vCenter=true&width=600&lines=Smart+Access+Control;Security+System;Arduino-based+Solution;RFID+Authentication" alt="Typing SVG" />

  ![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)
  ![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
  ![IoT](https://img.shields.io/badge/IoT-2C3E50?style=for-the-badge&logo=iot&logoColor=white)
  ![Security](https://img.shields.io/badge/Security-FF5733?style=for-the-badge)
</div>

## 🔧 Circuit Diagram

<div align="center">
  <img src="circuit-diagram.jpg" width="600" alt="Circuit Diagram" />
</div>

> ⚠️ *Make sure the image file is named `circuit-diagram.jpg` and is located in the same folder as the README.*

## 🌟 Project Overview

<img align="right" width="300" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&pause=1000&color=4EADF7&center=true&vCenter=true&multiline=true&width=300&height=100&lines=Scan+Card;Authenticate;Access+Granted" alt="Project Workflow" />

This RFID Door Access Control System is a smart security solution powered by Arduino. The system offers secure authentication through RFID technology, allowing only authorized cards to gain access.

When a valid RFID card is scanned, the system displays a welcoming "Door Opened!" message on the LCD screen, simulating access to a secured area. Unauthorized attempts trigger an "Access Denied!" alert accompanied by a warning sound from the buzzer.

Perfect for homes, offices, labs, or any space requiring controlled access, this system combines simplicity with effective security measures.

## ✨ Key Features

<div align="center">
  <table>
    <tr>
      <td align="center">
        <img width="60" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&color=00FF00&repeat=false&width=60&height=60&lines=✓" alt="Checkmark" />
        <br><b>Secure Authentication</b>
      </td>
      <td align="center">
        <img width="60" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&color=00FF00&repeat=false&width=60&height=60&lines=✓" alt="Checkmark" />
        <br><b>Visual Feedback</b>
      </td>
      <td align="center">
        <img width="60" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&color=00FF00&repeat=false&width=60&height=60&lines=✓" alt="Checkmark" />
        <br><b>Audio Alerts</b>
      </td>
    </tr>
    <tr>
      <td align="center">
        <img width="60" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&color=00FF00&repeat=false&width=60&height=60&lines=✓" alt="Checkmark" />
        <br><b>Multi-User Support</b>
      </td>
      <td align="center">
        <img width="60" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&color=00FF00&repeat=false&width=60&height=60&lines=✓" alt="Checkmark" />
        <br><b>User-Friendly Interface</b>
      </td>
      <td align="center">
        <img width="60" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&color=00FF00&repeat=false&width=60&height=60&lines=✓" alt="Checkmark" />
        <br><b>Quick Response Time</b>
      </td>
    </tr>
  </table>
</div>

## 🛒 Components Used

<div align="center">
  <table>
    <tr>
      <td align="center"><img width="60" height="60" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&color=FF0000&repeat=false&width=60&height=60&lines=A" alt="Arduino" /></td>
      <td><b>Arduino UNO</b> - Main controller for the system</td>
    </tr>
    <tr>
      <td align="center"><img width="60" height="60" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&color=0000FF&repeat=false&width=60&height=60&lines=R" alt="RFID" /></td>
      <td><b>MFRC522 RFID Reader</b> - Reads the RFID cards/tags</td>
    </tr>
    <tr>
      <td align="center"><img width="60" height="60" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&color=00FF00&repeat=false&width=60&height=60&lines=L" alt="LCD" /></td>
      <td><b>16x2 I2C LCD Display</b> - Provides visual interface and status messages</td>
    </tr>
    <tr>
      <td align="center"><img width="60" height="60" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&color=FFFF00&repeat=false&width=60&height=60&lines=B" alt="Buzzer" /></td>
      <td><b>Buzzer</b> - Provides audio feedback for access denied events</td>
    </tr>
    <tr>
      <td align="center"><img width="60" height="60" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&color=FFA500&repeat=false&width=60&height=60&lines=W" alt="Wires" /></td>
      <td><b>Jumper Wires & Breadboard</b> - For connecting all components</td>
    </tr>
  </table>
</div>

## 🛠️ Setup & Installation

### Hardware Assembly
Connect the RFID reader, LCD display, and buzzer to the Arduino according to standard pin configurations. The system uses SPI communication for the RFID reader and I2C for the LCD display.

### Software Installation
Install the required libraries in Arduino IDE:
- SPI Library (built-in)
- MFRC522 Library 
- Wire Library (built-in)
- LiquidCrystal_I2C Library

### Configuration
Upload the provided code and configure the valid RFID card UIDs by replacing the example values with your own card IDs:

```cpp
// Replace with your actual RFID card UIDs
byte validUID1[4] = {0x57, 0x30, 0x8D, 0x02};
byte validUID2[4] = {0x53, 0x6A, 0xB1, 0x2C};
```

## 🔄 How It Works

The system operates in a simple yet effective workflow:

1. **Standby Mode**: LCD displays "Scan your card" waiting for user interaction
2. **Authentication**: When a card is presented, the system reads and verifies the unique ID
3. **Access Decision**:
   - **Approved**: Valid cards receive "Door Opened!" message
   - **Denied**: Invalid cards trigger "Access Denied!" message with buzzer alert
4. **Reset**: System returns to standby mode after 2 seconds

## 🚀 Future Possibilities

<div align="center">
  <table>
    <tr>
      <td align="center" width="120">
        <img width="60" height="60" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&color=FF0000&repeat=false&width=60&height=60&lines=🔒" alt="Lock" />
        <br><b>Smart Lock Integration</b>
      </td>
      <td align="center" width="120">
        <img width="60" height="60" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&color=00FF00&repeat=false&width=60&height=60&lines=💾" alt="Database" />
        <br><b>EEPROM Storage</b>
      </td>
      <td align="center" width="120">
        <img width="60" height="60" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&color=0000FF&repeat=false&width=60&height=60&lines=👑" alt="Admin" />
        <br><b>Admin Mode</b>
      </td>
      <td align="center" width="120">
        <img width="60" height="60" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&color=FFFF00&repeat=false&width=60&height=60&lines=⏰" alt="Time" />
        <br><b>Time Restrictions</b>
      </td>
    </tr>
    <tr>
      <td align="center">
        <img width="60" height="60" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&color=FFA500&repeat=false&width=60&height=60&lines=📝" alt="Log" />
        <br><b>Access Logs</b>
      </td>
      <td align="center">
        <img width="60" height="60" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&color=800080&repeat=false&width=60&height=60&lines=📱" alt="Mobile" />
        <br><b>Mobile Alerts</b>
      </td>
      <td align="center">
        <img width="60" height="60" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&color=008080&repeat=false&width=60&height=60&lines=🔢" alt="Keypad" />
        <br><b>Keypad Backup</b>
      </td>
      <td align="center">
        <img width="60" height="60" src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=14&duration=4000&color=800000&repeat=false&width=60&height=60&lines=🚪" alt="Multi-door" />
        <br><b>Multi-Door Control</b>
      </td>
    </tr>
  </table>
</div>

## ❓ Quick Troubleshooting Tips

<div align="center">
  <table>
    <tr>
      <th>📢 Issue</th>
      <th>🔍 Solution</th>
    </tr>
    <tr>
      <td>LCD display blank</td>
      <td>Check I2C address (default: 0x27) and connections</td>
    </tr>
    <tr>
      <td>RFID not detecting cards</td>
      <td>Verify SPI connections and card placement</td>
    </tr>
    <tr>
      <td>Valid cards not recognized</td>
      <td>Run a UID dump sketch to confirm correct UID values</td>
    </tr>
  </table>
</div>

---

<div align="center">
  <p>Designed & Developed by V Abishek</p>
  
  [![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/Abivenkat13)
  [![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/vabishek13)
</div>
