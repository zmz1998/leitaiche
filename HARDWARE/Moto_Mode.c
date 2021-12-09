#include "Moto_Mode.h"

/*************************************************
  函数名称: move
  函数功能: 电机转动模式设置
  被本函数调用的函数: 无        
  调用本函数的函数:     
  输入参数说明: mode ：模式  speed : 速度  
  输出参数说明: 无       
  函数返回值: 无
  其它说明:		PB6  PB7	|	PB8		PB9
								1		0		|		1			0		PWM		正转
								0		1		|		0			1		PWM		反转
								0		0		|		0			0		PWM		刹车
*************************************************/
void move(char mode,u16 speed)
{
	switch(mode)
	{
		case 'F':					//前进
		{
			GPIO_SetBits(GPIOC,GPIO_Pin_6);	  
			GPIO_ResetBits(GPIOC,GPIO_Pin_7); 
		
			GPIO_SetBits(GPIOC,GPIO_Pin_8);	  
			GPIO_ResetBits(GPIOC,GPIO_Pin_9);
			
			PWM_L = speed;
			PWM_R = speed;
			
			break ;
		}
		case 'B':					//后退
		{
			GPIO_ResetBits(GPIOC,GPIO_Pin_6);	  
			GPIO_SetBits(GPIOC,GPIO_Pin_7); 
		
			GPIO_ResetBits(GPIOC,GPIO_Pin_8);	  
			GPIO_SetBits(GPIOC,GPIO_Pin_9); 

			PWM_L = speed;
			PWM_R = speed;
			break ;
		}
		case 'S':					//刹车
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
	delay_ms(100);		//刹车，保护驱动
	
	switch(mode)
	{
		case 'O':	//原地转
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
  函数名称: 涵道
  模式  speed : 速度  
  输出参数说明: 无       
  函数返回值: 无
  其它说明:		刹车 5%  满载 10%
*************************************************/
void handao(u16 speed)
{

PWMh = speed;}

