#include "gpio.h"

//////////////////////////////////////////////////////////////////////////////////	 
//������Ӧ������̨������
//STM32F103Z оƬ
//GPIO ����
////////////////////////////////////////////////////////////////////////////////// 
	
/*************************************************
  ��������: Gpio_Init
  ��������: GPIO������
  �����������õĺ���: ��        
  ���ñ������ĺ���: ��    
  �������˵��: ��    
  �������˵��: ��       
  ��������ֵ: ��
  ����˵��:��        
*************************************************/
void Gpio_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;															//����GPIO��ʼ���ṹ�����

	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOA | 										//ʹ��GPIOAʱ��
													RCC_APB2Periph_GPIOB |										//ʹ��GPIOBʱ��	
													RCC_APB2Periph_GPIOC , ENABLE);						//ʹ��GPIOCʱ�� 	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;									//IO���ٶ�Ϊ50MHz

/*************************************************	
//ADC I/O��ʼ������
//��������Ϊģ�����빦��,��ȡ��������ģ��ֵ
//PA.0,1,2,3,4,5,6,7
//PB.0,1
//PC.0,1,2,3,4,5
*************************************************/	

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;											//ѡ��GPIOģʽΪģ������
//	 PA0~7����
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0|GPIO_Pin_1|
																 GPIO_Pin_2|GPIO_Pin_3|
																 GPIO_Pin_4|GPIO_Pin_5|
																 GPIO_Pin_6|GPIO_Pin_7;							//ѡ��PA0~PA7
	GPIO_Init(GPIOA, &GPIO_InitStructure);													  //����PA0~PA7Ϊģ������	
	// PB0~1����
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0|GPIO_Pin_1;							//ѡ��PB0~PB1
	GPIO_Init(GPIOB, &GPIO_InitStructure);														//����PB0~PB1Ϊģ������
//	// PC0~5����
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0|GPIO_Pin_1|
																 GPIO_Pin_2|GPIO_Pin_3|
																 GPIO_Pin_4|GPIO_Pin_5;							//ѡ��PC0~PC5
	GPIO_Init(GPIOC, &GPIO_InitStructure);	
//	
/*************************************************	
//PWM�� I/O������
//��������Ϊ�����������,���TIM4��PWM���岨��
*************************************************/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  									//ѡ��GPIOģʽ�����������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | 
																GPIO_Pin_7 |
																GPIO_Pin_8;
//																GPIO_Pin_9 ; 				
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  									//ѡ��GPIOģʽ����������� ����
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
			
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
/*************************************************	
//�������� I/O������
//��������Ϊ�������,����ߵ͵�ƽ
// PC.6,7,8,9����
*************************************************/	

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 							//ѡ��GPIOģʽΪ�������
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 |
																GPIO_Pin_7 |
																GPIO_Pin_8 | 
																GPIO_Pin_9 ;					
	
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	//��ʼ��IO
	GPIO_ResetBits(GPIOC,GPIO_Pin_6);
	GPIO_ResetBits(GPIOC,GPIO_Pin_7);
	GPIO_ResetBits(GPIOC,GPIO_Pin_8);
	GPIO_ResetBits(GPIOC,GPIO_Pin_9);
		
/*************************************************	
//�ⲿ�ж� I/O������
//��������Ϊ�������빦��
//PD.1,2,3,4
*************************************************/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | 
																GPIO_Pin_4;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 								//ѡ��GPIOģʽΪ�������룻
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
/*************************************************	
//���� I/O������
//��������Ϊ�������빦��
//PA 15 key0 PC5 key1
*************************************************/	

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 							
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;					
	
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 							
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;					
	
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
}

