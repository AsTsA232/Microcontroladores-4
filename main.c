//user defined libs
#include "gpio.h"
#include "leds.h"
#include "timers.h"
#include "interrupts.h"

int main(void){
	init_gpio();
	//led_on_off(20);
	//led_onoff_timer2(1000);
	
	
	/*Using timers
	***************/
	timer2_ch1_oc();
	timer3_ch1_pwm();
		
	ext_interrupt();
	ext_interrupt2();
	while(1){
	
		
	}
}
