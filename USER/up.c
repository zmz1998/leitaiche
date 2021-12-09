#include "up.h"
extern u8 Ds[8];
extern u16 dirction;

/*************************************************
  函数名称: up_start
  函数功能: 启动登台
  被本函数调用的函数: 无        
  调用本函数的函数: main    
  输入参数说明:  无
  输出参数说明: 无       
  函数返回值: 无
  其它说明:无        
*************************************************/
void up_stage(void)
{
	EXTI->IMR &= ~(EXTI_Line2);
	EXTI->IMR &= ~(EXTI_Line4);
		move('B',2500);
	  delay_ms(900);
//	while(mseconds_1() < 100)
//		move('S',0);
	
//	EXTI->IMR |= (EXTI_Line0 | EXTI_Line1 | EXTI_Line2 | EXTI_Line3);//开启掉台检测
	EXTI->IMR |= EXTI_Line2;
	EXTI->IMR |= EXTI_Line4;
}

/*************************************************
  函数名称: up_against
  函数功能: 掉台后再次登台
  被本函数调用的函数: 无        
  调用本函数的函数: main    
  输入参数说明:  无
  输出参数说明: 无       
  函数返回值: 无
  其它说明:无        
*************************************************/
void up_against(void)
{
	move('S',0);
while(find_dirction()!=3)
  {
//		find_dirction();
//		delay_ms(5000);
//	printf("下右%d\r\n",Ds[0]);
//	printf("下后%d\r\n",Ds[1]);
//	printf("下左%d\r\n",Ds[2]);
//	printf("下前%d\r\n",Ds[3]);
//	printf("上右%d\r\n",Ds[4]);
//	printf("上后%d\r\n",Ds[5]);
//	printf("上左%d\r\n",Ds[6]);
//	printf("上前%d\r\n",Ds[7]);
//	printf("dirction:%d\r\n",dirction);
//  printf("find dirction:%d\r\n",find_dirction());
	switch(find_dirction())
		{
				case 1:						//前对擂台
				  move('B',600);
				  delay_ms(300);
				  turn('O',1200,450);    //  800 700
				  move('F',1000);
					delay_ms(1000);
				//printf("前%d\r\n",1);
					break;
				case 2:						//左对擂台
					turn('R',1200,250);     //800   320
				  move('F',1000);
					delay_ms(1000);
				//printf("左%d\r\n",2);
					break;
				case 3: 					//后对擂台
					move('F',1000);
					delay_ms(1000);
//				printf("后%d\r\n",3);
					break;
				case 4:						//右对擂台
					turn('L',1200,250);   //800    320
				  move('F',1000);
					delay_ms(1000);
				  break;
				case 5:						//前右对围墙
					move('B',800);       //B
					delay_ms(600);
					break;
				case 6:						//前左对围墙
					move('B',800);    //B
					delay_ms(600);
					break;
				case 7:						//后右对围墙
				  move('F',800);
					delay_ms(600);
					break;
				case 8:						//后左对围墙
					move('F',800);
					delay_ms(600);
					break;
				case 9:						//台上有敌人
					move('B',700);
				  delay_ms(200);
				  turn('L',1000,350);
				  move('B',800);
				  delay_ms(800);
					break;
				case 101:					  //ERROR
//				  move('B',800);
//				  delay_ms(300);
				  turn('O',1000,100); 

					move('F',1000);
				  delay_ms(300);
				//printf("error右%d\r\n",0);
					break;
			}
		}

    up_stage();
		turn('O',3000,150);
		move('S',0);
}
