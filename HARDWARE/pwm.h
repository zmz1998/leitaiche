#ifndef __pwm_H
#define __pwm_H
#include "stm32f10x.h"
#include "sys.h"


void TIM4_PWM_Init(u16 arr,u16 psc);	//TIM4��PWM��س�ʼ��
void TIM1_PWM_Init(u16 arr,u16 psc);	//TIM1��PWM��س�ʼ��
#define  PWM_L 	TIM4->CCR1
#define  PWM_R 	TIM4->CCR2
#define  PWM4_3 TIM4->CCR3
#define  PWM4_4 TIM4->CCR4
#define  PWMh   TIM1->CCR1

#endif
