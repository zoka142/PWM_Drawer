/*
 * PWM_Drawer_program.c
 *
 * Created: 10/25/2024 11:53:31 AM
 *  Author: dell
 */ 
#include "GLCD_interface.h"
#include "PWM_Drawer_interface.h"
#include "PWM_Drawer_config.h"
#include "PWM_interface.h"
#include "STD _TYPES.h"
#include "ICU_interface.h"

void PWM_Drawer_voidinit(void){
	#if GENERATE_PWM_FROM_SAME_MCU == 1
	GLCD_voidInit();
	PWM_voidInitChannel_0(PWM_ModeType,PWM_OutputMode);
	PWM_voidGenerateOnChannel_0(PWM_Prescaler,PWM_OutputMode,Duty_Cycle);	
	ICU_voidinit(ICU_Prescaler);			
	#elif GLCD_MCU == 1
	GLCD_voidInit();
	ICU_voidinit(ICU_Prescaler);
	#else			
	PWM_voidInitChannel_0(PWM_ModeType,PWM_OutputMode);
	PWM_voidGenerateOnChannel_0(PWM_Prescaler,PWM_OutputMode,Duty_Cycle);		
	#endif
}
void PWM_Drawer_voidMeasureSignal(PWM_Drawer_SignalData *copy_pstructData){
	ICU_SignalData Duty={0,0};
	ICU_voidGetDuty(ICU_Prescaler,&Duty);
	copy_pstructData->Period_Time_ms = Duty.Period_Time_ms;
	copy_pstructData->High_Time_ms = Duty.High_Time_ms;
	copy_pstructData->Low_Time_ms = Duty.Period_Time_ms - Duty.High_Time_ms;
	
	copy_pstructData->Freq_kHz = (1.0 / (copy_pstructData->Period_Time_ms));
	copy_pstructData->Duty_Percent = (u8)((copy_pstructData->High_Time_ms) * 100.0 / (copy_pstructData->Period_Time_ms));
}
void PWM_Drawer_voidDraw(PWM_Drawer_SignalData *copy_pstructData,f32 copy_f32Scale){
	GLCD_voidClearDisplay();
	GlCD_voidGoToLine(0);
	GLCD_voidString("frequency=");
	GLCD_voidFloat(copy_pstructData->Freq_kHz);
	GLCD_voidString("khz");
	
	GlCD_voidGoToLine(1);
	GLCD_voidString("duty=");
	GLCD_voidInteger(copy_pstructData->Duty_Percent);
	GLCD_voidString("%");
	
	GlCD_voidGoToLine(4);
	GLCD_voidString("time=");
	GLCD_voidFloat(copy_pstructData->Period_Time_ms);
	GLCD_voidString("ms");
	
	GlCD_voidGoToLine(5);
	GlCD_voidSpecialChar(PWM_DRAWER_GLCD_LEFT_ARROW_HEAD);
	for (u8 i = 0; i < ((u8)(copy_pstructData->High_Time_ms / copy_f32Scale)); i++) {
		GlCD_voidSpecialChar(PWM_DRAWER_GLCD_ARROW_MIDDLE_BODY);
	}
	GlCD_voidSpecialChar(PWM_DRAWER_GLCD_ARROW_MIDDLE_BODY);
	for (u8 i = 0; i < ((u8)(copy_pstructData->Low_Time_ms / copy_f32Scale)); i++) {
		GlCD_voidSpecialChar(PWM_DRAWER_GLCD_ARROW_MIDDLE_BODY);
	}
	GlCD_voidSpecialChar(PWM_DRAWER_GLCD_RIGHT_ARROW_HEAD);

		
	
	GlCD_voidGoToLine(6);
	u8 pixel_width_count = 0;
	while (pixel_width_count <120 ) {
		GlCD_voidSpecialChar(PWM_DRAWER_GLCD_RISING_EDGE); pixel_width_count += 5;
		for (u8 i = 0; i < ((u8)(copy_pstructData->High_Time_ms / copy_f32Scale)); i++) {
			GlCD_voidSpecialChar(PWM_DRAWER_GLCD_HIGH_LINE); pixel_width_count += 5;
		}
		GlCD_voidSpecialChar(PWM_DRAWER_GLCD_FALLING_EDGE); pixel_width_count += 5;
		for (u8 i = 0; i < ((u8)(copy_pstructData->Low_Time_ms / copy_f32Scale)); i++) {
			GlCD_voidSpecialChar(PWM_DRAWER_GLCD_LOW_LINE); pixel_width_count += 5;
		}
	}
	
}