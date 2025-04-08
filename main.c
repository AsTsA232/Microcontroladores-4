/*GPIO functional description (p.158)
Memory and bus architecture (p.46)

*/

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
	while(1){
		//motoruno1();
		//motordos1();
		//motoruno2();
		//motordos2();
		//	
		
		
	}
}