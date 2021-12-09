#ifndef __ADC_H
#define __ADC_H	
#include "sys.h"
#include "delay.h"
#include "stm32f10x.h"

void ADC_DMAConfiguration(void);	//ADC��DMA������
void Adc_Init(void);							//ADC��س�ʼ��
u16  Adc_GetValue(u8 Channel);		//��ȡĳ·AD����ֵ
u8   Adc_GetIO(u8 Channel);				//��ȡĳ·IO����ֵ
u16  Adc_GetAllIO(void); 					//��ȡ16·IO����ֵ

 
#endif 
