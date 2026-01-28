#ifndef MOTOR_H
#define MOTOR_H


#include "stdint.h"


void MOTOR_Init(void);
void MOTOR_SetSpeed(uint8_t pwm);
uint8_t MOTOR_ReadPotentiometer(void);


#endif

