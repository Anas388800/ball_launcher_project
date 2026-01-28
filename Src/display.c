#include "display.h"
#include "stm32f4xx_hal.h"


extern SPI_HandleTypeDef hspi1;


static const uint8_t bargraphLUT[8] = {
0x00, 0x01, 0x03, 0x07,
0x0F, 0x1F, 0x3F, 0x7F
};


static void MAX7219_Write(uint8_t reg, uint8_t data)
{
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
HAL_SPI_Transmit(&hspi1, &reg, 1, 10);
HAL_SPI_Transmit(&hspi1, &data, 1, 10);
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
}


void DISPLAY_Init(void)
{
    /* Mode test OFF */
    MAX7219_Write(0x0F, 0x00);   // DISPLAY_TEST
    /* Pas de decodage BCD */
    MAX7219_Write(0x09, 0x00);   // DECODE_MODE
    /* Nombre de digits utilises : 8 digits (0 à 7) */
    MAX7219_Write(0x0B, 0x07);   // SCAN_LIMIT
    /* Intensite lumineuse */
    MAX7219_Write(0x0A, 0x0F);   // INTENSITY (max)
    /* Sortie du mode shutdown */
    MAX7219_Write(0x0C, 0x01);   // SHUTDOWN → Normal operation
    /* Effacement de l'affichage */
    for (uint8_t i = 1; i <= 8; i++)
    {
        MAX7219_Write(i, 0x00);
    }
}


void DISPLAY_ShowPower(uint8_t power)
{
uint8_t level = (power * 7) / 255; // on map le level
MAX7219_Write(1, bargraphLUT[level]);
}
