#include "gpio.h"

//////////////////////////////////////////////////////////////////////////////////	 
//本程序应用于擂台机器人
//STM32F103Z 芯片
//GPIO 代码
////////////////////////////////////////////////////////////////////////////////// 
	
/*************************************************
  函数名称: Gpio_Init
  函数功能: GPIO的配置
  被本函数调用的函数: 无        
  调用本函数的函数: 无    
  输入参数说明: 无    
  输出参数说明: 无       
  函数返回值: 无
  其它说明:无        
*************************************************/
void Gpio_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;															//定义GPIO初始化结构体变量

	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOA | 										//使能GPIOA时钟
													RCC_APB2Periph_GPIOB |										//使能GPIOB时钟	
													RCC_APB2Periph_GPIOC , ENABLE);						//使能GPIOC时钟 	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;									//IO口速度为50MHz

/*************************************************	
//ADC I/O初始化配置
//设置引脚为模拟输入功能,获取传感器的模拟值
//PA.0,1,2,3,4,5,6,7
//PB.0,1
//PC.0,1,2,3,4,5
*************************************************/	

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;											//选择GPIO模式为模拟输入
//	 PA0~7配置
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0|GPIO_Pin_1|
																 GPIO_Pin_2|GPIO_Pin_3|
																 GPIO_Pin_4|GPIO_Pin_5|
																 GPIO_Pin_6|GPIO_Pin_7;							//选择PA0~PA7
	GPIO_Init(GPIOA, &GPIO_InitStructure);													  //配置PA0~PA7为模拟输入	
	// PB0~1配置
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0|GPIO_Pin_1;							//选择PB0~PB1
	GPIO_Init(GPIOB, &GPIO_InitStructure);														//配置PB0~PB1为模拟输入
//	// PC0~5配置
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0|GPIO_Pin_1|
																 GPIO_Pin_2|GPIO_Pin_3|
																 GPIO_Pin_4|GPIO_Pin_5;							//选择PC0~PC5
	GPIO_Init(GPIOC, &GPIO_InitStructure);	
//	
/*************************************************	
//PWM波 I/O口配置
//设置引脚为复用输出功能,输出TIM4的PWM脉冲波形
*************************************************/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  									//选择GPIO模式复用推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | 
																GPIO_Pin_7 |
																GPIO_Pin_8;
//																GPIO_Pin_9 ; 				
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  									//选择GPIO模式复用推挽输出 涵道
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
			
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
/*************************************************	
//驱动方向 I/O口配置
//设置引脚为输出功能,输出高低电平
// PC.6,7,8,9配置
*************************************************/	

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 							//选择GPIO模式为推挽输出
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 |
																GPIO_Pin_7 |
																GPIO_Pin_8 | 
																GPIO_Pin_9 ;					
	
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	//初始化IO
	GPIO_ResetBits(GPIOC,GPIO_Pin_6);
	GPIO_ResetBits(GPIOC,GPIO_Pin_7);
	GPIO_ResetBits(GPIOC,GPIO_Pin_8);
	GPIO_ResetBits(GPIOC,GPIO_Pin_9);
		
/*************************************************	
//外部中断 I/O口配置
//设置引脚为上拉输入功能
//PD.1,2,3,4
*************************************************/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | 
																GPIO_Pin_4;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 								//选择GPIO模式为上拉输入；
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
/*************************************************	
//开关 I/O口配置
//设置引脚为上拉输入功能
//PA 15 key0 PC5 key1
*************************************************/	

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 							
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;					
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 							
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;					
	
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
}

