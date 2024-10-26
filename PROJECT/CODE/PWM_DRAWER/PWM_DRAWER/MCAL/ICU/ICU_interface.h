/*
 * ICU_interface.h
 *
 * Created: 10/24/2024 1:17:29 PM
 *  Author: dell
 */ 
#include "STD _TYPES.h"

#ifndef ICU_INTERFACE_H_
#define ICU_INTERFACE_H_

#define ICU_RisingEdge					0
#define ICU_FallingEdge					1

#define ICU_Prescaler1					0
#define ICU_Prescaler8					1
#define ICU_Prescaler64					2
#define ICU_Prescaler256				3
#define ICU_Prescaler1024				4

#define ICU_RESOLUTION					65536

typedef struct {
	f32 High_Time_ms;
	f32 Period_Time_ms;
}ICU_SignalData;

typedef enum {
	ICU_Running,
	ICU_EVENT_CAPTURED
}ICU_StatusType;



void ICU_voidinit(u8 copy_u8Prescaler);
void ICU_voidSetEdge(u8 copy_u8Edge);
void ICU_voidClearTimerReg(void);
u16 ICU_u16GetValue(u16 *copy_pu16value);
ICU_StatusType ICU_GetStatus(void);
void ICU_voidGetDuty(u8 copy_u8PrescalerValue,ICU_SignalData *copy_pstructDataptr);



#endif /* ICU_INTERFACE_H_ */