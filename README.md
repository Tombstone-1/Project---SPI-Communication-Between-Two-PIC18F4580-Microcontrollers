# SPI Communication Between Two PIC18F4580 Microcontrollers

## 📖 Overview

This project demonstrates SPI-based communication between two **PIC18F4580** microcontrollers, with one configured as **Master** and the other as **Slave**. The master sends an 8-bit value (a single-digit number between 0–9), which the slave receives and displays on a **7-segment display**.

Although SPI doesn't inherently support acknowledgment, a **custom software-based acknowledgment mechanism** is implemented. The slave echoes the received data back to the master, and if the received data matches, an **LED on the master side** lights up to confirm successful communication.

---

## ⚙️ Features

- 📡 SPI communication between two PIC18F4580 microcontrollers.
- 🔢 Master sends an 8-bit code representing a single-digit number (0–9).
- 🔺 Slave receives and displays the digit on a 7-segment display.
- ✅ Custom acknowledgment:
  - Slave echoes received data.
  - If matched, a master-side LED turns ON.

---

## 🛠️ Hardware Used

- 2 × PIC18F4580 Microcontrollers  
- 1 × 7-Segment Display  
- 1 × LED (for acknowledgment indicator)  
- Breadboard, connecting wires, and power supply  

---

## 🧠 Software Logic

### Master:

- Configures SPI in Master mode.
- Sends an 8-bit value via SPI.
- Waits for the slave’s response.
- Compares the received byte to the original sent byte.
- Lights up a LED if acknowledgment is successful.

### Slave:

- Configures SPI in Slave mode.
- Receives data from the master.
- Displays the digit on a 7-segment display.
- Sends back the received byte to serve as acknowledgment.

---

## 🧪 How to Use

1. Load the respective firmware onto the Master and Slave PIC18F4580 microcontrollers.
2. Connect the SPI lines correctly:
   - Master SDO to Slave SDI  
   - Master SDI to Slave SDO  
   - Master SCK to Slave SCK  
   - Master SS to Slave SS  
3. Power the circuit and observe:
   - The slave displays the digit sent by the master.
   - The LED on the master lights up upon successful acknowledgment.

---

## 🧩 Simulation Support

A **Proteus simulation file** (`.pdsprj`) is included in this repository for testing the project virtually. You can open it using **Proteus Design Suite** to simulate the SPI communication and visualize the 7-segment display and acknowledgment LED.

---

## 🔄 Future Improvements

- Extend support to multi-digit numbers.

---

## 📁 Files Included

- `PIC_SPI_MASTER` – Firmware for master PIC18F4580  
- `PIC_SPI_SLAVE` – Firmware for slave PIC18F4580  
- `README.md` – Project documentation  
- `PIC_SPI_master_slave.pdsprj` – Proteus simulation file  

---



