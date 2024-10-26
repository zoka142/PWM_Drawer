/*
 * GLCD_interface.h
 *
 * Created: 10/22/2024 5:30:25 PM
 *  Author: dell
 */ 


#include "STD _TYPES.h"
#ifndef GLCD_INTERFACE_H_
#define GLCD_INTERFACE_H_

#define GLCD_NO_PAGES		0
#define GLCD_PAGE_0			1
#define GLCD_PAGE_1			2
#define GLCD_BOTH_PAGES		3

void GLCD_voidInit(void);
void GLCD_voidCMD(u8 copy_u8Cmd);
void GLCD_voidData(u8 copy_u8Data);
void GLCD_voidSelectPage(u8 copy_u8Page);
void GLCD_voidSetCursor(u16 copy_u16x,u16 copy_u16y);
void GLCD_voidChar(u8 copy_u8Char);
void GLCD_voidString(u8 *copy_pu8String);
void GlCD_voidSpecialChar(u64 copy_u64Special);
void GlCD_voidGoToLine(u8 copy_u8Line);
void GLCD_voidClearDisplay(void);
void GLCD_voidFloat(f32 copy_f32Float);
void GLCD_voidInteger(u16 copy_u16Integer);


#endif /* GLCD_INTERFACE_H_ */