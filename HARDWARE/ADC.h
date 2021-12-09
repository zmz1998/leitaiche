#ifndef __ADC_H
#define __ADC_H	
#include "sys.h"
#include "delay.h"
#include "stm32f10x.h"

void ADC_DMAConfiguration(void);	//ADC的DMA的配置
void Adc_Init(void);							//ADC相关初始化
u16  Adc_GetValue(u8 Channel);		//获取某路AD采样值
u8   Adc_GetIO(u8 Channel);				//获取某路IO采样值
u16  Adc_GetAllIO(void); 					//获取16路IO采样值

 
#endif 
