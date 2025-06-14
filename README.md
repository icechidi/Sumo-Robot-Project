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

## How It Works

- **Startup:** The robot waits for the activation switch to be pressed.
- **Edge Detection:** If the IR sensor detects the edge (LOW), the robot reverses and turns to avoid falling.
- **Opponent Detection:** If an opponent is detected within 30 cm by the ultrasonic sensor, the robot moves forward at full speed.
- **Searching:** If no opponent is detected, the robot rotates to search for one.
- **Deactivation:** If the switch is released, the robot stops all motors.

---

## Arduino Code

The main logic is in `Sumo Robot Competition.ino`.  
Upload this file to your Arduino board.

---

## Usage

1. Assemble the hardware according to the pin connections.
2. Upload the Arduino sketch to your board.
3. Place the robot in the sumo ring.
4. Press the activation switch to start the robot.
5. The robot will autonomously compete in the sumo ring.

---

## Customization

- **Detection Range:** Adjust the `distance < 30` value in the code to change how close the opponent must be before the robot attacks.
- **Motor Speed:** Change the values in `moveForward`, `reverse`, `turnRight`, and `rotateRight` functions to tune the robot's movement...

---

## License

This project is open-source and free to use for educational and competition purposes.

---

## Author

- Ice-Chidi
- https://github.com/icechidi

---