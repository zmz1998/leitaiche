#include "diaotaijiance.h"
#include "gpio.h"
#include "pwm.h"
#include "delay.h"
#include "action.h"
#include "dengtai.h"
#include "dengtai2.h"
#include "Moto_Mode.h"

void diaotaijiance(void)
{
	//ǰ�����⵽��
	
	if((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10))==0&&(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11))==0)
	{
		 action_disable();
		GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	  GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		GPIO_SetBits(GPIOA,GPIO_Pin_3);
    delay_ms(100);
		
		PWM2 = 125;     //���ϣ�
	  PWM4 = 150;    //���ϣ�
	  delay_ms(500);
		
		GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
		GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	  GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
		GPIO_SetBits(GPIOA,GPIO_Pin_3); 
	  TIM_SetCompare1(TIM4,700);    //B6;
    TIM_SetCompare2(TIM4,700);		//B7;
		delay_ms(500);
		
		GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	  GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		delay_ms(100);
		
	
		if((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5))==0||(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6))==0)
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
	    TIM_SetCompare1(TIM4,700);    //B6;
      TIM_SetCompare2(TIM4,700);		//B7;
			delay_ms(1000);
			
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		  delay_ms(100);
			
				//�������ӣ�
		while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5))==1||(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6))==1)
		{
				while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6))==1)
		{
			
			     GPIO_SetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
		       GPIO_ResetBits(GPIOA,GPIO_Pin_12); 
	         GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
		       GPIO_SetBits(GPIOA,GPIO_Pin_3); 
	         TIM_SetCompare1(TIM4,700);    //B6;
           TIM_SetCompare2(TIM4,700);		//B7;
					 delay_ms(100);
		  
			     GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		       GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	         GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		       GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		       delay_ms(100);
				
		}
		
		while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5))==1)
		{
			      GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
		        GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	          GPIO_SetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
		        GPIO_ResetBits(GPIOA,GPIO_Pin_3); 
	          TIM_SetCompare1(TIM4,700);    //B6;
            TIM_SetCompare2(TIM4,700);		//B7;
					  delay_ms(100);
		  
			     GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		       GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	         GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		       GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		       delay_ms(100);
				
		}
		
		}
	  
		
		  GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		  delay_ms(100);
		
			dengtai2();
		}
		
		//if((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5))==1&&(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6))==1)
		else
		{
			while((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12))==1||(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13))==1)
		{
			turnright();
		}
			/*while((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10))==0||(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11))==0)
			{
				turnright();
			}*/
			
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		  delay_ms(300);
			
			/*while((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10))==1||(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11))==1)
			{
				turnright();
			}*/
				while(1)
		{
			turnright();
			if((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12))==1||(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13))==1)
				break;
		}
		delay_ms(300);
			
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		  delay_ms(300);
			
			//ת���ǰ��һ�ξ���Ϊ��������׼����
			
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
	    TIM_SetCompare1(TIM4,700);    //B6;
      TIM_SetCompare2(TIM4,700);		//B7;
			delay_ms(1000);
			
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		  delay_ms(300);
			
	
				//�������ӣ�
		while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5))==1||(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6))==1)
		{
				while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6))==1)
		{
			
			     GPIO_SetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
		       GPIO_ResetBits(GPIOA,GPIO_Pin_12); 
	         GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
		       GPIO_SetBits(GPIOA,GPIO_Pin_3); 
	         TIM_SetCompare1(TIM4,700);    //B6;
           TIM_SetCompare2(TIM4,700);		//B7;
					 delay_ms(100);
		  
			     GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		       GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	         GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		       GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		       delay_ms(100);
				
		}
		
		while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5))==1)
		{
			      GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
		        GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	          GPIO_SetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
		        GPIO_ResetBits(GPIOA,GPIO_Pin_3); 
	          TIM_SetCompare1(TIM4,700);    //B6;
            TIM_SetCompare2(TIM4,700);		//B7;
					  delay_ms(100);
		  
			     GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		       GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	         GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		       GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		       delay_ms(100);
				
		}
		
		}
	  
		
		 GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		 GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	   GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		 GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		 delay_ms(100);
			
			dengtai2();
		}
	}
	
	
	//���Ҽ�⵽��
	
	while((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12))==0&&(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13))==0)
	{
		action_disable();
		GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	  GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		PWM2 = 125;     //���ϣ�
	  PWM4 = 150;    //���ϣ�
	  delay_ms(500);
		
		while((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12))==0||(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13))==0)
		{
			turnright();
		}
		  GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		  delay_ms(300);
		
		while(1)
		{
			turnright();
			if((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12))==1||(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13))==1)
				break;
		}
		
		  GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		  delay_ms(300);
		
		/*while((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12))==0||(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13))==0)
		{
			turnright();
		}*/
		
		  GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		  delay_ms(300);
		
      //ת���ǰ����		
		
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
	    TIM_SetCompare1(TIM4,700);    //B6;
      TIM_SetCompare2(TIM4,700);		//B7;
			delay_ms(1000);
			
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		  delay_ms(300);
			
			if((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5))==0||(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6))==0)
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
	    TIM_SetCompare1(TIM4,700);    //B6;
      TIM_SetCompare2(TIM4,700);		//B7;
			delay_ms(50);
			
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		  delay_ms(300);
			
			
				//�������ӣ�
		while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5))==1||(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6))==1)
		{
				while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6))==1)
		{
			
			     GPIO_SetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
		       GPIO_ResetBits(GPIOA,GPIO_Pin_12); 
	         GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
		       GPIO_SetBits(GPIOA,GPIO_Pin_3); 
	         TIM_SetCompare1(TIM4,700);    //B6;
           TIM_SetCompare2(TIM4,700);		//B7;
					 delay_ms(100);
		  
			     GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		       GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	         GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		       GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		       delay_ms(100);
				
		}
		
		while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5))==1)
		{
			      GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
		        GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	          GPIO_SetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
		        GPIO_ResetBits(GPIOA,GPIO_Pin_3); 
	          TIM_SetCompare1(TIM4,700);    //B6;
            TIM_SetCompare2(TIM4,700);		//B7;
					  delay_ms(100);
		  
			     GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		       GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	         GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		       GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		       delay_ms(100);
				
		}
		
		}
	  
			
		
		 GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		 GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	   GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		 GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		 delay_ms(100);
			
		 dengtai2();
		 
		}
		
		if((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5))==1&&(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6))==1)
		{
			while((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12))==1||(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13))==1)
			{
				turnright();
			}
			
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		  delay_ms(300);
			
			while((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12))==0||(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13))==0)
			{
				turnright();
			}
			
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		  delay_ms(100);
			
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
	    TIM_SetCompare1(TIM4,700);    //B6;
      TIM_SetCompare2(TIM4,700);		//B7;
			delay_ms(1000);
			
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		  delay_ms(100);
			
			
				//�������ӣ�
		while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5))==1||(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6))==1)
		{
				while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6))==1)
		{
			
			     GPIO_SetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
		       GPIO_ResetBits(GPIOA,GPIO_Pin_12); 
	         GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
		       GPIO_SetBits(GPIOA,GPIO_Pin_3); 
	         TIM_SetCompare1(TIM4,700);    //B6;
           TIM_SetCompare2(TIM4,700);		//B7;
					 delay_ms(100);
		  
			     GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		       GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	         GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		       GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		       delay_ms(100);
				
		}
		
		while((GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5))==1)
		{
			      GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
		        GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	          GPIO_SetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
		        GPIO_ResetBits(GPIOA,GPIO_Pin_3); 
	          TIM_SetCompare1(TIM4,700);    //B6;
            TIM_SetCompare2(TIM4,700);		//B7;
					  delay_ms(100);
		  
			     GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		       GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	         GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		       GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		       delay_ms(100);
				
		}
		
		}
	  
		
		 GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		 GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	   GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		 GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		 delay_ms(100);
			
			dengtai2();
			
		}
	}
	if(PBin(10)==0&&PBin(11)==0)
	{
		 movedown();
     delay_ms(180);
		PWM2 = 125;     //���ϣ�
	  PWM4 = 150;    //���ϣ�
	  delay_ms(500);
	   while(1)//PBin(12)==1||PBin(13)==1
		{
			turnright();
			if(PBin(12)==0&&PBin(13)==0)
				break;
		}
			/*while((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10))==0||(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11))==0)
			{
				turnright();
			}*/
			
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		  delay_ms(300);
			
			/*while((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10))==1||(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11))==1)
			{
				turnright();
			}*/
				while(1)
		{
			turnright();
			if((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12))==1&&(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13))==1)
				break;
		}
		delay_ms(100);
			
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		  delay_ms(300);
			
			//ת���ǰ��һ�ξ���Ϊ��������׼����
			
			GPIO_ResetBits(GPIOA,GPIO_Pin_11);	  //��ת��  ǰ��
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_ResetBits(GPIOA,GPIO_Pin_2);	  //��ת��  ǰ�ң�
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
	    TIM_SetCompare1(TIM4,700);    //B6;
      TIM_SetCompare2(TIM4,700);		//B7;
			delay_ms(1000);
			
			GPIO_SetBits(GPIOA,GPIO_Pin_11);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_12); 
	    GPIO_SetBits(GPIOA,GPIO_Pin_2);	  
		  GPIO_SetBits(GPIOA,GPIO_Pin_3); 
		  delay_ms(300);
			dengtai2();
	}
	
}
