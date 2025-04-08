/*
EXTI program:
- Enable the clocks for GPIOs and AFIO.
- Configure the Alternate Function to use a GPIO (usually standard after reset).
- Configure the interrupt input pin as input using CRL and CRH registers.
- Select the interrupt input pin using AFIO_EXTICR.
- Configure the RTSR and FTSR registers to choose the interrupt edge.
- Set the EXTI_IMR register to enable the interrupt for the line.
- Enable the EXTI interrupt using the ISER register or NVIC_EnableIRQ function.
- Clear the PR flag in the interrupt routine.
*/
#include <stm32f10x.h>
#include "timers.h"


void EXTI_IRQHandler()
{
	if (EXTI->PR & (1 << 4)) {  
        EXTI->PR |= (1 << 4);   
        motoruno1();
				motoruno2();
    }
    
    // Interrupción por PA2
    if (EXTI->PR & (1 << 2)) {  
        EXTI->PR |= (1 << 2);   
      motordos1();
			motordos2();
    }

	
}
void ext_interrupt(void){
	AFIO->EXTICR[0] = (1 << 0); //Selects PA1 for line 1
	EXTI->FTSR |= (1 << 1);	//interrupt on falling edge
	EXTI->IMR |= (1 << 1);	//enable interrupt
	NVIC->ISER[0] |= 1 << 7;
	
	AFIO->EXTICR[0] |= (1 << 8);   
  EXTI->FTSR |= (1 << 2);        
  EXTI->IMR |= (1 << 2);         

  NVIC->ISER[0] |= (1 << 7);     
  NVIC->ISER[0] |= (1 << 8);
}

