#include "Moto_Mode.h"

/*************************************************
  ��������: move
  ��������: ���ת��ģʽ����
  �����������õĺ���: ��        
  ���ñ������ĺ���:     
  �������˵��: mode ��ģʽ  speed : �ٶ�  
  �������˵��: ��       
  ��������ֵ: ��
  ����˵��:		PB6  PB7	|	PB8		PB9
								1		0		|		1			0		PWM		��ת
								0		1		|		0			1		PWM		��ת
								0		0		|		0			0		PWM		ɲ��
*************************************************/
void move(char mode,u16 speed)
{
	switch(mode)
	{
		case 'F':					//ǰ��
		{
			GPIO_SetBits(GPIOC,GPIO_Pin_6);	  
			GPIO_ResetBits(GPIOC,GPIO_Pin_7); 
		
			GPIO_SetBits(GPIOC,GPIO_Pin_8);	  
			GPIO_ResetBits(GPIOC,GPIO_Pin_9);
			
			PWM_L = speed;
			PWM_R = speed;
			
			break ;
		}
		case 'B':					//����
		{
			GPIO_ResetBits(GPIOC,GPIO_Pin_6);	  
			GPIO_SetBits(GPIOC,GPIO_Pin_7); 
		
			GPIO_ResetBits(GPIOC,GPIO_Pin_8);	  
			GPIO_SetBits(GPIOC,GPIO_Pin_9); 

			PWM_L = speed;
			PWM_R = speed;
			break ;
		}
		case 'S':					//ɲ��
		{
			GPIO_ResetBits(GPIOC,GPIO_Pin_6);	  
			GPIO_ResetBits(GPIOC,GPIO_Pin_7); 
		
			GPIO_ResetBits(GPIOC,GPIO_Pin_8);	  
			GPIO_ResetBits(GPIOC,GPIO_Pin_9); 
		
			PWM_L = 0;
			PWM_R = 0;
			break ;
		}
	}
}

void turn(char mode,u16 speed,u16 time)
{	
	move('S',0);
	delay_ms(100);		//ɲ������������
	
	switch(mode)
	{
		case 'O':	//ԭ��ת
		{		
			GPIO_SetBits(GPIOC,GPIO_Pin_6);	  
			GPIO_ResetBits(GPIOC,GPIO_Pin_7); 
			
			GPIO_ResetBits(GPIOC,GPIO_Pin_8);
			GPIO_SetBits(GPIOC,GPIO_Pin_9); 
			
			PWM_L = speed;
			PWM_R = speed;
			
			delay_ms(time);
			break;
		}	
		case 'R':			//turnright
		{
			GPIO_SetBits(GPIOC,GPIO_Pin_6);	  
			GPIO_ResetBits(GPIOC,GPIO_Pin_7); 
			
			GPIO_ResetBits(GPIOC,GPIO_Pin_8);
			GPIO_SetBits(GPIOC,GPIO_Pin_9); 
			
			PWM_L = speed;
			PWM_R = speed;
			
			delay_ms(time);
			break ;
		}
		case 'L':		//turnleft
		{
			GPIO_ResetBits(GPIOC,GPIO_Pin_6);	  
			GPIO_SetBits(GPIOC,GPIO_Pin_7); 
			
			GPIO_SetBits(GPIOC,GPIO_Pin_8);	  
			GPIO_ResetBits(GPIOC,GPIO_Pin_9);
			
			PWM_L = speed;
			PWM_R = speed;
			
			delay_ms(time);
			break ;
		}
	}		
}

/*************************************************
  ��������: ����
  ģʽ  speed : �ٶ�  
  �������˵��: ��       
  ��������ֵ: ��
  ����˵��:		ɲ�� 5%  ���� 10%
*************************************************/
void handao(u16 speed)
{

PWMh = speed;}

