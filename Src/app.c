#include "app.h"
#include "manual_mode.h"
#include "auto_mode.h"
#include "bluetooth.h"

static volatile ApplicationMode currentMode = MODE_MANUAL;

void APP_Init(void)
{
    MANUAL_Init();
    AUTO_Init();
    BT_Init();
}

// Machine a etat principale de l'application
void APP_Run(void)
{
    switch (currentMode)
    {
        case MODE_MANUAL:
            MANUAL_Run();
            break;

        case MODE_AUTO:
            AUTO_Run();
            break;

        case MODE_BLUETOOTH:
            BT_Run();
            break;

	default:
            currentMode = MODE_MANUAL;
    	    break;
    }
}

void APP_SetMode(ApplicationMode mode)
{
    currentMode = mode;
}

