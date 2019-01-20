#ifndef _USART_H_
#define _USART_H_


#include "stm32f10x.h"


void Usart1_Init(unsigned int baud);

void Usart2_Init(unsigned int baud);

void Usart3_Init(unsigned int baud);

void Usart_SendString(USART_TypeDef *USARTx, unsigned char *str, unsigned short len);

void UsartPrintf(USART_TypeDef *USARTx, char *fmt,...);


void SendInstr(u8 *pucStr, u8 ulNum) ;


#endif
