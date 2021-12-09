#include "exti.h"
#include "main.h"

	int flag_L = 0;
	int flag_R = 0;
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103ZE���İ�

//�ⲿ�ж� ��������	   
							  
//////////////////////////////////////////////////////////////////////////////////   
//�ⲿ�ж�0�������
void EXTIX_Init(void)
{
 
 	EXTI_InitTypeDef EXTI_InitStructure;
 	NVIC_InitTypeDef NVIC_InitStructure;


  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//ʹ�ܸ��ù���ʱ��

    //�ж����Լ��жϳ�ʼ������  �����ش���
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource4);

  	EXTI_InitStructure.EXTI_Line                             = EXTI_Line4;	
  	EXTI_InitStructure.EXTI_Mode                             = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger                          = EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd                          = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	                      //����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���

		NVIC_InitStructure.NVIC_IRQChannel                   = EXTI4_IRQn;			//ʹ�ܰ���KEY1���ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	          //��ռ���ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0x03;					  //�����ȼ�1 
  	NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;					//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure);  	  
	
		//�ж����Լ��жϳ�ʼ������  �����ش���
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource2); 
  	EXTI_InitStructure.EXTI_Line                             = EXTI_Line2;
	 	EXTI_InitStructure.EXTI_Mode                             = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger                          = EXTI_Trigger_Rising;
  	EXTI_Init(&EXTI_InitStructure);		                       //����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
		
    NVIC_InitStructure.NVIC_IRQChannel                   = EXTI2_IRQn;			//ʹ���ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	          //��ռ���ȼ�2�� 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0x02;					  //�����ȼ�2
  	NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;					//ʹ���ⲿ�ж�ͨ��
  	NVIC_Init(&NVIC_InitStructure);

   //�ж����Լ��жϳ�ʼ������  �����ش���	
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource1);
//  	EXTI_InitStructure.EXTI_Line                             = EXTI_Line1;
//		EXTI_InitStructure.EXTI_Mode                             = EXTI_Mode_Interrupt;	
//	  EXTI_InitStructure.EXTI_Trigger                          = EXTI_Trigger_Rising;
//  	EXTI_Init(&EXTI_InitStructure);	  	                    //����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���

//		NVIC_InitStructure.NVIC_IRQChannel                   = EXTI1_IRQn;			//ʹ�ܰ���KEY0���ڵ��ⲿ�ж�ͨ��
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	          //��ռ���ȼ�2 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0x01;					  //�����ȼ�0 
//  	NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;					//ʹ���ⲿ�ж�ͨ��
//  	NVIC_Init(&NVIC_InitStructure);  	 

//   //�ж����Լ��жϳ�ʼ������  �����ش��� 
// 	  GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource0); 
//  	EXTI_InitStructure.EXTI_Line                             = EXTI_Line0;
//		EXTI_InitStructure.EXTI_Mode                             = EXTI_Mode_Interrupt;	
//  	EXTI_InitStructure.EXTI_Trigger                          = EXTI_Trigger_Rising;
//  	EXTI_Init(&EXTI_InitStructure);		                       //����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���	

//  	NVIC_InitStructure.NVIC_IRQChannel                   = EXTI0_IRQn;			//ʹ���ⲿ�ж�ͨ��
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	          //��ռ���ȼ�2�� 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0x00;					  //�����ȼ�3
//  	NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;					//ʹ���ⲿ�ж�ͨ��
//  	NVIC_Init(&NVIC_InitStructure); 


}

//�ⲿ�ж�0������� 
//void EXTI0_IRQHandler(void)
//{
//	//delay_ms(10);//

//	while(PDin(0)==1)	 	 //
//	{				 
//		
//		move('F',2400);
//		delay_ms(1000);
//		turn('L',3000,500);
//	}
//	

//	EXTI_ClearITPendingBit(EXTI_Line0); //??3yLINE0��?��

//}
//void EXTI1_IRQHandler(void)
//{  
//	//delay_ms(10);//????

//	while(PDin(1)==1)	 	 //WK_UP���?��
//	{				 
//		move('F',2400);
//		delay_ms(1000);
//		turn('L',3000,500);
//	}

//	EXTI_ClearITPendingBit(EXTI_Line1); //??3yLINE0��?��??D??����???? 
//	
//}
void EXTI2_IRQHandler(void)
{
	//delay_ms(10);//????
 if(EXTI_GetITStatus(EXTI_Line2)!=RESET)//�ж�ĳ�����ϵ��ж��Ƿ���
 {
 if(PBin(2)==1)
 {
	 	move('B',1000);
//	while(PBin(2)==1)	 	 //WK_UP���?��
//	{				 
	  delay_ms(400);
		if(flag_L == 0)
			{
				turn('R',1200,500);
				flag_L = 1;
			}
			else
			{
				turn('L',1000,500);
				flag_L = 0;
			}	
//	}
 }
 }
	

	EXTI_ClearITPendingBit(EXTI_Line2); //??3yLINE0��?��??D??����???? 

}
void EXTI4_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line4)!=RESET)//�ж�ĳ�����ϵ��ж��Ƿ���
  {
	//delay_ms(10);//????
 if(PBin(4)==1)
 {
	 	move('B',1000);
//	while(PBin(4)==1)	 	 //WK_UP
//	{				 
	  delay_ms(400);
		if(flag_R == 0)
			{
				turn('R',1000,500);
				flag_R = 1;
			}
			else
			{
				turn('L',1200,500);
				flag_R = 0;
			}	
//	}
 }
 }
	

	EXTI_ClearITPendingBit(EXTI_Line4); //??3yLINE0��?��??D??����???? 

}

//void EXTI1_IRQHandler(void)
//{
//	delay_ms(10);//����
//	if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_1)==1)	 	 //WK_UP����
//	{				 
//		if(PDin(1)==1) 		
//		{
//			move('B',2800);
//			delay_ms(1000);
//			turn('L',3000,500);
//		}
//	}
//	EXTI_ClearITPendingBit(EXTI_Line1); //���LINE1�ϵ��жϱ�־λ  
//}
// 
////�ⲿ�ж�2�������
//void EXTI2_IRQHandler(void)
//{
//	delay_ms(10);//����
//	if(PDin(2)==1)
//		{
//			move('B',2800);
//			delay_ms(1000);
//			turn('R',3000,500);
//		}
//		 
//	EXTI_ClearITPendingBit(EXTI_Line2);  //���LINE2�ϵ��жϱ�־λ  
//}
////�ⲿ�ж�3�������
//void EXTI3_IRQHandler(void)
//{
//	delay_ms(10);//����
//	if(PDin(3)==1)
//		{
//			move('F',2800);
//			delay_ms(1000);
//			turn('R',3000,500);
//		}
//		 
//	EXTI_ClearITPendingBit(EXTI_Line3);  //���LINE3�ϵ��жϱ�־λ  
//}
