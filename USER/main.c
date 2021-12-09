#include "main.h"

float temp1;

void Init(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	Gpio_Init();
	Adc_Init();
	TIM4_PWM_Init(3599,0);   //电机初始化
	TIM1_PWM_Init(19999,71);  //涵道初始化
	uart_init(115200);
	
	delay_init();
	EXTIX_Init();
	EXTI->IMR &= ~(EXTI_Line2);
	EXTI->IMR &= ~(EXTI_Line4);
	delay_ms(1000);
}


int main (void)
{
	Init();
	handao(999);
	delay_ms(1500);
	
	while(!((Adc_GetValue(2)>2600)&&(Adc_GetValue(5)>2600)))
{
	delay_ms(100);
}
up_stage();
move('S',0);
turn('L',1800,400);
move('S',0);
	while(1)
	{  
		handao(1300);
		move('S',0);
		handao(1400); 
		if(Stage())//台上
		{ 
			
			printf("台上%d\r\n",0);
		switch(find_enemy())
			{
				case 0:						//无敌人
					move('F',800);
					delay_ms(10);
					break;
				case 1:						//前方有敌人
					move('F',1000);
					delay_ms(10);
					break;
				case 2: 					//右侧有敌人
				move('S',0);	
				turn('R',1200,350);
					break;
				case 3:						//后方有敌人
				move('S',0);	
				turn('R',1800,450);
					break;
				case 4:						//左侧有敌人
				move('S',0);	
				turn('L',1200,350);
					break;
				case 100:					//ERROR
					move('F',800);
					delay_ms(10);
					break;
			}
			}
		else
		{

				EXTI->IMR &= ~(EXTI_Line2);//关闭掉台检测
	      EXTI->IMR &= ~(EXTI_Line4);
				printf("        台下%d\r\n",0);
			up_against();
		}
  }

	
}
	

