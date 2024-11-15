/**
 * @file Stepper_Motor.c
 *
 * @brief Source file for the Stepper_Motor driver.
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

#include "Stepper_Motor.h"
 
void Stepper_Motor_Init()
{
	// Enable the clock to Port B by setting the 
	// RL bit (bit1) in the RCGCGPIO register
	SYSCTL->RCGCGPIO |= 0x02;
	
	// Configure the PB0, PB1, PB2, and PB3 pins as output
	// by setting Bits 3 to 0 in the DIR register
	GPIOB->DIR |= 0x0F;
	
	// Configure the PB0, PB1, PB2, and PB3 pins to function as
	// GPIO Pins by clearing bits 3 to 0 in the AFSEL register
	GPIOB->AFSEL &= ~0x0F;
	
	// Enable the digital funtionality for the PB0, PB1, PB2, and PB3 pins
	// by setting bits 3 to 0 in the DEN register
	GPIOB->DEN |= 0x0F;
	
	SYSCTL->RCGCGPIO |= 0x20;
	
	GPIOF->DIR |= 0x0C;
	
	GPIOF->AFSEL &= ~0x0C;
	
	GPIOF->DEN |= 0x0C;
	
	GPIOF->DATA |= 0x0C;
}
