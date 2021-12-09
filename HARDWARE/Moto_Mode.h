#ifndef __Moto_Mode_H
#define __Moto_Mode_H	

#include "sys.h"
#include "pwm.h"
#include "delay.h"

void move(char mode,u16 speed);
void turn(char mode,u16 speed,u16 time);
void handao(u16 speed);
		 				    
#endif
