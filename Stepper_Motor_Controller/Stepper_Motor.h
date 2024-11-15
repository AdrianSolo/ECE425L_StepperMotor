/**
 * @file Stepper_Motor.h
 *
 * @brief Header file for the Stepper_Motor driver.
 *
 * This file contains the function definitions for the Stepper_Motor driver. It uses
 * GPIO pins to provide output signals to the ULN2003 stepper motor driver.
 * 
 * The following components are used:
 *	-	28BYJ-48 5V Stepper Motor
 *  - ULN2003 Stepper Motor Driver
 *  - 3.3V / 5V Breadboard Power Supply Module (External Power Source)
 *
 * @author Aaron Nanas
 */

#include "TM4C123GH6PM.h"

/**
 * @brief Initializes the GPIO pins required for controlling a stepper motor.
 *
 * configures the necessary pins on Port B (PB0, PB1, PB2, PB3) as outputs
 * It enables the clock for Port B, sets the direction, disables
 * alternate functions, and enables digital functionality on the pins.
 * enables and configures the necessary settings for Port F.
 *
 * @param None
 *
 * @return None
 */
 void Stepper_Motor_Init();
 