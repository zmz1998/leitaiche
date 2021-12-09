#ifndef __duoji_H
#define __duoji_H
#include "sys.h"



void TIM3_PWM_Init(u16 arr,u16 psc);


#define PWM1   TIM3->CCR1
#define PWM2   TIM3->CCR2
#define PWM3   TIM3->CCR3
#define PWM4   TIM3->CCR4

#endif
