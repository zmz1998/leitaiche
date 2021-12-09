#include "delay.h"
#include "action.h"
#include "gpio.h"
#include "Moto_Mode.h"
//外部中断初始化函数

int flag=1;
int flag_R = 0;
int xinagzi = 1;

void action(void)
{    
    EXTI_InitTypeDef EXTI_InitStructure;
 	  NVIC_InitTypeDef NVIC_InitStructure;
	  GPIO_InitTypeDef GPIO_InitStructure;
	
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 //使能PC端口时钟:传感器；
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//外部中断，需要使能AFIO时钟
	 
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 //LED0-->PA.8 端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //上拉输入；
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.8
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;				 //LED0-->PA.8 端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //上拉输入；
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.8
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;				 //LED0-->PA.8 端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //上拉输入；
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.8
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				 //LED0-->PA.8 端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //上拉输入；
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.8
		
   
		
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource5);
		EXTI_ClearITPendingBit(EXTI_Line5);  //清除LINE15线路挂起位

   	EXTI_InitStructure.EXTI_Line=EXTI_Line5;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
		NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//使能按键所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//抢占优先级2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//子优先级1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
    NVIC_Init(&NVIC_InitStructure); 
	
	  GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource6);
		EXTI_ClearITPendingBit(EXTI_Line6);  //清除LINE15线路挂起位

   	EXTI_InitStructure.EXTI_Line=EXTI_Line6;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
		NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//使能按键所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//抢占优先级2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//子优先级1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
    NVIC_Init(&NVIC_InitStructure); 

  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource7);
		EXTI_ClearITPendingBit(EXTI_Line7);  //清除LINE15线路挂起位

   	EXTI_InitStructure.EXTI_Line=EXTI_Line7;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
		NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//使能按键所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//抢占优先级2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//子优先级1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
    NVIC_Init(&NVIC_InitStructure); 
	  GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource9);
		EXTI_ClearITPendingBit(EXTI_Line9);  //清除LINE15线路挂起位

   	EXTI_InitStructure.EXTI_Line=EXTI_Line9;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器	
		NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//使能按键所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//抢占优先级2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;					//子优先级1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;								//使能外部中断通道
    NVIC_Init(&NVIC_InitStructure); 
	
 
}


//外部中断初始化函数---diable
void action_disable(void)
{

    EXTI_InitTypeDef EXTI_InitStructure;
 	  NVIC_InitTypeDef NVIC_InitStructure;
	  GPIO_InitTypeDef GPIO_InitStructure;
	
	
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, DISABLE);	 //使能PC端口时钟:传感器；
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,DISABLE);//外部中断，需要使能AFIO时钟
	 
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;				 //LED0-->PA.8 端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //上拉输入；
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.8
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;				 //LED0-->PA.8 端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //上拉输入；
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.8
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;				 //LED0-->PA.8 端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //上拉输入；
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.8
	
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				 //LED0-->PA.8 端口配置
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //上拉输入；
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
    GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIOA.8
		
		
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource5);
		EXTI_ClearITPendingBit(EXTI_Line5);  //清除LINE15线路挂起位

   	EXTI_InitStructure.EXTI_Line=EXTI_Line5;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger =  EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = DISABLE;
  	EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
		NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//使能按键所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//抢占优先级2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;					//子优先级1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;								//使能外部中断通道
    NVIC_Init(&NVIC_InitStructure); 
	
	  GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource6);
		EXTI_ClearITPendingBit(EXTI_Line6);  //清除LINE15线路挂起位

   	EXTI_InitStructure.EXTI_Line=EXTI_Line6;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger =  EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = DISABLE;
  	EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
		NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//使能按键所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//抢占优先级2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;					//子优先级1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;								//使能外部中断通道
    NVIC_Init(&NVIC_InitStructure); 

  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource7);
		EXTI_ClearITPendingBit(EXTI_Line7);  //清除LINE15线路挂起位

   	EXTI_InitStructure.EXTI_Line=EXTI_Line7;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = DISABLE;
  	EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
		NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//使能按键所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//抢占优先级2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;					//子优先级1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;								//使能外部中断通道
    NVIC_Init(&NVIC_InitStructure); 
	  GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource9);
		EXTI_ClearITPendingBit(EXTI_Line9);  //清除LINE15线路挂起位

   	EXTI_InitStructure.EXTI_Line=EXTI_Line9;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger =  EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = DISABLE;
  	EXTI_Init(&EXTI_InitStructure);		//根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器	
		NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//使能按键所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;	//抢占优先级2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03;					//子优先级1
  	NVIC_InitStructure.NVIC_IRQChannelCmd = DISABLE;								//使能外部中断通道
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
			
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  //倒转；  前左；
			GPIO_ResetBits(GPIOA,GPIO_Pin_12); 
			GPIO_SetBits(GPIOA,GPIO_Pin_2);	  //倒转；  前左；
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
			  GPIO_SetBits(GPIOA,GPIO_Pin_11);	  //正转：  前左；
		    GPIO_ResetBits(GPIOA,GPIO_Pin_12); 
	      GPIO_SetBits(GPIOA,GPIO_Pin_2);	  //正转：  前右；
		    GPIO_ResetBits(GPIOA,GPIO_Pin_3); 
	      TIM_SetCompare1(TIM4,550);    //B6;
				TIM_SetCompare2(TIM4,550);		//B7;
				TIM_SetCompare3(TIM4,550);		//B8;
				TIM_SetCompare4(TIM4,550);		//B9;	
		}	
	}
	 EXTI_ClearITPendingBit(EXTI_Line5);  //清除LINE15线路挂起位
	 EXTI_ClearITPendingBit(EXTI_Line6);  //清除LINE15线路挂起位
	
	while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6))==1)
	{
		if(flag == 0)
			flag_R ++;
		xinagzi = 0;
		while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)==1)&&(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6))==1)
		{
			// GPIO_SetBits(GPIOB, GPIO_Pin_5);
			flag = 1;			
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  //倒转；  前左；
			GPIO_ResetBits(GPIOA,GPIO_Pin_12); 
			GPIO_SetBits(GPIOA,GPIO_Pin_2);	  //倒转；  前左；
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
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  //正转：  前左；
			GPIO_ResetBits(GPIOA,GPIO_Pin_12); 
			GPIO_SetBits(GPIOA,GPIO_Pin_2);	  //正转：  前右；
			GPIO_ResetBits(GPIOA,GPIO_Pin_3); 
			TIM_SetCompare1(TIM4,550);    //B6;
			TIM_SetCompare2(TIM4,550);		//B7;
			TIM_SetCompare3(TIM4,550);		//B8;
			TIM_SetCompare4(TIM4,550);		//B9;	
		}
	}
	 EXTI_ClearITPendingBit(EXTI_Line5);  //清除LINE15线路挂起位
	 EXTI_ClearITPendingBit(EXTI_Line6);  //清除LINE15线路挂起位
	

	while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7))==1)
	{
			
		while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9)==1)&&(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7))==1)
		{
			//  GPIO_ResetBits (GPIOB, GPIO_Pin_5);
			flag = 0;

			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //正转；  前左；
			GPIO_SetBits(GPIOA,GPIO_Pin_12); 
			GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //正转；  前左；
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
	 EXTI_ClearITPendingBit(EXTI_Line7);  //清除LINE15线路挂起位
	 EXTI_ClearITPendingBit(EXTI_Line9);  //清除LINE15线路挂起位

	
	while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9))==1)
	{
		
			while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7)==1)&&(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9))==1)
		{
			// GPIO_ResetBits (GPIOB, GPIO_Pin_5);
			flag = 0;
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //正转；  前左；
			GPIO_SetBits(GPIOA,GPIO_Pin_12); 
			GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //正转；  前左；
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
	 EXTI_ClearITPendingBit(EXTI_Line7);  //清除LINE15线路挂起位
	 EXTI_ClearITPendingBit(EXTI_Line9);  //清除LINE15线路挂起位
	
}



