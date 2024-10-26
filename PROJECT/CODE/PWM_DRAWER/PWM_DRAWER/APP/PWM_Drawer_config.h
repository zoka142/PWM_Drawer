/*
 * PWM_Drawer_config.h
 *
 * Created: 10/25/2024 11:58:07 AM
 *  Author: dell
 */ 


#ifndef PWM_DRAWER_CONFIG_H_
#define PWM_DRAWER_CONFIG_H_

#define  ICU_Prescaler		ICU_Prescaler64


#define  PWM_ModeType		PWM_ModeType_0_FastPWM
#define  PWM_OutputMode		PWM_CHANNEL_0_NONINVERTING
#define  PWM_Prescaler		PWM_CHANNEL_Prescaler64
#define  Duty_Cycle			90

#define GENERATE_PWM_FROM_SAME_MCU			1	

#if GENERATE_PWM_FROM_SAME_MCU == 0
	#define GLCD_MCU						0		
#endif

#endif /* PWM_DRAWER_CONFIG_H_ */