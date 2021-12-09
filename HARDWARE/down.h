#ifndef _down_H
#define _down_H	 

#define uint unsigned int
	
#include "sys.h"

#include "gpio.h"
#include "pwm.h"
#include "delay.h"

#include "Moto_Mode.h"
#include "adc.h"

#include "action.h"
#include "dengtai.h"
//#include "dengtai2.h"




void down(void);//初始化
//uint Stage();	 		//检测是否在台上	
uint find_enemy(void);//寻敌
uint find_dirction(void);
void up_stage(void);
uint Stage(void);
#endif
