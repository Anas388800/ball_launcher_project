#include "bluetooth.h"
#include "motor.h"
#include "display.h"
#include "stm32f4xx_hal.h"

extern UART_HandleTypeDef huart2;

static uint8_t rxByte;


void BT_Init(void)
{/* RAS pour le moment */}

/*  Mode BLUETOOTH recoit une commande via telephone avc moniteur bt simple et qui agit sur le moteur */
void BT_Run(void)
{

    if (HAL_UART_Receive(&huart2, &rxByte, 1, 10) == HAL_OK) // On essaie de lire 1 caractère
    {
        char cmd = (char)rxByte;

        if (cmd >= '0' && cmd <= '9')
        {
            /* Conversion caractère -> PWM */
            uint8_t pwm = (cmd - '0') * 28; // 0 à ~252

            MOTOR_SetSpeed(pwm);
            DISPLAY_ShowPower(pwm);
        }
        else if (cmd == 'S')
        {
            MOTOR_SetSpeed(0);
            DISPLAY_ShowPower(0);
        }
        // sinon : on ignore la commande    }
}