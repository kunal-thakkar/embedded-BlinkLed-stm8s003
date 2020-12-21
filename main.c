/* MAIN.C file
 * 
 * Copyright (c) 2002-2005 STMicroelectronics
 */

#include "stm8s.h"
#include "stm8s_delay.h"

	
void GPIO_setup(void) { 
	/* The following lines deinitialize the GPIOs we used. 
	Every time you reconfigure or setup a hardware peripheral 
	for the first time you must deinitialize it before using it
	*/
	GPIO_DeInit(GPIOA); 
	/*
	After deinitialization, we are good to go for initializing
	or setting up the GPIOs.
	*/
	GPIO_Init(GPIOA, GPIO_PIN_1, GPIO_MODE_IN_PU_NO_IT); 
	GPIO_Init(GPIOA, GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_FAST);
}

main() {
	bool i = FALSE; 
	GPIO_setup(); 
	for(;;) { 
		if(GPIO_ReadInputPin(GPIOA, GPIO_PIN_1) == FALSE) {
			while(GPIO_ReadInputPin(GPIOA, GPIO_PIN_1) == FALSE); 
			i ^= 1; 
		} 
		switch(i) { 
			case TRUE: { 
				delay_ms(1000); 
				break; 
			} 
			case FALSE: { 
				delay_ms(100); 
				break; 
			} 
		}
		GPIO_WriteReverse(GPIOA, GPIO_PIN_3); 
	}

}