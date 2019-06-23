#include "stm32f10x.h"
#include "usart.h"
#include "oled.h"
#include "delay.h"
#include "adc.h"

 u16 adc0,  adc1;
extern unsigned char usart1Buf[9];
extern unsigned char usart2Buf[9];

void hard_init()
{
		delay_init();	 
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    Adc_Init();
    OLED_Init();
    OLED_Clear1();
		Usart1_Init(9600); 
		Usart2_Init(9600);
		Usart3_Init(9600);
}

 int main(void)
 {		
	 //电流计算量
    float I1 = 0;
		float I2 = 0;
	  //电压计算量
		float temp0 = 0;
		float temp1 = 0;
	  //光照计算量
	  float Lux1 = 0;
	  float Lux2 = 0;
	  //光照整型辅助计算 
	  unsigned short Lx1 = 0;
    unsigned short Lx2 = 0;
	  hard_init();
	 while(1)
	 {
		 
		//采集第一路电流 PA0
		  adc0=Get_Adc_Average(ADC_Channel_0,10);     		
		  temp0=(float)adc0*(3.3/4096);
		  I1=temp0*1/3.3;
		 
		 //采集第二路电流 PA1
		 	adc1=Get_Adc_Average(ADC_Channel_1,10);     		
		  temp1=(float)adc1*(3.3/4096);
		  I2=temp1*1/3.3;
		 
		 //计算第一路光照
		 if(usart1Buf[2]==0x15) 
		 {
			 Lx1 = ((usart1Buf[4]<<24)|(usart1Buf[5]<<16)|(usart1Buf[6]<<8)|(usart1Buf[7]));	
			 Lux1 = (float) Lx1/100;
		 }
		
		 //计算第二路光照
		 if(usart2Buf[2]==0x15)
		 {
			 Lx2 = ((usart2Buf[4]<<24)|(usart2Buf[5]<<16)|(usart2Buf[6]<<8)|(usart2Buf[7]));	
			 Lux2 = (float) Lx2/100;			
		 }
		 
			//**************************OLED显示并蓝牙发送*****************************//
		  OLED_ShowString1(0,0,"Lx1:");		 
	   	Dis_Float(0,32,Lux1,2);
//	 	  UsartPrintf(USART3,"Lx1:%.2f \n\r",Lux1+1000000);
			UsartPrintf(USART3,"%.2f\n",Lux1+1000000);
		  delay_ms(5);
		 
		  OLED_ShowString1(0,2,"Lx2:");
		  Dis_Float(2,32,Lux2,2);
		  UsartPrintf(USART3,"%.2f\n",Lux2+2000000);
		 delay_ms(5);
		 
		  OLED_ShowString1(0,4,"I1 :");
      Dis_Float(4,32,I1,2);
		  UsartPrintf(USART3,"%.2f\n",I1+3000000);
		 delay_ms(5);
		 
		  OLED_ShowString1(0,6,"I2 :");
		  Dis_Float(6,32,I2,2);
			UsartPrintf(USART3,"%.2f\n",I2+4000000);
			delay_ms(50);
	 }

}


