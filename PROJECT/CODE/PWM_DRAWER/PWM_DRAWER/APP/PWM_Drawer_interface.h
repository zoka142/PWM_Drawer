/*
 * PWM_Drawer_interface.h
 *
 * Created: 10/25/2024 11:54:08 AM
 *  Author: dell
 */ 

#include "STD _TYPES.h"
#ifndef PWM_DRAWER_INTERFACE_H_
#define PWM_DRAWER_INTERFACE_H_

#define PWM_DRAWER_GLCD_HIGH_LINE					(0x0202020202UL)
#define PWM_DRAWER_GLCD_LOW_LINE					(0x4040404040UL)
#define PWM_DRAWER_GLCD_RISING_EDGE					(0x02027E4040UL)
#define PWM_DRAWER_GLCD_FALLING_EDGE				(0x40407E0202UL)
#define PWM_DRAWER_GLCD_RIGHT_ARROW_HEAD			(0x003E081C2AUL)
#define PWM_DRAWER_GLCD_LEFT_ARROW_HEAD				(0x2A1C083E00UL)
#define PWM_DRAWER_GLCD_ARROW_MIDDLE_BODY			(0x0808080808UL)
typedef struct {
	u8 Duty_Percent;
	f32 High_Time_ms;
	f32 Low_Time_ms;
	f32 Period_Time_ms;
	f32 Freq_kHz;
}PWM_Drawer_SignalData;


void PWM_Drawer_voidinit(void);
void PWM_Drawer_voidMeasureSignal(PWM_Drawer_SignalData *copy_pstructData);
void PWM_Drawer_voidDraw(PWM_Drawer_SignalData *copy_pstructData,f32 copy_f32Scale);


#endif /* PWM_DRAWER_INTERFACE_H_ */