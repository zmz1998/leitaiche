#include "huidu.h"
float huidu()
{
	double adcx;
	float temp;
	TIM3_PWM_Init(899,0);
	Gpio_Init();
	Adc_Init();	
	uart_init(9600);

//	adcx=Get_Adc_Average(ADC_Channel_1,10);
	temp=(float)adcx*(3.3/4096);
	temp=100*temp;
	printf("\r\n%0.3lf\r\n",temp);
	return temp;
	
}
