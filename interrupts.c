#include <stm32f10x.h>
#include "timers.h"
#include "leds.h"


void EXTI1_IRQHandler()
{ 			
        EXTI->PR |= (1 << 4);   
        motoruno1();
				motoruno2();
				stoptim2();
}
void EXTI2_IRQHandler(){
			
    // Interrupción por PA2 
			EXTI->PR |= (1 << 2);   
      motordos1();
			motordos2();	
			stoptim3();
}

void ext_interrupt(void){
	AFIO->EXTICR[0] = (1 << 0); //Selects PA1 for line 1
	EXTI->FTSR |= (1 << 1);	//interrupt on falling edge
	EXTI->IMR |= (1 << 1);	//enable interrupt
	NVIC->ISER[0] |= 1 << 7;
}

void ext_interrupt2(void){
	AFIO->EXTICR[0] |= (1 << 8);   
  EXTI->FTSR |= (1 << 2);        
  EXTI->IMR |= (1 << 2);         
  NVIC->ISER[0] |= (1 << 7);     
  NVIC->ISER[0] |= (1 << 8);
}

