#include "delay.h"
#include "action.h"
#include "gpio.h"
#include "Moto_Mode.h"
//�ⲿ�жϳ�ʼ������

int flag=1;
int flag_R = 0;
int xinagzi = 1;

void action(void)
{    
    EXTI_InitTypeDef EXTI_InitStructure;
 	  NVIC_InitTypeDef NVIC_InitStructure;
	  GPIO_InitTypeDef GPIO_InitStructure;
	
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 //ʹ��PC�˿�ʱ��:��������
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//�ⲿ�жϣ���Ҫʹ��AFIOʱ��
	 
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 //LED0-->PA.8 �˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //�������룻
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.8
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;				 //LED0-->PA.8 �˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //�������룻
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.8
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;				 //LED0-->PA.8 �˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //�������룻
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.8
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				 //LED0-->PA.8 �˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //�������룻
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.8
		
   
		
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource5);
		EXTI_ClearITPendingBit(EXTI_Line5);  //���LINE15��·����λ

   	EXTI_InitStructure.EXTI_Line=EXTI_Line5;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);		//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
		NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//��ռ���ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//�����ȼ�1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
    NVIC_Init(&NVIC_InitStructure); 
	
	  GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource6);
		EXTI_ClearITPendingBit(EXTI_Line6);  //���LINE15��·����λ

   	EXTI_InitStructure.EXTI_Line=EXTI_Line6;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);		//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
		NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//��ռ���ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//�����ȼ�1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
    NVIC_Init(&NVIC_InitStructure); 

  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource7);
		EXTI_ClearITPendingBit(EXTI_Line7);  //���LINE15��·����λ

   	EXTI_InitStructure.EXTI_Line=EXTI_Line7;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);		//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
		NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//��ռ���ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//�����ȼ�1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
    NVIC_Init(&NVIC_InitStructure); 
	  GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource9);
		EXTI_ClearITPendingBit(EXTI_Line9);  //���LINE15��·����λ

   	EXTI_InitStructure.EXTI_Line=EXTI_Line9;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);		//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���	
		NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//��ռ���ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;					//�����ȼ�1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//ʹ���ⲿ�ж�ͨ��
    NVIC_Init(&NVIC_InitStructure); 
	
 
}


//�ⲿ�жϳ�ʼ������---diable
void action_disable(void)
{

    EXTI_InitTypeDef EXTI_InitStructure;
 	  NVIC_InitTypeDef NVIC_InitStructure;
	  GPIO_InitTypeDef GPIO_InitStructure;
	
	
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, DISABLE);	 //ʹ��PC�˿�ʱ��:��������
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,DISABLE);//�ⲿ�жϣ���Ҫʹ��AFIOʱ��
	 
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 //LED0-->PA.8 �˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //�������룻
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.8
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;				 //LED0-->PA.8 �˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //�������룻
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.8
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;				 //LED0-->PA.8 �˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //�������룻
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.8
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				 //LED0-->PA.8 �˿�����
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //�������룻
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);					 //�����趨������ʼ��GPIOA.8
		
		
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource5);
		EXTI_ClearITPendingBit(EXTI_Line5);  //���LINE15��·����λ

   	EXTI_InitStructure.EXTI_Line=EXTI_Line5;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger =  EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = DISABLE;
  	EXTI_Init(&EXTI_InitStructure);		//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
		NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//��ռ���ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//�����ȼ�1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;								//ʹ���ⲿ�ж�ͨ��
    NVIC_Init(&NVIC_InitStructure); 
	
	  GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource6);
		EXTI_ClearITPendingBit(EXTI_Line6);  //���LINE15��·����λ

   	EXTI_InitStructure.EXTI_Line=EXTI_Line6;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger =  EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = DISABLE;
  	EXTI_Init(&EXTI_InitStructure);		//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
		NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//��ռ���ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//�����ȼ�1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;								//ʹ���ⲿ�ж�ͨ��
    NVIC_Init(&NVIC_InitStructure); 

  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource7);
		EXTI_ClearITPendingBit(EXTI_Line7);  //���LINE15��·����λ

   	EXTI_InitStructure.EXTI_Line=EXTI_Line7;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = DISABLE;
  	EXTI_Init(&EXTI_InitStructure);		//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���
		NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//��ռ���ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//�����ȼ�1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;								//ʹ���ⲿ�ж�ͨ��
    NVIC_Init(&NVIC_InitStructure); 
	  GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource9);
		EXTI_ClearITPendingBit(EXTI_Line9);  //���LINE15��·����λ

   	EXTI_InitStructure.EXTI_Line=EXTI_Line9;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger =  EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = DISABLE;
  	EXTI_Init(&EXTI_InitStructure);		//����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���	
		NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//ʹ�ܰ������ڵ��ⲿ�ж�ͨ��
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//��ռ���ȼ�2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;					//�����ȼ�1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;								//ʹ���ⲿ�ж�ͨ��
    NVIC_Init(&NVIC_InitStructure); 

}

void EXTI9_5_IRQHandler(void)
{
	while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5))==1)
	{	 
		if(flag == 0)
			flag_R ++;	
		xinagzi = 0;
		while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6)==1)&&(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5))==1)
		{ 
			// GPIO_SetBits(GPIOB, GPIO_Pin_5);
			flag = 1;
			
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
			GPIO_ResetBits(GPIOA,GPIO_Pin_12); 
			GPIO_SetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ��
			GPIO_ResetBits(GPIOA,GPIO_Pin_3); 

			TIM_SetCompare1(TIM4,550);    //B6;
			TIM_SetCompare2(TIM4,550);		//B7;
			TIM_SetCompare3(TIM4,550);		//B8;
			TIM_SetCompare4(TIM4,550);		//B9;			
		}
	
		while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6)==0)&&(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5))==1)
		{
			 // GPIO_SetBits(GPIOB, GPIO_Pin_5);
				flag = 1;
			  GPIO_SetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
		    GPIO_ResetBits(GPIOA,GPIO_Pin_12); 
	      GPIO_SetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
		    GPIO_ResetBits(GPIOA,GPIO_Pin_3); 
	      TIM_SetCompare1(TIM4,550);    //B6;
				TIM_SetCompare2(TIM4,550);		//B7;
				TIM_SetCompare3(TIM4,550);		//B8;
				TIM_SetCompare4(TIM4,550);		//B9;	
		}	
	}
	 EXTI_ClearITPendingBit(EXTI_Line5);  //���LINE15��·����λ
	 EXTI_ClearITPendingBit(EXTI_Line6);  //���LINE15��·����λ
	
	while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6))==1)
	{
		if(flag == 0)
			flag_R ++;
		xinagzi = 0;
		while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)==1)&&(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6))==1)
		{
			// GPIO_SetBits(GPIOB, GPIO_Pin_5);
			flag = 1;			
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
			GPIO_ResetBits(GPIOA,GPIO_Pin_12); 
			GPIO_SetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ��
			GPIO_ResetBits(GPIOA,GPIO_Pin_3); 
			TIM_SetCompare1(TIM4,550);    //B6;
			TIM_SetCompare2(TIM4,550);		//B7;
			TIM_SetCompare3(TIM4,550);		//B8;
			TIM_SetCompare4(TIM4,550);		//B9;	
		}
		while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)==0)&&(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6))==1)
		{
			 // GPIO_SetBits(GPIOB, GPIO_Pin_5);
			flag = 1;
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
			GPIO_ResetBits(GPIOA,GPIO_Pin_12); 
			GPIO_SetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
			GPIO_ResetBits(GPIOA,GPIO_Pin_3); 
			TIM_SetCompare1(TIM4,550);    //B6;
			TIM_SetCompare2(TIM4,550);		//B7;
			TIM_SetCompare3(TIM4,550);		//B8;
			TIM_SetCompare4(TIM4,550);		//B9;	
		}
	}
	 EXTI_ClearITPendingBit(EXTI_Line5);  //���LINE15��·����λ
	 EXTI_ClearITPendingBit(EXTI_Line6);  //���LINE15��·����λ
	

	while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7))==1)
	{
			
		while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9)==1)&&(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7))==1)
		{
			//  GPIO_ResetBits (GPIOB, GPIO_Pin_5);
			flag = 0;

			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
			GPIO_SetBits(GPIOA,GPIO_Pin_12); 
			GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ��
			GPIO_SetBits(GPIOA,GPIO_Pin_3); 
			TIM_SetCompare1(TIM4,550);    //B6;
			TIM_SetCompare2(TIM4,550);		//B7;
			TIM_SetCompare3(TIM4,550);		//B8;
			TIM_SetCompare4(TIM4,550);		//B9;	
		}
			while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9)==0)&&(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7))==1)
		{
			//GPIO_ResetBits (GPIOB, GPIO_Pin_5);
			flag = 0;
			 moveon();
		}
		
	}
	 EXTI_ClearITPendingBit(EXTI_Line7);  //���LINE15��·����λ
	 EXTI_ClearITPendingBit(EXTI_Line9);  //���LINE15��·����λ

	
	while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9))==1)
	{
		
			while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7)==1)&&(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9))==1)
		{
			// GPIO_ResetBits (GPIOB, GPIO_Pin_5);
			flag = 0;
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
			GPIO_SetBits(GPIOA,GPIO_Pin_12); 
			GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ��
			GPIO_SetBits(GPIOA,GPIO_Pin_3); 
			TIM_SetCompare1(TIM4,550);    //B6;
			TIM_SetCompare2(TIM4,550);		//B7;
			TIM_SetCompare3(TIM4,550);		//B8;
			TIM_SetCompare4(TIM4,550);		//B9;	
			
		}
		while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7)==0)&&(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9))==1)
		{
			 //GPIO_ResetBits (GPIOB, GPIO_Pin_5);
				flag = 0;
				moveon();
		}
	 
	}
	 EXTI_ClearITPendingBit(EXTI_Line7);  //���LINE15��·����λ
	 EXTI_ClearITPendingBit(EXTI_Line9);  //���LINE15��·����λ
	
}



