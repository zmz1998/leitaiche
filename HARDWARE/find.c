#include "find.h"


#define uint unsigned int

int i=0;
int j=0;
int num=0;
float t1;

uint AD5;
uint AD6;
uint AD7;
uint AD8;
uint AD9;
uint AD10;

void find()
{
	action();
	Gpio_Init();
	
	//读传感器值
	//PBin(10)	读PB_10	前光电
	//PBin(11)	读PB_11	后光电
	//PBin(12)	读PB_12	左光电
	//PBin(13)	读PB_13	右光电
	
	AD5 = Adc_GetValue(0); 	//前左红外测距传感器
	AD6 = Adc_GetValue(1); 	//前右红外测距传感器
	AD7 = Adc_GetValue(2); 	//后左红外测距传感器
	AD8 = Adc_GetValue(3); 	//后右红外测距传感器
	AD9 = Adc_GetValue(4); 	//中左红外测距传感器
	AD10 =Adc_GetValue(5); 	//中右红外测距传感器
	
	//均没有检测到的时候：
	
	while((AD5 < FLD) && (AD6 < FRD) && (AD7 < BLD) && (AD8 < BRD) && (AD9 < MLD) && (AD10 < MRD))
	{
		action();

		if(flag == 1)
		{
		/*	
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  //正转：  前左；
			GPIO_ResetBits(GPIOA,GPIO_Pin_12); 
			GPIO_SetBits(GPIOA,GPIO_Pin_2);	  //正转：  前右；
			GPIO_ResetBits(GPIOA,GPIO_Pin_3); 
			TIM_SetCompare1(TIM4,670);    //B6;
			TIM_SetCompare2(TIM4,550);		//B7- A11 and A12;
		*/	
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  //反转：  前左；
			GPIO_ResetBits(GPIOA,GPIO_Pin_12); 
		
			GPIO_SetBits(GPIOA,GPIO_Pin_2);	  //反转：  前右；
			GPIO_ResetBits(GPIOA,GPIO_Pin_3); 
			
			TIM_SetCompare1(TIM4,670);    //B6;
			TIM_SetCompare2(TIM4,550);		//B7;
			TIM_SetCompare3(TIM4,720);		//B8;
			TIM_SetCompare4(TIM4,600);		//B9;
		}
		if(flag == 0)
		{
		/*	
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //正转：  前左；
			GPIO_SetBits(GPIOA,GPIO_Pin_12); 
			GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //正转：  前右；
			GPIO_SetBits(GPIOA,GPIO_Pin_3); 
			TIM_SetCompare1(TIM4,550);    //B6;
			TIM_SetCompare2(TIM4,670);		//B7;
		*/				
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //正转：  前左；
			GPIO_SetBits(GPIOA,GPIO_Pin_12); 
		
			GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //正转：  前右；
			GPIO_SetBits(GPIOA,GPIO_Pin_3); 

			TIM_SetCompare1(TIM4,550);    //B6;
			TIM_SetCompare2(TIM4,670);		//B7;
			TIM_SetCompare3(TIM4,600);		//B8;
			TIM_SetCompare4(TIM4,720);		//B9;	
		}
	}	

	
	//前左
	while(AD5 > FLD)
	{
		while((AD5 > FLD) && (AD6 < FRD) && num < 100)
		{
			turnleft();
			delay_ms(1); 
			num++;
		}
		num = 0;
		while(PBin(10)==0)
		{			
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //正转：  前左；
			GPIO_SetBits(GPIOA,GPIO_Pin_12); 
		
			GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //正转：  前右；
			GPIO_SetBits(GPIOA,GPIO_Pin_3); 

			TIM_SetCompare1(TIM4,480);    //B6;
			TIM_SetCompare2(TIM4,480);		//B7;
			TIM_SetCompare3(TIM4,480);		//B8;
			TIM_SetCompare4(TIM4,480);		//B9;
		}
	}
	num = 0;
	//前右
	while(AD6 > FRD)
	{
		while((AD6 > FRD) && (AD5 < FLD) && (num < 100))
		{
			turnright();
			delay_ms(1);
			num++;
		}
		num = 0;
		while(PBin(10)==0)
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //正转：  前左；
			GPIO_SetBits(GPIOA,GPIO_Pin_12); 
		
			GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //正转：  前右；
			GPIO_SetBits(GPIOA,GPIO_Pin_3); 

			TIM_SetCompare1(TIM4,480);    //B6;
			TIM_SetCompare2(TIM4,480);		//B7;
			TIM_SetCompare3(TIM4,480);		//B8;
			TIM_SetCompare4(TIM4,480);		//B9;
		}
	}
	num = 0;
	
	//前左左
	while(AD9 > MLD)
	{
		while((AD9>MLD) && (AD5 < FLD) && (num < 100))
		{
			turnleft();
			delay_ms(1);
			num++;
		}
		while((AD5 > FLD) && (AD6 < FRD) && (PBin(10)==1) && num < 100)
		{
			turnleft();
			delay_ms(1);
			num++;
		}
		num = 0;
		while(PBin(10)==0)
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //正转：  前左；
			GPIO_SetBits(GPIOA,GPIO_Pin_12); 
		
			GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //正转：  前右；
			GPIO_SetBits(GPIOA,GPIO_Pin_3); 

			TIM_SetCompare1(TIM4,480);    //B6;
			TIM_SetCompare2(TIM4,480);		//B7;
			TIM_SetCompare3(TIM4,480);		//B8;
			TIM_SetCompare4(TIM4,480);		//B9;
		}
	}
	num = 0;
	
	//前右右
	while(AD10 > MRD)
	{
		while((AD10 > MRD) && (AD6 < FRD) && (num <100))
		{
			turnright();
			delay_ms(1);
			num++;
		}
		num = 0;	
		while((AD6 > FRD) && (AD5 < FLD) && (PBin(10)==1) && (num < 100))
		{
			turnright();
			delay_ms(1);
			num++;
		}
		num = 0;
		while(PBin(10)==0)
		{	
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //正转：  前左；
			GPIO_SetBits(GPIOA,GPIO_Pin_12); 
		
			GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //正转：  前右；
			GPIO_SetBits(GPIOA,GPIO_Pin_3); 

			TIM_SetCompare1(TIM4,480);    //B6;
			TIM_SetCompare2(TIM4,480);		//B7;
			TIM_SetCompare3(TIM4,480);		//B8;
			TIM_SetCompare4(TIM4,480);		//B9;
		}
	}		
	num = 0;
	
	}
