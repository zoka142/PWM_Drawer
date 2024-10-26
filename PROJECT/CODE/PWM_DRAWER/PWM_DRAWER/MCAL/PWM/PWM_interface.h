/*
 * PWM_interface.h
 *
 * Created: 8/12/2024 7:55:52 PM
 *  Author: user
 */ 


#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

#define PWM_ModeType_0_CTC					0
#define PWM_ModeType_0_PhaseCorrect			1
#define PWM_ModeType_0_FastPWM				2

#define PWM_ModeType_1A_PhaseCorrect		0
#define PWM_ModeType_1A_FastPWM				1


#define PWM_CHANNEL_0_NONINVERTING			0
#define PWM_CHANNEL_0_INVERTING             1

#define PWM_CHANNEL_1A_NONINVERTING			0
#define PWM_CHANNEL_1A_INVERTING            1

#define PWM_CHANNEL_Prescaler1			0
#define PWM_CHANNEL_Prescaler8			1
#define PWM_CHANNEL_Prescaler64			2
#define PWM_CHANNEL_Prescaler256		3
#define PWM_CHANNEL_Prescaler1024		4


                     

void PWM_voidInitChannel_0(u8 copy_u8ModeType,u8 copy_u8OutputMode);
void PWM_voidGenerateOnChannel_0(u8 copy_u8Prescaler,u8 copy_u8OutputMode, u8 copy_u8DutyCycle);
void PWM_voidInitChannel_1A(u8 copy_u8ModeType,u8 copy_u8OutputMode);
void PWM_voidGenerateOnChannel_1A(u8 copy_u8Prescaler, u8 copy_u8OutputMode, u32 copy_u32Frequency_hz, f32 copy_f32DutyCycle);
void PWM_voidGenerateOffChannel_1A(void);

#endif /* PWM_INTERFACE_H_ */