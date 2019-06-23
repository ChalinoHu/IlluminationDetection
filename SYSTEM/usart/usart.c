#include "usart.h"
#include "delay.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

void Usart1_Init(u32 baud)
{

	GPIO_InitTypeDef gpio_initstruct;
	USART_InitTypeDef usart_initstruct;
	NVIC_InitTypeDef nvic_initstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);							
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);							
	
	//PA9	TXD
	gpio_initstruct.GPIO_Mode = GPIO_Mode_AF_PP;										
	gpio_initstruct.GPIO_Pin = GPIO_Pin_9;											
	gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;								
	GPIO_Init(GPIOA, &gpio_initstruct);											
	
	//PA10	RXD
	gpio_initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;							
	gpio_initstruct.GPIO_Pin = GPIO_Pin_10;											
	gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;								
	GPIO_Init(GPIOA, &gpio_initstruct);												
	
	usart_initstruct.USART_BaudRate = baud;
	usart_initstruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;		//无硬件流控
	usart_initstruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;						//接收和发送
	usart_initstruct.USART_Parity = USART_Parity_No;									//无校验
	usart_initstruct.USART_StopBits = USART_StopBits_1;								//1位停止位
	usart_initstruct.USART_WordLength = USART_WordLength_8b;							//8位数据位
	USART_Init(USART1, &usart_initstruct);
	
	USART_Cmd(USART1, ENABLE);														//使能串口
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);									//使能接收中断
	
	nvic_initstruct.NVIC_IRQChannel = USART1_IRQn;									//usart1中断号
	nvic_initstruct.NVIC_IRQChannelCmd = ENABLE;										//中断通道使能
	nvic_initstruct.NVIC_IRQChannelPreemptionPriority = 0;							//抢占中断优先级(值越小优先级越高)
	nvic_initstruct.NVIC_IRQChannelSubPriority = 1;									//子中断优先级(值越小优先级越高)
	NVIC_Init(&nvic_initstruct);														//初始化NVIC

}


void Usart2_Init(u32 baud)
{

	GPIO_InitTypeDef gpio_initstruct;
	USART_InitTypeDef usart_initstruct;
	NVIC_InitTypeDef nvic_initstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	
	//PA2	TXD
	gpio_initstruct.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio_initstruct.GPIO_Pin = GPIO_Pin_2;
	gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpio_initstruct);
	
	//PA3	RXD
	gpio_initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	gpio_initstruct.GPIO_Pin = GPIO_Pin_3;
	gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &gpio_initstruct);
	
	usart_initstruct.USART_BaudRate = baud;
	usart_initstruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;		//无硬件流控
	usart_initstruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;						//接收和发送
	usart_initstruct.USART_Parity = USART_Parity_No;									//无校验
	usart_initstruct.USART_StopBits = USART_StopBits_1;								//1位停止位
	usart_initstruct.USART_WordLength = USART_WordLength_8b;							//8位数据位
	USART_Init(USART2, &usart_initstruct);
	
	USART_Cmd(USART2, ENABLE);														//使能串口
	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);									//使能接收中断
	
	nvic_initstruct.NVIC_IRQChannel = USART2_IRQn;
	nvic_initstruct.NVIC_IRQChannelCmd = ENABLE;
	nvic_initstruct.NVIC_IRQChannelPreemptionPriority = 0;
	nvic_initstruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&nvic_initstruct);
}


void Usart3_Init(u32 baud)
{

	GPIO_InitTypeDef gpio_initstruct;
	USART_InitTypeDef usart_initstruct;
	NVIC_InitTypeDef nvic_initstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	
	//PB10	TXD
	gpio_initstruct.GPIO_Mode = GPIO_Mode_AF_PP;
	gpio_initstruct.GPIO_Pin = GPIO_Pin_10;
	gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio_initstruct);
	
	//PB11	RXD
	gpio_initstruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	gpio_initstruct.GPIO_Pin = GPIO_Pin_11;
	gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &gpio_initstruct);
	
	usart_initstruct.USART_BaudRate = baud;
	usart_initstruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;		//无硬件流控
	usart_initstruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;						//接收和发送
	usart_initstruct.USART_Parity = USART_Parity_No;									//无校验
	usart_initstruct.USART_StopBits = USART_StopBits_1;								//1位停止位
	usart_initstruct.USART_WordLength = USART_WordLength_8b;							//8位数据位
	USART_Init(USART3, &usart_initstruct);
	
	USART_Cmd(USART3, ENABLE);														//使能串口
	
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);									//使能接收中断
	
	nvic_initstruct.NVIC_IRQChannel = USART3_IRQn;
	nvic_initstruct.NVIC_IRQChannelCmd = ENABLE;
	nvic_initstruct.NVIC_IRQChannelPreemptionPriority = 0;
	nvic_initstruct.NVIC_IRQChannelSubPriority = 3;
	NVIC_Init(&nvic_initstruct);

}

//发送字符串
void Usart_SendString(USART_TypeDef *USARTx, u8 *str, u16 len)
{

	u16 count = 0;
	
	for(; count < len; count++)
	{
		USART_SendData(USARTx, *str++);									//发送数据
		while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);		//等待发送完成
	}

}

//可变长参数格式化打印输出
void UsartPrintf(USART_TypeDef *USARTx, char *fmt,...)
{

	u8 UsartPrintfBuf[296];
	va_list ap;
	u8 *pStr = UsartPrintfBuf;
	
	va_start(ap, fmt);
	vsprintf((char *)UsartPrintfBuf, fmt, ap);							//格式化
	va_end(ap);
	
	while(*pStr != 0)
	{
		USART_SendData(USARTx, *pStr++);
		while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);
	}

}



u16 usart1Len;
u8 usart1Buf[9];
void USART1_IRQHandler(void)
{

	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)	//接收中断
	{
		if(usart1Len >= 9)									//防止数据过多，导致内存溢出
			usart1Len = 0;
		usart1Buf[usart1Len++] = USART1->DR;
		
		USART_ClearFlag(USART1, USART_FLAG_RXNE);
	}

}


u16 usart2Len;
u8 usart2Buf[9];
void USART2_IRQHandler(void)
{

	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)	//接收中断
	{
			if(usart2Len >= 9)									//防止数据过多，导致内存溢出
				usart2Len = 0;
			
			usart2Buf[usart2Len++] = USART2->DR;
		
		USART_ClearFlag(USART2, USART_FLAG_RXNE);
	}

}

u16 usart3Len;
u8 usart3Buf[9];
void USART3_IRQHandler(void)
{

	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)	//接收中断
	{
		
		USART_ClearFlag(USART3, USART_FLAG_RXNE);
	}

}
