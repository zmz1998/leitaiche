#include "up.h"
extern u8 Ds[8];
extern u16 dirction;

/*************************************************
  ��������: up_start
  ��������: ������̨
  �����������õĺ���: ��        
  ���ñ������ĺ���: main    
  �������˵��:  ��
  �������˵��: ��       
  ��������ֵ: ��
  ����˵��:��        
*************************************************/
void up_stage(void)
{
	EXTI->IMR &= ~(EXTI_Line2);
	EXTI->IMR &= ~(EXTI_Line4);
		move('B',2500);
	  delay_ms(900);
//	while(mseconds_1() < 100)
//		move('S',0);
	
//	EXTI->IMR |= (EXTI_Line0 | EXTI_Line1 | EXTI_Line2 | EXTI_Line3);//������̨���
	EXTI->IMR |= EXTI_Line2;
	EXTI->IMR |= EXTI_Line4;
}

/*************************************************
  ��������: up_against
  ��������: ��̨���ٴε�̨
  �����������õĺ���: ��        
  ���ñ������ĺ���: main    
  �������˵��:  ��
  �������˵��: ��       
  ��������ֵ: ��
  ����˵��:��        
*************************************************/
void up_against(void)
{
	move('S',0);
while(find_dirction()!=3)
  {
//		find_dirction();
//		delay_ms(5000);
//	printf("����%d\r\n",Ds[0]);
//	printf("�º�%d\r\n",Ds[1]);
//	printf("����%d\r\n",Ds[2]);
//	printf("��ǰ%d\r\n",Ds[3]);
//	printf("����%d\r\n",Ds[4]);
//	printf("�Ϻ�%d\r\n",Ds[5]);
//	printf("����%d\r\n",Ds[6]);
//	printf("��ǰ%d\r\n",Ds[7]);
//	printf("dirction:%d\r\n",dirction);
//  printf("find dirction:%d\r\n",find_dirction());
	switch(find_dirction())
		{
				case 1:						//ǰ����̨
				  move('B',600);
				  delay_ms(300);
				  turn('O',1200,450);    //  800 700
				  move('F',1000);
					delay_ms(1000);
				//printf("ǰ%d\r\n",1);
					break;
				case 2:						//�����̨
					turn('R',1200,250);     //800   320
				  move('F',1000);
					delay_ms(1000);
				//printf("��%d\r\n",2);
					break;
				case 3: 					//�����̨
					move('F',1000);
					delay_ms(1000);
//				printf("��%d\r\n",3);
					break;
				case 4:						//�Ҷ���̨
					turn('L',1200,250);   //800    320
				  move('F',1000);
					delay_ms(1000);
				  break;
				case 5:						//ǰ�Ҷ�Χǽ
					move('B',800);       //B
					delay_ms(600);
					break;
				case 6:						//ǰ���Χǽ
					move('B',800);    //B
					delay_ms(600);
					break;
				case 7:						//���Ҷ�Χǽ
				  move('F',800);
					delay_ms(600);
					break;
				case 8:						//�����Χǽ
					move('F',800);
					delay_ms(600);
					break;
				case 9:						//̨���е���
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
				//printf("error��%d\r\n",0);
					break;
			}
		}

    up_stage();
		turn('O',3000,150);
		move('S',0);
}
