#include "pwm.h"

//////////////////////////////////////////////////////////////////////////////////	 
//������Ӧ������̨������
//STM32F103Z оƬ
//PWM  ��������			   
////////////////////////////////////////////////////////////////////////////////// 	  

/*************************************************
  ��������: TIM4_PWM_Init
  ��������: TIM4��PWM��س�ʼ��
  �����������õĺ���: ��        
  ���ñ������ĺ���: ��    
  �������˵��:  arr���Զ���װֵ��psc��ʱ��Ԥ��Ƶ��
  �������˵��: ��       
  ��������ֵ: ��
  ����˵��:��        
*************************************************/

void TIM4_PWM_Init(u16 arr,u16 psc)
{  
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);// 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);  //ʹ��GPIO����ʱ��ʹ��                                                                     	                                                                  	
 
	TIM_TimeBaseStructure.TIM_Period = arr; 											//��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 80K
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 										//����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision =0; 									//����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	//TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); 							//����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 						//ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
	
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 899; 													//���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 		//�������:TIM����Ƚϼ��Ը�
	
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);  										//����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
  TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

  TIM_OC2Init(TIM4, &TIM_OCInitStructure);
  TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);

  TIM_OC3Init(TIM4, &TIM_OCInitStructure);
  TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);

  TIM_OC4Init(TIM4, &TIM_OCInitStructure);
  TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);

  TIM_CtrlPWMOutputs(TIM4,ENABLE);					//MOE �����ʹ��	
  TIM_ARRPreloadConfig(TIM4, ENABLE); 			//ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
	TIM_Cmd(TIM4, ENABLE);  									//ʹ��TIM1
  
}

/*************************************************
  ��������: TIM1_PWM_Init
  ��������: TIM1��PWM��س�ʼ��
  �����������õĺ���: ��        
  ���ñ������ĺ���: ��    
  �������˵��:  arr���Զ���װֵ��psc��ʱ��Ԥ��Ƶ��
  �������˵��: ��       
  ��������ֵ: ��
  ����˵��:��        
*************************************************/
void TIM1_PWM_Init(u16 arr,u16 psc)
{  
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);// 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);  //ʹ��GPIO����ʱ��ʹ��                                                                     	                                                                  	
 
	TIM_TimeBaseStructure.TIM_Period = arr; 											//��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 80K
	TIM_TimeBaseStructure.TIM_Prescaler =psc; 										//����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  ����Ƶ
	TIM_TimeBaseStructure.TIM_ClockDivision =0; 									//����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	//TIM���ϼ���ģʽ
//	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;                //���ظ�
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); 							//����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; 						//ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
	
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 899; 													//���ô�װ�벶��ȽϼĴ���������ֵ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; 		//�������:TIM����Ƚϼ��Ը�
  TIM_OCInitStructure.TIM_OCIdleState=TIM_OCIdleState_Set;
	
	TIM_OC1Init(TIM1, &TIM_OCInitStructure);  										//����TIM_OCInitStruct��ָ���Ĳ�����ʼ������TIMx
  TIM_OC1PreloadConfig(TIM1, TIM_OCPreload_Enable);

  TIM_OC2Init(TIM1, &TIM_OCInitStructure);
  TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);

  TIM_OC3Init(TIM1, &TIM_OCInitStructure);
  TIM_OC3PreloadConfig(TIM1, TIM_OCPreload_Enable);

  TIM_OC4Init(TIM1, &TIM_OCInitStructure);
  TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);

  TIM_CtrlPWMOutputs(TIM1,ENABLE);					//MOE �����ʹ��	
  TIM_ARRPreloadConfig(TIM1, ENABLE); 			//ʹ��TIMx��ARR�ϵ�Ԥװ�ؼĴ���
	TIM_Cmd(TIM1, ENABLE);  									//ʹ��TIM1
  
}
