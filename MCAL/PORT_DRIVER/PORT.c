/*
 * PORT.c
 *
 *  Created on: Jun 15, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"
#include "PORT_hw.h"
#include "PORT_lcfg.h"
#include "PORT.h"

void PORT_init(void)
{
	uint8 i;
	PORT_PortType PortId;
	Port_ChannelType ChannelPos;
	PORT_PinDirType PinDir;
	/****************** INIT DIRECTION ***********************/
	for(i=0;i<PORT_ACTIVATED_PINS_NUMBER;i++)
	{
		PortId = (PORT_PinGroup[i].id) / 8;
		ChannelPos = (PORT_PinGroup[i].id) % 8;
		PinDir = PORT_PinGroup[i].PinDir;

		switch(PortId)
		{
		case PORT_Port_A:
			if(PinDir == Dir_Output)
			{
				SET_BIT(DDRA_REG,ChannelPos);
			}
			else
			{
				CLR_BIT(DDRA_REG,ChannelPos);
			}
			break;
		case PORT_Port_B:
			if(PinDir == Dir_Output)
			{
				SET_BIT(DDRB_REG,ChannelPos);
			}
			else
			{
				CLR_BIT(DDRB_REG,ChannelPos);
			}
			break;
		case PORT_Port_C:
			if(PinDir == Dir_Output)
			{
				SET_BIT(DDRC_REG,ChannelPos);
			}
			else
			{
				CLR_BIT(DDRC_REG,ChannelPos);
			}
			break;
		case PORT_Port_D:
			if(PinDir == Dir_Output)
			{
				SET_BIT(DDRD_REG,ChannelPos);
			}
			else
			{
				CLR_BIT(DDRD_REG,ChannelPos);
			}
			break;
		default:
			/*error*/
			break;
		}
	}
}