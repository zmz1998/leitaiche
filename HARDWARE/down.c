#include "down.h"
#define uint unsigned int
	u8 Ds[8] = {0};			//��ǰ̨��״̬
	u16 dirction = 0;

int AD1 = 0;		//ǰ�� ������
int AD2 = 0;		//ǰ�� ������
int AD3 = 0;		//��   ������
int AD4 = 0;		//���� ������
int AD5 = 0;		//���� �����ഫ����
int AD6 = 0;		//��   �����ഫ����

int AD7 = 0;		//��ǰ �����ഫ����
int AD8 = 0;		//���� �����ഫ����
int AD9 = 0;		//�Ϻ� �����ഫ����
int AD10 = 0;		//���� �����ഫ����

int Qian = 0;		//ǰ���޵���
int You = 0;		//�����޵���
int Hou = 0;		//�����޵���
int Zuo = 0;		//�����޵���
int Summ = 0;	 	//ǰ�����Ҽ�����⵽	

uint Stage(void)//����Ƿ���̨��
{
	Qian = Adc_GetIO(0)|Adc_GetIO(1);
	Zuo  = Adc_GetIO(11);
	Hou  = Adc_GetIO(4)|Adc_GetIO(10);
	You  = Adc_GetIO(2);
	Summ = Qian + Hou + Zuo + You;
		
	if (Summ>=2)
	{
		return 0;  //��̨��
	}
	else
	{
		return 1;   //��̨��
	}
	
}
/*************************************************
  ��������: find_emeny
  ��������: Ѱ�ҵ���
  �����������õĺ���: ��        
  ���ñ������ĺ���: main    
  �������˵��:  ��
  �������˵��: ĳ���������޵���       
  ��������ֵ: ��
  ����˵��:��        
*************************************************/

uint find_enemy(void)
{
	static u16 enemy = 0;
	
	
	AD1 = Adc_GetIO(0);		//ǰ��  �����ഫ����   1     A0
	AD2 = Adc_GetIO(1);		//ǰ��  �����ഫ����   2     A1
	AD3 = Adc_GetIO(2);		//��    �����ഫ����   4     A2
	AD4 = Adc_GetIO(10);		//����  �����ഫ����   8     C0
  AD5 = Adc_GetIO(4);		//����  �����ഫ����   16    A4
	AD6 = Adc_GetIO(11);		//��    �����ഫ����   32    C1 
  enemy = AD6*32+AD5*16+AD4*8+AD3*4+AD2*2+AD1;
//	AD7 = Adc_GetValue(12);		//��ǰ  �����ഫ����   64    C2
//  AD8 = Adc_GetValue(13);		//����  �����ഫ����   128   C3
//	AD9 = Adc_GetValue(8);		//�Ϻ�  �����ഫ����   256   B0
//	AD10= Adc_GetValue(9);		//����  �����ഫ����   512   B1
	
	if (enemy==0)
	{
		return 0;  	//�޵���
	}
	if ((enemy==1)||(enemy==2)||(enemy==3))  
	{
		return 1;   //ǰ���е���
	}
	if (enemy==4)
	{
		return 2;   //�Ҳ��е���
	}
	if ((enemy==8)||(enemy==16)||(enemy==24))
	{
		return 3;   //���е���
	}
	if (enemy==32)
	{
		return 4;   //����е���
	}
	else
	{
		return 100;	//����
	}
}
/*************************************************
  ��������: find_dirction
  ��������: ��̨�¼�⳯��
  �����������õĺ���: ��        
  ���ñ������ĺ���: main    
  �������˵��:  ��
  �������˵��: ����       
  ��������ֵ: ��
  ����˵��:��        
*************************************************/
uint find_dirction(void)
{
  dirction = 0;
	Ds[0]=Adc_GetIO(2);                  //1    ����
	Ds[1]=Adc_GetIO(4)||Adc_GetIO(10);    //2    �º�
	Ds[2]=Adc_GetIO(11);                  //4    ����
	Ds[3]=Adc_GetIO(0)||Adc_GetIO(1);    //8    ��ǰ
	Ds[4]=Adc_GetIO(13);                       //16   ����
	Ds[5]=Adc_GetIO(9);                      //32   �Ϻ�
	Ds[6]=Adc_GetIO(8);                      //64   ����
	Ds[7]=Adc_GetIO(12);                      //128  ��ǰ
dirction=128*Ds[7]+64*Ds[6]+32*Ds[5]+16*Ds[4]+8*Ds[3]+4*Ds[2]+2*Ds[1]+1*Ds[0];
	

	
/////////////////////////����̨��һ������⵽/////////////////////////
	if(dirction==42||dirction==8||dirction==34||dirction==10)//ǰ���ͺ����
		{
			return 1;		//��̨�£�ǰ������̨
		}
	
	if(dirction==20||dirction==84||dirction==21)
		{
			return 2;		//��̨�£�������̨
		}		
	
	if(dirction==2||dirction==136||dirction==138)//����ǰ����
		{
			return 3;		//��̨�£��󷽶���̨
			
		}		
//	
	if(dirction==69||dirction==65||dirction==0)//�����Һ���
		{
			return 4;		//��̨�£��Ҳ����̨
		}	
/////////////////////////////��Χ�����������ڲ���⵽/////////////////////////
////	
////	if((AD2 > 1000)&&(AD3 > 1000)&&(AD5 > FD)&&(AD6 < RD)&&(AD7 < BD)&&(AD8 > LD))
		if(dirction==137||dirction==153)
		{
			return 5;		//��̨�£�ǰ�Ҽ�⵽Χ��
		}	
//	if((AD3 > 1000)&&(AD4 > 1000)&&(AD5 > FD)&&(AD6 > RD)&&(AD7 < BD)&&(AD8 < LD))
		if(dirction==204)
		{
			return 6;		//��̨�£�ǰ���⵽Χ��
		}		

//	if((AD1 > 1000)&&(AD4 > 1000)&&(AD5 < FD)&&(AD6 > RD)&&(AD7 > BD)&&(AD8 < LD))
		if(dirction==51)
		{
			return 7;		//��̨�£����Ҽ�⵽Χ��
		}	
//	if((AD1 > 1000)&&(AD2 > 1000)&&(AD5 < FD)&&(AD6 < RD)&&(AD7 > BD)&&(AD8 > LD))
		if(dirction==102)
		{
			return 8;		//��̨�£������⵽Χ�� 8
		}		

    if(dirction==170)
		{
			return 9;		//̨���е���
		}		
//		
/////////////////////////////�������ϰ�����������⵽/////////////////////////
////	if((AD5 > FD)&&(AD6 > RD)&&(AD7 < BD)&&(AD8 > LD))
//		if(dirction==45||dirction==43||dirction==62||dirction==105)
//		{
//			return 11;	//��̨�£�ǰ���������Ҳ��⵽Χ��
//		}	
////	if((AD5 > FD)&&(AD6 > RD)&&(AD7 > BD)&&(AD8 < LD))
//		if(dirction==74||dirction==75)
//		{
//			return 12;	//��̨�£�ǰ�����Ҳ�ͺ󷽼�⵽Χ��
//		}	
////	if((AD5 > FD)&&(AD6 < RD)&&(AD7 > BD)&&(AD8 > LD))
//		if(dirction==30||dirction==28)
//		{
//			return 13;	//��̨�£�ǰ�������ͺ󷽼�⵽Χ��
//		}	
////	if((AD5 < FD)&&(AD6 > RD)&&(AD7 > BD)&&(AD8 > LD))
//		if(dirction==135||dirction==150||dirction==151)
//		{
//			return 14;	//��̨�£��Ҳࡢ���ͺ󷽼�⵽Χ��
//		}	
//		
//		
///////////////////////////б����̨�������������⵽/////////////////////////ǰ�����
//	if(dirction==148)
//		{
//			return 15;	//��̨�£�ǰ�����Ҳ����̨
//		}	
//	if(dirction==101)
//		{
//			return 16;	//��̨�£�ǰ����������̨
//		}
//	if(dirction==187)
//		{
//			return 17;	//��̨�£��󷽺��Ҳ����̨
//		}	
//	if(dirction==107)
//		{
//			return 18;	//��̨�£��󷽺�������̨
//		}
//	
	//////////////
	else
		{
			return 101;//����
		}
		
}

