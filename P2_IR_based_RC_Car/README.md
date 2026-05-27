# 🚗 IR Remote Control Car using Arduino UNO
---

An **IR Remote Control Car** is an Arduino-based robotics project that allows wireless movement control using an **Infrared (IR) Remote**.

The project is built using **Arduino UNO**, an **L293D Motor Driver IC**, **DC Motors**, and an **IR Receiver Module**.  
The car receives signals from the IR remote and performs movement actions like:

- Moving Forward
- Moving Backward
- Stopping

The **IR Receiver** reads the remote button signals and sends them to the Arduino UNO.  
Based on the received IR code, the Arduino controls the motors through the **L293D Motor Driver**.

This project demonstrates the practical implementation of:

- Embedded Systems
- Robotics
- Wireless Control
- Arduino Programming
- Motor Driver Interfacing

![IR Remote Control Car](./Assets/Simulation.gif)


# 🔧 Components Used
---

- Arduino UNO
- L293D Motor Driver IC
- IR Receiver Module
- IR Remote Control
- 4 × DC Motors
- 9V Battery
- Breadboard
- Jumper Wires


# 🔌 Connections
---

## IR Receiver Module

| IR Receiver Pin | Arduino UNO |
|---|---|
| VCC | 5V |
| GND | GND |
| OUT | Digital Pin 11 |


## L293D Motor Driver Connections

| L293D Pin | Connection |
|---|---|
| Enable 1&2 | Digital Pin 10 |
| Input 1 | Digital Pin 9 |
| Output 1 | Motor Terminal 2 (Right x 2) |
| Output 2 | Motor Terminal 1 (Right x 2) |
| Input 2 | Digital Pin 8 |
| Power 2 | 9V battery (+) |
| Enable 3&4 | Digital Pin 5 |
| Input 3 | Digital Pin 4 |
| Output 3 | Motor Terminal 2 (Left x 2) |
| Output 4 | Motor Terminal 1 (Left x 2) |
| Input 4 | Digital Pin 3 |
| Motor VCC | 9V Battery |
| Power 1 | 5V Arduino |
| GND Pins | GND |


## DC Motor Connections

| Motor | Connection |
|---|---|
| Left Motors | L293D Output 3 & 4 |
| Right Motors | L293D Output 1 & 2 |


## Power Supply

| Component | Power |
|---|---|
| Arduino UNO | USB / 5V |
| Motors | 9V Battery |


# 🎮 Remote Control Functions
---

| Remote Button | Action |
|---|---|
| Forward Button | Move Forward |
| Backward Button | Move Backward |
| Stop Button | Stop Motors |


# 🚀 Features
---

- Wireless IR Remote Control
- Forward & Backward Movement
- Left & Right Turning
- Motor Driver Integration
- Real-Time Command Execution
- Simple Robotics Automation


# 📂 Project Files
---

- `codeFile.ino` → Arduino Source Code
- `Components.csv` → Components List
- `Schematic Diagram.pdf` → Circuit Diagram
- `Simulation.gif` → Project Simulation


# 👨‍💻 Author
---

**Arghadip Biswas**

- [LinkedIn](https://www.linkedin.com/in/arghadip-biswas2002/)
- [Instagram: @mr_arghadip.official](https://www.instagram.com/mr_arghadip.official/)
- [Github: arghadip2002](https://github.com/arghadip2002)
- Email - mrarghadipofficial@gmail.com