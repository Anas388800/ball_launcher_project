#include "auto_mode.h"
#include "stm32f4xx_hal.h"


extern TIM_HandleTypeDef htim2;


#define SERVO_0_DEG   1000
#define SERVO_90_DEG  1500

#define AUTO_PERIOD_MS  5000

static uint32_t lastTick = 0;
static uint8_t servoPosition = 0;

/* Position de depart du servomoteur pour bloquer les balon*/
void AUTO_Init(void)
{
    servoPosition = 0;
    lastTick = HAL_GetTick();

    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, SERVO_0_DEG);
}


/* Laisse passer un ballon toute les cinq seconde (a readjuster) */

void AUTO_Run(void)
{
    if (HAL_GetTick() - lastTick >= AUTO_PERIOD_MS)
    {
        if (servoPosition == 0)
        {
            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, SERVO_90_DEG);
            servoPosition = 1;
        }
        else
        {
            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, SERVO_0_DEG);
            servoPosition = 0;
        }

        lastTick = HAL_GetTick();
    }
}