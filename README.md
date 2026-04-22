# Automated Water Level Monitoring System

This project implements a water level monitoring system using both **8051** and **ARM7 (LPC2148)** microcontrollers.

## Features

* Detects water levels: Empty, Low, Medium, Full
* LED indicators for each level
* Buzzer alert for low/empty condition
* Implemented on two architectures for comparison

## Tech Stack

* Embedded C
* 8051 Microcontroller
* ARM7 (LPC2148)
* Proteus Simulation

## How It Works

The system uses four digital inputs to represent different water levels in the tank (L1–L4).

Initially, when the tank is full, all sensors are active, and all LEDs are turned ON, indicating the full level.

As the water level decreases, the sensors are deactivated sequentially from top to bottom. This results in the LEDs turning OFF one by one, visually indicating the dropping water level.

When the water reaches the lowest level (L1), a buzzer is activated along with the LED indication to alert that the water level is critically low.

Invalid or unexpected sensor combinations trigger the buzzer as a safety indication.


## Author

Vivek Binod
