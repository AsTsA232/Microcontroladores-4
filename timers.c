#include "stm32f10x.h"


void delay_timer2()
{
	RCC->APB1ENR |= 1 << 0; //enable TIM2 clock 
	TIM2->ARR = 7;
	TIM2->SR |= ~(1 << 0); //clear uif flag
	TIM2->CR1 |= ~(1 << 4);//upcounting
	while (TIM2->SR & (1 << 0))
	TIM2->CR1 = ~(1 << 0); //counter disable 
}

void timer2_ch1_oc(void){
	RCC->APB1ENR|= 1 << 0; //TIM2 clk enabled
TIM2->PSC = 27;               // Valor del prescaler
TIM2->ARR = 64284;             // Valor de comparación (autoreload)
//TIM2->CCR1 = 3273;             // Ciclo de trabajo (duty cycle)
TIM2->CCMR1 |= (1 << 6) | (1 << 5); // Modo PWM 1 en el canal 1
TIM2->CCMR1 &= ~(1 << 4);      // Configuración correcta para PWM
TIM2->CCER |= (1 << 0);        // Habilitar salida del canal 1
TIM2->CR1 |= (1 << 0); 
}
	
	
void timer3_ch1_pwm(){

	RCC->APB1ENR |= (1 << 1);	//TIM3 clk enabled
	
	TIM3->PSC=27;			//prescaler value
	TIM3->ARR=65453;	//Value to compare
	//TIM3->CCR1 = 3273;	//Duty cicle 
	TIM3->CCMR1 |= (1 << 6) | (1 << 5); //pwm mode1 ch1
	TIM3->CCMR1 &= ~(1 << 4);
	TIM3->CCER	|=	(1 << 0);	//ch1 output enable
	TIM3->CR1		|=	(1 << 0); //counter enabled
	
}
//0°->90°->180°
void motoruno1(){
		for (volatile int i = 0;i < 100;i++)
			{
				TIM2->CCR1 = 1800;
				for (int j = 0;j < 75453;j++);
			}

		for (volatile int i = 100;i > 0;i--)
			{
				TIM2->CCR1 = 3857;
				for (int j = 0;j < 75453;j++);
			}
			
			for (volatile int i = 0;i < 100;i++)
			{
				TIM2->CCR1 = 5914;
				for (int j = 0;j < 75453;j++);
			}
}



//180°->90°->0°
void motoruno2(){
		for (volatile int i = 0;i < 100;i++)
			{
				TIM2->CCR1 = 5914;
				for (int j = 0;j < 75453;j++);
			}

		for (volatile int i = 100;i > 0;i--)
			{
				TIM2->CCR1 = 3857;
				for (int j = 0;j < 75453;j++);
			}
			
			for (volatile int i = 0;i < 100;i++)
			{
				TIM2->CCR1 = 1800;
				for (int j = 0;j < 75453;j++);
			}
	}



	
	
//0°->90°->180°
	void motordos1(){
		//SEGUNDO MOTOR TIMER 3
	
		for (volatile int i = 0;i < 100;i++)
			{
				TIM3->CCR1 = 1800;
				for (int j = 0;j < 65453;j++);
			}

		for (volatile int i = 100;i > 0;i--)
			{
				TIM3->CCR1 = 3857;
				for (int j = 0;j < 65453;j++);
			}
			
			for (volatile int i = 0;i < 100;i++)
			{
				TIM3->CCR1 = 5914;
				for (int j = 0;j < 65453;j++);
			}
	}


	
	//180°->90°->0°
	void motordos2(){
	for (volatile int i = 0;i < 100;i++)
			{
				TIM3->CCR1 = 5914;
				for (int j = 0;j < 65453;j++);
			}

		for (volatile int i = 100;i > 0;i--)
			{
				TIM3->CCR1 = 3857;
				for (int j = 0;j < 65453;j++);
			}
			
			for (volatile int i = 0;i < 100;i++)
			{
				TIM3->CCR1 = 1800;
				for (int j = 0;j < 65453;j++);
			}
		
	}
	
	
	void stoptim3(){
		TIM3->CR1		|=	~(1 << 0);
	}
	void stoptim2(){
		TIM2->CR1 |= ~(1 << 0);
	}
	
	
