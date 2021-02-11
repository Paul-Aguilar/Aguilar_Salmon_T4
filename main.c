
#include <stdio.h>
/**Standard integer definition provided by the compiler*/
#include <stdint.h>
#include "MK64F12.h"
//#define DEBUG_ON
int main(void) {
	/**Activating the GPIOB clock gating*/
	SIM->SCGC5 |= 0x2E00;
	SIM->SCGC5 |= 0x0200;
	/**Pin control configuration of GPIOB pin22 as GPIO*/
	PORTB->PCR[22] = 0x00000100;
	PORTB->PCR[21] = 0x00000100;
	PORTE->PCR[26] = 0x00000100;
	PORTC->PCR[6] = 0x00000103;
	PORTA->PCR[4] = 0x00000103;
	/**Assigns a safe value to the output pin*/
	GPIOC->PDDR &= ~(0x02040);
	GPIOB->PDOR |= 0x00400000;
	GPIOB->PDDR |= 0x00400000;

	GPIOB->PDOR |= 0x00200000;
	GPIOB->PDDR |= 0x00200000;

	GPIOE->PDOR |= 0x04000000;
	GPIOE->PDDR |= 0x04000000;

	uint16_t sw2_value = 0;
	uint16_t sw3_value = 0;
	uint16_t time_delay = 6500;

	while(1) {

		sw2_value = GPIOC->PDIR;
		sw3_value = GPIOA->PDIR;

		uint16_t time_delay = 6500;

		if (0 != sw2_value)
		{
			if(0 != sw3_value)
			{
				uint16_t time_delay = 6500;

				GPIOB->PCOR = 0x00400000;
				delay(time_delay);
				GPIOB->PSOR = 0x00400000;

				GPIOB->PCOR = 0x00200000;
				delay(time_delay);
				GPIOB->PSOR = 0x00200000;

				GPIOE->PCOR = 0x04000000;
				delay(time_delay);
				GPIOE->PSOR = 0x04000000;


			}
			if(0 == sw3_value)
			{
				uint16_t time_delay = 6500*3;

				GPIOB->PCOR = 0x00400000;
				delay(time_delay);
				GPIOB->PSOR = 0x00400000;

				GPIOB->PCOR = 0x00200000;
				delay(time_delay);
				GPIOB->PSOR = 0x00200000;

				GPIOE->PCOR = 0x04000000;
				delay(time_delay);
				GPIOE->PSOR = 0x04000000;
			}

		}
		if (0 == sw2_value)
		{
			if(0 != sw3_value)
			{
				uint16_t time_delay = 6500;
				white_on();
				delay(time_delay);
				white_off();
			}
			if(0 == sw3_value)
			{
				uint16_t time_delay = 6500*3;
				white_on();
				delay(time_delay);
				white_off();
			}
		}




		}
	return 0 ;
}

void white_on(void)
{
	GPIOB->PTOR = 0x00400000;
	GPIOB->PTOR = 0x00200000;
	GPIOE->PTOR = 0x04000000;
}
void white_off(void)
{
	GPIOB->PTOR = 0x00400000;
	GPIOB->PTOR = 0x00200000;
	GPIOE->PTOR = 0x04000000;
}

void delay(uint16_t time_delay)
{
	volatile uint16_t j, i;
	for(j = delay; j > 0; j--)
	{
		__asm("nop");
	}
}




//encendemos LED rojo y despues lo apagamos
//GPIOB->PCOR = 0x00400000;
//GPIOB->PSOR = 0x00400000;


//encendemos LED azul y despues lo apagamos
//GPIOB->PCOR = 0x00200000;
//GPIOB->PSOR = 0x00200000;

//encedemos LED verde y despues lo apagamos
//GPIOE->PCOR = 0x04000000;
//GPIOE->PSOR = 0x04000000;

//white_on();
//white_off();
