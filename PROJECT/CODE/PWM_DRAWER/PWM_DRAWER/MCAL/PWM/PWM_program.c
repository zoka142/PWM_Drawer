/*
 * PWM_program.c
 *
 * Created: 8/12/2024 7:55:34 PM
 *  Author: user
 */ 


/* UTILES_LIB */
#include "STD _TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "PWM_interface.h"
#include "PWM_register.h"
#include "DIO_interface.h"



void PWM_voidInitChannel_0(u8 copy_u8ModeType,u8 copy_u8OutputMode)
{
	DIO_voidSetPinDirection(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT);
	switch(copy_u8ModeType){
		case PWM_ModeType_0_PhaseCorrect:
		SET_BIT(TCCR0_REG, WGM00);
		CLR_BIT(TCCR0_REG, WGM01);
		break;
		
		case PWM_ModeType_0_CTC:
		CLR_BIT(TCCR0_REG, WGM00);
		SET_BIT(TCCR0_REG, WGM01);
		break;
		
		case PWM_ModeType_0_FastPWM:
		SET_BIT(TCCR0_REG, WGM00);
		SET_BIT(TCCR0_REG, WGM01);
		break;
	}
	
	
	switch(copy_u8OutputMode)
	{
		case PWM_CHANNEL_0_NONINVERTING:
		CLR_BIT(TCCR0_REG, COM00);
		SET_BIT(TCCR0_REG, COM01);
		break;
		
		case PWM_CHANNEL_0_INVERTING:
		SET_BIT(TCCR0_REG, COM00);
		SET_BIT(TCCR0_REG, COM01);
		break;
	}
	
}


void PWM_voidGenerateOnChannel_0(u8 copy_u8Prescaler,u8 copy_u8OutputMode, u8 copy_u8DutyCycle)
{
	if(copy_u8DutyCycle<=100)
	{
		switch(copy_u8OutputMode)
		{
			case PWM_CHANNEL_0_NONINVERTING:
			OCR0_REG = (((u16)copy_u8DutyCycle*256)/100)-1;
			break;
			
			case PWM_CHANNEL_0_INVERTING:
			copy_u8DutyCycle = 100 - copy_u8DutyCycle;
			OCR0_REG = (((u16)copy_u8DutyCycle*256)/100)-1;
			break;
		}
		switch(copy_u8Prescaler){
			case PWM_CHANNEL_Prescaler8:
			CLR_BIT(TCCR0_REG, CS00);
			SET_BIT(TCCR0_REG, CS01);
			CLR_BIT(TCCR0_REG, CS02);
			break;
			case PWM_CHANNEL_Prescaler64:
			SET_BIT(TCCR0_REG, CS00);
			SET_BIT(TCCR0_REG, CS01);
			CLR_BIT(TCCR0_REG, CS02);
			break;
			case PWM_CHANNEL_Prescaler256:
			CLR_BIT(TCCR0_REG, CS00);
			CLR_BIT(TCCR0_REG, CS01);
			SET_BIT(TCCR0_REG, CS02);
			break;
			case PWM_CHANNEL_Prescaler1024:
			SET_BIT(TCCR0_REG, CS10);
			CLR_BIT(TCCR0_REG, CS11);
			SET_BIT(TCCR0_REG, CS12);
			break;
		}
	}
}


void PWM_voidInitChannel_1A(u8 copy_u8ModeType,u8 copy_u8OutputMode)
{
	DIO_voidSetPinDirection(DIO_PORTD, DIO_PIN5, DIO_PIN_OUTPUT);
	switch(copy_u8ModeType){
		case PWM_ModeType_1A_PhaseCorrect:
		SET_BIT(TCCR1A_REG, WGM10);
		SET_BIT(TCCR1A_REG, WGM11);
		CLR_BIT(TCCR1B_REG, WGM12);
		SET_BIT(TCCR1B_REG, WGM13);
		break;
		
		case PWM_ModeType_1A_FastPWM:
		SET_BIT(TCCR1A_REG, WGM10);
		SET_BIT(TCCR1A_REG, WGM11);
		SET_BIT(TCCR1B_REG, WGM12);
		SET_BIT(TCCR1B_REG, WGM13);
		break;
	}
	
	switch(copy_u8OutputMode)
	{
		case PWM_CHANNEL_1A_NONINVERTING:
		CLR_BIT(TCCR1A_REG, COM1A0);
		SET_BIT(TCCR1A_REG, COM1A1);
		break;
		
		case PWM_CHANNEL_1A_INVERTING:
		SET_BIT(TCCR1A_REG, COM1A0);
		SET_BIT(TCCR1A_REG, COM1A1);
		break;
	}	
}


void PWM_voidGenerateOnChannel_1A(u8 copy_u8Prescaler, u8 copy_u8OutputMode, u32 copy_u32Frequency_hz, f32 copy_f32DutyCycle)
{
	if(copy_f32DutyCycle<=100)
	{
		f32 local_f32prescaler =0 ;
		switch(copy_u8Prescaler){
			case PWM_CHANNEL_Prescaler8:
			local_f32prescaler=0.5;
			break;
			case PWM_CHANNEL_Prescaler64:
			local_f32prescaler=4;
			break;
			case PWM_CHANNEL_Prescaler256:
			local_f32prescaler=16;
			break;
			case PWM_CHANNEL_Prescaler1024:
			local_f32prescaler=64;
			break;
		}
		switch(copy_u8OutputMode)
		{
			case PWM_CHANNEL_1A_NONINVERTING:
			ICR1_u16_REG = ((1000000UL/copy_u32Frequency_hz)/local_f32prescaler)-1;
			OCR1A_u16_REG = ((copy_f32DutyCycle*255)/100.0)-1;
			break;
			case PWM_CHANNEL_1A_INVERTING:
			ICR1_u16_REG = ((1000000UL/copy_u32Frequency_hz)/local_f32prescaler)-1;
			copy_f32DutyCycle = 100 - copy_f32DutyCycle;
			OCR1A_u16_REG = ((copy_f32DutyCycle*255)/100.0)-1;
			break;
		}
		
		switch(copy_u8Prescaler){
			case PWM_CHANNEL_Prescaler8:
			CLR_BIT(TCCR1B_REG, CS10);
			SET_BIT(TCCR1B_REG, CS11);
			CLR_BIT(TCCR1B_REG, CS12);
			break;
			case PWM_CHANNEL_Prescaler64:
			SET_BIT(TCCR1B_REG, CS10);
			SET_BIT(TCCR1B_REG, CS11);
			CLR_BIT(TCCR1B_REG, CS12);
			break;
			case PWM_CHANNEL_Prescaler256:
			CLR_BIT(TCCR1B_REG, CS10);
			CLR_BIT(TCCR1B_REG, CS11);
			SET_BIT(TCCR1B_REG, CS12);
			break;
			case PWM_CHANNEL_Prescaler1024:
			SET_BIT(TCCR1B_REG, CS10);
			CLR_BIT(TCCR1B_REG, CS11);
			SET_BIT(TCCR1B_REG, CS12);
			break;
	}
	}
	}
void PWM_voidGenerateOffChannel_1A(){
	CLR_BIT(TCCR1B_REG, CS10);
	CLR_BIT(TCCR1B_REG, CS11);
	CLR_BIT(TCCR1B_REG, CS12);
}