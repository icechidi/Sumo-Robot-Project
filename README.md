# Sumo Robot Project

This project is an Arduino-based Sumo Robot designed for sumo robot competitions. The robot uses an ultrasonic sensor to detect opponents, an IR sensor to detect the edge of the ring, and a switch to activate or deactivate the robot. The robot is programmed to aggressively seek out opponents and avoid falling off the ring.

---

## Features

- **Motor Driver Control:** Dual motor driver for left and right wheels.
- **Ultrasonic Sensor:** Detects opponents within a specified range.
- **IR Sensor:** Detects the edge of the sumo ring to prevent falling off.
- **Activation Switch:** Enables or disables the robot.
- **Autonomous Behavior:** Aggressively seeks opponents and avoids the edge.

---

## Hardware Requirements

- Arduino Uno/Nano or compatible board
- L298N or similar dual H-bridge motor driver
- 2 DC motors with wheels
- Ultrasonic sensor (HC-SR04)
- IR sensor (for edge detection)
- Push button switch
- Power supply (battery pack)
- Sumo robot chassis

---

## Pin Connections

| Component         | Arduino Pin |
|-------------------|-------------|
| Left Motor ENA    | 11          |
| Left Motor IN1    | 5           |
| Left Motor IN2    | 6           |
| Right Motor ENB   | 3           |
| Right Motor IN3   | 9           |
| Right Motor IN4   | 10          |
| Ultrasonic Trig   | 7           |
| Ultrasonic Echo   | 8           |
| IR Sensor         | 4           |
| Switch            | 12          |

---

