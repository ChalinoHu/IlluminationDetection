#ifndef __USART_H_
#define __USART_H_


#include "stm32f10x.h"


void Usart1_Init(u32 baud);

void Usart2_Init(u32 baud);

void Usart3_Init(u32 baud);

void Usart_SendString(USART_TypeDef *USARTx, u8 *str, u16 len);

void UsartPrintf(USART_TypeDef *USARTx, char *fmt,...);




#endif
