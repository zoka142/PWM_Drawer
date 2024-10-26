/*
 * PWM_DRAWER.c
 *
 * Created: 10/22/2024 5:27:04 PM
 * Author : dell
 */ 

#include "BIT_MATH.h"
#include "STD _TYPES.h"
#define  F_CPU 16000000
#include <util/delay.h>

#include <avr/io.h>
#include "PWM_Drawer_interface.h"
#include "GLCD_interface.h"
#include "ICU_interface.h"
#include "PWM_interface.h"

int main(void)
{
	 PWM_Drawer_voidinit();
	 PWM_Drawer_SignalData Signal_Data = {0, 0, 0, 0, 0};
	 f32 Scale_ms = 0;

    while (1) 
    {
		PWM_Drawer_voidMeasureSignal(&Signal_Data);
		Scale_ms = (Signal_Data.Period_Time_ms)/3;
		PWM_Drawer_voidDraw(&Signal_Data, Scale_ms);
		_delay_ms(1000);
    }
}

