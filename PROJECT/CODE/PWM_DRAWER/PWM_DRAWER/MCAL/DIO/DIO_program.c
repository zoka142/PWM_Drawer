/*
 * DIO_program.c
 *
 * Created: 15/07/2024 10:40:55 PM
 *  Author: user
 */ 
#include "STD _TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_register.h"

void DIO_voidSetPinDirection(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
		switch(copy_u8PinDirection)
		{
			case DIO_PIN_INPUT:
			CLR_BIT(DDRA_REG, copy_u8PinId);
			break;
			
			case DIO_PIN_OUTPUT:
			SET_BIT(DDRA_REG, copy_u8PinId);
			break;
		}
		break;
		
		case DIO_PORTB:
		switch(copy_u8PinDirection)
		{
			case DIO_PIN_INPUT:
			CLR_BIT(DDRB_REG, copy_u8PinId);
			break;
			
			case DIO_PIN_OUTPUT:
			SET_BIT(DDRB_REG, copy_u8PinId);
			break;
		}
		break;
		
		case DIO_PORTC:
		switch(copy_u8PinDirection)
		{
			case DIO_PIN_INPUT:
			CLR_BIT(DDRC_REG, copy_u8PinId);
			break;
			
			case DIO_PIN_OUTPUT:
			SET_BIT(DDRC_REG, copy_u8PinId);
			break;
		}
		break;
		
		case DIO_PORTD:
		switch(copy_u8PinDirection)
		{
			case DIO_PIN_INPUT:
			CLR_BIT(DDRD_REG, copy_u8PinId);
			break;
			
			case DIO_PIN_OUTPUT:
			SET_BIT(DDRD_REG, copy_u8PinId);
			break;
		}
		break;
	}
}


void DIO_voidSetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
		switch(copy_u8PinValue)
		{
			case DIO_PIN_LOW:
			CLR_BIT(PORTA_REG, copy_u8PinId);
			break;
			
			case DIO_PIN_HIGH:
			SET_BIT(PORTA_REG, copy_u8PinId);
			break;
		}
		break;
		
		case DIO_PORTB:
		switch(copy_u8PinValue)
		{
			case DIO_PIN_LOW:
			CLR_BIT(PORTB_REG, copy_u8PinId);
			break;
			
			case DIO_PIN_HIGH:
			SET_BIT(PORTB_REG, copy_u8PinId);
			break;
		}
		break;
		
		case DIO_PORTC:
		switch(copy_u8PinValue)
		{
			case DIO_PIN_LOW:
			CLR_BIT(PORTC_REG, copy_u8PinId);
			break;
			
			case DIO_PIN_HIGH:
			SET_BIT(PORTC_REG, copy_u8PinId);
			break;
		}
		break;
		
		case DIO_PORTD:
		switch(copy_u8PinValue)
		{
			case DIO_PIN_LOW:
			CLR_BIT(PORTD_REG, copy_u8PinId);
			break;
			
			case DIO_PIN_HIGH:
			SET_BIT(PORTD_REG, copy_u8PinId);
			break;
		}
		break;
	}
}


void DIO_voidGetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8* copy_pu8PinValue)
{
	if(copy_pu8PinValue!= NULL)
	{
		switch(copy_u8PortId)
		{
			case DIO_PORTA:
			*copy_pu8PinValue = GET_BIT(PINA_REG, copy_u8PinId);
			break;
			
			case DIO_PORTB:
			*copy_pu8PinValue = GET_BIT(PINB_REG, copy_u8PinId);
			break;
			
			case DIO_PORTC:
			*copy_pu8PinValue = GET_BIT(PINC_REG, copy_u8PinId);
			break;
			
			case DIO_PORTD:
			*copy_pu8PinValue = GET_BIT(PIND_REG, copy_u8PinId);
			break;
		}
	}
	else
	{
		// Do Nothing
	}
}


void DIO_voidTogglePinValue(u8 copy_u8PortId, u8 copy_u8PinId)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
		TOG_BIT(PORTA_REG, copy_u8PinId);
		break;
		
		case DIO_PORTB:
		TOG_BIT(PORTB_REG, copy_u8PinId);
		break;
		
		case DIO_PORTC:
		TOG_BIT(PORTC_REG, copy_u8PinId);
		break;
		
		case DIO_PORTD:
		TOG_BIT(PORTD_REG, copy_u8PinId);
		break;
	}
}


void DIO_voidActivePinInPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
		SET_BIT(PORTA_REG, copy_u8PinId);
		break;
		
		case DIO_PORTB:
		SET_BIT(PORTB_REG, copy_u8PinId);
		break;
		
		case DIO_PORTC:
		SET_BIT(PORTC_REG, copy_u8PinId);
		break;
		
		case DIO_PORTD:
		SET_BIT(PORTD_REG, copy_u8PinId);
		break;
	}
}

//Port APi
void DIO_voidSetPortDirection(u8 copy_u8PortId,u8 copy_u8PortDirection)
{
	switch(copy_u8PortId)
	{
		case DIO_PORTA:
		switch(copy_u8PortDirection)
		{
			case DIO_PORT_INPUT:
			CLR_BIT(DDRA_REG, copy_u8PortId);
			break;
			
			case DIO_PORT_OUTPUT:
			SET_BIT(DDRA_REG, copy_u8PortId);
			break;
		}
		break;
		
		case DIO_PORTB:
		switch(copy_u8PortDirection)
		{
			case DIO_PORT_INPUT:
			CLR_BIT(DDRB_REG, copy_u8PortId);
			break;
			
			case DIO_PORT_OUTPUT:
			SET_BIT(DDRB_REG, copy_u8PortId);
			break;
		}
		break;
		
		case DIO_PORTC:
		switch(copy_u8PortDirection)
		{
			case DIO_PORT_INPUT:
			CLR_BIT(DDRC_REG, copy_u8PortId);
			break;
			
			case DIO_PORT_OUTPUT:
			SET_BIT(DDRC_REG, copy_u8PortId);
			break;
			
			case DIO_PORTD:
			switch(copy_u8PortDirection)
			{
				case DIO_PORT_INPUT:
				CLR_BIT(DDRD_REG, copy_u8PortId);
				break;
				
				case DIO_PORT_OUTPUT:
				SET_BIT(DDRD_REG, copy_u8PortId);
				break;
			}
			break;
		}
		break;
	}
}
void DIO_voidSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue){
	
}

void DIO_voidGetPortValue(u8 copy_u8PortId, u8* copy_pu8PortValue)
{
	
}
void DIO_voidTogglePortValue             (u8 copy_u8PortId)
{
	
}
void DIO_voidActivePortInPullUpResistance(u8 copy_u8PortId)
{
	
}