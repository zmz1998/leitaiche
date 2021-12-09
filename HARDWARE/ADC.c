#include "adc.h"

u16 ADC_DMA_Value[16] = {0};	//ADC_DMA 存储地址
u16 last_ADValue[16]={0};		//上一次ADC值
u16 ADValue[16] = {0};			//当前ADC值
u16 adcv[15]={1100,1100,1100,1100,1100,1100,1100,1100,1100,1100,1100,1100,1100,1100,1100};           //adc设定值
#define adc_k		0.8					//滤波因子	
//////////////////////////////////////////////////////////////////////////////////	 
//本程序应用于擂台机器人
//STM32F103Z 芯片
//ADC 代码
////////////////////////////////////////////////////////////////////////////////// 
	
/*************************************************
  函数名称: ADC_DMAConfiguration
  函数功能: ADC的DMA的配置
  被本函数调用的函数: 无        
  调用本函数的函数: 无    
  输入参数说明: 无    
  输出参数说明: 无       
  函数返回值: 无
  其它说明:无        
*************************************************/

void ADC_DMAConfiguration(void)
{
	DMA_InitTypeDef DMA_InitStructure;																//定义DMA初始化结构体变量
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);								// 使能DMA1时钟
	// DMA通道1配置
	DMA_DeInit(DMA1_Channel1); 																				//复位DMA1通道1	
	DMA_InitStructure.DMA_PeripheralBaseAddr =(u32)( &(ADC1->DR));		//ADC1数据寄存器 	   （定义 DMA通道外设基地址=ADC1_DR）
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)ADValue;						  //获取ADC的数组 	   （定义DMA通道存储器地址）
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;								//片内外设作源头	   （指定外设为源地址）
	DMA_InitStructure.DMA_BufferSize = 16;														//每次DMA16个数据	   （定义DMA缓冲区大小为16）
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;	//外设地址不增加 	   （当前外设寄存器地址不变）
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;						//内存地址增加  	   （当前存储器地址不变）
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;	//半字 	   （定义外设数据宽度16位）
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;					//半字	   （定义存储器数据宽度16位）
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;										//普通模式				   （DMA通道操作模式位环形缓冲模式）
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;								//高优先级				   （DMA通道优先级高）
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;											//非内存到内存		 	 （禁止DMA通道存储器到存储器传输）
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);											//将配置载入DMA1通道1（初始化DMA通道1）
	
	DMA_ITConfig(DMA1_Channel1, DMA_IT_TC, ENABLE);										//DMA通道1传输完成中断
	
	DMA_Cmd(DMA1_Channel1, ENABLE);																		//使能DMA1通道1
}

/*************************************************
  函数名称: ADC_Init
  函数功能: ADC相关初始化
  被本函数调用的函数:   ADC_DMAConfiguration      
  调用本函数的函数: 无    
  输入参数说明: 无    
  输出参数说明: 无       
  函数返回值: 无
  其它说明:无        
*************************************************/
void Adc_Init(void)
{
	ADC_InitTypeDef ADC_InitStructure;																//定义ADC初始化结构体变量

  // 允许ADC  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1|RCC_APB2Periph_AFIO,ENABLE);								//使能ADC1时钟
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);   															//设置ADC分频因子6 72M/6=12,ADC最大时间不能超过14M
	
	ADC_DeInit(ADC1);   //复位
	// ADC1配置
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;								//规则同步模式   （ADC1和ADC2工作在独立模式）
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;											//连续多通道模式 （扫描模式<多通道>）
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;								//ADC转换工作在连续模式
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//转换由软件而不是外部触发启动
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;						//ADC数据右对齐
	ADC_InitStructure.ADC_NbrOfChannel = 16;													//16个通道
	ADC_Init(ADC1, &ADC_InitStructure);																//初始化ADC1
	
	ADC_Cmd(ADC1, ENABLE);																						//使能ADC1   
	ADC_ResetCalibration(ADC1);																				//重置ADC1校准寄存器
	while(ADC_GetResetCalibrationStatus(ADC1));												//等待ADC1校准重置完成
	ADC_StartCalibration(ADC1);																				//开始ADC1校准状态
	while(ADC_GetCalibrationStatus(ADC1));														//等待ADC1校准完成
	
	// 配置通道16的采样速度
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 	1, ADC_SampleTime_239Cycles5);		//A0		//ADC1选择信道9,音序器等级1,采样时间239.5个周期
	ADC_RegularChannelConfig(ADC1, ADC_Channel_1, 	2, ADC_SampleTime_239Cycles5);		//A1
	ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 	3, ADC_SampleTime_239Cycles5);		//A2
	ADC_RegularChannelConfig(ADC1, ADC_Channel_3, 	4, ADC_SampleTime_239Cycles5);		//A3
	ADC_RegularChannelConfig(ADC1, ADC_Channel_4, 	5, ADC_SampleTime_239Cycles5);		//A4
	ADC_RegularChannelConfig(ADC1, ADC_Channel_5, 	6, ADC_SampleTime_239Cycles5);		//A5
	ADC_RegularChannelConfig(ADC1, ADC_Channel_6, 	7, ADC_SampleTime_239Cycles5);		//A6
	ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 	8, ADC_SampleTime_239Cycles5);		//A7
	ADC_RegularChannelConfig(ADC1, ADC_Channel_8, 	9, ADC_SampleTime_239Cycles5);		//B0
	ADC_RegularChannelConfig(ADC1, ADC_Channel_9,  10, ADC_SampleTime_239Cycles5);  	//B1		 
	ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 11, ADC_SampleTime_239Cycles5);		//C0
	ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 12, ADC_SampleTime_239Cycles5);		//C1
	ADC_RegularChannelConfig(ADC1, ADC_Channel_12, 13, ADC_SampleTime_239Cycles5);		//C2
	ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 14, ADC_SampleTime_239Cycles5);		//C3
	ADC_RegularChannelConfig(ADC1, ADC_Channel_14, 15, ADC_SampleTime_239Cycles5);		//C4
	ADC_RegularChannelConfig(ADC1, ADC_Channel_15, 16, ADC_SampleTime_239Cycles5);		//C5
	
	// 人工打开ADC转换. 
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);								//使能ADC1软件开始转换
	
	ADC_DMAConfiguration();																//ADC DMA配置
	ADC_DMACmd(ADC1, ENABLE);															// 使能ADC1的DMA模式 
}

/*
*************************************************/				
u16 Adc_GetValue(u8 Channel)
{
	if(Channel < 16)
		return ADValue[Channel];
	else
		return 0;
}

/*************************************************
  函数名称: filter
  函数功能: 对通道进行滤波处理
  被本函数调用的函数: 无        
  调用本函数的函数:     
  输入参数说明: 通道，0~15
  输出参数说明: 无       
  函数返回值: 返回滤波后的数据
  其它说明:无        
*************************************************/
u16 filter(u8 Channel)   
{  
	u16 new_value,value;	
	value=last_ADValue[Channel];	
	new_value = ADValue[Channel];   
	return (adc_k * new_value + (1 - adc_k) * value); 
 }
/*************************************************
  函数名称: Adc_GetIO
  函数功能: 获取某路IO采样值
  被本函数调用的函数: 无        
  调用本函数的函数: 无    
  输入参数说明: Channel输入通道0~15   
  输出参数说明: 无       
  函数返回值: 返回值0或1
  其它说明:无        
*************************************************/
u8 Adc_GetIO(u8 Channel)
{
	return 	(filter(Channel) > adcv[Channel])?1:0;
	
	
}


/*************************************************
  函数名称: Adc_GetAllIO
  函数功能: 获取16路IO采样值
  被本函数调用的函数: 无        
  调用本函数的函数: 无    
  输入参数说明: 无
  输出参数说明: 无       
  函数返回值: 返回16路IO状态，16位无符号整形每一位对应一路
  其它说明:无        
*************************************************/
u16 Adc_GetAllIO(void)		
{
	u16 temp = 0;
	u8 i;
	for(i=0; i<6; i++)
	{
		if(ADValue[i] > 1200)
			temp |= (0x01<<i);
	}
	return temp;	
}
 
