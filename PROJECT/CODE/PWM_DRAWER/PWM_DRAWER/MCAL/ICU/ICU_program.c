/*
 * ICU_program.c
 *
 * Created: 10/24/2024 1:16:41 PM
 *  Author: dell
 */ 
#include "BIT_MATH.h"
#include "STD _TYPES.h"
#include "DIO_interface.h"
#define  F_CPU 16000000

#include "ICU_register.h"
#include "ICU_interface.h"

void ICU_voidinit(u8 copy_u8Prescaler){
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN6,DIO_PIN_INPUT);
	TCCR1A_REG=0;
	SET_BIT(TIFR_REG,ICF1);
	SET_BIT(TCCR1B_REG,CS10);
	switch(copy_u8Prescaler){
		case ICU_Prescaler8:
		CLR_BIT(TCCR1B_REG, CS10);
		SET_BIT(TCCR1B_REG, CS11);
		CLR_BIT(TCCR1B_REG, CS12);
		break;
		case ICU_Prescaler64:
		SET_BIT(TCCR1B_REG, CS10);
		SET_BIT(TCCR1B_REG, CS11);
		CLR_BIT(TCCR1B_REG, CS12);
		break;
		case ICU_Prescaler256:
		CLR_BIT(TCCR1B_REG, CS10);
		CLR_BIT(TCCR1B_REG, CS11);
		SET_BIT(TCCR1B_REG, CS12);
		break;
		case ICU_Prescaler1024:
		CLR_BIT(TCCR1B_REG, CS10);
		SET_BIT(TCCR1B_REG, CS11);
		SET_BIT(TCCR1B_REG, CS12);
		break;
	}
}
void ICU_voidSetEdge(u8 copy_u8Edge){
	switch(copy_u8Edge){
		case ICU_RisingEdge:
		SET_BIT(TCCR1B_REG,ICES1);
		break;
		case ICU_FallingEdge:
		CLR_BIT(TCCR1B_REG,ICES1);
		break;
	}
}
void ICU_voidClearTimerReg(void){
	TCNT1_u16_REG =0x0000;
}
u16 ICU_u16GetValue(u16 *copy_pu16value){
	*copy_pu16value=ICR1_u16_REG;
	return *copy_pu16value;
}
ICU_StatusType ICU_GetStatus(void){
	if (GET_BIT(TIFR_REG,ICF1)==0){
		return ICU_Running;
	}
	else return ICU_EVENT_CAPTURED;
	
}
void ICU_voidGetDuty(u8 copy_u8PrescalerValue,ICU_SignalData *copy_pstructDataptr){
	u16 a =0,b=0,c=0, t=0,h=0;//change
	ICU_voidSetEdge(ICU_RisingEdge);
	while (ICU_GetStatus() == ICU_Running);
	ICU_u16GetValue(&a);  		
	SET_BIT(TIFR_REG,ICF1);  	
	
	ICU_voidSetEdge(ICU_FallingEdge);  	
	while (ICU_GetStatus() == ICU_Running);
	ICU_u16GetValue(&b);  		
	SET_BIT(TIFR_REG,ICF1);    
	
	ICU_voidSetEdge(ICU_RisingEdge);;  
	while (ICU_GetStatus() == ICU_Running);
	ICU_u16GetValue(&c);  		
	SET_BIT(TIFR_REG,ICF1);    	
 	
	 f32 local_f32prescaler = 0;
	 switch(copy_u8PrescalerValue){
		 case ICU_Prescaler8:
		 local_f32prescaler=0.5;
		 break;
		 case ICU_Prescaler64:
		 local_f32prescaler=4;
		 break;
		 case ICU_Prescaler256:
		 local_f32prescaler=16;
		 break;
		 case ICU_Prescaler1024:
		 local_f32prescaler=64;
		 break;
	 }
	h=b-a;
	t=c-a;
	copy_pstructDataptr->High_Time_ms=(f32)h * local_f32prescaler  * 1000.0 / F_CPU;
	copy_pstructDataptr->Period_Time_ms=(f32)t  * local_f32prescaler * 1000.0 / F_CPU;
	 		
}


