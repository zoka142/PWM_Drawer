/*
 * GLCD_program.c
 *
 * Created: 10/22/2024 5:30:00 PM
 *  Author: dell
 */ 

#include "BIT_MATH.h"
#include "STD _TYPES.h"
#define  F_CPU 16000000
#include <util/delay.h>

#include "DIO_interface.h"
#include "DIO_register.h"

#include "GLCD_interface.h"
#include "GLCD_config.h"
#include "GLCD_Char_Patterns.h"

u8 GLCD_u8CurrentY_address = 0;
u8 GLCD_u8CurrentX_address = 0;
u8 GLCD_u8CurrentPage	   = 0;
void GLCD_voidInit(void){
	DIO_voidSetPinDirection(GLCD_RS_PORT,GLCD_RS_PIN,DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(GLCD_RW_PORT,GLCD_RW_PIN,DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(GLCD_E_PORT,GLCD_E_PIN,DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(GLCD_RST_PORT,GLCD_RST_PIN,DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(GLCD_CS1_PORT,GLCD_CS1_PIN,DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(GLCD_CS2_PORT,GLCD_CS2_PIN,DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(GLCD_D0_PORT,GLCD_D0_PIN,DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(GLCD_D1_PORT,GLCD_D1_PIN,DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(GLCD_D2_PORT,GLCD_D2_PIN,DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(GLCD_D3_PORT,GLCD_D3_PIN,DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(GLCD_D4_PORT,GLCD_D4_PIN,DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(GLCD_D5_PORT,GLCD_D5_PIN,DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(GLCD_D6_PORT,GLCD_D6_PIN,DIO_PORT_OUTPUT);
	DIO_voidSetPinDirection(GLCD_D7_PORT,GLCD_D7_PIN,DIO_PORT_OUTPUT);
	
	DIO_voidSetPinValue(GLCD_RST_PORT,GLCD_RST_PIN,DIO_PIN_LOW);
	_delay_ms(10);
	DIO_voidSetPinValue(GLCD_RST_PORT,GLCD_RST_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	GLCD_voidSelectPage(GLCD_BOTH_PAGES);
	_delay_ms(1);
	GLCD_voidCMD(0b00111111);
	GLCD_voidCMD(0b11000000);
	_delay_ms(1);
	GLCD_voidSelectPage(GLCD_PAGE_0);
	_delay_ms(1);
}
void GLCD_voidCMD(u8 copy_u8Cmd){
	DIO_voidSetPinValue(GLCD_RS_PORT,GLCD_RS_PIN,DIO_PIN_LOW);
	DIO_voidSetPinValue(GLCD_RW_PORT,GLCD_RW_PIN,DIO_PIN_LOW);
	DIO_voidSetPinValue(GLCD_D0_PORT,GLCD_D0_PIN, GET_BIT(copy_u8Cmd,0));
	DIO_voidSetPinValue(GLCD_D1_PORT,GLCD_D1_PIN, GET_BIT(copy_u8Cmd,1));
	DIO_voidSetPinValue(GLCD_D2_PORT,GLCD_D2_PIN, GET_BIT(copy_u8Cmd,2));
	DIO_voidSetPinValue(GLCD_D3_PORT,GLCD_D3_PIN, GET_BIT(copy_u8Cmd,3));
	DIO_voidSetPinValue(GLCD_D4_PORT,GLCD_D4_PIN, GET_BIT(copy_u8Cmd,4));
	DIO_voidSetPinValue(GLCD_D5_PORT,GLCD_D5_PIN, GET_BIT(copy_u8Cmd,5));
	DIO_voidSetPinValue(GLCD_D6_PORT,GLCD_D6_PIN, GET_BIT(copy_u8Cmd,6));
	DIO_voidSetPinValue(GLCD_D7_PORT,GLCD_D7_PIN, GET_BIT(copy_u8Cmd,7));
	DIO_voidSetPinValue(GLCD_E_PORT,GLCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(GLCD_E_PORT,GLCD_E_PIN,DIO_PIN_LOW);
}
void GLCD_voidData(u8 copy_u8Data){
	
	DIO_voidSetPinValue(GLCD_RS_PORT,GLCD_RS_PIN,DIO_PIN_HIGH);
	DIO_voidSetPinValue(GLCD_RW_PORT,GLCD_RW_PIN,DIO_PIN_LOW);
	DIO_voidSetPinValue(GLCD_D0_PORT,GLCD_D0_PIN, GET_BIT(copy_u8Data,0));
	DIO_voidSetPinValue(GLCD_D1_PORT,GLCD_D1_PIN, GET_BIT(copy_u8Data,1));
	DIO_voidSetPinValue(GLCD_D2_PORT,GLCD_D2_PIN, GET_BIT(copy_u8Data,2));
	DIO_voidSetPinValue(GLCD_D3_PORT,GLCD_D3_PIN, GET_BIT(copy_u8Data,3));
	DIO_voidSetPinValue(GLCD_D4_PORT,GLCD_D4_PIN, GET_BIT(copy_u8Data,4));
	DIO_voidSetPinValue(GLCD_D5_PORT,GLCD_D5_PIN, GET_BIT(copy_u8Data,5));
	DIO_voidSetPinValue(GLCD_D6_PORT,GLCD_D6_PIN, GET_BIT(copy_u8Data,6));
	DIO_voidSetPinValue(GLCD_D7_PORT,GLCD_D7_PIN, GET_BIT(copy_u8Data,7));
	DIO_voidSetPinValue(GLCD_E_PORT,GLCD_E_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(GLCD_E_PORT,GLCD_E_PIN,DIO_PIN_LOW);
}
void GLCD_voidSelectPage(u8 copy_u8Page){
	switch (copy_u8Page){
		case GLCD_NO_PAGES:
			DIO_voidSetPinValue(GLCD_CS1_PORT,GLCD_CS1_PIN,DIO_PIN_LOW);
			DIO_voidSetPinValue(GLCD_CS2_PORT,GLCD_CS2_PIN,DIO_PIN_LOW);
			break;
			case GLCD_PAGE_0:
			DIO_voidSetPinValue(GLCD_CS1_PORT,GLCD_CS1_PIN,DIO_PIN_HIGH);
			DIO_voidSetPinValue(GLCD_CS2_PORT,GLCD_CS2_PIN,DIO_PIN_LOW);
			GLCD_u8CurrentPage = 0;
			break;
			case GLCD_PAGE_1:
			DIO_voidSetPinValue(GLCD_CS1_PORT,GLCD_CS1_PIN,DIO_PIN_LOW);
			DIO_voidSetPinValue(GLCD_CS2_PORT,GLCD_CS2_PIN,DIO_PIN_HIGH);
			GLCD_u8CurrentPage = 1;
			break;
			case GLCD_BOTH_PAGES:
			DIO_voidSetPinValue(GLCD_CS1_PORT,GLCD_CS1_PIN,DIO_PIN_HIGH);
			DIO_voidSetPinValue(GLCD_CS2_PORT,GLCD_CS2_PIN,DIO_PIN_HIGH);
			break;
	}
}
void GLCD_voidSetCursor(u16 copy_u16x,u16 copy_u16y){
	GLCD_u8CurrentX_address =+copy_u16x;
	GLCD_u8CurrentY_address =+copy_u16y;
	GLCD_voidCMD(0xB8+GLCD_u8CurrentX_address);
	GLCD_voidCMD(0x40+GLCD_u8CurrentY_address);
}
void GLCD_voidChar(u8 copy_u8Char){
	
		switch (copy_u8Char) {
			case 'A': case 'a': GlCD_voidSpecialChar(GLCD_CHAR_A); break;
			case 'F': case 'f': GlCD_voidSpecialChar(GLCD_CHAR_F); break;
			case 'R': case 'r': GlCD_voidSpecialChar(GLCD_CHAR_R); break;
			case 'E': case 'e': GlCD_voidSpecialChar(GLCD_CHAR_E); break;
			case 'Q': case 'q': GlCD_voidSpecialChar(GLCD_CHAR_Q); break;
			case 'U': case 'u': GlCD_voidSpecialChar(GLCD_CHAR_U); break;
			case 'N': case 'n': GlCD_voidSpecialChar(GLCD_CHAR_N); break;
			case 'C': case 'c': GlCD_voidSpecialChar(GLCD_CHAR_C); break;
			case 'Y': case 'y': GlCD_voidSpecialChar(GLCD_CHAR_Y); break;
			case 'D': case 'd': GlCD_voidSpecialChar(GLCD_CHAR_D); break;
			case 'T': case 't': GlCD_voidSpecialChar(GLCD_CHAR_T); break;
			case 'K': case 'k': GlCD_voidSpecialChar(GLCD_CHAR_K); break;
			case 'H': case 'h': GlCD_voidSpecialChar(GLCD_CHAR_H); break;
			case 'Z': case 'z': GlCD_voidSpecialChar(GLCD_CHAR_Z); break;
			case 'M': case 'm': GlCD_voidSpecialChar(GLCD_CHAR_M); break;
			case 'S': case 's': GlCD_voidSpecialChar(GLCD_CHAR_S); break;
			case 'I': case 'i': GlCD_voidSpecialChar(GLCD_CHAR_I); break;
			case '%': GlCD_voidSpecialChar(GLCD_CHAR_PERCENT); break;
			case '=': GlCD_voidSpecialChar(GLCD_CHAR_EQUAL); break;
			case '.': GlCD_voidSpecialChar(GLCD_CHAR_POINT); break;
			case ' ': GlCD_voidSpecialChar(GLCD_CHAR_SPACE); break;
			case '-': GlCD_voidSpecialChar(GLCD_CHAR_NEGATIVE); break;
			case '0': GlCD_voidSpecialChar(GLCD_CHAR_0); break;
			case '1': GlCD_voidSpecialChar(GLCD_CHAR_1); break;
			case '2': GlCD_voidSpecialChar(GLCD_CHAR_2); break;
			case '3': GlCD_voidSpecialChar(GLCD_CHAR_3); break;
			case '4': GlCD_voidSpecialChar(GLCD_CHAR_4); break;
			case '5': GlCD_voidSpecialChar(GLCD_CHAR_5); break;
			case '6': GlCD_voidSpecialChar(GLCD_CHAR_6); break;
			case '7': GlCD_voidSpecialChar(GLCD_CHAR_7); break;
			case '8': GlCD_voidSpecialChar(GLCD_CHAR_8); break;
			case '9': GlCD_voidSpecialChar(GLCD_CHAR_9); break;
			default: break;
		}
		GLCD_voidSetCursor(GLCD_u8CurrentX_address,GLCD_u8CurrentY_address);
		GLCD_voidData(0);
		GLCD_u8CurrentY_address++;
		if (GLCD_u8CurrentY_address >= 60 && GLCD_u8CurrentPage == 0) {
			GLCD_voidSelectPage(GLCD_PAGE_1);
			GLCD_u8CurrentY_address = 0;
	}
		if(GLCD_u8CurrentY_address>=60 && GLCD_u8CurrentPage == 1){
			GLCD_voidSelectPage(GLCD_PAGE_0);
			GLCD_u8CurrentX_address++;
			GlCD_voidGoToLine(GLCD_u8CurrentX_address);
		}
}


void GLCD_voidString(u8 *copy_pu8String){
	
	if(copy_pu8String!=NULL)
	{
		u8 local_u8counter=0;
		while(copy_pu8String[local_u8counter]!='\0')
		{
			GLCD_voidChar(copy_pu8String[local_u8counter]);
			local_u8counter++;
		}
	}
	else
	{
		// return Error state
	}
	}
void GlCD_voidSpecialChar(u64 copy_u64Special){
	for(int i=0 ; i < 5 ; i++){
		GLCD_voidSetCursor(GLCD_u8CurrentX_address,GLCD_u8CurrentY_address);
		GLCD_voidData((copy_u64Special>>(i*8U)) & 0xFF);
		GLCD_u8CurrentY_address++;
		if(GLCD_u8CurrentY_address>=60 && GLCD_u8CurrentPage == 0){
			GLCD_voidSelectPage(GLCD_PAGE_1);
			GLCD_u8CurrentY_address=0;
		}
		if(GLCD_u8CurrentY_address>=60 && GLCD_u8CurrentPage == 1){
			GLCD_voidSelectPage(GLCD_PAGE_0);
			GLCD_u8CurrentX_address++;
			GlCD_voidGoToLine(GLCD_u8CurrentX_address);
		}
	}
	
}
void GlCD_voidGoToLine(u8 copy_u8Line){
	if (copy_u8Line < 8){
		GLCD_voidSelectPage(GLCD_PAGE_0);
		GLCD_voidSetCursor(copy_u8Line,0);
		GLCD_u8CurrentY_address = 0;
	}
	
}
void GLCD_voidClearDisplay(void){
	GLCD_voidSelectPage(GLCD_BOTH_PAGES);
	for(u8 i=0;i<8;i++){
		for(u8 j=0;j<60;j++){
			GLCD_voidSetCursor(i,j);
			GLCD_voidData(0);
		}
	}
	GLCD_voidSelectPage(GLCD_PAGE_0);
	GLCD_voidSetCursor(0,0);
}
void GLCD_voidFloat(f32 copy_f32Float){
	u8 local_u8integer = (u8)copy_f32Float;
	GLCD_voidInteger(local_u8integer);
	GLCD_voidChar('.');
	f32 Local_f32decimal = copy_f32Float - (f32)local_u8integer;
	for(u8 i = 0;i < 3;i++){
	// Extract the first two decimal digits and display them
	Local_f32decimal *= 10.0;
	u8 local_u8first_digit = (u8)Local_f32decimal;      // First decimal digit
	GLCD_voidInteger(local_u8first_digit);
	Local_f32decimal = Local_f32decimal - local_u8first_digit;}
}
void GLCD_voidInteger(u16 copy_u16Integer){
	if (copy_u16Integer < 0) {
		GLCD_voidChar('-');
		copy_u16Integer = -1 * copy_u16Integer;
	}
	char str_reversed[5];
	char* str_ptr = str_reversed;

	// Extract digits and store them in reverse order
	do {
		*str_ptr++ = (copy_u16Integer % 10) + '0'; // Convert digit to ASCII
		copy_u16Integer /= 10;
	} while (copy_u16Integer > 0);

	// Display characters in reverse
	while (str_ptr != str_reversed) {
		GLCD_voidChar(*--str_ptr);
	}

}
