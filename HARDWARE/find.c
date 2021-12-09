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
	
	//��������ֵ
	//PBin(10)	��PB_10	ǰ���
	//PBin(11)	��PB_11	����
	//PBin(12)	��PB_12	����
	//PBin(13)	��PB_13	�ҹ��
	
	AD5 = Adc_GetValue(0); 	//ǰ������ഫ����
	AD6 = Adc_GetValue(1); 	//ǰ�Һ����ഫ����
	AD7 = Adc_GetValue(2); 	//��������ഫ����
	AD8 = Adc_GetValue(3); 	//���Һ����ഫ����
	AD9 = Adc_GetValue(4); 	//��������ഫ����
	AD10 =Adc_GetValue(5); 	//���Һ����ഫ����
	
	//��û�м�⵽��ʱ��
	
	while((AD5 < FLD) && (AD6 < FRD) && (AD7 < BLD) && (AD8 < BRD) && (AD9 < MLD) && (AD10 < MRD))
	{
		action();

		if(flag == 1)
		{
		/*	
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
			GPIO_ResetBits(GPIOA,GPIO_Pin_12); 
			GPIO_SetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
			GPIO_ResetBits(GPIOA,GPIO_Pin_3); 
			TIM_SetCompare1(TIM4,670);    //B6;
			TIM_SetCompare2(TIM4,550);		//B7- A11 and A12;
		*/	
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
			GPIO_ResetBits(GPIOA,GPIO_Pin_12); 
		
			GPIO_SetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
			GPIO_ResetBits(GPIOA,GPIO_Pin_3); 
			
			TIM_SetCompare1(TIM4,670);    //B6;
			TIM_SetCompare2(TIM4,550);		//B7;
			TIM_SetCompare3(TIM4,720);		//B8;
			TIM_SetCompare4(TIM4,600);		//B9;
		}
		if(flag == 0)
		{
		/*	
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
			GPIO_SetBits(GPIOA,GPIO_Pin_12); 
			GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
			GPIO_SetBits(GPIOA,GPIO_Pin_3); 
			TIM_SetCompare1(TIM4,550);    //B6;
			TIM_SetCompare2(TIM4,670);		//B7;
		*/				
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
			GPIO_SetBits(GPIOA,GPIO_Pin_12); 
		
			GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
			GPIO_SetBits(GPIOA,GPIO_Pin_3); 

			TIM_SetCompare1(TIM4,550);    //B6;
			TIM_SetCompare2(TIM4,670);		//B7;
			TIM_SetCompare3(TIM4,600);		//B8;
			TIM_SetCompare4(TIM4,720);		//B9;	
		}
	}	

	
	//ǰ��
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
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
			GPIO_SetBits(GPIOA,GPIO_Pin_12); 
		
			GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
			GPIO_SetBits(GPIOA,GPIO_Pin_3); 

			TIM_SetCompare1(TIM4,480);    //B6;
			TIM_SetCompare2(TIM4,480);		//B7;
			TIM_SetCompare3(TIM4,480);		//B8;
			TIM_SetCompare4(TIM4,480);		//B9;
		}
	}
	num = 0;
	//ǰ��
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
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
			GPIO_SetBits(GPIOA,GPIO_Pin_12); 
		
			GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
			GPIO_SetBits(GPIOA,GPIO_Pin_3); 

			TIM_SetCompare1(TIM4,480);    //B6;
			TIM_SetCompare2(TIM4,480);		//B7;
			TIM_SetCompare3(TIM4,480);		//B8;
			TIM_SetCompare4(TIM4,480);		//B9;
		}
	}
	num = 0;
	
	//ǰ����
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
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
			GPIO_SetBits(GPIOA,GPIO_Pin_12); 
		
			GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
			GPIO_SetBits(GPIOA,GPIO_Pin_3); 

			TIM_SetCompare1(TIM4,480);    //B6;
			TIM_SetCompare2(TIM4,480);		//B7;
			TIM_SetCompare3(TIM4,480);		//B8;
			TIM_SetCompare4(TIM4,480);		//B9;
		}
	}
	num = 0;
	
	//ǰ����
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
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
			GPIO_SetBits(GPIOA,GPIO_Pin_12); 
		
			GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
			GPIO_SetBits(GPIOA,GPIO_Pin_3); 

			TIM_SetCompare1(TIM4,480);    //B6;
			TIM_SetCompare2(TIM4,480);		//B7;
			TIM_SetCompare3(TIM4,480);		//B8;
			TIM_SetCompare4(TIM4,480);		//B9;
		}
	}		
	num = 0;
	
	}
