#include "manual_mode.h"
#include "motor.h"
#include "display.h"

/*
 * Mode MANUEL :
 * - Lecture potentiomètre via ADC
 * - Conversion en PWM moteur
 * - Affichage puissance via MAX7219
 */

void MANUAL_Init(void){/*RAS*/}

void MANUAL_Run(void)
{
    uint8_t speed;

    /* Lecture du potentiomètre */
    speed = MOTOR_ReadPotentiometer();

    /* Application PWM moteur */
    MOTOR_SetSpeed(speed);

    /* Affichage bargraph */
    DISPLAY_ShowPower(speed);
}
