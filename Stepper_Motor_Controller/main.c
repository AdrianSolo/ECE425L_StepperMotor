/*
 * @file main.c
 *
 * @brief Main source code for the Stepper_Motor_Controller program.
 *
 * This file contains the main entry point and function definitions for the Stepper_Motor_Controller program.
 * This lab demonstrates how to control a stepper motor using GPIO.
 *
 * The following components are used:
 *	- PMOD BTN module
 *	-	28BYJ-48 5V Stepper Motor
 *  - ULN2003 Stepper Motor Driver
 *  - 3.3V / 5V Breadboard Power Supply Module (External Power Source)
 *
 * It configures the pins used by the PMOD BTN module to generate interrupts on rising edges.
 * The PMOD BTN module will be used to control the rotation of the stepper motor.
 *
 * @author Adrian Solorzano 
 */

#include "TM4C123GH6PM.h"
#include "SysTick_Delay.h"
#include "Stepper_Motor.h"
#include "PMOD_BTN_Interrupt.h"

static uint8_t enable = 0;
static uint8_t direction_select = 0;

void PMOD_BTN_Handler(uint8_t pmod_btn_status);

int main(void)
{
    SysTick_Delay_Init();  // Initialize delay
	
    Stepper_Motor_Init();  // Initialize stepper motor
	
    PMOD_BTN_Interrupt_Init(&PMOD_BTN_Handler);  // Set up button interrupt

    int step_index = 0;  // Track current step
	
    const uint8_t half_step[] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x09};  // Half-step sequence

    while (1)  // Main loop
    {
        if (enable == 1)  // Check if motor is enabled
        {
            if (direction_select == 0)  // Counterclockwise rotation
            {
                if (step_index == 0) step_index = 7;  // Wrap to last step
							
                GPIOB->DATA = (GPIOB->DATA & ~0x0F) | half_step[step_index];  // Update motor step
							
                step_index--;  // Move to previous step
            }
            else if (direction_select == 1)  // Clockwise rotation
            {
                if (step_index == 7) step_index = 0;  // Wrap to first step
							
                GPIOB->DATA = (GPIOB->DATA & ~0x0F) | half_step[step_index];  // Update motor step
							
                step_index++;  // Move to next step
            }
						
            SysTick_Delay1us(1200);  // Delay for motor speed control
        }
    }
}
