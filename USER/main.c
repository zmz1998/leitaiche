#include "main.h"

float temp1;

void Init(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	Gpio_Init();
	Adc_Init();
	TIM4_PWM_Init(3599,0);   //�����ʼ��
	TIM1_PWM_Init(19999,71);  //������ʼ��
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
		if(Stage())//̨��
		{ 
			
			printf("̨��%d\r\n",0);
		switch(find_enemy())
			{
				case 0:						//�޵���
					move('F',800);
					delay_ms(10);
					break;
				case 1:						//ǰ���е���
					move('F',1000);
					delay_ms(10);
					break;
				case 2: 					//�Ҳ��е���
				move('S',0);	
				turn('R',1200,350);
					break;
				case 3:						//���е���
				move('S',0);	
				turn('R',1800,450);
					break;
				case 4:						//����е���
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

				EXTI->IMR &= ~(EXTI_Line2);//�رյ�̨���
	      EXTI->IMR &= ~(EXTI_Line4);
				printf("        ̨��%d\r\n",0);
			up_against();
		}
  }

	
}
	

