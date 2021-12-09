#include "dengtai.h"
#include "action.h"
#include "duoji.h"
#include "delay.h"
//#include "fast.h"
//#include "move_turn.h"

void dengtai(void)	
{	
	delay_ms(50);

	GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //正转：  前左；
	GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //正转：  前右；
	GPIO_SetBits(GPIOA,GPIO_Pin_3); 

	TIM_SetCompare1(TIM4,680);    //B6;
	TIM_SetCompare2(TIM4,680);		//B7;
	TIM_SetCompare3(TIM4,680);		//B8;
	TIM_SetCompare4(TIM4,680);		//B9;
	delay_ms(200);
	 
	GPIO_SetBits(GPIOA,GPIO_Pin_11);	  //正转：  前左；
	GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	GPIO_SetBits(GPIOA,GPIO_Pin_2);	  //正转：  前右；
	GPIO_SetBits(GPIOA,GPIO_Pin_3); 
	delay_ms(50);
	 
	fast();	 
	delay_ms(600);
	PWM1 = 60;
	PWM2 = 121;
	delay_ms(700);
	
	PWM1 = 67;  
	PWM2 = 112;
	PWM4 = 64;      
	PWM3 = 121;
	delay_ms(200);
	PWM1 = 160;  
	PWM2 = 160;	
	delay_ms(600);
	  
	PWM4 = 76; 
  PWM3 = 110;
	delay_ms(300);
	PWM3 = 160;
	PWM4 = 160;
}
