#include "exti.h"
#include "main.h"

	int flag_L = 0;
	int flag_R = 0;
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F103ZE核心板

//外部中断 驱动代码	   
							  
//////////////////////////////////////////////////////////////////////////////////   
//外部中断0服务程序
void EXTIX_Init(void)
{
 
 	EXTI_InitTypeDef EXTI_InitStructure;
 	NVIC_InitTypeDef NVIC_InitStructure;


  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);	//使能复用功能时钟

    //中断线以及中断初始化配置  上升沿触发
  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource4);

  	EXTI_InitStructure.EXTI_Line                             = EXTI_Line4;	
  	EXTI_InitStructure.EXTI_Mode                             = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger                          = EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd                          = ENABLE;
  	EXTI_Init(&EXTI_InitStructure);	 	                      //根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器

		NVIC_InitStructure.NVIC_IRQChannel                   = EXTI4_IRQn;			//使能按键KEY1所在的外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	          //抢占优先级2 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0x03;					  //子优先级1 
  	NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;					//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure);  	  
	
		//中断线以及中断初始化配置  上升沿触发
		GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource2); 
  	EXTI_InitStructure.EXTI_Line                             = EXTI_Line2;
	 	EXTI_InitStructure.EXTI_Mode                             = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger                          = EXTI_Trigger_Rising;
  	EXTI_Init(&EXTI_InitStructure);		                       //根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器
		
    NVIC_InitStructure.NVIC_IRQChannel                   = EXTI2_IRQn;			//使能外部中断通道
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	          //抢占优先级2， 
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0x02;					  //子优先级2
  	NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;					//使能外部中断通道
  	NVIC_Init(&NVIC_InitStructure);

   //中断线以及中断初始化配置  上升沿触发	
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource1);
//  	EXTI_InitStructure.EXTI_Line                             = EXTI_Line1;
//		EXTI_InitStructure.EXTI_Mode                             = EXTI_Mode_Interrupt;	
//	  EXTI_InitStructure.EXTI_Trigger                          = EXTI_Trigger_Rising;
//  	EXTI_Init(&EXTI_InitStructure);	  	                    //根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器

//		NVIC_InitStructure.NVIC_IRQChannel                   = EXTI1_IRQn;			//使能按键KEY0所在的外部中断通道
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	          //抢占优先级2 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0x01;					  //子优先级0 
//  	NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;					//使能外部中断通道
//  	NVIC_Init(&NVIC_InitStructure);  	 

//   //中断线以及中断初始化配置  上升沿触发 
// 	  GPIO_EXTILineConfig(GPIO_PortSourceGPIOD,GPIO_PinSource0); 
//  	EXTI_InitStructure.EXTI_Line                             = EXTI_Line0;
//		EXTI_InitStructure.EXTI_Mode                             = EXTI_Mode_Interrupt;	
//  	EXTI_InitStructure.EXTI_Trigger                          = EXTI_Trigger_Rising;
//  	EXTI_Init(&EXTI_InitStructure);		                       //根据EXTI_InitStruct中指定的参数初始化外设EXTI寄存器	

//  	NVIC_InitStructure.NVIC_IRQChannel                   = EXTI0_IRQn;			//使能外部中断通道
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	          //抢占优先级2， 
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0x00;					  //子优先级3
//  	NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;					//使能外部中断通道
//  	NVIC_Init(&NVIC_InitStructure); 


}

//外部中断0服务程序 
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

//	EXTI_ClearITPendingBit(EXTI_Line0); //??3yLINE0é?μ

//}
//void EXTI1_IRQHandler(void)
//{  
//	//delay_ms(10);//????

//	while(PDin(1)==1)	 	 //WK_UP°′?ü
//	{				 
//		move('F',2400);
//		delay_ms(1000);
//		turn('L',3000,500);
//	}

//	EXTI_ClearITPendingBit(EXTI_Line1); //??3yLINE0é?μ??D??±ê???? 
//	
//}
void EXTI2_IRQHandler(void)
{
	//delay_ms(10);//????
 if(EXTI_GetITStatus(EXTI_Line2)!=RESET)//判断某个线上的中断是否发生
 {
 if(PBin(2)==1)
 {
	 	move('B',1000);
//	while(PBin(2)==1)	 	 //WK_UP°′?ü
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
	

	EXTI_ClearITPendingBit(EXTI_Line2); //??3yLINE0é?μ??D??±ê???? 

}
void EXTI4_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line4)!=RESET)//判断某个线上的中断是否发生
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
	

	EXTI_ClearITPendingBit(EXTI_Line4); //??3yLINE0é?μ??D??±ê???? 

}

//void EXTI1_IRQHandler(void)
//{
//	delay_ms(10);//消抖
//	if(GPIO_ReadInputDataBit(GPIOD, GPIO_Pin_1)==1)	 	 //WK_UP按键
//	{				 
//		if(PDin(1)==1) 		
//		{
//			move('B',2800);
//			delay_ms(1000);
//			turn('L',3000,500);
//		}
//	}
//	EXTI_ClearITPendingBit(EXTI_Line1); //清除LINE1上的中断标志位  
//}
// 
////外部中断2服务程序
//void EXTI2_IRQHandler(void)
//{
//	delay_ms(10);//消抖
//	if(PDin(2)==1)
//		{
//			move('B',2800);
//			delay_ms(1000);
//			turn('R',3000,500);
//		}
//		 
//	EXTI_ClearITPendingBit(EXTI_Line2);  //清除LINE2上的中断标志位  
//}
////外部中断3服务程序
//void EXTI3_IRQHandler(void)
//{
//	delay_ms(10);//消抖
//	if(PDin(3)==1)
//		{
//			move('F',2800);
//			delay_ms(1000);
//			turn('R',3000,500);
//		}
//		 
//	EXTI_ClearITPendingBit(EXTI_Line3);  //清除LINE3上的中断标志位  
//}
