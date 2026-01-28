#include "motor.h"
#include "stm32f4xx_hal.h"


extern TIM_HandleTypeDef htim3;
extern ADC_HandleTypeDef hadc1;


void MOTOR_Init(void)
{
HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}


void MOTOR_SetSpeed(uint8_t pwm)
{
__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pwm);
}


uint8_t MOTOR_ReadPotentiometer(void)
{
HAL_ADC_Start(&hadc1);
HAL_ADC_PollForConversion(&hadc1, 10);
uint16_t value = HAL_ADC_GetValue(&hadc1);
return (value * 255) / 4095;
}
