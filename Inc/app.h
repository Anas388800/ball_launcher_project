#ifndef APP_H
#define APP_H


#include "stdint.h"


typedef enum {
MODE_MANUAL = 0,
MODE_AUTO,
MODE_BLUETOOTH
} ApplicationMode;


void APP_Init(void);
void APP_Run(void);
void APP_SetMode(ApplicationMode mode);



#endif
