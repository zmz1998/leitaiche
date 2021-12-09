#include "adc.h"

u16 ADC_DMA_Value[16] = {0};	//ADC_DMA �洢��ַ
u16 last_ADValue[16]={0};		//��һ��ADCֵ
u16 ADValue[16] = {0};			//��ǰADCֵ
u16 adcv[15]={1100,1100,1100,1100,1100,1100,1100,1100,1100,1100,1100,1100,1100,1100,1100};           //adc�趨ֵ
#define adc_k		0.8					//�˲�����	
//////////////////////////////////////////////////////////////////////////////////	 
//������Ӧ������̨������
//STM32F103Z оƬ
//ADC ����
////////////////////////////////////////////////////////////////////////////////// 
	
/*************************************************
  ��������: ADC_DMAConfiguration
  ��������: ADC��DMA������
  �����������õĺ���: ��        
  ���ñ������ĺ���: ��    
  �������˵��: ��    
  �������˵��: ��       
  ��������ֵ: ��
  ����˵��:��        
*************************************************/

void ADC_DMAConfiguration(void)
{
	DMA_InitTypeDef DMA_InitStructure;																//����DMA��ʼ���ṹ�����
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);								// ʹ��DMA1ʱ��
	// DMAͨ��1����
	DMA_DeInit(DMA1_Channel1); 																				//��λDMA1ͨ��1	
	DMA_InitStructure.DMA_PeripheralBaseAddr =(u32)( &(ADC1->DR));		//ADC1���ݼĴ��� 	   ������ DMAͨ���������ַ=ADC1_DR��
	DMA_InitStructure.DMA_MemoryBaseAddr = (u32)ADValue;						  //��ȡADC������ 	   ������DMAͨ���洢����ַ��
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;								//Ƭ��������Դͷ	   ��ָ������ΪԴ��ַ��
	DMA_InitStructure.DMA_BufferSize = 16;														//ÿ��DMA16������	   ������DMA��������СΪ16��
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;	//�����ַ������ 	   ����ǰ����Ĵ�����ַ���䣩
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;						//�ڴ��ַ����  	   ����ǰ�洢����ַ���䣩
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;	//���� 	   �������������ݿ��16λ��
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;					//����	   ������洢�����ݿ��16λ��
	DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;										//��ͨģʽ				   ��DMAͨ������ģʽλ���λ���ģʽ��
	DMA_InitStructure.DMA_Priority = DMA_Priority_High;								//�����ȼ�				   ��DMAͨ�����ȼ��ߣ�
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;											//���ڴ浽�ڴ�		 	 ����ֹDMAͨ���洢�����洢�����䣩
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);											//����������DMA1ͨ��1����ʼ��DMAͨ��1��
	
	DMA_ITConfig(DMA1_Channel1, DMA_IT_TC, ENABLE);										//DMAͨ��1��������ж�
	
	DMA_Cmd(DMA1_Channel1, ENABLE);																		//ʹ��DMA1ͨ��1
}

/*************************************************
  ��������: ADC_Init
  ��������: ADC��س�ʼ��
  �����������õĺ���:   ADC_DMAConfiguration      
  ���ñ������ĺ���: ��    
  �������˵��: ��    
  �������˵��: ��       
  ��������ֵ: ��
  ����˵��:��        
*************************************************/
void Adc_Init(void)
{
	ADC_InitTypeDef ADC_InitStructure;																//����ADC��ʼ���ṹ�����

  // ����ADC  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1|RCC_APB2Periph_AFIO,ENABLE);								//ʹ��ADC1ʱ��
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);   															//����ADC��Ƶ����6 72M/6=12,ADC���ʱ�䲻�ܳ���14M
	
	ADC_DeInit(ADC1);   //��λ
	// ADC1����
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;								//����ͬ��ģʽ   ��ADC1��ADC2�����ڶ���ģʽ��
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;											//������ͨ��ģʽ ��ɨ��ģʽ<��ͨ��>��
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;								//ADCת������������ģʽ
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;	//ת��������������ⲿ��������
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;						//ADC�����Ҷ���
	ADC_InitStructure.ADC_NbrOfChannel = 16;													//16��ͨ��
	ADC_Init(ADC1, &ADC_InitStructure);																//��ʼ��ADC1
	
	ADC_Cmd(ADC1, ENABLE);																						//ʹ��ADC1   
	ADC_ResetCalibration(ADC1);																				//����ADC1У׼�Ĵ���
	while(ADC_GetResetCalibrationStatus(ADC1));												//�ȴ�ADC1У׼�������
	ADC_StartCalibration(ADC1);																				//��ʼADC1У׼״̬
	while(ADC_GetCalibrationStatus(ADC1));														//�ȴ�ADC1У׼���
	
	// ����ͨ��16�Ĳ����ٶ�
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 	1, ADC_SampleTime_239Cycles5);		//A0		//ADC1ѡ���ŵ�9,�������ȼ�1,����ʱ��239.5������
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
	
	// �˹���ADCת��. 
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);								//ʹ��ADC1�����ʼת��
	
	ADC_DMAConfiguration();																//ADC DMA����
	ADC_DMACmd(ADC1, ENABLE);															// ʹ��ADC1��DMAģʽ 
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
  ��������: filter
  ��������: ��ͨ�������˲�����
  �����������õĺ���: ��        
  ���ñ������ĺ���:     
  �������˵��: ͨ����0~15
  �������˵��: ��       
  ��������ֵ: �����˲��������
  ����˵��:��        
*************************************************/
u16 filter(u8 Channel)   
{  
	u16 new_value,value;	
	value=last_ADValue[Channel];	
	new_value = ADValue[Channel];   
	return (adc_k * new_value + (1 - adc_k) * value); 
 }
/*************************************************
  ��������: Adc_GetIO
  ��������: ��ȡĳ·IO����ֵ
  �����������õĺ���: ��        
  ���ñ������ĺ���: ��    
  �������˵��: Channel����ͨ��0~15   
  �������˵��: ��       
  ��������ֵ: ����ֵ0��1
  ����˵��:��        
*************************************************/
u8 Adc_GetIO(u8 Channel)
{
	return 	(filter(Channel) > adcv[Channel])?1:0;
	
	
}


/*************************************************
  ��������: Adc_GetAllIO
  ��������: ��ȡ16·IO����ֵ
  �����������õĺ���: ��        
  ���ñ������ĺ���: ��    
  �������˵��: ��
  �������˵��: ��       
  ��������ֵ: ����16·IO״̬��16λ�޷�������ÿһλ��Ӧһ·
  ����˵��:��        
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
 
