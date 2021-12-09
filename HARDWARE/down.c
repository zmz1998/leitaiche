#include "down.h"
#define uint unsigned int
	u8 Ds[8] = {0};			//当前台下状态
	u16 dirction = 0;

int AD1 = 0;		//前左 红外光电
int AD2 = 0;		//前右 红外光电
int AD3 = 0;		//右   红外光电
int AD4 = 0;		//后右 红外光电
int AD5 = 0;		//后左 红外测距传感器
int AD6 = 0;		//左   红外测距传感器

int AD7 = 0;		//上前 红外测距传感器
int AD8 = 0;		//上右 红外测距传感器
int AD9 = 0;		//上后 红外测距传感器
int AD10 = 0;		//上左 红外测距传感器

int Qian = 0;		//前有无敌人
int You = 0;		//右有无敌人
int Hou = 0;		//后有无敌人
int Zuo = 0;		//左有无敌人
int Summ = 0;	 	//前后左右几个检测到	

uint Stage(void)//检测是否在台上
{
	Qian = Adc_GetIO(0)|Adc_GetIO(1);
	Zuo  = Adc_GetIO(11);
	Hou  = Adc_GetIO(4)|Adc_GetIO(10);
	You  = Adc_GetIO(2);
	Summ = Qian + Hou + Zuo + You;
		
	if (Summ>=2)
	{
		return 0;  //在台下
	}
	else
	{
		return 1;   //在台上
	}
	
}
/*************************************************
  函数名称: find_emeny
  函数功能: 寻找敌人
  被本函数调用的函数: 无        
  调用本函数的函数: main    
  输入参数说明:  无
  输出参数说明: 某个方向有无敌人       
  函数返回值: 无
  其它说明:无        
*************************************************/

uint find_enemy(void)
{
	static u16 enemy = 0;
	
	
	AD1 = Adc_GetIO(0);		//前左  红外测距传感器   1     A0
	AD2 = Adc_GetIO(1);		//前右  红外测距传感器   2     A1
	AD3 = Adc_GetIO(2);		//右    红外测距传感器   4     A2
	AD4 = Adc_GetIO(10);		//后右  红外测距传感器   8     C0
  AD5 = Adc_GetIO(4);		//后左  红外测距传感器   16    A4
	AD6 = Adc_GetIO(11);		//左    红外测距传感器   32    C1 
  enemy = AD6*32+AD5*16+AD4*8+AD3*4+AD2*2+AD1;
//	AD7 = Adc_GetValue(12);		//上前  红外测距传感器   64    C2
//  AD8 = Adc_GetValue(13);		//上右  红外测距传感器   128   C3
//	AD9 = Adc_GetValue(8);		//上后  红外测距传感器   256   B0
//	AD10= Adc_GetValue(9);		//上左  红外测距传感器   512   B1
	
	if (enemy==0)
	{
		return 0;  	//无敌人
	}
	if ((enemy==1)||(enemy==2)||(enemy==3))  
	{
		return 1;   //前方有敌人
	}
	if (enemy==4)
	{
		return 2;   //右侧有敌人
	}
	if ((enemy==8)||(enemy==16)||(enemy==24))
	{
		return 3;   //后方有敌人
	}
	if (enemy==32)
	{
		return 4;   //左侧有敌人
	}
	else
	{
		return 100;	//错误
	}
}
/*************************************************
  函数名称: find_dirction
  函数功能: 在台下检测朝向
  被本函数调用的函数: 无        
  调用本函数的函数: main    
  输入参数说明:  无
  输出参数说明: 方向       
  函数返回值: 无
  其它说明:无        
*************************************************/
uint find_dirction(void)
{
  dirction = 0;
	Ds[0]=Adc_GetIO(2);                  //1    下右
	Ds[1]=Adc_GetIO(4)||Adc_GetIO(10);    //2    下后
	Ds[2]=Adc_GetIO(11);                  //4    下左
	Ds[3]=Adc_GetIO(0)||Adc_GetIO(1);    //8    下前
	Ds[4]=Adc_GetIO(13);                       //16   上右
	Ds[5]=Adc_GetIO(9);                      //32   上后
	Ds[6]=Adc_GetIO(8);                      //64   上左
	Ds[7]=Adc_GetIO(12);                      //128  上前
dirction=128*Ds[7]+64*Ds[6]+32*Ds[5]+16*Ds[4]+8*Ds[3]+4*Ds[2]+2*Ds[1]+1*Ds[0];
	

	
/////////////////////////对擂台，一个测距检测到/////////////////////////
	if(dirction==42||dirction==8||dirction==34||dirction==10)//前测距和后红外
		{
			return 1;		//在台下，前方对擂台
		}
	
	if(dirction==20||dirction==84||dirction==21)
		{
			return 2;		//在台下，左侧对擂台
		}		
	
	if(dirction==2||dirction==136||dirction==138)//后测距前红外
		{
			return 3;		//在台下，后方对擂台
			
		}		
//	
	if(dirction==69||dirction==65||dirction==0)//左测距右红外
		{
			return 4;		//在台下，右侧对擂台
		}	
/////////////////////////////对围栏，两个相邻测距检测到/////////////////////////
////	
////	if((AD2 > 1000)&&(AD3 > 1000)&&(AD5 > FD)&&(AD6 < RD)&&(AD7 < BD)&&(AD8 > LD))
		if(dirction==137||dirction==153)
		{
			return 5;		//在台下，前右检测到围栏
		}	
//	if((AD3 > 1000)&&(AD4 > 1000)&&(AD5 > FD)&&(AD6 > RD)&&(AD7 < BD)&&(AD8 < LD))
		if(dirction==204)
		{
			return 6;		//在台下，前左检测到围栏
		}		

//	if((AD1 > 1000)&&(AD4 > 1000)&&(AD5 < FD)&&(AD6 > RD)&&(AD7 > BD)&&(AD8 < LD))
		if(dirction==51)
		{
			return 7;		//在台下，后右检测到围栏
		}	
//	if((AD1 > 1000)&&(AD2 > 1000)&&(AD5 < FD)&&(AD6 < RD)&&(AD7 > BD)&&(AD8 > LD))
		if(dirction==102)
		{
			return 8;		//在台下，后左检测到围栏 8
		}		

    if(dirction==170)
		{
			return 9;		//台上有敌人
		}		
//		
/////////////////////////////三侧有障碍，三个测距检测到/////////////////////////
////	if((AD5 > FD)&&(AD6 > RD)&&(AD7 < BD)&&(AD8 > LD))
//		if(dirction==45||dirction==43||dirction==62||dirction==105)
//		{
//			return 11;	//在台下，前方、左侧和右侧检测到围栏
//		}	
////	if((AD5 > FD)&&(AD6 > RD)&&(AD7 > BD)&&(AD8 < LD))
//		if(dirction==74||dirction==75)
//		{
//			return 12;	//在台下，前方、右侧和后方检测到围栏
//		}	
////	if((AD5 > FD)&&(AD6 < RD)&&(AD7 > BD)&&(AD8 > LD))
//		if(dirction==30||dirction==28)
//		{
//			return 13;	//在台下，前方、左侧和后方检测到围栏
//		}	
////	if((AD5 < FD)&&(AD6 > RD)&&(AD7 > BD)&&(AD8 > LD))
//		if(dirction==135||dirction==150||dirction==151)
//		{
//			return 14;	//在台下，右侧、左侧和后方检测到围栏
//		}	
//		
//		
///////////////////////////斜对擂台，两个红外光电检测到/////////////////////////前左后右
//	if(dirction==148)
//		{
//			return 15;	//在台下，前方和右侧对擂台
//		}	
//	if(dirction==101)
//		{
//			return 16;	//在台下，前方和左侧对擂台
//		}
//	if(dirction==187)
//		{
//			return 17;	//在台下，后方和右侧对擂台
//		}	
//	if(dirction==107)
//		{
//			return 18;	//在台下，后方和左侧对擂台
//		}
//	
	//////////////
	else
		{
			return 101;//错误
		}
		
}

